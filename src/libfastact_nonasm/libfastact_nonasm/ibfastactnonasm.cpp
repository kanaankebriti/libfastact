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

struct VERTEX
{
    FLOAT x, y, z, rhw; // from the D3DFVF_XYZRHW flag
    DWORD color;       // from the D3DFVF_DIFFUSE flag
};

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
#include <iostream>
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

/// <summary>begins draw to screen</summary>
extern "C" __declspec(dllexport) void fa_begindraw()
{
    d3ddev->BeginScene();
}

/// <summary>ends draw to screen</summary>
extern "C" __declspec(dllexport) void fa_enddraw()
{
    d3ddev->EndScene();
}

/// <summary>draws a 2d pixel with color RGB</summary>
extern "C" __declspec(dllexport) void fa_pset(int _x, int _y, int _r, int _b, int _g)
{
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;

    struct VERTEX
    {
        FLOAT x, y, z, rhw; // from the D3DFVF_XYZRHW flag
        BYTE b, g, r;       // from the D3DFVF_DIFFUSE flag
    };
    VERTEX p1 = { _x,_y,0,1, _r,_b,_g };

    d3ddev->CreateVertexBuffer(sizeof(VERTEX), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);

    void* p1_Void;                                            // the void pointer
    vertex_buffer->Lock(0, 0, &p1_Void, D3DLOCK_READONLY);    // lock the vertex buffer
    memcpy(p1_Void, &p1, sizeof(VERTEX));           // copy the vertices to the locked buffer
    vertex_buffer->Unlock();// unlock the vertex buffer
    d3ddev->SetFVF(D3DFVF);
    d3ddev->SetStreamSource(0, vertex_buffer, 0, sizeof(VERTEX));
    d3ddev->DrawPrimitive(D3DPT_POINTLIST, 0, 1);
}

/// <summary>draws a 2d pixel with color RGB</summary>
extern "C" __declspec(dllexport) void fa_line(float _x1, float _y1, float _x2, float _y2, unsigned short int _r, unsigned short int _b, unsigned short int _g)
{
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;

    VERTEX vertices[] =
    {
        { _x1, _y1, 0.5f, 1.0f, D3DCOLOR_XRGB(_r, _b, _g) },
        { _x2, _y2, 0.5f, 1.0f, D3DCOLOR_XRGB(_r, _b, _g)},
    };

    d3ddev->CreateVertexBuffer(2*sizeof(VERTEX), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);

    void* pVoid;                                            // the void pointer
    vertex_buffer->Lock(0, 0, (void**)&pVoid, D3DLOCK_READONLY);    // lock the vertex buffer
    memcpy(pVoid,vertices, sizeof(vertices));           // copy the vertices to the locked buffer
    vertex_buffer->Unlock();// unlock the vertex buffer
    d3ddev->SetFVF(D3DFVF);
    d3ddev->SetStreamSource(0, vertex_buffer, 0, sizeof(VERTEX));
    d3ddev->DrawPrimitive(D3DPT_LINESTRIP, 0, 1);
}

extern "C" __declspec(dllexport) void fa_circle(int xCenter, int yCenter, int nRadius, unsigned short int _r, unsigned short int _b, unsigned short int _g)
{
    VERTEX* pVertices = new VERTEX[2 * 3.141592653 * nRadius];

    //Bresenham algorithm
    int x = 0, y = nRadius, d = 1 - nRadius, i = 0;

    while (x <= y)
    {
        //get eight points
        //(x,y)
        pVertices[i].x = x + xCenter;
        pVertices[i].y = y + yCenter;
        pVertices[i].z = 0.5f;
        pVertices[i].rhw = 1.0f;
        pVertices[i].color = D3DCOLOR_XRGB(_r, _b, _g);

        //(x,-y)
        ++i;
        pVertices[i].x = x + xCenter;
        pVertices[i].y = -y + yCenter;
        pVertices[i].z = 0.5f;
        pVertices[i].rhw = 1.0f;
        pVertices[i].color = D3DCOLOR_XRGB(_r, _b, _g);

        //(-x, y)
        ++i;
        pVertices[i].x = -x + xCenter;
        pVertices[i].y = y + yCenter;
        pVertices[i].z = 0.5f;
        pVertices[i].rhw = 1.0f;
        pVertices[i].color = D3DCOLOR_XRGB(_r, _b, _g);

        //(-x, -y)
        ++i;
        pVertices[i].x = -x + xCenter;
        pVertices[i].y = -y + yCenter;
        pVertices[i].z = 0.5f;
        pVertices[i].rhw = 1.0f;
        pVertices[i].color = D3DCOLOR_XRGB(_r, _b, _g);

        //(y, x)
        ++i;
        pVertices[i].x = y + xCenter;
        pVertices[i].y = x + yCenter;
        pVertices[i].z = 0.5f;
        pVertices[i].rhw = 1.0f;
        pVertices[i].color = D3DCOLOR_XRGB(_r, _b, _g);

        //(-y, x)
        ++i;
        pVertices[i].x = -y + xCenter;
        pVertices[i].y = x + yCenter;
        pVertices[i].z = 0.5f;
        pVertices[i].rhw = 1.0f;
        pVertices[i].color = D3DCOLOR_XRGB(_r, _b, _g);

        //(y, -x)
        ++i;
        pVertices[i].x = y + xCenter;
        pVertices[i].y = -x + yCenter;
        pVertices[i].z = 0.5f;
        pVertices[i].rhw = 1.0f;
        pVertices[i].color = D3DCOLOR_XRGB(_r, _b, _g);

        //(-y,-x)
        ++i;
        pVertices[i].x = -y + xCenter;
        pVertices[i].y = -x + yCenter;
        pVertices[i].z = 0.5f;
        pVertices[i].rhw = 1.0f;
        pVertices[i].color = D3DCOLOR_XRGB(_r, _b, _g);

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
    d3ddev->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    d3ddev->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    d3ddev->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    d3ddev->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
    d3ddev->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
    d3ddev->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
    d3ddev->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA | D3DCOLORWRITEENABLE_BLUE | D3DCOLORWRITEENABLE_GREEN | D3DCOLORWRITEENABLE_RED);
    d3ddev->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
    d3ddev->SetRenderState(D3DRS_FOGENABLE, FALSE);
    d3ddev->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
    d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    d3ddev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG2);
    d3ddev->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
    d3ddev->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
    d3ddev->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
    d3ddev->SetFVF(D3DFVF);
    d3ddev->DrawPrimitiveUP(D3DPT_POINTLIST, i, pVertices, sizeof(VERTEX));
    delete[] pVertices;
}