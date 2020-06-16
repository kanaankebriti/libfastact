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

LPDIRECT3D9 d3d;                                    // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;                           // the pointer to the device class
D3DCOLOR palette = D3DCOLOR_XRGB(255, 255, 255);    // palette color for text, graphics
D3DCOLOR bpalette = D3DCOLOR_XRGB(0, 0, 0);         // palette color for background
FLOAT screen_center_x = 0, screen_center_y = 0;     // center of screen
HWND hWnd;											// window handler