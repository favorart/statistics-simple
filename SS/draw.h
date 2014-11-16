#pragma once
//--
#define  _UNICODE

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <tchar.h>
#include <CommCtrl.h>
#define  sqr(x) x*x
//--
struct myData
{   int  lengh;
	   int* n;
	double* x;
	double* EV;
	double* a; // lengh+1
	double  min_x, max_x;
	   int  min_n, max_n;
	myData()
	{
		lengh = 0;
		n  = NULL;
		x  = NULL;
		a  = NULL;
		EV = NULL;
	}
~myData()
	{
		if(n)  free(n );
		if(x)  free(x );
		if(a)  free(a );
		if(EV) free(EV);
	}
};
//--
#ifdef DECLARE_GLOBALS
size_t Width, Height;
RECT Rect1;
#else
extern size_t Width, Height;
extern RECT Rect1;
#endif
//--
//--
void DrawRect(HDC hdc,RECT Rect,int cWight,DWORD lpColor,int iStyle);
void FillCircle(HDC hdc,int c_x,int c_y,int r,DWORD lpColor);
void DrawForm(HDC hdc,RECT Rect);
void Calculate(HWND hList, HWND hListCh, 
	              myData& vrtx, double* num_ch, 
															TCHAR *filename, bool mylocale
														);
//void DrawCoord(HDC hdc,myData* vrtx,bool cPFlag = 0);
//void DrawCoord_t(HDC hdc,myData* vrtx);
void DrawGraphic(HDC hdc,myData* vrtx,DWORD lpColorG,DWORD lpColorP,DWORD lpColorD,bool hChk);
//void DrawPoligon(HDC hdc,myData* vrtx,DWORD lpColor,DWORD cSteps);
//void DrawDistPro(HDC hdc,myData* vrtx);
//--
int InsertListViewItem(HWND hwndListView, int lLin, int lCol, int iSubItemYesNo, TCHAR* txt);
//--