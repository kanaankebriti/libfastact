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
#ifndef __LIBFASTACT_AIRFOIL_H__
#define __LIBFASTACT_AIRFOIL_H__

fa_point2d static NACA0006[] =
{
	D3DXVECTOR2(1000,0.63),
	D3DXVECTOR2(950, 4.03),
	D3DXVECTOR2(900, 7.24),
	D3DXVECTOR2(800, 13.12),
	D3DXVECTOR2(700, 18.32),
	D3DXVECTOR2(600, 22.82),
	D3DXVECTOR2(500, 26.47),
	D3DXVECTOR2(400, 29.02),
	D3DXVECTOR2(300, 30.01),
	D3DXVECTOR2(250, 29.71),
	D3DXVECTOR2(200, 28.69),
	D3DXVECTOR2(150, 26.73),
	D3DXVECTOR2(100, 23.41),
	D3DXVECTOR2(75, 21.00),
	D3DXVECTOR2(50, 17.77),
	D3DXVECTOR2(25, 13.07),
	D3DXVECTOR2(12.5, 9.47),
	D3DXVECTOR2(0, 0),
	D3DXVECTOR2(12.5, -9.47),
	D3DXVECTOR2(25.0, -13.07),
	D3DXVECTOR2(50.0, -17.77),
	D3DXVECTOR2(75.0, -21),
	D3DXVECTOR2(100, -23.41),
	D3DXVECTOR2(200, -28.69),
	D3DXVECTOR2(300, -30.01),
	D3DXVECTOR2(400, -29.02),
	D3DXVECTOR2(500, -26.47),
	D3DXVECTOR2(600, -22.82),
	D3DXVECTOR2(700, -18.32),
	D3DXVECTOR2(800, -13.12),
	D3DXVECTOR2(900, -7.24),
	D3DXVECTOR2(950, -4.03),
	D3DXVECTOR2(1000, -0.63)
};

fa_point2d static NACA0010[] =
{
	D3DXVECTOR2(1000,1.05),
	D3DXVECTOR2(950,6.72),
	D3DXVECTOR2(900.0,12.07),
	D3DXVECTOR2(800.0,21.87),
	D3DXVECTOR2(700.0,30.53),
	D3DXVECTOR2(600.0,38.03),
	D3DXVECTOR2(500.0,44.12),
	D3DXVECTOR2(400.0,48.37),
	D3DXVECTOR2(300.0,50.02),
	D3DXVECTOR2(250.0,49.52),
	D3DXVECTOR2(200.0,47.82),
	D3DXVECTOR2(150.0,44.55),
	D3DXVECTOR2(100.0,39.02),
	D3DXVECTOR2(075.0,35.00),
	D3DXVECTOR2(50.0,29.62),
	D3DXVECTOR2(25.0,21.78),
	D3DXVECTOR2(12.5,15.78),
	D3DXVECTOR2(0,0),
	D3DXVECTOR2(12.5,-15.78),
	D3DXVECTOR2(25,-21.78),
	D3DXVECTOR2(50,-29.62),
	D3DXVECTOR2(75,-35.00),
	D3DXVECTOR2(100,-39.02),
	D3DXVECTOR2(150,-44.55),
	D3DXVECTOR2(200,-47.82),
	D3DXVECTOR2(250,-49.52),
	D3DXVECTOR2(300,-50.02),
	D3DXVECTOR2(400,-48.37),
	D3DXVECTOR2(500,-44.12),
	D3DXVECTOR2(600,-38.03),
	D3DXVECTOR2(700,-30.53),
	D3DXVECTOR2(800,-21.87),
	D3DXVECTOR2(900,-12.07),
	D3DXVECTOR2(950,-6.72),
	D3DXVECTOR2(1000,-1.05),
};

#endif // !__LIBFASTACT_AIRFOIL_H__