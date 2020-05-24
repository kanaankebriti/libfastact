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

/// <summary>draws a 2d circle based on center location and radius</summary>
__declspec(dllexport) VOID fa_circle(INT xCenter, INT yCenter, UINT nRadius)
{
    extern LPDIRECT3DDEVICE9 d3ddev;                    // the pointer to the device class
    extern FLOAT screen_center_x, screen_center_y;      // center of screen
    extern D3DCOLOR palette;                            // palette color for text, graphics
    VERTEX* vertices;
    vertices = malloc(6 * nRadius * sizeof(VERTEX));    // note that 6 = (int) 2*3.141

    //Bresenham algorithm
    INT x = 0, y = nRadius, d = 1 - nRadius, i = 0;

    while (x <= y)
    {
        //get eight points
        //(x,y)
        vertices[i].location.x = x + xCenter + screen_center_x;
        vertices[i].location.y = y + yCenter + screen_center_y;
        vertices[i].location.z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(x,-y)
        ++i;
        vertices[i].location.x = x + xCenter + screen_center_x;
        vertices[i].location.y = -y + yCenter + screen_center_y;
        vertices[i].location.z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(-x,y)
        ++i;
        vertices[i].location.x = -x + xCenter + screen_center_x;
        vertices[i].location.y = y + yCenter + screen_center_y;
        vertices[i].location.z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(-x,-y)
        ++i;
        vertices[i].location.x = -x + xCenter + screen_center_x;
        vertices[i].location.y = -y + yCenter + screen_center_y;
        vertices[i].location.z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(y,x)
        ++i;
        vertices[i].location.x = y + xCenter + screen_center_x;
        vertices[i].location.y = x + yCenter + screen_center_y;
        vertices[i].location.z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(-y,x)
        ++i;
        vertices[i].location.x = -y + xCenter + screen_center_x;
        vertices[i].location.y = x + yCenter + screen_center_y;
        vertices[i].location.z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(y,-x)
        ++i;
        vertices[i].location.x = y + xCenter + screen_center_x;
        vertices[i].location.y = -x + yCenter + screen_center_y;
        vertices[i].location.z = 0;
        vertices[i].rhw = 1.0f;
        vertices[i].color = palette;

        //(-y,-x)
        ++i;
        vertices[i].location.x = -y + xCenter + screen_center_x;
        vertices[i].location.y = -x + yCenter + screen_center_y;
        vertices[i].location.z = 0;
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