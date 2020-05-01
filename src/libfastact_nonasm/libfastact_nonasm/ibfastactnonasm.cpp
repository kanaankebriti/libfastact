/*░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░ This file is part of libfastact.										░
░																		░
░ libfastact is free software: you can redistribute it and/or modify	░
░ it under the terms of the GNU General Public License as published by	░
░ the Free Software Foundation, either version 3 of the License, or		░
░ (at your option) any later version.									░
░																		░
░ libfastact is distributed in the hope that it will be useful,			░
░ but WITHOUT ANY WARRANTY; without even the implied warranty of		░
░ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the			░
░ GNU General Public License for more details.							░
░																		░
░ You should have received a copy of the GNU General Public License		░
░ along with Foobar.  If not, see <https://www.gnu.org/licenses/>.		░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░*/
#define WIN32_LEAN_AND_MEAN
#define D3DFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

#include <d3d9.h>
#include "libfastact.h"

LPDIRECT3D9 d3d;            // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;   // the pointer to the device class

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}

/// <summary>returns *d3ddev</summary>
extern "C" __declspec(dllexport) IDirect3DDevice9* fa_get_d3ddev(void)
{
    return d3ddev;
}

/// <summary>main rendering function</summary>
extern "C" __declspec(dllexport) void fa_render(void)
{
    d3ddev->Present(NULL, NULL, NULL, NULL);
}

/// <summary>cleans up Direct3D and COM</summary>
extern "C" __declspec(dllexport) void fa_closegraph(void)
{
    d3ddev->Release();  // close and release the 3D device
    d3d->Release();     // close and release Direct3D
}

/// <summary>initializes and prepares Direct3D</summary>
extern "C" __declspec(dllexport) void fa_initgraph(HWND hWnd)
{
    d3d = Direct3DCreate9(D3D_SDK_VERSION);     // create the Direct3D interface
    D3DPRESENT_PARAMETERS d3dpp;                // create a struct to hold various device information
    fa_memset(&d3dpp, 0, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;                      // program windowed, not fullscreen
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;   // discard old frames
    d3dpp.hDeviceWindow = hWnd;                 // set the window to be used by Direct3D
    // create a device class using this information and the info from the d3dpp stuct
    d3d->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &d3ddev);
}

/// <summary>draws a 2d pixel with color RGB</summary>
extern "C" __declspec(dllexport) void fa_pset()
{
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;

    struct VERTEX
    {
        FLOAT x, y, z, rhw; // from the D3DFVF_XYZRHW flag
        BYTE b, g, r;       // from the D3DFVF_DIFFUSE flag
    };
    VERTEX p1 = { 10,10,0,1, 255,255,255 };

    d3ddev->CreateVertexBuffer(sizeof(VERTEX), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);

    void* p1_Void;                                            // the void pointer
    vertex_buffer->Lock(0, 0, &p1_Void, D3DLOCK_READONLY);    // lock the vertex buffer
    memcpy(p1_Void, &p1, sizeof(VERTEX));           // copy the vertices to the locked buffer
    vertex_buffer->Unlock();// unlock the vertex buffer
    d3ddev->SetFVF(D3DFVF);
    d3ddev->SetStreamSource(0, vertex_buffer, 0, sizeof(VERTEX));
    d3ddev->DrawPrimitive(D3DPT_POINTLIST, 0, 1);
}