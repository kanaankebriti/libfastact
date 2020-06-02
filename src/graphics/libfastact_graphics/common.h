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
#define D3DFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

#include <d3d9.h>
#include <d3dx9core.h>
#include "libfastact.h"

struct fa_VERTEX
{
    D3DXVECTOR3 location;   // (x,y,z)
    FLOAT rhw;              // from the D3DFVF_XYZRHW flag
    DWORD color;            // from the D3DFVF_DIFFUSE flag
}typedef fa_VERTEX;

struct fa_point2d
{
    D3DXVECTOR2 location;
}typedef fa_point2d;