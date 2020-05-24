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

/// <summary>draws a 2d rectangle</summary>
__declspec(dllexport) VOID fa_rectangle(FLOAT _x1, FLOAT _y1, FLOAT _x2, FLOAT _y2)
{
    extern LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
    extern D3DCOLOR palette;            // palette color for text, graphics
    VOID* pVoid;                        // the void pointer
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