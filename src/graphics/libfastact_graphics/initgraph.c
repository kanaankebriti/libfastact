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

/// <summary>initializes and prepares Direct3D</summary>
__declspec(dllexport) VOID fa_initgraph(HWND hWnd)
{
    extern LPDIRECT3D9 d3d;                     // the pointer to our Direct3D interface
    extern LPDIRECT3DDEVICE9 d3ddev;            // the pointer to the device class
    D3DPRESENT_PARAMETERS d3dpp;                // create a struct to hold various device information

    d3d = Direct3DCreate9(D3D_SDK_VERSION);     // create the Direct3D interface
    fa_memset(&d3dpp, 0, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;                      // program windowed, not fullscreen
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;   // discard old frames
    d3dpp.hDeviceWindow = hWnd;                 // set the window to be used by Direct3D
    
    // create a device class using this information and the info from the d3dpp struct
    IDirect3D9_CreateDevice(d3d, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
    // turn off the 3D lighting
    IDirect3DDevice9_SetRenderState(d3ddev, D3DRS_LIGHTING, FALSE);
}