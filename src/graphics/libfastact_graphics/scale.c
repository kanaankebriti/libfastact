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
__declspec(dllexport) fa_point2d* fa_scale(fa_point2d* _pointlist, UINT _size, FLOAT _factor)
{
    extern FLOAT screen_center_x, screen_center_y;      // center of screen
    extern D3DCOLOR palette;                            // palette color for text, graphics
    fa_point2d centroid = { 0,0 };
    float x_distance_from_centroid, y_distance_from_centroid;
    fa_point2d* scaled_pointlist;
    UINT register i;    // loop counter

    // number scaled points is equal to number of original points
    scaled_pointlist = (fa_point2d*)malloc(_size * sizeof(fa_point2d));

    // find centroid of shape
    for (i = 0; i < _size; i++)
    {
        centroid.location.x += _pointlist[i].location.x;
        centroid.location.y += _pointlist[i].location.y;
    }

    centroid.location.x /= _size;
    centroid.location.y /= _size;
    
    //centroid.location.x += screen_center_x;
    //centroid.location.y += screen_center_y;

    // scale
    for (i = 0; i < _size; i++)
    {
        x_distance_from_centroid =  _pointlist[i].location.x - centroid.location.x;
        y_distance_from_centroid =  _pointlist[i].location.y - centroid.location.y;
        
        x_distance_from_centroid *= _factor;
        y_distance_from_centroid *= _factor;

        scaled_pointlist[i].location.x = centroid.location.x + x_distance_from_centroid;
        scaled_pointlist[i].location.y = centroid.location.y + y_distance_from_centroid;
        printf("x=%f\ty=%f\n", scaled_pointlist[i].location.x, scaled_pointlist[i].location.y);
    }

    return scaled_pointlist;
}