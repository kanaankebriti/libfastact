﻿/*░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
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
░ along with libfastact.  If not, see <https://www.gnu.org/licenses/>.	░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░*/
#define D3DFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

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
}typedef VERTEX;

/// <summary>begins draw to screen</summary>
__declspec(dllexport) VOID fa_begindraw(VOID)
{
    IDirect3DDevice9_BeginScene(d3ddev);
}

/// <summary>draws a 2d circle based on center location and radius</summary>
__declspec(dllexport) VOID fa_circle(INT xCenter, INT yCenter, UINT nRadius)
{
    VERTEX* vertices;
    vertices = malloc(6 * nRadius * sizeof(VERTEX)); // note that 6 = (int) 2*3.141

    //Bresenham algorithm
    INT x = 0, y = nRadius, d = 1 - nRadius, i = 0;

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
        {
            d += 2 * x + 3;
        }
        ++x;
    }
    IDirect3DDevice9_SetFVF(d3ddev, D3DFVF);
    IDirect3DDevice9_DrawPrimitiveUP(d3ddev, D3DPT_POINTLIST, i, vertices, sizeof(VERTEX));
    free(vertices);
}

/// <summary>cleans up Direct3D and COM</summary>
 __declspec(dllexport) VOID fa_closegraph(VOID)
{
    IDirect3DDevice9_Release(d3ddev);  // close and release the 3D device
    IDirect3DDevice9_Release(d3d);     // close and release Direct3D
}

__declspec(dllexport) VOID fa_cls(VOID)
{
    IDirect3DDevice9_Clear(d3ddev, 0, 0, 1, bpalette, 1, 0);
}

/// <summary>draws a 2d rectangle</summary>
__declspec(dllexport) VOID fa_rectangle(FLOAT _x1, FLOAT _y1, FLOAT _x2, FLOAT _y2)
{
    VOID* pVoid; // the void pointer
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;

    VERTEX vertices[8] =
    {   // top
        { _x1, _y1, 0.5f, 1.0f, palette },
        { _x2, _y1, 0.5f, 1.0f, palette },
        // right
        { _x2, _y1, 0.5f, 1.0f, palette },
        { _x2, _y2, 0.5f, 1.0f, palette },
        // bottom
        { _x1, _y2, 0.5f, 1.0f, palette },
        { _x2, _y2, 0.5f, 1.0f, palette },
        // left
        { _x1, _y1, 0.5f, 1.0f, palette },
        { _x1, _y2, 0.5f, 1.0f, palette },
    };

    IDirect3DDevice9_CreateVertexBuffer(d3ddev, sizeof(vertices), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    IDirect3DVertexBuffer9_Lock(vertex_buffer, 0, 0, (VOID**)&pVoid, D3DLOCK_READONLY);    // lock the vertex buffer
    fa_memcpy(pVoid, vertices, sizeof(vertices));   // copy the vertices to the locked buffer
    IDirect3DVertexBuffer9_Unlock(vertex_buffer);   // unlock the vertex buffer
    IDirect3DDevice9_SetFVF(d3ddev, D3DFVF);        // select which vertex format we are using
    IDirect3DDevice9_SetStreamSource(d3ddev, 0, vertex_buffer, 0, sizeof(VERTEX));  // select the vertex buffer to display
    IDirect3DDevice9_DrawPrimitive(d3ddev, D3DPT_LINELIST, 0, 4);                   // copy the vertex buffer to the back buffer
}

/// <summary>ends draw to screen</summary>
__declspec(dllexport) VOID fa_enddraw(VOID)
{
    IDirect3DDevice9_EndScene(d3ddev);
}

/// <summary>returns *d3ddev</summary>
__declspec(dllexport) IDirect3DDevice9 * fa_get_d3ddev(VOID)
{
    return d3ddev;
}

/// <summary>initializes and prepares Direct3D</summary>
__declspec(dllexport) VOID fa_initgraph(HWND hWnd)
{
    d3d = Direct3DCreate9(D3D_SDK_VERSION);     // create the Direct3D interface
    D3DPRESENT_PARAMETERS d3dpp;                // create a struct to hold various device information
    fa_memset(&d3dpp, 0, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;                      // program windowed, not fullscreen
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;   // discard old frames
    d3dpp.hDeviceWindow = hWnd;                 // set the window to be used by Direct3D
    // create a device class using this information and the info from the d3dpp struct
    IDirect3D9_CreateDevice(d3d, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
}

/// <summary>draws a 2d pixel with color RGB</summary>
__declspec(dllexport) VOID fa_line(FLOAT _x1, FLOAT _y1, FLOAT _x2, FLOAT _y2)
{
    VOID* pVoid; // the void pointer
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;

    VERTEX vertices[2] =
    {
        { _x1, _y1, 0.5f, 1.0f, palette },
        { _x2, _y2, 0.5f, 1.0f, palette },
    };

    IDirect3DDevice9_CreateVertexBuffer(d3ddev, sizeof(vertices), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    IDirect3DVertexBuffer9_Lock(vertex_buffer, 0, 0, (VOID**)&pVoid, D3DLOCK_READONLY);    // lock the vertex buffer
    fa_memcpy(pVoid, vertices, sizeof(vertices));                      // copy the vertices to the locked buffer
    IDirect3DVertexBuffer9_Unlock(vertex_buffer);                                        // unlock the vertex buffer
    IDirect3DDevice9_SetFVF(d3ddev, D3DFVF);                        // select which vertex format we are using
    IDirect3DDevice9_SetStreamSource(d3ddev, 0, vertex_buffer, 0, sizeof(VERTEX));  // select the vertex buffer to display
    IDirect3DDevice9_DrawPrimitive(d3ddev, D3DPT_LINESTRIP, 0, 1);                  // copy the vertex buffer to the back buffer
}

/// <summary>draws txt to screen at location (x,y) with color RGB</summary>
__declspec(dllexport) VOID fa_outtextxy(FLOAT _x, FLOAT _y, CONST CHAR* txt)
{
    // set font up
    LPD3DXFONT font;
    D3DXCreateFont(d3ddev, 16, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &font);

    // set rectangle
    RECT FontRect;

    // get text width
    ULONG string_length = fa_strlen(txt);
    DrawTextW(NULL, txt, string_length, &FontRect, DT_CALCRECT, palette);

    // set rectangle up
    FontRect.left = _x;
    FontRect.top = _y;
    FontRect.bottom = _y + 16;
    --(FontRect.right);

    // draw final text
    DrawTextA(NULL, txt, -1, &FontRect, DT_CENTER, palette);
}

/// <summary>sets palette color for backgound</summary>
__declspec(dllexport) VOID fa_setbkcolor(WORD _r, WORD _g, WORD _b)
{
    bpalette = D3DCOLOR_XRGB(_r, _b, _g);
}

/// <summary>sets palette color for text and graphics</summary>
__declspec(dllexport) VOID fa_setcolor(WORD _r, WORD _g, WORD _b)
{
    palette = D3DCOLOR_XRGB(_r, _b, _g);
}

/// <summary>draws a 2d pixel with color specified in palette</summary>
__declspec(dllexport) VOID fa_pset(FLOAT _x, FLOAT _y)
{
    VOID* pVoid;    // the void pointer
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;
    VERTEX p1 = { _x,_y,0,1,palette };

    IDirect3DDevice9_CreateVertexBuffer(d3ddev, sizeof(VERTEX), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    IDirect3DVertexBuffer9_Lock(vertex_buffer, 0, 0, &pVoid, D3DLOCK_READONLY);    // lock the vertex buffer
    fa_memcpy(pVoid, &p1, sizeof(VERTEX));                  // copy the vertices to the locked buffer
    IDirect3DVertexBuffer9_Unlock(vertex_buffer);           // unlock the vertex buffer
    IDirect3DDevice9_SetFVF(d3ddev, D3DFVF);                // select which vertex format we are using
    IDirect3DDevice9_SetStreamSource(d3ddev, 0, vertex_buffer, 0, sizeof(VERTEX));  // select the vertex buffer to display
    IDirect3DDevice9_DrawPrimitive(d3ddev, D3DPT_POINTLIST, 0, 1);                  // copy the vertex buffer to the back buffer
}

/// <summary>main rendering function</summary>
__declspec(dllexport) VOID fa_render(VOID)
{
    IDirect3DDevice9_Present(d3ddev, NULL, NULL, NULL, NULL);
}