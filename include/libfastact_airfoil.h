﻿/*░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
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

fa_point2d static NACA0006[33] =
{
	D3DXVECTOR2(1000.0,0.63),
	D3DXVECTOR2(950.0,04.03),
	D3DXVECTOR2(900.0,07.24),
	D3DXVECTOR2(800.0,13.12),
	D3DXVECTOR2(700.0,18.32),
	D3DXVECTOR2(600.0,22.82),
	D3DXVECTOR2(500.0,26.47),
	D3DXVECTOR2(400.0,29.02),
	D3DXVECTOR2(300.0,30.01),
	D3DXVECTOR2(250.0,29.71),
	D3DXVECTOR2(200.0,28.69),
	D3DXVECTOR2(150.0,26.73),
	D3DXVECTOR2(100.0,23.41),
	D3DXVECTOR2(75.00,21.00),
	D3DXVECTOR2(50.00,17.77),
	D3DXVECTOR2(25.00,13.07),
	D3DXVECTOR2(12.50,09.47),
	D3DXVECTOR2(0,0),
	D3DXVECTOR2(12.50,-9.47),
	D3DXVECTOR2(25.00,-13.07),
	D3DXVECTOR2(50.00,-17.77),
	D3DXVECTOR2(75.00,-21.00),
	D3DXVECTOR2(100.0,-23.41),
	D3DXVECTOR2(200.0,-28.69),
	D3DXVECTOR2(300.0,-30.01),
	D3DXVECTOR2(400.0,-29.02),
	D3DXVECTOR2(500.0,-26.47),
	D3DXVECTOR2(600.0,-22.82),
	D3DXVECTOR2(700.0,-18.32),
	D3DXVECTOR2(800.0,-13.12),
	D3DXVECTOR2(900.0,-07.24),
	D3DXVECTOR2(950.0,-04.03),
	D3DXVECTOR2(1000.0,-0.63)
};

fa_point2d static NACA0010[35] =
{
	D3DXVECTOR2(1000.0,1.05),
	D3DXVECTOR2(950.0,06.72),
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
	D3DXVECTOR2(50.00,29.62),
	D3DXVECTOR2(25.00,21.78),
	D3DXVECTOR2(12.50,15.78),
	D3DXVECTOR2(0,0),
	D3DXVECTOR2(12.50,-15.78),
	D3DXVECTOR2(25.00,-21.78),
	D3DXVECTOR2(50.00,-29.62),
	D3DXVECTOR2(75.00,-35.00),
	D3DXVECTOR2(100.0,-39.02),
	D3DXVECTOR2(150.0,-44.55),
	D3DXVECTOR2(200.0,-47.82),
	D3DXVECTOR2(250.0,-49.52),
	D3DXVECTOR2(300.0,-50.02),
	D3DXVECTOR2(400.0,-48.37),
	D3DXVECTOR2(500.0,-44.12),
	D3DXVECTOR2(600.0,-38.03),
	D3DXVECTOR2(700.0,-30.53),
	D3DXVECTOR2(800.0,-21.87),
	D3DXVECTOR2(900.0,-12.07),
	D3DXVECTOR2(950.0,-06.72),
	D3DXVECTOR2(1000.0,-1.05),
};

fa_point2d static NACA2414[61] =
{
	D3DXVECTOR2(1000.0,01.47),
	D3DXVECTOR2(997.39,02.10),
	D3DXVECTOR2(989.29,03.96),
	D3DXVECTOR2(975.87,07.00),
	D3DXVECTOR2(957.29,11.12),
	D3DXVECTOR2(933.72,16.20),
	D3DXVECTOR2(905.42,22.07),
	D3DXVECTOR2(872.67,28.57),
	D3DXVECTOR2(835.82,35.52),
	D3DXVECTOR2(795.27,42.74),
	D3DXVECTOR2(751.43,50.04),
	D3DXVECTOR2(704.80,57.23),
	D3DXVECTOR2(655.86,64.12),
	D3DXVECTOR2(605.15,70.53),
	D3DXVECTOR2(553.24,76.29),
	D3DXVECTOR2(500.69,81.20),
	D3DXVECTOR2(448.08,85.12),
	D3DXVECTOR2(395.98,87.87),
	D3DXVECTOR2(344.54,89.13),
	D3DXVECTOR2(294.82,88.66),
	D3DXVECTOR2(247.40,86.45),
	D3DXVECTOR2(202.85,82.55),
	D3DXVECTOR2(161.69,77.07),
	D3DXVECTOR2(124.40,70.14),
	D3DXVECTOR2(91.410,61.98),
	D3DXVECTOR2(63.100,52.81),
	D3DXVECTOR2(39.770,42.89),
	D3DXVECTOR2(21.650,32.45),
	D3DXVECTOR2(8.9200,21.71),
	D3DXVECTOR2(1.6900,10.85),
	D3DXVECTOR2(0,0),
	D3DXVECTOR2(3.7900,-10.31),
	D3DXVECTOR2(12.930,-19.56),
	D3DXVECTOR2(27.300,-27.70),
	D3DXVECTOR2(46.690,-34.71),
	D3DXVECTOR2(70.870,-40.54),
	D3DXVECTOR2(99.570,-45.16),
	D3DXVECTOR2(132.46,-48.58),
	D3DXVECTOR2(169.18,-50.82),
	D3DXVECTOR2(209.37,-51.95),
	D3DXVECTOR2(252.60,-52.08),
	D3DXVECTOR2(298.44,-51.33),
	D3DXVECTOR2(346.44,-49.87),
	D3DXVECTOR2(396.11,-47.87),
	D3DXVECTOR2(447.39,-45.37),
	D3DXVECTOR2(499.31,-42.32),
	D3DXVECTOR2(551.29,-38.86),
	D3DXVECTOR2(602.76,-35.16),
	D3DXVECTOR2(653.16,-31.32),
	D3DXVECTOR2(701.94,-27.45),
	D3DXVECTOR2(748.57,-23.65),
	D3DXVECTOR2(792.52,-19.98),
	D3DXVECTOR2(833.31,-16.50),
	D3DXVECTOR2(870.48,-13.28),
	D3DXVECTOR2(903.60,-10.35),
	D3DXVECTOR2(932.30,-07.76),
	D3DXVECTOR2(956.26,-05.57),
	D3DXVECTOR2(975.18,-03.81),
	D3DXVECTOR2(988.86,-02.52),
	D3DXVECTOR2(997.13,-01.73),
	D3DXVECTOR2(1000.0,-01.47)
};

#endif // !__LIBFASTACT_AIRFOIL_H__