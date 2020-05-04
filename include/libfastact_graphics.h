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
░ along with Foobar.  If not, see <https://www.gnu.org/licenses/>.		░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░*/
#pragma once

#include <d3d9.h>

#ifdef __cplusplus
extern "C"
{
#endif
	// graphics
	/// <summary>begins draw to screen</summary>
	void fa_begindraw();
	/// <summary>draws a circle based on center location and radius and color RGB</summary>
	void fa_circle(int _xCenter, int _yCenter, int _Radius, unsigned short int _R, unsigned short int _B, unsigned short int _G);
	/// <summary>cleans up Direct3D and COM</summary>
	void fa_closegraph(void);
	/// <summary>clears entire viewport rectangle and sets background color</summary>
	void fa_cls(unsigned short int _R, unsigned short int _G, unsigned short int _B);
	/// <summary>draws txt to screen at location (x,y) with color RGB</summary>
	void fa_outtextxy(float _X, float _Y, unsigned short int _R, unsigned short int _G, unsigned short int _B, const char* _Txt);
	/// <summary>ends draw to screen</summary>
	void fa_enddraw();
	/// <summary>returns *d3ddev</summary>
	IDirect3DDevice9* fa_get_d3ddev(void);
	/// <summary>initializes and prepares Direct3D</summary>
	void fa_initgraph(HWND hWnd);
	/// <summary>draws a 2d line with color RGB</summary>
	void fa_line(float _X1, float _Y1, float _X2, float _Y2, unsigned short int _R, unsigned short int _B, unsigned short int _G);
	/// <summary>draws a 2d pixel with color RGB</summary>
	void fa_pset(float _X, float _Y, unsigned short int _R, unsigned short int _B, unsigned short int _G);
	/// <summary>main rendering function</summary>
	void fa_render(void);
#ifdef __cplusplus
}
#endif