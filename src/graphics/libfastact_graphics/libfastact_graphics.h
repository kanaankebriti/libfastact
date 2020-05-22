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
#pragma once

#ifndef __LIBFASTACT_GRAPHICS_H__
#define __LIBFASTACT_GRAPHICS_H__

#include <d3d9.h>

#ifdef __cplusplus
extern "C"
{
#endif
	// graphics
	/// <summary>begins draw to screen</summary>
	void fa_begindraw(void);
	/// <summary>draws a 2d circle based on center location and radius</summary>
	void fa_circle(int _xCenter, int _yCenter, unsigned int _Radius);
	/// <summary>cleans up Direct3D and COM</summary>
	void fa_closegraph(void);
	/// <summary>clears entire viewport rectangle and sets background color</summary>
	void fa_cls(void);
	/// <summary>ends draw to screen</summary>
	void fa_enddraw(void);
	/// <summary>draws a 2d rectangle</summary>
	void fa_rectangle(float _x1, float _y1, float _x2, float _y2);
	/// <summary>returns *d3ddev</summary>
	IDirect3DDevice9* fa_get_d3ddev(void);
	/// <summary>initializes and prepares Direct3D</summary>
	void fa_initgraph(HWND hWnd);
	/// <summary>draws a 2d line with color RGB</summary>
	void fa_line(float _X1, float _Y1, float _X2, float _Y2);
	/// <summary>draws txt to screen at location (x,y) with color RGB</summary>
	void fa_outtextxy(float _X, float _Y, const char* _Txt);
	/// <summary>sets palette color for backgound</summary>
	void fa_setbkcolor(unsigned short int _R, unsigned short int _G, unsigned short int _B);
	/// <summary>sets palette color for text, graphics and backgound</summary>
	void fa_setcolor(unsigned short int _R, unsigned short int _G, unsigned short int _B);
	/// <summary>draws a 2d pixel with color RGB</summary>
	void fa_pset(float _X, float _Y);
	/// <summary>main rendering function</summary>
	void fa_render(void);
#ifdef __cplusplus
}
#endif

#endif // !__LIBFASTACT_GRAPHICS_H__