#include "window.h"

window::window(HINSTANCE hInstance, int w, int h, LPCWSTR name)
	: m_hInstance(hInstance), m_width(w), m_height(h), name(name)
{

    // clear out the window class for use
    ZeroMemory(&m_wc, sizeof(WNDCLASSEX));

    // fill in the struct with the needed information
    m_wc.cbSize = sizeof(WNDCLASSEX);
    m_wc.style = CS_HREDRAW | CS_VREDRAW;
    m_wc.lpfnWndProc = WindowProc;
    m_wc.hInstance = hInstance;
    m_wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    m_wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    m_wc.lpszClassName = name;


    // register the window class
    RegisterClassEx(&m_wc);
    windowCreate();

}

window::~window(){}

void window::windowCreate()
{
        m_hWnd = CreateWindowEx(NULL,
        name,    // name of the window class
        L"Our First Windowed Program",   // title of the window
        WS_OVERLAPPEDWINDOW,    // window style
        900,    // x-position of the window
        400,    // y-position of the window
        m_width,    // width of the window
        m_height,    // height of the window
        NULL,    // we have no parent window, NULL
        NULL,    // we aren't using menus, NULL
        m_hInstance,    // application handle
        NULL);    // used with multiple windows, NULL

}

HWND* window::hWndGet()
{
    return &m_hWnd;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and find what code to run for the message given
    switch (message)
    {
        // this message is read when the window is closed
    case WM_DESTROY:
    {
        // close the application entirely
        PostQuitMessage(0);
        return 0;
    } break;
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc(hWnd, message, wParam, lParam);
}



/*
* OLD CODE
* 
* 
   //the handle for the window
   HWND hWnd;

   // this struct holds information for the window class
   WNDCLASSEX wc;

   // clear out the window class for use
   ZeroMemory(&wc, sizeof(WNDCLASSEX));

   // fill in the struct with the needed information
   wc.cbSize = sizeof(WNDCLASSEX);
   wc.style = CS_HREDRAW | CS_VREDRAW;
   wc.lpfnWndProc = WindowProc;
   wc.hInstance = hInstance;
   wc.hCursor = LoadCursor(NULL, IDC_ARROW);
   wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
   wc.lpszClassName = L"WindowClass1";

   // register the window class
   RegisterClassEx(&wc);


   // create the window and use the result as the handle
   hWnd = CreateWindowEx(NULL,
       L"WindowClass1",    // name of the window class
       L"Our First Windowed Program",   // title of the window
       WS_OVERLAPPEDWINDOW,    // window style
       300,    // x-position of the window
       300,    // y-position of the window
       1280,    // width of the window
       720,    // height of the window
       NULL,    // we have no parent window, NULL
       NULL,    // we aren't using menus, NULL
       hInstance,    // application handle
       NULL);    // used with multiple windows, NULL


*/

/*
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and find what code to run for the message given
    switch (message)
    {
        // this message is read when the window is closed
    case WM_DESTROY:
    {
        // close the application entirely
        PostQuitMessage(0);
        return 0;
    } break;
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc(hWnd, message, wParam, lParam);
}
*/

/*
  m_hWnd = CreateWindowEx(NULL,
      name,    // name of the window class
      L"Our First Windowed Program",   // title of the window
      WS_OVERLAPPEDWINDOW,    // window style
      900,    // x-position of the window
      400,    // y-position of the window
      w,    // width of the window
      h,    // height of the window
      NULL,    // we have no parent window, NULL
      NULL,    // we aren't using menus, NULL
      hInstance,    // application handle
      NULL);    // used with multiple windows, NULL
      */