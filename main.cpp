
#include "window.h"

#pragma comment (lib, "d3d9.lib")

LPDIRECT3D9 d3d; //the pointer to our DIrect3D interface
LPDIRECT3DDEVICE9 d3ddev; //the pointer to the device class

void initD3D(HWND hWnd); //sets up and inintializes Direct3D
void render_frame(void); //Renders a single frame
void cleanD3D(void); //closes Direct3D and releases memory


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  
    window w(hInstance, 640, 480, L"Windowprogram1");

    // display the window on the screen
    ShowWindow(*w.hWndGet(), nCmdShow);
   
    initD3D(*w.hWndGet());

    MSG msg = { 0 };

    while (WM_QUIT != msg.message) {
        // wait for the next message in the queue, store the result in 'msg'
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            // translate keystroke messages into the right format
            TranslateMessage(&msg);

            // send the message to the WindowProc function
            DispatchMessage(&msg);

        }
        else
        {
            render_frame();
        }
       
    }
    
    cleanD3D();
    return msg.wParam; // return this part of the WM_QUIT message to Windows
	

	//return 0;
}


void initD3D (HWND hWnd)
{
    d3d = Direct3DCreate9(D3D_SDK_VERSION); //create the Direct3D interface

    D3DPRESENT_PARAMETERS d3dpp; //create a struct to hold various device information

    ZeroMemory(&d3dpp, sizeof(d3dpp)); //clear out the struct for use
    d3dpp.Windowed = TRUE; //windowed mode
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //discarding old frames in the swap chain
    d3dpp.hDeviceWindow = hWnd; //setting device window to our window handle

    d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev); // create d3d device

}

void render_frame(void)
{
    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(20, 0, 25), 1.0f, 0);

    d3ddev->BeginScene(); //begins 3d scene

    d3ddev->EndScene(); //ends 3d scene

    d3ddev->Present(NULL, NULL, NULL, NULL); //displays the created frame
}

void cleanD3D(void)
{
    d3ddev->Release(); //close and release the 3D device
    d3d->Release(); //close and release Direct3D
}

