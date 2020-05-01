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
	/// <summary>cleans up Direct3D and COM</summary>
	void fa_closegraph(void);
	/// <summary>returns *d3ddev</summary>
	IDirect3DDevice9* fa_get_d3ddev(void);
	/// <summary>initializes and prepares Direct3D</summary>
	void fa_initgraph(HWND hWnd);
	/// <summary>draws a 2d line with color RGB</summary>
	void fa_line(void);
	/// <summary>draws a 2d pixel with color RGB</summary>
	void fa_pset(void);
	/// <summary>main rendering function</summary>
	void fa_render(void);
#ifdef __cplusplus
}
#endif