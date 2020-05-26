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
#include <stdio.h>
/// <summary>draws catmull-rom spline</summary>
__declspec(dllexport) VOID fa_drawcrs(fa_VERTEX* vertices, UINT _size)
{
    extern LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
    VOID* pVoid;                        // the void pointer
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;

    //for(UINT i=0; i<=_size; i++)
        D3DXVec3CatmullRom(&vertices[2].location, &vertices[0].location, &vertices[1].location, &vertices[3].location, &vertices[4].location, 0.5);

    IDirect3DDevice9_CreateVertexBuffer(d3ddev, _size * sizeof(vertices), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    IDirect3DVertexBuffer9_Lock(vertex_buffer, 0, 0, (VOID**)&pVoid, D3DLOCK_READONLY);    // lock the vertex buffer
    fa_memcpy(pVoid, vertices, _size * sizeof(vertices));   // copy the vertices to the locked buffer
    IDirect3DVertexBuffer9_Unlock(vertex_buffer);   // unlock the vertex buffer
    IDirect3DDevice9_SetFVF(d3ddev, D3DFVF);        // select which vertex format we are using
    IDirect3DDevice9_SetStreamSource(d3ddev, 0, vertex_buffer, 0, sizeof(fa_VERTEX));  // select the vertex buffer to display
    IDirect3DDevice9_DrawPrimitive(d3ddev, D3DPT_LINESTRIP, 0, 4);                   // copy the vertex buffer to the back buffer
}