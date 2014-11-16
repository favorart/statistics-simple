//--
#define DECLARE_GLOBALS
//--
#include <windows.h>
#include <tchar.h>
//--
#include "resource.h"
#include "draw.h"
//--
#pragma warning (disable:4010)
#pragma warning (disable:4996)
//--
#define CLR_BG_SPEC  RGB(223, 225, 234)
#define CLR_POLIGON  RGB(016, 032, 255)
#define CLR_HISTOGR  RGB(000, 255, 000)
#define CLR_F_DSTRB  RGB(255, 000, 000)
//--
LRESULT CALLBACK            WndProc (HWND   hWnd, UINT messg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK       AboutDlgProc (HWND   hDlg, UINT  uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK  FloatPointDlgProc (HWND hFpDlg, UINT  uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK  ColorShapeDlgProc (HWND hCsDlg, UINT  uMsg, WPARAM wParam, LPARAM lParam);
//--
void                         OnMenu (HWND   hWnd,             WPARAM wParam, 
	                                    TCHAR *newFile, myData *vrtx, HWND hListView, 
																																			  bool &mylocale, DWORD *myColor);
//--
INT WINAPI  WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
	// HINSTANCE  hIcon;
	HWND      hWnd;  
 MSG       lpMsg;
 WNDCLASS  wc;
	TCHAR     szClassName[] = _T("Class_Statistic_Simple");

 // Заполняем структуру класса окна
 wc.style         = CS_HREDRAW | CS_VREDRAW;
 wc.lpfnWndProc   = WndProc;
 wc.cbClsExtra    = 0;
 wc.cbWndExtra    = 0;
 wc.hInstance     = hInstance;
 wc.hIcon         = LoadIcon   (hInstance, MAKEINTRESOURCE (IDI_MYICON));
 wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)CreateSolidBrush (0xFEF5F3); // (COLOR_MENUHILIGHT);
 wc.lpszMenuName  = MAKEINTRESOURCE (IDR_MENU1);
 wc.lpszClassName = szClassName;
 
 // Регистрируем класс окна
 if( !RegisterClass (&wc) )
 {
		MessageBox (NULL, _T("Can't register window class"), _T("Error"), MB_OK | MB_ICONWARNING);
  return 0;
 }

 // Создаем основное окно приложения
 hWnd = CreateWindow ( 
       szClassName,                       // Имя класса                    
       _T("Statistic Simple"),            // Текст заголовка 
       WS_OVERLAPPEDWINDOW | WS_SYSMENU,  // Стиль окна 
							0,    0,                           // Позиция левого верхнего угла   
       1024,  600,                        // Ширина и высота окна     
       (HWND) NULL,                       // Указатель на родительское окно NULL     
       (HMENU) NULL,                      // Используется меню класса окна               
       (HINSTANCE) hInstance,             // Указатель на текущее приложение
       NULL );						                      // Передается в качестве lParam в событие WM_CREATE

 if( !hWnd ) 
 {
		MessageBox (NULL, _T("Can't create main window"), _T("Error"), MB_OK | MB_ICONWARNING);
  return 0;
 }

 // Показываем наше окно
 ShowWindow   (hWnd, nCmdShow); 
 UpdateWindow (hWnd);

 // Выполняем цикл обработки сообщений до закрытия приложения
 while( GetMessage (&lpMsg, NULL, 0, 0) )  
 { TranslateMessage (&lpMsg);
    DispatchMessage (&lpMsg);
 }

 return (lpMsg.wParam);
}
//--
LRESULT CALLBACK  WndProc (HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	RECT        Rect;
	HDC         hdc, hCmpDC;
	HBITMAP     hBmp;
	//--
	static double  num_ch[8];
	static myData  vrtx;
	static TCHAR   newFile[1024] = {_T("inc.txt")};
	static bool    mylocale      =  0;
	static DWORD   myColor[]     = { CLR_POLIGON, CLR_HISTOGR, CLR_F_DSTRB };
	//--
	static HWND  h_Chk1, h_Chk2, h_Chk3, h_Chk4, hListViewCh, hListView;
	static int   listView = 0xF1, listViewCh = 0xFC;
	static RECT  Rect1;

	switch (messg)
	{
	case WM_CREATE:
		{
			RegisterHotKey (hWnd, HK_FILE,   MOD_CONTROL, 0x4f); // 'O'
			RegisterHotKey (hWnd, HK_README, MOD_CONTROL, 0x48); // 'H'
			RegisterHotKey (hWnd, HK_PRINT,  MOD_CONTROL, 0x50); // 'P'
			RegisterHotKey (hWnd, HK_COLOR,  MOD_CONTROL, 0x4c); // 'L'
			RegisterHotKey (hWnd, HK_EXIT,   NULL, 0x1B);        // 'Esc'

			GetClientRect (hWnd, &Rect);
			h_Chk1 = CreateWindow (TEXT ("button"), TEXT ("Poligon"), 
				WS_VISIBLE | WS_CHILD | BS_CHECKBOX, 
				Rect.right - 550, 
				300 + 10, 
				200, 
				25, 
				hWnd, (HMENU) 0xCB01, (HINSTANCE) GetWindowLong (hWnd, GWL_HINSTANCE), NULL);
			h_Chk2 = CreateWindow (TEXT ("button"), TEXT ("Histogram"), 
				WS_VISIBLE | WS_CHILD | BS_CHECKBOX, 
				Rect.right - 550, 
				300 + 35, 
				200, 
				25, 
				hWnd, (HMENU) 0xCB02, (HINSTANCE) GetWindowLong (hWnd, GWL_HINSTANCE), NULL);
			h_Chk3 = CreateWindow (TEXT ("button"), TEXT ("Distribution Function"), 
				WS_VISIBLE | WS_CHILD | BS_CHECKBOX, 
				Rect.right - 550, 
				300 + 60, 
				200, 
				25, 
				hWnd, (HMENU) 0xCB03, (HINSTANCE) GetWindowLong (hWnd, GWL_HINSTANCE), NULL);
			h_Chk4 = CreateWindow (TEXT ("button"), TEXT ("Show marks"), 
				WS_VISIBLE | WS_CHILD | BS_CHECKBOX, 
				Rect.right - 550, 
				300 + 100, 
				200, 
				25, 
				hWnd, (HMENU) 0xCB04, (HINSTANCE) GetWindowLong (hWnd, GWL_HINSTANCE), NULL);

			CheckDlgButton (hWnd, 0xCB01, BST_UNCHECKED);
			CheckDlgButton (hWnd, 0xCB02, BST_UNCHECKED);
			CheckDlgButton (hWnd, 0xCB03, BST_UNCHECKED);
			CheckDlgButton (hWnd, 0xCB04, BST_CHECKED  );

			hListViewCh = CreateWindow (WC_LISTVIEW, _T("MyList"), 
				LVS_REPORT | WS_CHILD | WS_VISIBLE, 
				Rect.right - 265, 
				312, 
				250, 
				200, 
				hWnd, (HMENU) listViewCh, (HINSTANCE) GetWindowLong (hWnd, GWL_HINSTANCE), NULL);
			//--
			LVCOLUMN lvColumn = {0};
			lvColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT;
			lvColumn.fmt  = LVCFMT_CENTER;
			lvColumn.pszText = _T("№");
			lvColumn.cx = 30;
			ListView_InsertColumn (hListViewCh, 0, &lvColumn);

			lvColumn.pszText = _T("Property");
			lvColumn.cx = 70;
			ListView_InsertColumn (hListViewCh, 1, &lvColumn);

			lvColumn.pszText = _T("Value");
			lvColumn.cx = 120;
			ListView_InsertColumn (hListViewCh, 2, &lvColumn);
			//--
			hListView = CreateWindow (WC_LISTVIEW, _T("Set of variate values"), 
				LVS_REPORT|WS_CHILD|WS_VISIBLE, 
				Rect.right - 550, 
				Rect.top   +  15, 
				535, 
				275, 
				hWnd, 
				(HMENU) listView, (HINSTANCE) GetWindowLong (hWnd, GWL_HINSTANCE), NULL);
			//--
			lvColumn.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT;
			lvColumn.pszText = _T("No");
			lvColumn.fmt = LVCFMT_CENTER;
			lvColumn.cx = 43;
			ListView_InsertColumn (hListView, 0, &lvColumn);
			//--
			lvColumn.pszText = _T("[ a[i-1]      ,         a[i] )");
			lvColumn.cx = 151;
			ListView_InsertColumn (hListView, 1, &lvColumn);
			//--
			lvColumn.pszText = _T("xi");
			lvColumn.cx = 85;
			ListView_InsertColumn (hListView, 2, &lvColumn);
			//--
			lvColumn.pszText = _T("ni");
			ListView_InsertColumn (hListView, 3, &lvColumn);
			//--
			lvColumn.pszText = _T("Ʋ");
			ListView_InsertColumn (hListView, 4, &lvColumn);
			//--
			lvColumn.pszText = _T("ΣƲ");
			ListView_InsertColumn (hListView, 5, &lvColumn);
			//--
			// hLabel_2 = CreateWindow (_T("STATIC"), 
			//																										NULL, //"ST_U", 
			//																										WS_CHILD | WS_VISIBLE | WS_TABSTOP, 
			//																										Rect.right     - 265, // left
			//																										Rect.bottom/2  +  10, // top
			//																										255, 																		// Width
			//																										Rect.bottom/2  -  25, // Height
			//																										hWnd, 
			//																										(HMENU)label_2, 
			//																										(HINSTANCE)GetWindowLong (hWnd, GWL_HINSTANCE), 
			//																										NULL );

			// hLabel_1 = CreateWindow (_T("STATIC"), 
			// 																									NULL, 
			// 																									WS_CHILD | WS_VISIBLE | WS_TABSTOP, 
			// 																									Rect.right     - 410, 
			// 																									Rect.top       +  15, 
			// 																									Rect.right     -  15, 
			// 																									Rect.bottom/2  -  10, 
			// 																									hWnd, 
			// 																									(HMENU)label_1, 
			// 																									(HINSTANCE)GetWindowLong (hWnd, GWL_HINSTANCE), 
			// 																									NULL );

			break;
		}

	case WM_PAINT:
		{
			GetClientRect (hWnd, &Rect);
			hdc = BeginPaint (hWnd, &ps);
			// Создание теневогоs контекста для двойной буфферизации
			hCmpDC = CreateCompatibleDC (hdc);
			hBmp   = CreateCompatibleBitmap (hdc, Rect.right - Rect.left, Rect.bottom - Rect.top);
			SelectObject (hCmpDC, hBmp);

			// Закраска фоновым цветом
			HBRUSH _WHITE_BRUSH = CreateSolidBrush (0xFFFFFF);

			// здесь прекрасно работающий label
			// hdc1 = BeginPaint (hLabel_2 /* вот тут *** hWnd было - поэтому не работало */, &ps1);
			// SetWindowPos (hLabel_2, 
			// 												  HWND_TOP, 
			// 												  Rect.right     - 270, 
			// 												  Rect.bottom/2  +  10, 
			// 												  255, 																	
			// 												  Rect.bottom/2  -  25, 
			// 												  NULL);
			// GetClientRect (hLabel_2, &Rect2);
			// FillRect (hdc1, &Rect2, (HBRUSH) (_WHITE_BRUSH));
			// EndPaint (hLabel_2, &ps1);
			//--

			// Здесь рисуем на контексте hCmpDC
			DrawForm (hCmpDC, Rect);

			if( IsDlgButtonChecked (hWnd, 0xCB03) == 1U )
			{
				DrawGraphic (hCmpDC, &vrtx, 0xFFFFFF, 0xFFFFFF, myColor[2], (bool) IsDlgButtonChecked (hWnd, 0xCB04));
			}
			if( IsDlgButtonChecked (hWnd, 0xCB03) == 0U )
			{ 
				if( IsDlgButtonChecked (hWnd, 0xCB02) )
					DrawGraphic (hCmpDC, &vrtx, 0xFFFFFF, myColor[1], 0xFFFFFF, (bool) IsDlgButtonChecked (hWnd, 0xCB04));
				if( IsDlgButtonChecked (hWnd, 0xCB01) )
					DrawGraphic (hCmpDC, &vrtx, myColor[0], 0xFFFFFF, 0xFFFFFF, (bool) IsDlgButtonChecked (hWnd, 0xCB04));			
			}
			//--

			// Копируем изображение из теневого контекста на экран
			SetStretchBltMode (hdc, COLORONCOLOR);
			BitBlt (hdc, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top, hCmpDC, 0, 0, SRCCOPY);

			// Удаляем ненужные системные объекты
			DeleteObject (_WHITE_BRUSH);
			//--
			DeleteDC (hCmpDC);
			DeleteObject (hBmp);
			hCmpDC = NULL;
			EndPaint (hWnd, &ps);
			break;
		}

	case WM_MOVE:
	case WM_SIZE:
		GetClientRect (hWnd, &Rect);
		//--
		SetWindowPos (h_Chk1, NULL, Rect.right - 550, 300  + 10, 200, 25, SWP_NOZORDER | SWP_NOSIZE);
		SetWindowPos (h_Chk2, NULL, Rect.right - 550, 300  + 35, 200, 25, SWP_NOZORDER | SWP_NOSIZE);
		SetWindowPos (h_Chk3, NULL, Rect.right - 550, 300  + 60, 200, 25, SWP_NOZORDER | SWP_NOSIZE);
		SetWindowPos (h_Chk4, NULL, Rect.right - 550, 300  +100, 200, 25, SWP_NOZORDER | SWP_NOSIZE);
		//-- LISTVIEW POSITION
		SetWindowPos (hListViewCh, NULL,
			Rect.right - 265,
			312,
			250,
			200,
			SWP_NOSIZE);
		//-- LISTVIEW POSITION
		SetWindowPos (hListView, NULL,
			Rect.right - 550,
			Rect.top   +  15,
			535,
			340,
			SWP_NOSIZE | SWP_NOZORDER);
		//--
		break;

	case WM_CTLCOLORSTATIC:
		SetTextColor ((HDC) wParam, 0);
		SetBkMode    ((HDC) wParam, TRANSPARENT);
		return (BOOL) CreateSolidBrush (0xEAE1DF);
		break;

	case WM_GETMINMAXINFO:
		((MINMAXINFO*) lParam)->ptMinTrackSize.x = 1024;
		((MINMAXINFO*) lParam)->ptMinTrackSize.y =  600;
		break;

	case WM_ERASEBKGND:
		return 1;
		break;

	case WM_COMMAND:
		{
			OnMenu (hWnd, wParam, newFile, &vrtx, hListView, mylocale, myColor);

			switch (wParam)
			{
				// check box code
			case 0xCB01:
				if( IsDlgButtonChecked (hWnd, 0xCB01) )
				{ CheckDlgButton (hWnd, 0xCB01, BST_UNCHECKED); }
				else
				{
					CheckDlgButton (hWnd, 0xCB01, BST_CHECKED);
					CheckDlgButton (hWnd, 0xCB03, BST_UNCHECKED);
				}
				break;

			case 0xCB02:
				if( IsDlgButtonChecked (hWnd, 0xCB02) )
				{ CheckDlgButton (hWnd, 0xCB02, BST_UNCHECKED); }
				else
				{
					CheckDlgButton (hWnd, 0xCB02, BST_CHECKED);
					CheckDlgButton (hWnd, 0xCB03, BST_UNCHECKED);
				}			
				break;

			case 0xCB03:
				if( IsDlgButtonChecked (hWnd, 0xCB03) )
				{ CheckDlgButton (hWnd, 0xCB03, BST_UNCHECKED); }
				else
				{
					CheckDlgButton (hWnd, 0xCB01, BST_UNCHECKED);
					CheckDlgButton (hWnd, 0xCB02, BST_UNCHECKED);
					CheckDlgButton (hWnd, 0xCB03, BST_CHECKED  );
				}			
				break;

			case 0xCB04:
				if( IsDlgButtonChecked (hWnd, 0xCB04) )
					CheckDlgButton (hWnd, 0xCB04, BST_UNCHECKED);
				else
					CheckDlgButton (hWnd, 0xCB04, BST_CHECKED  );
				break;
			}

			GetClientRect  (hWnd, &Rect);
			InvalidateRect (hWnd, &Rect, 0);
			break;
		}

	case WM_USER+1:
		Calculate (hListView, hListViewCh, vrtx, num_ch, newFile, mylocale);
		GetClientRect  (hWnd, &Rect);
		InvalidateRect (hWnd, &Rect, 0);
		break;

	case WM_HOTKEY:
		switch (wParam)
		{
		case HK_FILE:
			SendMessage (hWnd, WM_COMMAND,  ID_FILE_OPENS, 0);
			break;

		case HK_PRINT:
			SendMessage (hWnd, WM_COMMAND, ID_FILE_PRINTS, 0);
			break;

		case HK_README:
			SendMessage (hWnd, WM_COMMAND, ID_FILE_README, 0);
			break;

		case HK_COLOR:
			SendMessage (hWnd, WM_COMMAND, ID_FILE_COLOR , 0);
			break;

		case HK_EXIT:
			SendMessage (hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;

	case WM_QUIT:
		SendMessage (hWnd, WM_DESTROY, 0, 0);
		break;

	case WM_CLOSE:
		SendMessage (hWnd, WM_DESTROY, 0, 0);
		break;

	case WM_DESTROY:
		PostQuitMessage (0);
		break;

	default:
		return (DefWindowProc (hWnd, messg, wParam, lParam));
	}

	return (0);
}
//--
void  OnMenu (HWND hWnd, WPARAM wParam, 
	             TCHAR *newFile, myData *vrtx, 
														HWND hListView, bool &mylocale, DWORD *myColor)
{
	OPENFILENAME OpenFileName = {};  // common dialog box structure
	CHOOSECOLOR  cc = {};            // common dialog box structure 

	switch (wParam)
	{
	case ID_FILE_EXIT:
		SendMessage (hWnd, WM_QUIT, 0, 0);
		break;

	case ID_FILE_OPENS:
		// MessageBox (0, "Sorry, it is not complited", "Oops!", MB_OK | MB_ICONINFORMATION);

		TCHAR  szFile[260];            // buffer for file name
		//	HWND hwnd;                  // owner window
		// HANDLE hfile;               // file handle

		// Initialize OPENFILENAME
		OpenFileName.lStructSize = sizeof (OpenFileName);
		OpenFileName.hwndOwner   = hWnd;
		OpenFileName.lpstrFile   = szFile;

		// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
		// use the contents of szFile to initialize itself.
		OpenFileName.lpstrFile[0]    = '\0';
		OpenFileName.nMaxFile        = sizeof (szFile);
		OpenFileName.lpstrFilter     = _T("Text\0*.TXT\0All\0*.*\0");
		OpenFileName.nFilterIndex    = 1;
		OpenFileName.lpstrFileTitle  = NULL;
		OpenFileName.nMaxFileTitle   = 0;
		OpenFileName.lpstrInitialDir = NULL;
		OpenFileName.Flags           = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		// Display the Open dialog box. 
		if( GetOpenFileName (&OpenFileName) == TRUE ) 
		{
			_tcscpy (newFile, OpenFileName.lpstrFile);

			mylocale = (bool) (DialogBox ( (HINSTANCE) GetWindowLong (hWnd, GWL_HINSTANCE), 
				TEXT ("FloatPointDlg"), 
				hWnd, 
				(DLGPROC) FloatPointDlgProc
				));

			SendMessage (hWnd, WM_USER+1, 0, 0);
		}
		// hfile = CreateFile (OpenFileName.lpstrFile, \
		GENERIC_READ, \
		0, \
		(LPSECURITY_ATTRIBUTES)NULL, \
		OPEN_EXISTING, \
		FILE_ATTRIBUTE_NORMAL, \
		(HANDLE)NULL);
		break;

	case ID_FILE_README:
		ShellExecute (NULL, NULL, _T("readme.txt"), NULL, NULL, SW_SHOWNORMAL);
		break;

	case ID_FILE_ABOUT:
		DialogBox ( (HINSTANCE)GetWindowLong (hWnd, GWL_HINSTANCE), 
			TEXT ("AboutDlg"), 
			hWnd, 
			(DLGPROC)AboutDlgProc 
			);
		break;

	case ID_FILE_COLOR:
		{
			RECT Rect;
			int shape = DialogBox ( (HINSTANCE)GetWindowLong (hWnd, GWL_HINSTANCE), 
				TEXT ("ColorShapeDlg"), 
				hWnd, 
				(DLGPROC)ColorShapeDlgProc
				);

			static COLORREF acrCustClr[16]; // array of custom colors 
			// HBRUSH hbrush;                // brush handle
			// DWORD rgbCurrent;      // initial color selection

			// Initialize CHOOSECOLOR 
			cc.lStructSize = sizeof (cc);
			cc.hwndOwner = hWnd;
			cc.lpCustColors = (LPDWORD)acrCustClr;
			cc.rgbResult = myColor[shape];
			cc.Flags = CC_FULLOPEN | CC_RGBINIT;

			if( ChooseColor (&cc)) 
			{
				myColor[shape] = cc.rgbResult;

				GetClientRect (hWnd, &Rect  );
				InvalidateRect (hWnd, &Rect, 0);
			}
		}
		break;


	case ID_FILE_PRINTS:
		{
			PRINTDLG pd = {0};
			DOCINFO docInfo = {0};

			// Инициализация DOCINFO
			docInfo.cbSize = sizeof (docInfo);
			docInfo.lpszDocName = _T("Statistic Simple");

			// Инициализация PRINTDLG
			pd.lStructSize = sizeof (PRINTDLG);
			pd.hwndOwner = hWnd;
			pd.hDevMode = NULL;  // Не забудьте освободить или сохранить hDevMode
			pd.hDevNames = NULL; // Не забудьте освободить или сохранить hDevNames
			pd.Flags = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC;
			pd.nCopies = 1;
			pd.nFromPage = 0xFFFF;
			pd.nToPage = 0xFFFF;
			pd.nMinPage = 1;
			pd.nMaxPage = 0xFFFF;

			//DEVMODE DevMode = {};
			//
			//DevMode.dmOrientation = DMORIENT_LANDSCAPE;
			//DevMode.dmFields |= DM_ORIENTATION;
			//GlobalUnlock (pd.hDevMode);

			//pd.hDevMode = NULL;
			//if( GetPrinterDeviceDefaults (&pd))
			//{
			//			DEVMODE *dm = (DEVMODE*)LocalLock (pd.hDevMode);
			//			dm->dmFields = DM_ORIENTATION | DM_PAPERSIZE;
			//			dm->dmOrientation = DMORIENT_LANDSCAPE; 
			//			dm->dmPaperSize = DMPAPER_A4;
			//			//prtDlg.m_pd.hDevMode = pd.hDevMode;
			//			LocalUnlock (pd.hDevMode);
			//}

			if( PrintDlg (&pd) ) 
			{ // GDI обращается к выполнению вывода данных.
				// Now that PrintDlg has returned, a device context handle
				// for the chosen printer is in printDlg.hDC.

				StartDoc (pd.hDC, &docInfo);
				// Draw Graphic
				{
					StartPage (pd.hDC);
					RECT Rect_tmp = Rect1;
					Rect1.left    =  100;
					Rect1.top     =  100;
					Rect1.right   =  GetDeviceCaps (pd.hDC, HORZRES) / 2 - 100;
					Rect1.bottom  =  GetDeviceCaps (pd.hDC, VERTRES)     - 100;			
					DrawGraphic (pd.hDC, vrtx, 0x000000, 0x000000, 0xFFFFFF, 1);
					//--
					Rect1.left    =  100 + GetDeviceCaps (pd.hDC, HORZRES) / 2;
					Rect1.top     =  100;
					Rect1.right   =  GetDeviceCaps (pd.hDC, HORZRES) - 100;
					Rect1.bottom  =  GetDeviceCaps (pd.hDC, VERTRES) - 100;	
					DrawGraphic (pd.hDC, vrtx, 0xFFFFFF, 0xFFFFFF, 0x000000, 1);
					//--
					Rect1 = Rect_tmp;	
					EndPage (pd.hDC);

					// Draw Text
					//		StartPage (pd.hDC);
					//			TEXTMETRIC tm;
					//			RECT myRect;
					//			GetTextMetrics (pd.hDC, &tm);

					//			myRect.left   = (LONG) (GetDeviceCaps (pd.hDC, HORZRES)*0.05);
					//			myRect.top    = (LONG) (GetDeviceCaps (pd.hDC, VERTRES)*0.05);
					//			myRect.right  =	 (LONG) (GetDeviceCaps (pd.hDC, HORZRES)*0.95);
					//			myRect.bottom = (LONG) (GetDeviceCaps (pd.hDC, VERTRES)*0.95);

					//			SIZE s;
					//			TCHAR _text[100] = {_T("No     [   aj    ,     ai  )      xi         ni        V          EV")};
					//			TextOut (pd.hDC, myRect.left, myRect.top, _text, _tcslen (_text));
					//			myRect.top += tm.tmHeight;

					//			for (int j=0; j<10; j++)
					//			{
					//				_text[0]=0;
					//				for (int i=0, len=0; i<7; i++)
					//				{
					//					_tcscat (_text+_tcslen (_text), _T("   "));
					//					GetTextExtentPoint32 (pd.hDC, _text, 	 (_tcslen (_text)), &s);
					//					len +=  s.cx;
					//					ListView_GetItemText (hListView, j, i, _text, 100);
					//					TextOut (pd.hDC, 
					//													myRect.left + len, 
					//													myRect.top  + j*tm.tmHeight, 
					//													_text, 
					//													_tcslen (_text)
					//												);
					//			}
					//		}
					//	EndPage (pd.hDC);

				}
				EndDoc (pd.hDC);

				if( pd.hDevMode) 
					GlobalFree (pd.hDevMode);
				if( pd.hDevNames) 
					GlobalFree (pd.hDevNames);
				DeleteDC (pd.hDC); 			// После выполнения удаляем DC.
			}
		}
		break;
	}
}

INT_PTR CALLBACK      AboutDlgProc (HWND   hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch ( uMsg ) 
	{
	case WM_INITDIALOG:
		return TRUE;


	case WM_PAINT:
		{
			RECT Rect;
			PAINTSTRUCT ps;
			HDC hdc;

			GetClientRect (hDlg, &Rect);
			hdc = BeginPaint (hDlg, &ps);
			FillRect (hdc, &Rect, (HBRUSH)CreateSolidBrush (0xEAE1DF));
			EndPaint (hDlg, &ps);
			return TRUE;
		}

	case WM_CTLCOLORSTATIC:
		SetTextColor ( (HDC)wParam, 0);
		SetBkMode ( (HDC)wParam, TRANSPARENT);
		return (BOOL)CreateSolidBrush (0xEAE1DF);

	case WM_COMMAND:
		switch ( wParam ) 
		{case IDOK:
		EndDialog ( hDlg, TRUE );
		return TRUE;
		}
		break;
	}
	return FALSE;
}
INT_PTR CALLBACK FloatPointDlgProc (HWND hFpDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hCombo = NULL;

	switch (uMsg) 
	{
	 case WM_INITDIALOG:
	 	hCombo = (HWND) GetDlgItem (hFpDlg, IDD_COMBOF);
	 
	 	SendMessage (hCombo, CB_DELETESTRING, 0, 0);
	 	SendMessage (hCombo, CB_ADDSTRING,    0, (LPARAM) _T(".") );
	 	SendMessage (hCombo, CB_ADDSTRING,    0, (LPARAM) _T(", ") );
	 	SendMessage (hCombo, CB_SETCURSEL,    0, 0);
	 	return TRUE;
	 
	 case WM_PAINT:
	 	{
	 		RECT         Rect;
	 		PAINTSTRUCT  ps;
	 		HDC          hdc;
	 
	 		GetClientRect (hFpDlg, &Rect);
	 		hdc = BeginPaint (hFpDlg, &ps);
	 
	 		FillRect (hdc, &Rect, (HBRUSH) CreateSolidBrush (0xEAE1DF));
	 
	 		EndPaint (hFpDlg, &ps);
	 		return TRUE;
	 	}
	 
	 case WM_CTLCOLORSTATIC:
	 	SetTextColor ((HDC) wParam, 0);
	 	SetBkMode    ((HDC) wParam, TRANSPARENT);
	 	return (BOOL) CreateSolidBrush (0xEAE1DF);
	 
	 case WM_COMMAND:
	 	switch (wParam) 
	 	{
	 	 case IDOK:
	 	  hCombo = (HWND)GetDlgItem (hFpDlg, IDD_COMBOF);
	 	  EndDialog (hFpDlg, SendMessage (hCombo, CB_GETCURSEL, 0, 0));
	 	  return TRUE;
	 	}
	 	break;
	}
	return FALSE;
}


INT_PTR CALLBACK ColorShapeDlgProc (HWND hCsDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hCombo;

	switch (uMsg) 
	{
  case WM_INITDIALOG:
  	hCombo = (HWND) GetDlgItem (hCsDlg, IDD_COMBOC);
  
  	/* hCombo = CreateWindow ("COMBOBOX", 
  	 *                        NULL, 
  	 *                        WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST, 
  	 *                        10, 15, 40, 15, 
  	 *                        hFpDlg, 
  	 *                        NULL, 
  	 *                        ghInstance, 
  	 *                        NULL );
  	 */
  
  	/* if( !hCombo )
  	 * {
  	 *  MessageBox (hFpDlg, "Could not create the combo box", "Error", MB_OK | MB_ICONWARNING);
  	 *  return FALSE;
  		* }
  	 */
  
  	SendMessage (hCombo, CB_DELETESTRING, 0, 0);
  	SendMessage (hCombo, CB_ADDSTRING,    0, (LPARAM) _T("Poligon")    );
  	SendMessage (hCombo, CB_ADDSTRING,    0, (LPARAM) _T("Histogram")  );
  	SendMessage (hCombo, CB_ADDSTRING,    0, (LPARAM) _T("Distr Func") );
  	SendMessage (hCombo, CB_SETCURSEL,    0, 0);
  	return TRUE;
  
  case WM_PAINT:
  	{
  		RECT         Rect;
  		PAINTSTRUCT  ps;
  		HDC          hdc;
  
  		GetClientRect (hCsDlg, &Rect);
  		hdc = BeginPaint (hCsDlg, &ps);
  
  		FillRect (hdc, &Rect, (HBRUSH) CreateSolidBrush (0xEAE1DF));
  
  		EndPaint (hCsDlg, &ps);
  		return TRUE;
  	}
  
  case WM_CTLCOLORSTATIC:
  	SetTextColor ( (HDC)wParam, 0);
  	SetBkMode   ( (HDC)wParam, TRANSPARENT);
  	return (BOOL)CreateSolidBrush (0xEAE1DF);
  
  case WM_COMMAND:
  	switch (wParam) 
  	{
  	 case IDOK:
  	  hCombo = (HWND) GetDlgItem (hCsDlg, IDD_COMBOC);
  	  EndDialog (hCsDlg, SendMessage (hCombo, CB_GETCURSEL, 0, 0));
  	  return TRUE;
  	}
  	break;
	}
	return FALSE;
}
