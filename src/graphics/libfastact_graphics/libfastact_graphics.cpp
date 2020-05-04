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
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "libfastact.lib")

#include <stdio.h>
#include <d3d9.h>
#include <d3dx9core.h>
#include "libfastact.h"


LPDIRECT3D9 d3d;                                // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;                       // the pointer to the device class
DWORD palette = D3DCOLOR_XRGB(255, 255, 255);   // palette color for text, graphics
DWORD bpalette = D3DCOLOR_XRGB(0, 0, 0);        // palette color for text, graphics

struct VERTEX
{
    FLOAT x, y, z, rhw; // from the D3DFVF_XYZRHW flag
    DWORD color;       // from the D3DFVF_DIFFUSE flag
};

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}

/// <summary>begins draw to screen</summary>
extern "C" __declspec(dllexport) void fa_begindraw()
{
    d3ddev->BeginScene();
}

/// <summary>draws a 2d circle with color specified in palette</summary>
extern "C" __declspec(dllexport) void fa_circle(int xCenter, int yCenter, int nRadius)
{
    VERTEX* vertices = new VERTEX[2 * 3.141592653 * nRadius];

    //Bresenham algorithm
    int x = 0, y = nRadius, d = 1 - nRadius, i = 0;

    while (x <= y)
    {
        //get eight points
        //(x,y)
        vertices[i].x = x + xCenter;
        vertices[i].y = y + yCenter;
        vertices[i].z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(x,-y)
        ++i;
        vertices[i].x = x + xCenter;
        vertices[i].y = -y + yCenter;
        vertices[i].z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(-x,y)
        ++i;
        vertices[i].x = -x + xCenter;
        vertices[i].y = y + yCenter;
        vertices[i].z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(-x,-y)
        ++i;
        vertices[i].x = -x + xCenter;
        vertices[i].y = -y + yCenter;
        vertices[i].z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(y,x)
        ++i;
        vertices[i].x = y + xCenter;
        vertices[i].y = x + yCenter;
        vertices[i].z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(-y,x)
        ++i;
        vertices[i].x = -y + xCenter;
        vertices[i].y = x + yCenter;
        vertices[i].z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(y,-x)
        ++i;
        vertices[i].x = y + xCenter;
        vertices[i].y = -x + yCenter;
        vertices[i].z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(-y,-x)
        ++i;
        vertices[i].x = -y + xCenter;
        vertices[i].y = -x + yCenter;
        vertices[i].z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        ++i;
        if (d > 0)
        {
            d += 2 * (x - y) + 5;
            --y;
        }
        else
            d += 2 * x + 3;
        ++x;
    }
    d3ddev->SetFVF(D3DFVF);
    d3ddev->DrawPrimitiveUP(D3DPT_POINTLIST, i, vertices, sizeof(VERTEX));
    delete[] vertices;
}

/// <summary>cleans up Direct3D and COM</summary>
extern "C" __declspec(dllexport) void fa_closegraph(void)
{
    d3ddev->Release();  // close and release the 3D device
    d3d->Release();     // close and release Direct3D
}

extern "C" __declspec(dllexport) void fa_cls(void)
{
    d3ddev->Clear(0, 0, 1, bpalette, 1, 0);
}

/// <summary>ends draw to screen</summary>
extern "C" __declspec(dllexport) void fa_enddraw()
{
    d3ddev->EndScene();
}

/// <summary>returns *d3ddev</summary>
extern "C" __declspec(dllexport) IDirect3DDevice9 * fa_get_d3ddev(void)
{
    return d3ddev;
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
extern "C" __declspec(dllexport) void fa_line(float _x1, float _y1, float _x2, float _y2)
{
    void* pVoid; // the void pointer
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;

    VERTEX vertices[] =
    {
        { _x1, _y1, 0.5f, 1.0f, palette },
        { _x2, _y2, 0.5f, 1.0f, palette },
    };

    d3ddev->CreateVertexBuffer(2 * sizeof(VERTEX), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    vertex_buffer->Lock(0, 0, (void**)&pVoid, D3DLOCK_READONLY);    // lock the vertex buffer
    memcpy(pVoid, vertices, sizeof(vertices));                      // copy the vertices to the locked buffer
    vertex_buffer->Unlock();                                        // unlock the vertex buffer
    d3ddev->SetFVF(D3DFVF);                                         // select which vertex format we are using
    d3ddev->SetStreamSource(0, vertex_buffer, 0, sizeof(VERTEX));   // select the vertex buffer to display
    d3ddev->DrawPrimitive(D3DPT_LINESTRIP, 0, 1);                   // copy the vertex buffer to the back buffer
}

/// <summary>draws txt to screen at location (x,y) with color RGB</summary>
extern "C" __declspec(dllexport) void fa_outtextxy(float _x, float _y, const char* txt)
{
    // set font up
    LPD3DXFONT font;
    D3DXCreateFont(d3ddev, 16, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &font);

    // set rectangle
    RECT FontRect;

    // get text width
    unsigned long long int string_length = fa_strlen(txt);
    font->DrawText(NULL, LPCWSTR(txt), string_length, &FontRect, DT_CALCRECT, palette);

    // set rectangle up
    FontRect.left = _x;
    FontRect.top = _y;
    FontRect.bottom = _y + 16;
    --(FontRect.right);

    // draw final text
    font->DrawTextA(NULL, txt, -1, &FontRect, DT_CENTER, palette);
}

/// <summary>sets palette color for backgound</summary>
extern "C" __declspec(dllexport) void fa_setbkcolor(unsigned short int _r, unsigned short int _g, unsigned short int _b)
{
    bpalette = D3DCOLOR_XRGB(_r, _b, _g);
}

/// <summary>sets palette color for text and graphics</summary>
extern "C" __declspec(dllexport) void fa_setcolor(unsigned short int _r, unsigned short int _g, unsigned short int _b)
{
    palette = D3DCOLOR_XRGB(_r, _b, _g);
}

/// <summary>draws a 2d pixel with color specified in palette</summary>
extern "C" __declspec(dllexport) void fa_pset(float _x, float _y)
{
    VOID* pVoid;    // the void pointer
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;
    VERTEX p1 = { _x,_y,0,1,palette };

    d3ddev->CreateVertexBuffer(sizeof(VERTEX), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    vertex_buffer->Lock(0, 0, &pVoid, D3DLOCK_READONLY);    // lock the vertex buffer
    fa_memcpy(pVoid, &p1, sizeof(VERTEX));                     // copy the vertices to the locked buffer
    vertex_buffer->Unlock();                                // unlock the vertex buffer
    d3ddev->SetFVF(D3DFVF);                                 // select which vertex format we are using
    d3ddev->SetStreamSource(0, vertex_buffer, 0, sizeof(VERTEX));// select the vertex buffer to display
    d3ddev->DrawPrimitive(D3DPT_POINTLIST, 0, 1);           // copy the vertex buffer to the back buffer
}

/// <summary>main rendering function</summary>
extern "C" __declspec(dllexport) void fa_render(void)
{
    d3ddev->Present(NULL, NULL, NULL, NULL);
}