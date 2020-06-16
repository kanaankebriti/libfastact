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
░ along with libfastact.  If not, see <https://www.gnu.org/licenses/>.	░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░*/
#include "common.h"

/// <summary>draws a triangle</summary>
__declspec(dllexport) VOID fa_triangle(fa_point2d _p1, fa_point2d _p2, fa_point2d _p3)
{
    extern LPDIRECT3DDEVICE9 d3ddev;                // the pointer to the device class
    extern D3DCOLOR palette;                        // palette color for text, graphics
    extern FLOAT screen_center_x, screen_center_y;  // center of screen
    VOID* pVoid;                                    // the void pointer
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;

    fa_VERTEX vertices[6] =
    {
        {screen_center_x - _p1.location.x, screen_center_y - _p1.location.y, 0.5f, 1.0f, palette },
        {screen_center_x - _p2.location.x, screen_center_y - _p2.location.y, 0.5f, 1.0f, palette },
        {screen_center_x - _p1.location.x, screen_center_y - _p1.location.y, 0.5f, 1.0f, palette },
        {screen_center_x - _p3.location.x, screen_center_y - _p3.location.y, 0.5f, 1.0f, palette },
        {screen_center_x - _p2.location.x, screen_center_y - _p2.location.y, 0.5f, 1.0f, palette },
        {screen_center_x - _p3.location.x, screen_center_y - _p3.location.y, 0.5f, 1.0f, palette }
    };

    IDirect3DDevice9_CreateVertexBuffer(d3ddev, sizeof(vertices), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    IDirect3DVertexBuffer9_Lock(vertex_buffer, 0, 0, (VOID**)&pVoid, D3DLOCK_READONLY); // lock the vertex buffer
    fa_memcpy(pVoid, vertices, sizeof(vertices));   // copy the vertices to the locked buffer
    IDirect3DVertexBuffer9_Unlock(vertex_buffer);   // unlock the vertex buffer
    IDirect3DDevice9_SetFVF(d3ddev, D3DFVF);        // select which vertex format we are using
    IDirect3DDevice9_SetStreamSource(d3ddev, 0, vertex_buffer, 0, sizeof(fa_VERTEX));   // select the vertex buffer to display
    IDirect3DDevice9_DrawPrimitive(d3ddev, D3DPT_LINELIST, 0, 3);                      // copy the vertex buffer to the back buffer
}