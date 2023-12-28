#pragma once
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h> 



LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


class window
{
public:
	window(HINSTANCE hInstance, int w, int h, LPCWSTR name);
	~window();

public:
	HWND* hWndGet();
	void windowCreate();
	


private:
	int m_height;
	int m_width;
	LPCWSTR name;
	HWND m_hWnd;
	WNDCLASSEX m_wc;
	HINSTANCE m_hInstance;



};
