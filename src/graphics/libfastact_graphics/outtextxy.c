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

/// <summary>draws txt to screen at location (x,y)</summary>
__declspec(dllexport) VOID fa_outtextxy(FLOAT _x, FLOAT _y, CONST CHAR* txt)
{
    extern LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
    extern D3DCOLOR palette;            // palette color for text, graphics

    // set font up
    LPD3DXFONT font;
    D3DXCreateFont(d3ddev, 16, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &font);

    // set rectangle
    RECT FontRect;

    // get text width
    ULONG string_length = fa_strlen(txt);
    DrawTextW(NULL, txt, string_length, &FontRect, DT_CALCRECT, palette);

    // set rectangle up
    FontRect.left = _x;
    FontRect.top = _y;
    FontRect.bottom = _y + 16;
    --(FontRect.right);

    // draw final text
    DrawTextA(NULL, txt, -1, &FontRect, DT_CENTER, palette);
}