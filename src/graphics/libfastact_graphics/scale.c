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
#include "stdio.h"
/// <summary>scales a 2d shape based on pointlist</summary>
__declspec(dllexport) VOID fa_scale(fa_point2d* _pointlist, UINT _size, INT _factor)
{
    extern LPDIRECT3DDEVICE9 d3ddev;                    // the pointer to the device class
    extern FLOAT screen_center_x, screen_center_y;      // center of screen
    extern D3DCOLOR palette;                            // palette color for text, graphics
    fa_point2d centroid = { 0,0 };

    // find centroid of shape
    for (int i = 0; i < _size; i++)
    {
        centroid.location.x += _pointlist[i].location.x;
        centroid.location.y += _pointlist[i].location.y;
    }

    centroid.location.x /= _size;
    centroid.location.y /= _size;
    
    printf("center_x=%f\tcenter_y=%f\n", centroid.location.x, centroid.location.y);
}