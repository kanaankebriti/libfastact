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

/// <summary>draws catmull-rom spline</summary>
__declspec(dllexport) VOID fa_drawcrs(fa_point2d* point, UINT _size, FLOAT _weight)
{
    extern LPDIRECT3DDEVICE9 d3ddev;        // the pointer to the device class
    extern D3DCOLOR palette;                // palette color for text, graphics
    extern FLOAT screen_center_x, screen_center_y;      // center of screen
    VOID* pVoid;                            // the void pointer
    UINT register i, j, m;                  // counter
    FLOAT k = 1;                            // weight counter
    LPDIRECT3DVERTEXBUFFER9 vertex_buffer;
    fa_VERTEX* vertex;
    UINT number_of_vertices = _size / sizeof(fa_point2d);                   // number of control points
    number_of_vertices += (number_of_vertices - 4) * _weight + _weight;     // number of control points + interpolated points
    // memory allocation for vertices
    vertex = malloc(number_of_vertices * sizeof(fa_VERTEX));

    // map control point #0 and point #1 to vertex #0 and vertex #1
    for (i = 0; i <= 1; i++)
    {
        vertex[i].location.x = point[i].location.x + screen_center_x;
        vertex[i].location.y = point[i].location.y + screen_center_y;
        vertex[i].location.z = 0;
        vertex[i].rhw = 1.0;
        vertex[i].color = palette;
    }

    // map control point #2 to point #n-1 to vertex
    for (i = _weight + 2, j = 2; i <= number_of_vertices - 1; i += _weight + 1, j++)
    {
        vertex[i].location.x = point[j].location.x + screen_center_x;
        vertex[i].location.y = point[j].location.y + screen_center_y;
        vertex[i].location.z = 0;
        vertex[i].rhw = 1.0;
        vertex[i].color = palette;
    }

    // map control point #n to vertex
    i -= _weight;
    vertex[i].location.x = point[(_size / sizeof(fa_point2d)) - 1].location.x + screen_center_x;
    vertex[i].location.y = point[(_size / sizeof(fa_point2d)) - 1].location.y + screen_center_y;
    vertex[i].location.z = 0;
    vertex[i].rhw = 1.0;
    vertex[i].color = palette;

    // point #1 to point #n-1 catmull-rom interpolation
    for (i = 1, m = 0; i < number_of_vertices - 2; i += _weight + 1, m++)
        for (j = i + 1, k = 1; j <= i + _weight; j++, k++)
        {
            D3DXVec3CatmullRom(&vertex[j].location, &point[m].location, &point[m + 1].location, &point[m + 2].location, &point[m + 3].location, k / (_weight + 1));
            vertex[j].location.x += screen_center_x;
            vertex[j].location.y += screen_center_y;
            vertex[j].color = palette;
            vertex[j].rhw = 1.0;
        }

    IDirect3DDevice9_CreateVertexBuffer(d3ddev, number_of_vertices * sizeof(fa_VERTEX) - sizeof(D3DXVECTOR3), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);
    IDirect3DVertexBuffer9_Lock(vertex_buffer, 0, 0, (VOID**)&pVoid, D3DLOCK_READONLY);     // lock the vertex buffer
    fa_memcpy(pVoid, vertex, number_of_vertices * sizeof(fa_VERTEX) - sizeof(D3DXVECTOR3)); // copy the vertices to the locked buffer
    free(vertex);
    IDirect3DVertexBuffer9_Unlock(vertex_buffer);   // unlock the vertex buffer
    IDirect3DDevice9_SetFVF(d3ddev, D3DFVF);        // select which vertex format we are using
    IDirect3DDevice9_SetStreamSource(d3ddev, 0, vertex_buffer, 0, sizeof(fa_VERTEX));   // select the vertex buffer to display
    IDirect3DDevice9_DrawPrimitive(d3ddev, D3DPT_LINESTRIP, 0, number_of_vertices); // copy the vertex buffer to the back buffer
}