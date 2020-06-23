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
#include <d3dx9core.h>

struct fa_point2d
{
	D3DXVECTOR2 location;
}typedef fa_point2d;

struct fa_mesh2d
{
	D3DXVECTOR2 p1, p2, p3, centroid;
}typedef fa_mesh2d;

#ifdef __cplusplus
extern "C"
{
#endif
	// graphics
	/// <summary>begins draw to screen</summary>
	VOID fa_begindraw(VOID);
	/// <summary>redefine center of screen's position</summary>
	VOID fa_center(INT xCenter, INT yCenter);
	/// <summary>draws a 2d circle based on center location and radius</summary>
	VOID fa_circle(INT _xCenter, INT _yCenter, UINT _Radius);
	/// <summary>cleans up Direct3D and COM</summary>
	VOID fa_closegraph(VOID);
	/// <summary>clears entire viewport rectangle and sets background color</summary>
	VOID fa_cls(VOID);
	/// <summary>creates then opens a new window</summary>
	HWND fa_createwindow(CONST CHAR* _Title, HINSTANCE _HInstance, UINT _Width, UINT _Height);
	/// <summary>draws catmull-rom spline</summary>
	fa_point2d* fa_drawcrs(fa_point2d* _Vertices, UINT _Size, FLOAT _Weight);
	/// <summary>draws list of points</summary>
	VOID fa_drawplist(fa_point2d* point, UINT _size);
	/// <summary>ends draw to screen</summary>
	VOID fa_enddraw(VOID);
	/// <summary>draws a 2d rectangle</summary>
	VOID fa_rectangle(FLOAT _x1, FLOAT _y1, FLOAT _x2, FLOAT _y2);
	/// <summary>returns *d3ddev</summary>
	IDirect3DDevice9* fa_get_d3ddev(VOID);
	/// <summary>initializes and prepares Direct3D</summary>
	VOID fa_initgraph(HWND hWnd);
	/// <summary>draws a 2d line</summary>
	VOID fa_line(FLOAT _X1, FLOAT _Y1, FLOAT _X2, FLOAT _Y2);
	/// <summary>meshing a point list using clarkson-delaunay algorithm</summary>
	fa_mesh2d* fa_meshing(fa_point2d* _PointList, INT _NumberOfInputPoints, INT* _NumTriangleVertices);
	/// <summary>draws txt to screen at location (x,y)</summary>
	VOID fa_outtextxy(LONG _X, LONG _Y, CONST CHAR* _Txt);
	/// <summary>draws a 2d pixel with color RGB</summary>
	VOID fa_pset(FLOAT _X, FLOAT _Y);
	/// <summary>main rendering function</summary>
	VOID fa_render(VOID);
	/// <summary>scales a 2d shape based on pointlist</summary>
	VOID fa_scale(fa_point2d* _pointlist, UINT _size, INT _factor);
	/// <summary>sets palette color for backgound</summary>
	VOID fa_setbkcolor(unsigned short int _R, unsigned short int _G, unsigned short int _B);
	/// <summary>sets palette color for text, graphics and backgound</summary>
	VOID fa_setcolor(unsigned short int _R, unsigned short int _G, unsigned short int _B);
	/// <summary>draws a triangle</summary>
	VOID fa_triangle(fa_point2d _P1, fa_point2d _P2, fa_point2d _P3);
#ifdef __cplusplus
}
#endif

#endif // !__LIBFASTACT_GRAPHICS_H__