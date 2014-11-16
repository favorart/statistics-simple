#include "draw.h"
//--
#pragma warning (disable:4996)
//--
#define MIN(A,B) ((A)>(B)?(B):(A))
#define MAX(A,B) ((A)>(B)?(A):(B))
//--
void  DrawRect (HDC hdc, RECT Rect, int  cWight, DWORD lpColor, int iStyle)
{
	HGDIOBJ hpen, hPen_old;

	hpen = CreatePen (iStyle, cWight, lpColor);
	hPen_old = SelectObject (hdc, hpen);
	//--
	MoveToEx (hdc, Rect.left, Rect.top, NULL);
	LineTo (hdc, Rect.right, Rect.top);
	LineTo (hdc, Rect.right, Rect.bottom);
	LineTo (hdc, Rect.left, Rect.bottom);
	LineTo (hdc, Rect.left, Rect.top);
	//--
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
}

void  FillCircle (HDC hdc, int c_x, int c_y, int r, DWORD lpColor)
{
	int n;
	HGDIOBJhpen, hPen_old;

	if(r > 30)
		return;

	hpen = CreatePen (PS_SOLID, 1, lpColor);
	hPen_old = SelectObject (hdc, hpen);
	//--
	for(n=0; n<360; n++)
	{		
		int r_x =  (int ) (c_x + r * cos((float)n));
		int r_y =  (int ) (c_y + r * sin((float)n));

		MoveToEx (hdc, c_x, c_y, NULL);
		LineTo   (hdc, r_x, r_y);
	}
	MoveToEx (hdc, c_x, c_y, NULL);
}

void  DrawForm (HDChdc, RECTRect)
{
	LOGBRUSH br;
	HGDIOBJ  hpen, hPen_old;
	HBRUSH   brush_font,  brush_white;
	HBRUSH   brush_font1, brush_font2, brush_font3, brush_font4;

	br.lbStyle  = BS_SOLID;
	br.lbColor  = 0xEAE1DF;
	brush_font  = CreateBrushIndirect (&br);
	br.lbColor  = 0xF4EBE9;
	brush_font1 = CreateBrushIndirect (&br); // +10
	br.lbColor  = 0xE0D7D5;																	 
	brush_font2 = CreateBrushIndirect (&br); // -10
	br.lbColor  = 0xFEF5F3;																	 
	brush_font3 = CreateBrushIndirect (&br); // +20
	br.lbColor  = 0xD6CDCB;																	 
	brush_font4 = CreateBrushIndirect (&br); // -20
	br.lbColor  = 0xFFFFFF;
	brush_white = CreateBrushIndirect (&br);
	//--
	FillRect (hdc, &Rect, (HBRUSH) (brush_font));/*  (COLOR_MENUBAR+1) */
	//--
	Rect1.top    = Rect.top    + 15;
	Rect1.bottom = Rect.bottom - 15;
	Rect1.left   = Rect.left   + 15;
	Rect1.right  = Rect.right  - 570;

	/* Rect2.top = 365+10;
	 * Rect2.bottom = 665-15;
	 * Rect2.left = Rect.right-270;
	 * Rect2.right = Rect.right-15;
		*/
	/* Rect3.top = Rect.top+15;
	 * Rect3.bottom = Rect.bottom/2-10;
	 * Rect3.left = Rect.right-410;
	 * Rect3.right = Rect.right-15;
		*/
	FillRect (hdc, &Rect1, (HBRUSH) (brush_white));// brush_font

	// FillRect (hdc, &Rect2, (HBRUSH) (brush_white));
	// FillRect (hdc, &Rect3, (HBRUSH) (brush_white));
	//--
	hpen = CreatePen (PS_SOLID, 1, 0xD6CDCB);
	hPen_old = SelectObject (hdc, hpen);

	MoveToEx (hdc, 15, 15, NULL);
	LineTo   (hdc, 15, Rect.bottom-15);
	MoveToEx (hdc, 14, 14, NULL);
	LineTo   (hdc, 14, Rect.bottom-14);
	MoveToEx (hdc, 13, 13, NULL);
	LineTo   (hdc, 13, Rect.bottom-13);
	MoveToEx (hdc, 12, 12, NULL);
	LineTo   (hdc, 12, Rect.bottom-12);
	MoveToEx (hdc, 11, 11, NULL);
	LineTo   (hdc, 11, Rect.bottom-11);

	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	//--
	hpen = CreatePen (PS_SOLID, 1, 0xFEF5F3);
	hPen_old = SelectObject (hdc, hpen);

	MoveToEx (hdc, Rect.right-570, 15, NULL);
	LineTo   (hdc, Rect.right-570, Rect.bottom-15);
	MoveToEx (hdc, Rect.right-569, 14, NULL);
	LineTo   (hdc, Rect.right-569, Rect.bottom-14);
	MoveToEx (hdc, Rect.right-568, 13, NULL);
	LineTo   (hdc, Rect.right-568, Rect.bottom-13);
	MoveToEx (hdc, Rect.right-567, 12, NULL);
	LineTo   (hdc, Rect.right-567, Rect.bottom-12);
	MoveToEx (hdc, Rect.right-566, 11, NULL);
	LineTo   (hdc, Rect.right-566, Rect.bottom-11);

	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	//--
	hpen = CreatePen (PS_SOLID, 1, 0xE0D7D5);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, 15, 15, NULL);
	LineTo (hdc, Rect.right-570, 15);
	MoveToEx (hdc, 14, 14, NULL);
	LineTo (hdc, Rect.right-569, 14);
	MoveToEx (hdc, 13, 13, NULL);
	LineTo (hdc, Rect.right-568, 13);
	MoveToEx (hdc, 12, 12, NULL);
	LineTo (hdc, Rect.right-567, 12);
	MoveToEx (hdc, 11, 11, NULL);
	LineTo (hdc, Rect.right-566, 11);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	// //----
	hpen = CreatePen (PS_SOLID, 1, 0xF4EBE9);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, 15, Rect.bottom-15, NULL);
	LineTo (hdc, Rect.right-569, Rect.bottom-15);
	MoveToEx (hdc, 14, Rect.bottom-14, NULL);
	LineTo (hdc, Rect.right-568, Rect.bottom-14);
	MoveToEx (hdc, 13, Rect.bottom-13, NULL);
	LineTo (hdc, Rect.right-567, Rect.bottom-13);
	MoveToEx (hdc, 12, Rect.bottom-12, NULL);
	LineTo (hdc, Rect.right-566, Rect.bottom-12);
	MoveToEx (hdc, 11, Rect.bottom-11, NULL);
	LineTo (hdc, Rect.right-565, Rect.bottom-11);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	//--
	hpen = CreatePen (PS_SOLID, 1, 0xFEF5F3);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, Rect.right-15, 15, NULL);
	LineTo (hdc, Rect.right-15, 300-10);
	MoveToEx (hdc, Rect.right-14, 14, NULL);
	LineTo (hdc, Rect.right-14, 300-9);
	MoveToEx (hdc, Rect.right-13, 13, NULL);
	LineTo (hdc, Rect.right-13, 300-8);
	MoveToEx (hdc, Rect.right-12, 12, NULL);
	LineTo (hdc, Rect.right-12, 300-7);
	MoveToEx (hdc, Rect.right-11, 11, NULL);
	LineTo (hdc, Rect.right-11, 300-6);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	// //----
	hpen = CreatePen (PS_SOLID, 1, 0xD6CDCB);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, Rect.right-555, 10, NULL);
	LineTo (hdc, Rect.right-555, 300-5);
	MoveToEx (hdc, Rect.right-554, 11, NULL);
	LineTo (hdc, Rect.right-554, 300-6);
	MoveToEx (hdc, Rect.right-553, 12, NULL);
	LineTo (hdc, Rect.right-553, 300-7);
	MoveToEx (hdc, Rect.right-552, 13, NULL);
	LineTo (hdc, Rect.right-552, 300-8);
	MoveToEx (hdc, Rect.right-551, 14, NULL);
	LineTo (hdc, Rect.right-551, 300-9);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	// //----
	hpen = CreatePen (PS_SOLID, 1, 0xE0D7D5);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, Rect.right-551, 15, NULL);
	LineTo (hdc, Rect.right-15, 15);
	MoveToEx (hdc, Rect.right-552, 14, NULL);
	LineTo (hdc, Rect.right-14, 14);
	MoveToEx (hdc, Rect.right-553, 13, NULL);
	LineTo (hdc, Rect.right-13, 13);
	MoveToEx (hdc, Rect.right-554, 12, NULL);
	LineTo (hdc, Rect.right-12, 12);
	MoveToEx (hdc, Rect.right-555, 11, NULL);
	LineTo (hdc, Rect.right-11, 11);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	// //----
	hpen = CreatePen (PS_SOLID, 1, 0xF4EBE9);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, Rect.right-551, 300-10, NULL);
	LineTo (hdc, Rect.right-14, 300-10);
	MoveToEx (hdc, Rect.right-552, 300-9, NULL);
	LineTo (hdc, Rect.right-13, 300-9);
	MoveToEx (hdc, Rect.right-553, 300-8, NULL);
	LineTo (hdc, Rect.right-12, 300-8);
	MoveToEx (hdc, Rect.right-554, 300-7, NULL);
	LineTo (hdc, Rect.right-11, 300-7);
	MoveToEx (hdc, Rect.right-555, 300-6, NULL);
	LineTo (hdc, Rect.right-10, 300-6);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	//--
	hpen = CreatePen (PS_SOLID, 1, 0xFEF5F3);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, Rect.right-15, 300+10, NULL);
	LineTo (hdc, Rect.right-15, 527-15);
	MoveToEx (hdc, Rect.right-14, 300+9, NULL);
	LineTo (hdc, Rect.right-14, 527-14);
	MoveToEx (hdc, Rect.right-13, 300+8, NULL);
	LineTo (hdc, Rect.right-13, 527-13);
	MoveToEx (hdc, Rect.right-12, 300+7, NULL);
	LineTo (hdc, Rect.right-12, 527-12);
	MoveToEx (hdc, Rect.right-11, 300+6, NULL);
	LineTo (hdc, Rect.right-11, 527-11);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	// //----
	hpen = CreatePen (PS_SOLID, 1, 0xD6CDCB);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, Rect.right-270, 300+6, NULL);
	LineTo (hdc, Rect.right-270, 527-11);
	MoveToEx (hdc, Rect.right-269, 300+7, NULL);
	LineTo (hdc, Rect.right-269, 527-12);
	MoveToEx (hdc, Rect.right-268, 300+8, NULL);
	LineTo (hdc, Rect.right-268, 527-13);
	MoveToEx (hdc, Rect.right-267, 300+9, NULL);
	LineTo (hdc, Rect.right-267, 527-14);
	MoveToEx (hdc, Rect.right-266, 300+10, NULL);
	LineTo (hdc, Rect.right-266, 527-15);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	// //----
	hpen = CreatePen (PS_SOLID, 1, 0xE0D7D5);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, Rect.right-266, 300+10, NULL);
	LineTo (hdc, Rect.right-15, 300+10);
	MoveToEx (hdc, Rect.right-267, 300+9, NULL);
	LineTo (hdc, Rect.right-14, 300+9);
	MoveToEx (hdc, Rect.right-268, 300+8, NULL);
	LineTo (hdc, Rect.right-13, 300+8);
	MoveToEx (hdc, Rect.right-269, 300+7, NULL);
	LineTo (hdc, Rect.right-12, 300+7);
	MoveToEx (hdc, Rect.right-270, 300+6, NULL);
	LineTo (hdc, Rect.right-11, 300+6);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	// //----
	hpen = CreatePen (PS_SOLID, 1, 0xF4EBE9);
	hPen_old = SelectObject (hdc, hpen);
	MoveToEx (hdc, Rect.right-266, 527-15, NULL);
	LineTo (hdc, Rect.right-15, 527-15);
	MoveToEx (hdc, Rect.right-267, 527-14, NULL);
	LineTo (hdc, Rect.right-14, 527-14);
	MoveToEx (hdc, Rect.right-268, 527-13, NULL);
	LineTo (hdc, Rect.right-13, 527-13);
	MoveToEx (hdc, Rect.right-269, 527-12, NULL);
	LineTo (hdc, Rect.right-12, 527-12);
	MoveToEx (hdc, Rect.right-270, 527-11, NULL);
	LineTo (hdc, Rect.right-11, 527-11);
	SelectObject (hdc, hPen_old);
	DeleteObject (hpen);
	//--
	DeleteObject (brush_font);
	DeleteObject (brush_font1);
	DeleteObject (brush_font2);
	DeleteObject (brush_font3);
	DeleteObject (brush_font4);
	DeleteObject (brush_white);
}

void Calculate (HWNDhList, HWND hListCh, myData&vrtx, double * num_ch, 
	TCHAR * filename, boolmylocale)
{
	// probablyget
	int quan_elen = 0;
#ifdefUNICODE
	int len = 2000;
#else
	int len = 1000;
#endif

	// init
	double * buffer =  (double * )malloc (sizeof (double) * len);

	if (mylocale)
		setlocale (LC_NUMERIC, "Russian_Russia.1251");
	else
		setlocale (LC_NUMERIC, "C");

	FILE * file;
	{
		__int 16isUni;
		file = _tfopen (filename, _T ("rb"));
		fread (& (isUni), 1, 2, file);
		fclose (file);
		if (	isUni =  =  (__int 16)0xFFFE||isUni =  =  (__int 16)0xFEFF||isUni =  =  (__int 16)0xFEBB)
			file = _tfopen (filename, _T ("r, ccs = UNICODE"));
		else
			file = _tfopen (filename, _T ("r"));		
	}
	if (!file)
	{
		MessageBox (NULL, TEXT ("Please, checkinputfile."), TEXT ("Error"), MB_OK|MB_ICONWARNING);
		free (buffer);
		return;		
	}
	// {		
	// 	if ( * FileNameNEW)
	// 	{
	// 		filename = FileNameNEW;
	// 		// HANDLEH_IN_FILE = CreateFile (filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	// 		// longhandle = _open_osfhandle ( (LONG)H_IN_FILE, 0);
	// 		// file = _fdopen (handle, "r");
	// 		fopen_s (&file, filename, "r+");
	// 		if (!file)
	// 		{
	// 			MessageBox (NULL, "Please, checkCORRECTinputfile.", "Error", MB_OK|MB_ICONWARNING);
	// 			return;
	// 		}
	// 	}
	// 	else

	// else
	// 	fopen_s (&file, filename, "w+");

	while (_ftscanf (file, _T ("%lf"), & (buffer[quan_elen])) =  = 1)
	{
		if (!quan_elen)
		{vrtx.min_x = buffer[0];
		vrtx.max_x = buffer[0];
		}

		if (buffer[quan_elen]>vrtx.max_x)
			vrtx.max_x = buffer[quan_elen];
		if (buffer[quan_elen]<vrtx.min_x)
			vrtx.min_x = buffer[quan_elen];

		if (quan_elen+1 =  = len)
		{
			len *  = 3;
			// realloc (buffer, sizeof (double) * len);
			//-----------------------------------------------------------------------------------------
			double * newbuffer =  (double * )malloc (sizeof (double) * len);
			memcpy (newbuffer, buffer, len/3);
			free (buffer);
			buffer = newbuffer;
			//-----------------------------------------------------------------------------------------
			// MSDNпредлагаетнамследующийкод:
			// double * oldbuffer = buffer;// savepoint erincasereallocfails
			// if ( (buffer =  (double * )realloc (buffer, sizeof (double) * len)) =  = NULL)
			// {
			// free (oldbuffer);// freeoriginalblock
			// exit (1);
			// }
			//-----------------------------------------------------------------------------------------
		}
		quan_elen++;
	}
	fclose (file);

	if (!quan_elen)
	{free (buffer);return;}

	doubleh;
	if (quan_elen =  = 1)h = 0;
	elseh =  (vrtx.max_x-vrtx.min_x)/ (sqrt ( (double)quan_elen)-1);

	if (!h)
		vrtx.lengh = 1;
	else
		vrtx.lengh =  (int ) (sqrt ( (double)quan_elen));

	vrtx.n =  (int  * )malloc (sizeof (int ) * vrtx.lengh);
	vrtx.x =  (double * )malloc (sizeof (double) * vrtx.lengh);
	vrtx.EV =  (double * )malloc (sizeof (double) * vrtx.lengh);
	vrtx.a =  (double * )malloc (sizeof (double) *  (vrtx.lengh+1));
	double * V =  (double * )malloc (sizeof (double) * vrtx.lengh);

	int i = 0;
	vrtx.a[0] = vrtx.min_x-h/2;
	for (i = 0; (i<vrtx.lengh)&& (vrtx.max_x> = vrtx.a[i]);i++)
		vrtx.a[i+1] = vrtx.a[i]+h;

	vrtx.x[0] =  (vrtx.a[0]+vrtx.a[1])/2;
	for (i = 0;i<vrtx.lengh-1;i++)
		vrtx.x[i+1] = vrtx.x[i]+h;

	for (i = 0;i<vrtx.lengh;i++)
	{
		vrtx.n[i] = 0;
		for (int j = 0;j<quan_elen;j++)
			if (vrtx.a[i]< = buffer[j]&&buffer[j]< = vrtx.a[i+1])
				vrtx.n[i]++;
		V[i] =  (double)vrtx.n[i]/quan_elen;
	}

	doubleM_X = 0, M_X2 = 0, M_X3 = 0, M_X4 = 0;
	for (i = 0;i<vrtx.lengh;i++)
	{
		M_X+ = vrtx.x[i] * vrtx.n[i];
		M_X2+ = sqr (vrtx.x[i]) * vrtx.n[i];
		M_X3+ = pow (vrtx.x[i], 3) * vrtx.n[i];
		M_X4+ = pow (vrtx.x[i], 4) * vrtx.n[i];
	}
	M_X/ = quan_elen;
	M_X2/ = quan_elen;
	M_X3/ = quan_elen;
	M_X4/ = quan_elen;

	double	S2 = 	M_X2-sqr (M_X);
	double	S = sqrt (S2);
	doubleVar =  (S/M_X) * 100;// %
	if (!M_X)Var = 0;

	doubleMe;
	if (vrtx.lengh%2)Me = vrtx.x[ (vrtx.lengh)/2];
	elseMe =  (vrtx.x[ (vrtx.lengh/2)+1]+vrtx.x[vrtx.lengh/2])/2;

	// мода---------------------------------------------------------------------------------------
	int  * index =  (int  * )calloc (vrtx.lengh, sizeof (int ));
	int mode_lengh = 0;

	vrtx.max_n = vrtx.n[0];
	vrtx.min_n = vrtx.n[0];
	for (int j = 0;j<vrtx.lengh;j++)
	{
		if (vrtx.max_n<vrtx.n[j])vrtx.max_n = vrtx.n[j];
		if (vrtx.min_n>vrtx.n[j])vrtx.min_n = vrtx.n[j];
	}

	for (int j = 0;j<vrtx.lengh;j++)
		if (vrtx.max_n =  = vrtx.n[j])
		{index[mode_lengh++] = j;}

		double * M0 =  (double * )malloc (sizeof (double) * mode_lengh);
		for (int j = mode_lengh;j--;)
			M0[j] = vrtx.x[index[j]];
		//---------------------------------------------------------------------------------------------

		doubleS3 = S2 * S;
		doubleS4 = sqr (S2);

		doubleMu3 = M_X3-3 * M_X2 * M_X+2 * pow (M_X, 3);
		doubleMu4 = M_X4+6 * sqr (M_X) * M_X2-3 * pow (M_X, 4)-4 * M_X3 * M_X;

		doubleAs;
		doubleEk;
		if (S2)
		{As = Mu3/S3;
		Ek = Mu4/S4-3;
		}
		else
		{As = 0;
		Ek = 0;
		}
		//---------------------------------------------------------------------------------------------
		SendMessage (hList, LVM_DELETEALLITEMS, 0, 0);

		file = _tfopen (_T ("out.txt"), _T ("wt, ccs = UNICODE"));
		_ftprint f (file, _T ("\nNo[aj, ai)xiniƲΣƲ\n"));

		TCHARstring_to_list[100];
		doubleEV = 0;
		for (i = 0;i<vrtx.lengh;i++)
		{

			EV+ = V[i];
			vrtx.EV[i] = EV;
			_ftprint f (file, _T ("%3d[%.6lf, %.6lf)%.6lf%6d%.6lf%.6lf\n"), i+1, vrtx.a[i], \
				vrtx.a[i+1], vrtx.x[i], vrtx.n[i], V[i], EV);

			int k = 0;
			_stprint f (string_to_list, _T ("%d"), i+1);
			InsertListViewItem (hList, i, k, k, string_to_list);
			k++;

			_stprint f (string_to_list, _T ("[%lf, %lf)"), vrtx.a[i], vrtx.a[i+1]);
			InsertListViewItem (hList, i, k, k, string_to_list);
			k++;

			_stprint f (string_to_list, _T ("%lf"), vrtx.x[i]);
			InsertListViewItem (hList, i, k, k, string_to_list);
			k++;

			_stprint f (string_to_list, _T ("%d"), vrtx.n[i]);
			InsertListViewItem (hList, i, k, k, string_to_list);
			k++;

			_stprint f (string_to_list, _T ("%lf"), V[i]);
			InsertListViewItem (hList, i, k, k, string_to_list);
			k++;

			_stprint f (string_to_list, _T ("%lf"), EV);
			InsertListViewItem (hList, i, k, k, string_to_list);
		}
		_ftprint f (file, _T ("%4d1.000000\n"), quan_elen);

		_stprint f (string_to_list, _T ("%d"), quan_elen);
		InsertListViewItem (hList, vrtx.lengh, 0, 0, NULL);
		InsertListViewItem (hList, vrtx.lengh, 3, 1, string_to_list);
		InsertListViewItem (hList, vrtx.lengh, 4, 1, _T ("1.000000"));

		num_ch[0] = M_X;
		num_ch[1] = S2;
		num_ch[2] = S;
		num_ch[3] = Var;
		num_ch[4] = Me;
		num_ch[5] = As;
		num_ch[6] = Ek;
		_ftprint f (file, _T ("\nⴳ = %.6lf\n\
																				ⴳ² = %.6lf\n\
																				S² = %.6lf\n\
																				S = %.6lf\n\
																				Var = %.6lf%%\n\
																				Me = %.6lf\n\
																				As = %.6lf\n\
																				Ek = %.6lf\n")
																				, M_X, M_X2, S2, S, Var, Me, As, Ek);

		_ftprint f (file, _T ("Mo = "));
		for (int i = mode_lengh;i--;)
		{
			_ftprint f (file, _T ("%.6lf, "), M0[i]);
		}
		//--------------------------------------------------------------------------------------------
		TCHARsymbols[8][10] = {_T ("ⴳ"), 
			_T ("S²"), 
			_T ("S"), 
			_T ("Var"), 
			_T ("Me"), 
			_T ("As"), 
			_T ("Ek"), 
			_T ("Mo")};
		TCHARstr[8][23];
		for (int j = 0;j<8;j++)
			_stprint f (str[j], _T ("%6.6lf"), num_ch[j]);
		//--
		SendMessage (hListCh, LVM_DELETEALLITEMS, 0, 0);
		//--
		TCHARctr[20];
		for (i = 0;i<8;i++)
		{
			_stprint f (ctr, _T ("%d"), i+1);
			/* _tcscat (str[i], "");
			if (i =  = 3)
			_tcscat (str[i], "%"); */
			InsertListViewItem (hListCh, i, 0, 0, ctr);
			InsertListViewItem (hListCh, i, 1, 1, symbols[i]);
			if (i<7)InsertListViewItem (hListCh, i, 2, 2, str[i]);
		}
		for (i = 0;i<mode_lengh;i++)
		{
			_stprint f (ctr, _T ("%lf"), M0[i]);		
			if (i)InsertListViewItem (hListCh, 7+i, 0, 0, _T (""));
			InsertListViewItem (hListCh, 7+i, 2, 2, ctr);
		}
		//--------------------------------------------------------------------------------------------
		fclose (file);
		free (buffer);
		free (M0);
		free (V);
		free (index);
}
// void DrawCoord (HDChdc, myData * vrtx, boolcPFlag)
// {
// 	if (!vrtx->lengh)
// 		return;
// 	//--
// 	#defineMinNvrtx->min_n
// 	#defineMaxNvrtx->max_n
// 	#defineMinXvrtx->min_x
// 	#defineMaxXvrtx->max_x
// 	//--	
// 	// int qty = vrtx->lengh;
// 	int x0 = Rect1.left+100;
// 	int y0 = Rect1.bottom-50;
// 	int G_Width = Rect1.right-Rect1.left-200;
// 	int G_Height = Rect1.bottom-Rect1.top-75;
// 	{
// 		HGDIOBJhpen, hPen_old;
// 		hpen = CreatePen (PS_SOLID, 1+ (cPFlag * 5), 0x000000);
// 		hPen_old = SelectObject (hdc, hpen);
// 		//--	
// 		MoveToEx (hdc, (Rect1.left+12- (cPFlag * 200)), ( (Rect1.bottom-20)), NULL);
// 		LineTo (hdc, (Rect1.right-13), ( (Rect1.bottom-20)));						
// 				LineTo (hdc, (Rect1.right-13-9- (cPFlag * 50)), ( (Rect1.bottom-20)-3- (cPFlag * 25)));						
// 				LineTo (hdc, (Rect1.right-13-5- (cPFlag * 50)), ( (Rect1.bottom-20)));						
// 				LineTo (hdc, (Rect1.right-13-9- (cPFlag * 50)), ( (Rect1.bottom-20)+3+ (cPFlag * 25)));						
// 				LineTo (hdc, (Rect1.right-13), ( (Rect1.bottom-20)));						
// 		//--
// 		MoveToEx (hdc, (Rect1.left+20), (Rect1.bottom-13), NULL);
// 		LineTo (hdc, (Rect1.left+20), (Rect1.top+10));
// 				LineTo (hdc, (Rect1.left+23), (Rect1.top+19));
// 				LineTo (hdc, (Rect1.left+20), (Rect1.top+13));
// 				LineTo (hdc, (Rect1.left+17), (Rect1.top+19));
// 				LineTo (hdc, (Rect1.left+20), (Rect1.top+10));
// 		//--																											
// 		for (int n = 0;n<3;n++)
// 		{			
// 		MoveToEx (hdc, (x0+G_Width/2 * n), (Rect1.bottom-15- (cPFlag * 30)), NULL);
// 		LineTo (hdc, (x0+G_Width/2 * n), (Rect1.bottom-25+ (cPFlag * 30)));			
// 		}
// 		//--
// 		TCHARstr_X[3][10], str_N[3][10];
// 		//--
// 		_stprint f (str_X[0], _T ("%3.3lf"), MinX);
// 		_stprint f (str_X[1], _T ("%3.3lf"), (MaxX+MinX)/2);
// 		_stprint f (str_X[2], _T ("%3.3lf"), MaxX);
// 		_itot (MinN, str_N[0], 10);
// 		_itot ( (MaxN+MinN)/2, str_N[1], 10);
// 		_itot (MaxN, str_N[2], 10);
// 		//--
// 		TextOut (hdc, Rect1.right-19, Rect1.bottom-45- (cPFlag * 100), _T ("x"), 1);
// 		TextOut (hdc, Rect1.left+30+ (cPFlag * 60), Rect1.top+2, _T ("n"), 1);
// 		for (int n = 0;n<3;n++)
// 		{
// 			TextOut (hdc, (x0+G_Width/2 * n)-3-6 *  ( (lstrlen (str_X[n])-2)), (Rect1.bottom-25)-17- (cPFlag * 100), str_X[n], lstrlen (str_X[n]));
// 		}
// 		for (int n = 0;n<3;n++)
// 		{
// 			TextOut (hdc, (Rect1.left+31+ (cPFlag * 50)), (y0-G_Height/4 * n * 2)-9- (cPFlag * 150), str_N[n], lstrlen (str_N[n]));
// 		}
// 		//--
// 		for (int n = 0;n<5;n++)
// 		{
// 			MoveToEx (hdc, (Rect1.left+20+5), (y0-G_Height/4 * n), NULL);
// 	LineTo (hdc, (Rect1.left+20-5), (y0-G_Height/4 * n));
// 		}
// 		SelectObject (hdc, hPen_old);
// 		DeleteObject (hpen);
// 	}
// 	//--
// 	#undefMinN
// 	#undefMaxN
// 	#undefMinX
// 	#undefMaxX
// 	//--
// }
// void DrawCoord_t (HDChdc, myData * vrtx)
// {
// 	if (!vrtx->lengh)
// 		return;
// 	//--
// 	#defineMinNvrtx->min_n
// 	#defineMaxNvrtx->max_n
// 	#defineMinXvrtx->min_x
// 	#defineMaxXvrtx->max_x
// 	//--	
// 	// int qty = vrtx->lengh;
// 	int x0 = Rect1.left+100;
// 	int y0 = Rect1.bottom-50;
// 	int G_Width = Rect1.right-Rect1.left-200;
// 	int G_Height = Rect1.bottom-Rect1.top-75;
// 	{
// 		HGDIOBJhpen, hPen_old;
// 		hpen = CreatePen (PS_SOLID, 1, 0x000000);
// 		hPen_old = SelectObject (hdc, hpen);
// 		//--	
// 		MoveToEx (hdc, (Rect1.left+12), (Rect1.bottom-20), NULL);
// 		LineTo (hdc, (Rect1.right-13), (Rect1.bottom-20));
// 				LineTo (hdc, (Rect1.right-22), (Rect1.bottom-17));
// 				LineTo (hdc, (Rect1.right-18), (Rect1.bottom-20));
// 				LineTo (hdc, (Rect1.right-22), (Rect1.bottom-23));
// 				LineTo (hdc, (Rect1.right-13), (Rect1.bottom-20));
// 		//--
// 		MoveToEx (hdc, (Rect1.left+20), (Rect1.bottom-13), NULL);
// 		LineTo (hdc, (Rect1.left+20), (Rect1.top+10));
// 				LineTo (hdc, (Rect1.left+23), (Rect1.top+19));
// 				LineTo (hdc, (Rect1.left+20), (Rect1.top+13));
// 				LineTo (hdc, (Rect1.left+17), (Rect1.top+19));
// 				LineTo (hdc, (Rect1.left+20), (Rect1.top+10));
// 		//--																											
// 		for (int n = 0;n<3;n++)
// 		{			
// 		MoveToEx (hdc, (x0+G_Width/2 * n), (Rect1.bottom-15), NULL);
// 		LineTo (hdc, (x0+G_Width/2 * n), (Rect1.bottom-25));			
// 		}
// 		//--
// 		TCHARstr_X[3][10];
// 		//--
// 		_stprint f (str_X[0], _T ("%3.3lf"), MinX);
// 		_stprint f (str_X[1], _T ("%3.3lf"), (MaxX+MinX)/2);
// 		_stprint f (str_X[2], _T ("%3.3lf"), MaxX);
// 		//--
// 		TextOut (hdc, Rect1.right-19, Rect1.bottom-45, _T ("x"), 1);
// 		TextOut (hdc, Rect1.left+30, Rect1.top+2, _T ("F (x)"), 4);
// 		TextOut (hdc, Rect1.left+30, Rect1.top+22, _T ("1.00"), 4);
// 		for (int n = 0;n<3;n++)
// 		{
// 			TextOut (hdc, (x0+G_Width/2 * n)-3-6 *  ( (lstrlen (str_X[n])-2)), (Rect1.bottom-20-5)-17, str_X[n], lstrlen (str_X[n]));
// 		}
// 		//--
// 		for (int n = 1;n<6;n++)
// 		{
// 			MoveToEx (hdc, (Rect1.left+25), (Rect1.bottom- (Rect1.bottom- (Rect1.top+24))/5 * n), NULL);
// 	LineTo (hdc, (Rect1.left+15), (Rect1.bottom- (Rect1.bottom- (Rect1.top+24))/5 * n));
// 		}
// 		SelectObject (hdc, hPen_old);		
// 		DeleteObject (hpen);
// 		//--
// 		hpen = CreatePen (PS_SOLID, 1, 0x0000FF);
// 		hPen_old = SelectObject (hdc, hpen);
// 		//--
// 		MoveToEx (hdc, Rect1.left+12, Rect1.bottom-20, NULL);
// 			LineTo (hdc, Rect1.left+87, Rect1.bottom-20);
// 		//--
// 		SelectObject (hdc, hPen_old);
// 		DeleteObject (hpen);
// 	}
// 	//--
// 	#undefMinN
// 	#undefMaxN
// 	#undefMinX
// 	#undefMaxX
// 	//--
// }
void DrawGraphic (HDChdc, myData * vrtx, DWORD lpColorG, DWORD lpColorP, DWORD lpColorD, boolhChk)
{
	if (vrtx->lengh<2)
		return;
	//--
	boolDrawP = true;
	boolDrawG = true;
	boolDrawC = true;
	boolDrawD = true;
	if (lpColorD =  = 0xFFFFFF)
	{
		DrawD = false;
	}
	if (lpColorG =  = 0xFFFFFF)
	{
		DrawG = false;
	}
	if (lpColorP =  = 0xFFFFFF)
	{
		DrawP = false;
	}
	if ( (!DrawP)&& (!DrawG)&& (!DrawD))
	{
		DrawC = false;
	}
	//--
#defineMinNvrtx->min_n
#defineMaxNvrtx->max_n
#defineMinXvrtx->min_x
#defineMaxXvrtx->max_x
	//--	
	int qty = vrtx->lengh;
	doubledN = MaxN-MinN;	
	doubledX = MaxX-MinX;
	int x0 =  (int ) (Rect1.left+ (double) (Rect1.right-Rect1.left) * 0.24);
	int y0 =  (int ) (Rect1.bottom- (double) (Rect1.bottom-Rect1.top) * 0.10);
	int G_Width =  (int ) ( (double) (Rect1.right-Rect1.left) * 0.55);
	int G_Height =  (int ) ( (double) (Rect1.bottom-Rect1.top) * 0.85);
	doublemX = G_Width/dX;
	doublemN = G_Height/dN;
	int h =  (G_Width)/20;
	int v =  (G_Height)/20;
	//--
	HGDIOBJhpen, hPen_old;
	if (DrawP)
	{
		int cSteps =  (int ) (1+sqrt ( (float) (G_Width * G_Height))/100);
		//--		
		hpen = CreatePen (PS_SOLID, 1, lpColorP);
		hPen_old = SelectObject (hdc, hpen);
		//--
		RECTRect_tmp;
		//--
		for (int n = 0;n<qty;n++)
		{
			int x1 = Rect_tmp.left =  (LONG) ( (vrtx->a[n]-MinX) * mX+x0);
			int x2 = x1;
			Rect_tmp.right =  (LONG) ( (vrtx->a[n+1]-MinX) * mX+x0);
			int y1 = Rect_tmp.top =  (LONG) (y0- (vrtx->n[n]-MinN) * mN);
			int y2 = y1;
			Rect_tmp.bottom = y0;		
			boolbx = false, by = false;
			for (;/*  ( (x1< = x2)|| (y1< = y2)) */;)
			{				
				MoveToEx (hdc, x1, y1, NULL);
				LineTo (hdc, x2, y2);
				if (y1> = Rect_tmp.bottom)
				{
					if (y1 =  = Rect_tmp.bottom)
					{
						by = true;
					}
					if (y1>Rect_tmp.bottom)
					{
						x1+ = y1-Rect_tmp.bottom;
					}
					else
						if (by)
							x1+ = cSteps;
					if (x2< = Rect_tmp.right)
						x2+ = cSteps;								
					y1 = Rect_tmp.bottom;
				}
				else
				{
					x2+ = cSteps;
				}
				if (x2> = Rect_tmp.right)
				{
					if (x2>Rect_tmp.right)
					{
						bx = true;
					}
					if (x2>Rect_tmp.right)
					{
						y2+ = x2-Rect_tmp.right;
					}
					else
						if (bx)
							y2+ = cSteps;						
					if (y1<Rect_tmp.bottom)
						y1+ = cSteps;
					x2 = Rect_tmp.right;
				}
				else
				{
					y1+ = cSteps;
				}
				if (y1>Rect_tmp.bottom)
				{
					if (!by)
						x1+ = y1-Rect_tmp.bottom;
					y1 = Rect_tmp.bottom;
				}		
				if (x2>Rect_tmp.right)
				{
					y2+ = x2-Rect_tmp.right;
					x2 = Rect_tmp.right;
				}
				if (y2>Rect_tmp.bottom)
					y2 = Rect_tmp.bottom;
				if (x1>Rect_tmp.right)
					x1 = Rect_tmp.right;
				if ( (x1 =  = x2)&& (y1 =  = y2))
					break;
			}
			//--
			DrawRect (hdc, Rect_tmp, 1, lpColorP, PS_SOLID);
			//--
		}
		SelectObject (hdc, hPen_old);
		DeleteObject (hpen);
	}
	//--
	if (DrawG)
	{		
		//--
		int r =  (int ) (1+pow ( (double) (G_Width * G_Height), 0.25)/4);
		int x1 =  (int ) ( (vrtx->x[0]-MinX) * mX+x0);
		int y1 =  (int ) (y0- (vrtx->n[0]-MinN) * mN);
		FillCircle (hdc, x1, y1, r, lpColorG);
		//--		
		MoveToEx (hdc, x1, y1, NULL);
		for (int n = 1;n<qty;n++)
		{
			x1 =  (int ) ( (vrtx->x[n]-MinX) * mX+x0);
			y1 =  (int ) (y0- (vrtx->n[n]-MinN) * mN);
			int pen_cWight =  (int ) (1+pow ( (double) (G_Width * G_Height), 0.5)/400);
			hpen = CreatePen (PS_SOLID, pen_cWight, lpColorG);
			hPen_old = SelectObject (hdc, hpen);
			LineTo (hdc, x1, y1);
			FillCircle (hdc, x1, y1, r, lpColorG);
			SelectObject (hdc, hPen_old);
			DeleteObject (hpen);				
		}
		//--		
	}
	if (DrawD)
	{
		//--
		HGDIOBJhpen, hPen_old;
		hpen = CreatePen (PS_SOLID, (int ) (1+pow ( (double) (G_Width * G_Height), 0.5)/400), lpColorD);
		hPen_old = SelectObject (hdc, hpen);
		//--
		RECTRect_tmp;
		//--
		for (int n = 0;n<qty;n++)
		{
			Rect_tmp.left =  (LONG) ( (vrtx->a[n]-MinX) * mX+x0);
			Rect_tmp.right =  (LONG) ( (vrtx->a[n+1]-MinX) * mX+x0);
			Rect_tmp.bottom =  (LONG) (Rect1.bottom-v);
			Rect_tmp.top =  (LONG) (Rect_tmp.bottom-vrtx->EV[n] * G_Height * 1.067);
			//--			
			DrawRect (hdc, Rect_tmp, 1, 0x000000, PS_DOT);		
			//--
			MoveToEx (hdc, Rect_tmp.right, Rect_tmp.top, NULL);
			LineTo (hdc, Rect_tmp.left, Rect_tmp.top);
			//--
			for (int k = 1;k< (G_Width)/75;k++)
			{				
				MoveToEx (hdc, Rect_tmp.left, Rect_tmp.top, NULL);
				LineTo (hdc, Rect_tmp.left+ (int ) (h/1.3), Rect_tmp.top+k);
				MoveToEx (hdc, Rect_tmp.left, Rect_tmp.top, NULL);
				LineTo (hdc, Rect_tmp.left+ (int ) (h/1.3), Rect_tmp.top-k);
			}
			//--
			if (n =  =  (qty-1))
			{
				MoveToEx (hdc, Rect_tmp.right, Rect_tmp.top, NULL);
				LineTo (hdc, Rect1.right-2 * h, Rect_tmp.top);
			}
			//--
		}
		//--
		SelectObject (hdc, hPen_old);
		DeleteObject (hpen);
	}
	//--
	if (DrawC)
	{
		HGDIOBJhpen, hPen_old;
		hpen = CreatePen (PS_SOLID, (int ) (1+log10 ( (float) (G_Width * G_Height))/6), 0x000000);
		hPen_old = SelectObject (hdc, hpen);
		//--
		/* horisontalline (X) */
		MoveToEx (hdc, (Rect1.left+h), (Rect1.bottom-v), NULL);
		LineTo (hdc, (Rect1.right-h), (Rect1.bottom-v));						
		LineTo (hdc, (Rect1.right-h-h/2), (Rect1.bottom-v-v/10));						
		LineTo (hdc, (Rect1.right-h-h/4), (Rect1.bottom-v));						
		LineTo (hdc, (Rect1.right-h-h/2), (Rect1.bottom-v+v/10));						
		LineTo (hdc, (Rect1.right-h), (Rect1.bottom-v));					
		//--
		/* verticalline (N) */
		MoveToEx (hdc, (Rect1.left+h * 2), (Rect1.bottom-v/2), NULL);
		LineTo (hdc, (Rect1.left+h * 2), (Rect1.top+v/2));
		LineTo (hdc, (Rect1.left+h * 2+h/5), (Rect1.top+v/2+h/2));
		LineTo (hdc, (Rect1.left+h * 2), (Rect1.top+v/2+h/4));
		LineTo (hdc, (Rect1.left+h * 2-h/5), (Rect1.top+v/2+h/2));
		LineTo (hdc, (Rect1.left+h * 2), (Rect1.top+v/2));
		//--
		/* horisontalorient_line (X) */
		for (int n = 0;n<3;n++)
		{			
			MoveToEx (hdc, (x0+G_Width/2 * n), (Rect1.bottom-v+ (int )sqrt ( (float) (v * h))/3), NULL);
			LineTo (hdc, (x0+G_Width/2 * n), (Rect1.bottom-v- (int )sqrt ( (float) (v * h))/3));			
		}
		//--
		TCHARstr_X[3][10], str_N[3][10];
		//--
		_stprint f (str_X[0], _T ("%3.3lf"), (MinX));
		_stprint f (str_X[1], _T ("%3.3lf"), (MaxX+MinX)/2);
		_stprint f (str_X[2], _T ("%3.3lf"), (MaxX));
		if (!DrawD)
		{
			_itot (MinN, str_N[0], 10);
			_itot ( (MaxN+MinN)/2, str_N[1], 10);
			_itot (MaxN, str_N[2], 10);
		}
		//--
		TextOut (hdc, Rect1.right-h * 2, Rect1.bottom-v * 2, _T ("x"), 1);
		//--
		TextOut (hdc, Rect1.left+h * 3, Rect1.top+v/3, ( (DrawD)? (_T ("F (x)")): (_T ("n"))), ( (DrawD)? (4): (1)));			
		//--
		for (int n = 0; (n<3&&hChk);n++)
		{
			TextOut (hdc, (x0+G_Width/2 * n), (Rect1.bottom-v * 2), str_X[n], lstrlen (str_X[n]));
		}
		if (!DrawD)
		{
			for (int n = 0; (n<3&&hChk);n++)
			{
				TextOut (hdc, (Rect1.left+h * 3), (y0-G_Height/4 * n * 2), str_N[n], lstrlen (str_N[n]));
			}
		}
		else
		{
			if (hChk)
				TextOut (hdc, (Rect1.left+h * 3), (y0-G_Height), _T ("1.000"), 5);
		}
		//--
		/* verticalorient_line (N) */
		int q =  ( (DrawD)? (11): (5));
		int y =  ( (DrawD)? (Rect1.bottom-v): (y0));
		for (int n = 0;n<q;n++)
		{
			MoveToEx (hdc, (Rect1.left+h * 2- (int )sqrt ( (float) (v * h))/3), (int ) (y- (G_Height+ (G_Height * 0.067 * DrawD))/ (q-1) *  (n)), NULL);
			LineTo (hdc, (Rect1.left+h * 2+ (int )sqrt ( (float) (v * h))/3), (int ) (y- (G_Height+ (G_Height * 0.067 * DrawD))/ (q-1) *  (n)));
		}
		if (DrawD)
		{
			HGDIOBJhpen, hPen_old;
			hpen = CreatePen (PS_SOLID, (int ) (1+pow ( (double) (G_Width * G_Height), 0.5)/400), lpColorD);
			hPen_old = SelectObject (hdc, hpen);
			//--
			MoveToEx (hdc, (Rect1.left+h), (Rect1.bottom-v), NULL);
			LineTo (hdc, (LONG) ( (vrtx->a[0]-MinX) * mX+x0), (Rect1.bottom-v));
			//--
			SelectObject (hdc, hPen_old);
			DeleteObject (hpen);
		}
		SelectObject (hdc, hPen_old);
		DeleteObject (hpen);
	}
	//--
#undefMinN
#undefMaxN
#undefMinX
#undefMaxX
	//--
}
// void DrawPoligon (HDChdc, myData * vrtx, DWORD lpColor, DWORD cSteps)
// {
// 	if (!vrtx->lengh)
// 		return;
// 	//--
// 	#defineMinNvrtx->min_n
// 	#defineMaxNvrtx->max_n
// 	#defineMinXvrtx->min_x
// 	#defineMaxXvrtx->max_x
// 	//--
// 	int qty = vrtx->lengh;
// 	doubledN = MaxN-MinN;	
// 	doubledX = MaxX-MinX;
// 	int x0 = Rect1.left+100;
// 	int y0 = Rect1.bottom-50;
// 	int G_Width = Rect1.right-Rect1.left-200;
// 	int G_Height = Rect1.bottom-Rect1.top-75;
// 	doublemX = G_Width/dX;
// 	doublemN = G_Height/dN;
// 	//--
// 	{
// 		//--
// 		HGDIOBJhpen, hPen_old;
// 		hpen = CreatePen (PS_SOLID, ( (cSteps<5)? (1): (cSteps/15)), lpColor);
// 		hPen_old = SelectObject (hdc, hpen);
// 		//--
// 		RECTRect_tmp;
// 		//--
// 		//--
// 		for (int n = 0;n<qty;n++)
// 		{
// 			int x1 = Rect_tmp.left =  (LONG) ( (vrtx->a[n]-MinX) * mX+x0);
// 			int x2 = x1;
// 			Rect_tmp.right =  (LONG) ( (vrtx->a[n+1]-MinX) * mX+x0);
// 			int y1 = Rect_tmp.top =  (LONG) (y0- (vrtx->n[n]-MinN) * mN);
// 			int y2 = y1;
// 			Rect_tmp.bottom = y0;		
// 			boolbx = false, by = false;
// 			for (;/*  ( (x1< = x2)|| (y1< = y2)) */;)
// 			{				
// 				MoveToEx (hdc, x1, y1, NULL);
// 						LineTo (hdc, x2, y2);
// 				if (y1> = Rect_tmp.bottom)
// 				{
// 					if (y1 =  = Rect_tmp.bottom)
// 					{
// 						by = true;
// 					}
// 					if (y1>Rect_tmp.bottom)
// 					{
// 						x1+ = y1-Rect_tmp.bottom;
// 					}
// 					else
// 						if (by)
// 							x1+ = cSteps;
// 					if (x2< = Rect_tmp.right)
// 						x2+ = cSteps;								
// 					y1 = Rect_tmp.bottom;
// 				}
// 				else
// 				{
// 					x2+ = cSteps;
// 				}
// 				if (x2> = Rect_tmp.right)
// 				{
// 					if (x2>Rect_tmp.right)
// 					{
// 						bx = true;
// 					}
// 					if (x2>Rect_tmp.right)
// 					{
// 						y2+ = x2-Rect_tmp.right;
// 					}
// 					else
// 						if (bx)
// 							y2+ = cSteps;						
// 					if (y1<Rect_tmp.bottom)
// 						y1+ = cSteps;
// 					x2 = Rect_tmp.right;
// 				}
// 				else
// 				{
// 					y1+ = cSteps;
// 				}
// 				if (y1>Rect_tmp.bottom)
// 				{
// 					if (!by)
// 						x1+ = y1-Rect_tmp.bottom;
// 					y1 = Rect_tmp.bottom;
// 				}		
// 				if (x2>Rect_tmp.right)
// 				{
// 					y2+ = x2-Rect_tmp.right;
// 					x2 = Rect_tmp.right;
// 				}
// 				if (y2>Rect_tmp.bottom)
// 					y2 = Rect_tmp.bottom;
// 				if (x1>Rect_tmp.right)
// 					x1 = Rect_tmp.right;
// 				if ( (x1 =  = x2)&& (y1 =  = y2))
// 					break;
// 			}
// 			//--
// 			DrawRect (hdc, Rect_tmp, 0x00FF00, PS_SOLID);
// 			//--
// 		}		
// 		SelectObject (hdc, hPen_old);
// 	DeleteObject (hpen);
// 	}
// 	//--
// 	#undefMinN
// 	#undefMaxN
// 	#undefMinX
// 	#undefMaxX
// 	//--
// }
// void DrawDistPro (HDChdc, myData * vrtx)
// {
// 	if (!vrtx->lengh)
// 		return;
// 	//--
// 	#defineMinNvrtx->min_n
// 	#defineMaxNvrtx->max_n
// 	#defineMinXvrtx->min_x
// 	#defineMaxXvrtx->max_x
// 	//--
// 	int qty = vrtx->lengh;
// 	doubledN = 1;	
// 	doubledX = MaxX-MinX;
// 	int x0 = Rect1.left+100;
// 	int y0 = Rect1.bottom-20;
// 	int G_Width = Rect1.right-Rect1.left-200;
// 	int G_Height = Rect1.bottom-Rect1.top-75;
// 	doublemX = G_Width/dX;
// 	doublemN =  (G_Height+25)/dN;
// 	//--
// 	{
// 		//--
// 		HGDIOBJhpen, hPen_old;
// 		hpen = CreatePen (PS_SOLID, 1, 0x0000FF);
// 		hPen_old = SelectObject (hdc, hpen);
// 		//--
// 		RECTRect_tmp;
// 		//--
// 		unsignedint step = 5;
// 		//--		
// 		for (int n = 0;n<qty;n++)
// 		{
// 			Rect_tmp.left =  (LONG) ( (vrtx->a[n]-MinX) * mX+x0);
// 			Rect_tmp.right =  (LONG) ( (vrtx->a[n+1]-MinX) * mX+x0);
// 			Rect_tmp.bottom = y0;
// 			Rect_tmp.top = Rect_tmp.bottom-vrtx->EV[n] * mN;
// 			//--			
// 			DrawRect (hdc, Rect_tmp, 0x000000, PS_DOT);
// 			MoveToEx (hdc, Rect_tmp.right, Rect_tmp.top, NULL);
// 			LineTo (hdc, Rect_tmp.left, Rect_tmp.top);
// 			MoveToEx (hdc, Rect_tmp.left, Rect_tmp.top, NULL);
// 			LineTo (hdc, Rect_tmp.left+7, Rect_tmp.top+3);		
// 			MoveToEx (hdc, Rect_tmp.left, Rect_tmp.top, NULL);
// 			LineTo (hdc, Rect_tmp.left+7, Rect_tmp.top+2);	
// 			MoveToEx (hdc, Rect_tmp.left, Rect_tmp.top, NULL);
// 			LineTo (hdc, Rect_tmp.left+7, Rect_tmp.top+1);
// 			MoveToEx (hdc, Rect_tmp.left, Rect_tmp.top, NULL);
// 			LineTo (hdc, Rect_tmp.left+7, Rect_tmp.top-1);
// 			MoveToEx (hdc, Rect_tmp.left, Rect_tmp.top, NULL);
// 			LineTo (hdc, Rect_tmp.left+7, Rect_tmp.top-2);		
// 			MoveToEx (hdc, Rect_tmp.left, Rect_tmp.top, NULL);
// 			LineTo (hdc, Rect_tmp.left+7, Rect_tmp.top-3);	
// 			//--
// 			if (n =  =  (qty-1))
// 			{
// 				MoveToEx (hdc, Rect_tmp.right, Rect_tmp.top, NULL);
// 				LineTo (hdc, Rect1.right-15, Rect_tmp.top);
// 			}
// 			//--
// 		}		
// 		//--
// 		SelectObject (hdc, hPen_old);
// 	DeleteObject (hpen);
// 	}
// 	//--
// 	#undefMinN
// 	#undefMaxN
// 	#undefMinX
// 	#undefMaxX
// 	//--
// }
//--
int   InsertListViewItem (HWND hwndListView, int lLin, int lCol, int iSubItemYesNo, TCHAR * txt)
{
	LVITEM item = {0};
	RECT rect;
	GetClientRect (hwndListView, &rect);

	item.mask = LVIF_TEXT;
	// Point totherightaddress:
	item.pszText = txt;
	// Notabene:youmightwanttochecklLinandlColvaluesfirst
	item.iItem = lLin;
	item.iSubItem = lCol;

	switch (iSubItemYesNo)
	{
		case 0:
			// SendLVM_INSERTITEMmessageifyouwanttoinsertanitem (returns-1ifitfails):
			SendMessage ( (HWND)hwndListView, (Uint)LVM_INSERTITEM, (WPARAM)0, (LPARAM)&item);
			break;

		default:
			// SendLVM_SETITEMmessageifyouwanttoinsertasubitem (returnsFALSEifitfails):
			SendMessage ( (HWND)hwndListView, (Uint)LVM_SETITEM, (WPARAM)0, (LPARAM)&item);
			break;
	}
	return 0;
}
//--
