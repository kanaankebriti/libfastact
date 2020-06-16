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
/// <summary>draws txt to screen at location (x,y)</summary>
extern "C" __declspec(dllexport) VOID fa_outtextxy(LONG _x, LONG _y, CONST CHAR* txt)
{
    extern LPDIRECT3DDEVICE9 d3ddev;                // the pointer to the device class
    extern D3DCOLOR palette;                        // palette color for text, graphics
    extern FLOAT screen_center_x, screen_center_y;  // center of screen
    extern HWND hWnd;					            // window handler
    
    // set font up
    LPD3DXFONT font;
    D3DXCreateFont(d3ddev, 16, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &font);

    // set rectangle
    RECT FontRect;

    // get text width
    unsigned long long int string_length = fa_strlen(txt);

    // set rectangle up
    FontRect.left = screen_center_x + _x;
    FontRect.top = screen_center_y -_y;
    FontRect.bottom = FontRect.top + 16;
    FontRect.right = FontRect.left + (16 * string_length);
    printf("%d\t%d\t%d\t%d\n", _x, _y, FontRect.bottom, FontRect.right);
    // draw final text
    font->DrawTextA(NULL, LPCSTR(txt), -1, &FontRect, DT_CENTER, palette);
}