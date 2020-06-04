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

/// <summary>draws list of points</summary>
__declspec(dllexport) VOID fa_drawplist(fa_point2d* point, UINT _size)
{
    extern LPDIRECT3DDEVICE9 d3ddev;                        // the pointer to the device class
    extern D3DCOLOR palette;                                // palette color for text, graphics
    extern FLOAT screen_center_x, screen_center_y;          // center of screen
    UINT register i;                                        // counter
    VOID* pVoid;                                            // the void pointer
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;
    fa_VERTEX* vertex;                                      // array vertices that to be drawed
    UINT number_of_vertices = _size / sizeof(fa_point2d);   // number of control points

    // memory allocation for vertices
    vertex = malloc(number_of_vertices * sizeof(fa_VERTEX));

    // map control point #0 to point #n to vertex
    for (i = 0; i < number_of_vertices; i++)
    {
        vertex[i].location.x = point[i].location.x + screen_center_x;
        vertex[i].location.y = point[i].location.y + screen_center_y;
        vertex[i].location.z = 0;
        vertex[i].rhw = 1.0;
        vertex[i].color = palette;
    }

    IDirect3DDevice9_CreateVertexBuffer(d3ddev, number_of_vertices * sizeof(fa_VERTEX) - sizeof(D3DXVECTOR3), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    IDirect3DVertexBuffer9_Lock(vertex_buffer, 0, 0, (VOID**)&pVoid, D3DLOCK_READONLY);     // lock the vertex buffer
    fa_memcpy(pVoid, vertex, number_of_vertices * sizeof(fa_VERTEX) - sizeof(D3DXVECTOR3)); // copy the vertices to the locked buffer
    free(vertex);
    IDirect3DVertexBuffer9_Unlock(vertex_buffer);                                       // unlock the vertex buffer
    IDirect3DDevice9_SetFVF(d3ddev, D3DFVF);                                            // select which vertex format we are using
    IDirect3DDevice9_SetStreamSource(d3ddev, 0, vertex_buffer, 0, sizeof(fa_VERTEX));   // select the vertex buffer to display
    IDirect3DDevice9_DrawPrimitive(d3ddev, D3DPT_POINTLIST, 0, number_of_vertices);     // copy the vertex buffer to the back buffer
}