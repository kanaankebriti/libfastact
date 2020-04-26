macro interface32 name
{
	struc name
	{
        .vtbl dd ?
        virtual at 0
	}

iend fix end virtual}

macro COMCall object,method,[arg]
{
common
	if ~ arg eq
reverse
	push arg
common
	end if
	mov  eax,[object#.#vtbl]
	push rax
	mov  eax,[eax]
	call QWORD [eax+object#.#method]
}

D3D_SDK_VERSION equ 31

interface32 IDirect3D9

        .QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.RegisterSoftwareDevice dd ?
    	.GetAdapterCount dd ?
    	.GetAdapterIdentifier dd ?
    	.GetAdapterModeCount dd ?
    	.EnumAdapterModes dd ?
    	.GetAdapterDisplayMode dd ?
    	.CheckDeviceType dd ?
    	.CheckDeviceFormat dd ?
    	.CheckDeviceMultiSampleType dd ?
    	.CheckDepthStencilMatch dd ?
    	.CheckDeviceFormatConversion dd ?
    	.GetDeviceCaps dd ?
    	.GetAdapterMonitor dd ?
    	.CreateDevice dd ?

iend

interface32 IDirect3DDevice9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.TestCooperativeLevel dd ?
    	.GetAvailableTextureMem dd ?
    	.EvictManagedResources dd ?
    	.GetDirect3D dd ?
    	.GetDeviceCaps dd ?
	.GetDisplayMode dd ?
	.GetCreationParameters dd ?
	.SetCursorProperties dd ?
	.SetCursorPosition dd ?
	.ShowCursor dd ?
	.CreateAdditionalSwapChain dd ?
	.GetSwapChain dd ?
	.GetNumberOfSwapChains dd ?
    	.Reset dd ?
    	.Present dd ?
    	.GetBackBuffer dd ?
    	.GetRasterStatus dd ?
	.SetDialogBoxMode dd ?
	.SetGammaRamp dd ?
	.GetGammaRamp dd ?
	.CreateTexture dd ?
	.CreateVolumeTexture dd ?
	.CreateCubeTexture dd ?
	.CreateVertexBuffer dd ?
	.CreateIndexBuffer dd ?
	.CreateRenderTarget dd ?
    	.CreateDepthStencilSurface dd ?
    	.UpdateSurface dd ?
	.UpdateTexture dd ?
    	.GetRenderTargetData dd ?
    	.GetFrontBufferData dd ?
    	.StretchRect dd ?
    	.ColorFill dd ?
    	.CreateOffscreenPlainSurface dd ?
    	.SetRenderTarget dd ?
    	.GetRenderTarget dd ?
    	.SetDepthStencilSurface dd ?
    	.GetDepthStencilSurface dd ?
    	.BeginScene dd ?
    	.EndScene dd ?
    	.Clear dd ?
    	.SetTransform dd ?
    	.GetTransform dd ?
    	.MultiplyTransform dd ?
    	.SetViewport dd ?
    	.GetViewport dd ?
    	.SetMaterial dd ?
    	.GetMaterial dd ?
    	.SetLight dd ?
    	.GetLight dd ?
	.LightEnable dd ?
	.GetLightEnable dd ?
	.SetClipPlane dd ?
	.GetClipPlane dd ?
	.SetRenderState dd ?
	.GetRenderState dd ?
	.CreateStateBlock dd ?
	.BeginStateBlock dd ?
	.EndStateBlock dd ?
	.SetClipStatus dd ?
	.GetClipStatus dd ?
	.GetTexture dd ?
	.SetTexture dd ?
    	.GetTextureStageState dd ?
	.SetTextureStageState dd ?
    	.GetSamplerState dd ?
    	.SetSamplerState dd ?
    	.ValidateDevice dd ?
    	.SetPaletteEntries dd ?
    	.GetPaletteEntries dd ?
    	.SetCurrentTexturePalette dd ?
    	.GetCurrentTexturePalette dd ?
    	.SetScissorRect dd ?
    	.GetScissorRect dd ?
    	.SetSoftwareVertexProcessing dd ?
    	.GetSoftwareVertexProcessing dd ?
    	.SetNPatchMode dd ?
    	.GetNPatchMode dd ?
    	.DrawPrimitive dd ?
    	.DrawIndexedPrimitive dd ?
	.DrawPrimitiveUP dd ?
	.DrawIndexedPrimitiveUP dd ?
	.ProcessVertices dd ?
	.CreateVertexDeclaration dd ?
	.SetVertexDeclaration dd ?
	.GetVertexDeclaration dd ?
	.SetFVF dd ?
	.GetFVF dd ?
	.CreateVertexShader dd ?
	.SetVertexShader dd ?
	.GetVertexShader dd ?
	.SetVertexShaderConstantF dd ?
	.GetVertexShaderConstantF dd ?
	.SetVertexShaderConstantI dd ?
	.GetVertexShaderConstantI dd ?
	.SetVertexShaderConstantB dd ?
	.GetVertexShaderConstantB dd ?
	.SetStreamSource dd ?
	.GetStreamSource dd ?
    	.SetStreamSourceFreq dd ?
    	.GetStreamSourceFreq dd ?
    	.SetIndices dd ?
    	.GetIndices dd ?
    	.CreatePixelShader dd ?
    	.SetPixelShader dd ?
    	.GetPixelShader dd ?
    	.SetPixelShaderConstantF dd ?
    	.GetPixelShaderConstantF dd ?
    	.SetPixelShaderConstantI dd ?
    	.GetPixelShaderConstantI dd ?
    	.SetPixelShaderConstantB dd ?
    	.GetPixelShaderConstantB dd ?
    	.DrawRectPatch dd ?
    	.DrawTriPatch dd ?
    	.DeletePatch dd ?
    	.CreateQuery dd ?

iend

interface32 IDirect3DStateBlock9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.Capture dd ?
    	.Apply dd ?

iend

interface32 IDirect3DSwapChain9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.Present dd ?
    	.GetFrontBufferData dd ?
    	.GetBackBuffer dd ?
    	.GetRasterStatus dd ?
    	.GetDisplayMode dd ?
    	.GetDevice dd ?
    	.GetPresentParameters dd ?

iend

interface32 IDirect3DResource9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.SetPrivateData dd ?
    	.GetPrivateData dd ?
    	.FreePrivateData dd ?
    	.SetPriority dd ?
    	.GetPriority dd ?
    	.PreLoad dd ?
    	.GetType dd ?

iend

interface32 IDirect3DVertexDeclaration9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.GetDeclaration dd ?

iend

interface32 IDirect3DVertexShader9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.GetFunction dd ?

iend

interface32 IDirect3DPixelShader9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.GetFunction dd ?

iend

interface32 IDirect3DBaseTexture9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.SetPrivateData dd ?
    	.GetPrivateData dd ?
    	.FreePrivateData dd ?
    	.SetPriority dd ?
    	.GetPriority dd ?
    	.PreLoad dd ?
    	.GetType dd ?
    	.SetLOD dd ?
    	.GetLOD dd ?
    	.GetLevelCount dd ?
    	.SetAutoGenFilterType dd ?
    	.GetAutoGenFilterType dd ?
    	.GenerateMipSubLevels dd ?

iend

interface32 IDirect3DTexture9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.SetPrivateData dd ?
    	.GetPrivateData dd ?
    	.FreePrivateData dd ?
    	.SetPriority dd ?
    	.GetPriority dd ?
    	.PreLoad dd ?
    	.GetType dd ?
    	.SetLOD dd ?
    	.GetLOD dd ?
    	.GetLevelCount dd ?
    	.SetAutoGenFilterType dd ?
    	.GetAutoGenFilterType dd ?
    	.GenerateMipSubLevels dd ?
    	.GetLevelDesc dd ?
    	.GetSurfaceLevel dd ?
    	.LockRect dd ?
    	.UnlockRect dd ?
    	.AddDirtyRect dd ?

iend

interface32 IDirect3DVolumeTexture9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.SetPrivateData dd ?
    	.GetPrivateData dd ?
    	.FreePrivateData dd ?
    	.SetPriority dd ?
    	.GetPriority dd ?
    	.PreLoad dd ?
    	.GetType dd ?
    	.SetLOD dd ?
    	.GetLOD dd ?
    	.GetLevelCount dd ?
    	.SetAutoGenFilterType dd ?
    	.GetAutoGenFilterType dd ?
    	.GenerateMipSubLevels dd ?
    	.GetLevelDesc dd ?
    	.GetVolumeLevel dd ?
    	.LockBox dd ?
    	.UnlockBox dd ?
    	.AddDirtyBox dd ?

iend

interface32 IDirect3DCubeTexture9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.SetPrivateData dd ?
    	.GetPrivateData dd ?
    	.FreePrivateData dd ?
    	.SetPriority dd ?
    	.GetPriority dd ?
    	.PreLoad dd ?
    	.GetType dd ?
    	.SetLOD dd ?
    	.GetLOD dd ?
    	.GetLevelCount dd ?
    	.SetAutoGenFilterType dd ?
    	.GetAutoGenFilterType dd ?
    	.GenerateMipSubLevels dd ?
    	.GetLevelDesc dd ?
    	.GetCubeMapSurface dd ?
    	.LockRect dd ?
    	.UnlockRect dd ?
    	.AddDirtyRect dd ?

iend

interface32 IDirect3DVertexBuffer9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

	.GetDevice dd ?
	.SetPrivateData dd ?
	.GetPrivateData dd ?
	.FreePrivateData dd ?
	.SetPriority dd ?
	.GetPriority dd ?
	.PreLoad dd ?
	.GetType dd ?
	.Lock dd ?
	.Unlock dd ?
	.GetDesc dd ?

iend

interface32 IDirect3DIndexBuffer9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

	.GetDevice dd ?
    	.SetPrivateData dd ?
    	.GetPrivateData dd ?
    	.FreePrivateData dd ?
    	.SetPriority dd ?
    	.GetPriority dd ?
    	.PreLoad dd ?
    	.GetType dd ?
    	.Lock dd ?
    	.Unlock dd ?
    	.GetDesc dd ?

iend

interface32 IDirect3DSurface9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.SetPrivateData dd ?
    	.GetPrivateData dd ?
    	.FreePrivateData dd ?
    	.SetPriority dd ?
    	.GetPriority dd ?
    	.PreLoad dd ?
    	.GetType dd ?
    	.GetContainer dd ?
    	.GetDesc dd ?
    	.LockRect dd ?
    	.UnlockRect dd ?
    	.GetDC dd ?
    	.ReleaseDC dd ?

iend

interface32 IDirect3DVolume9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

    	.GetDevice dd ?
    	.SetPrivateData dd ?
    	.GetPrivateData dd ?
    	.FreePrivateData dd ?
    	.GetContainer dd ?
    	.GetDesc dd ?
    	.LockBox dd ?
    	.UnlockBox dd ?

iend

interface32 IDirect3DQuery9

    	.QueryInterface dd ?
    	.AddRef dd ?
    	.Release dd ?

	.GetDevice dd ?
	.GetType dd ?
	.GetDataSize dd ?
	.Issue dd ?
	.GetData dd ?

iend

D3DSPD_IUNKNOWN=0x00000001

D3DCREATE_FPU_PRESERVE=0x00000002
D3DCREATE_MULTITHREADED=0x00000004

D3DCREATE_PUREDEVICE=0x00000010
D3DCREATE_SOFTWARE_VERTEXPROCESSING=0x00000020
D3DCREATE_HARDWARE_VERTEXPROCESSING=0x00000040
D3DCREATE_MIXED_VERTEXPROCESSING=0x00000080

D3DCREATE_DISABLE_DRIVER_MANAGEMENT=0x00000100
D3DCREATE_ADAPTERGROUP_DEVICE=0x00000200

D3DADAPTER_DEFAULT=0

D3DENUM_WHQL_LEVEL=0x00000002

D3DPRESENT_BACK_BUFFERS_MAX=3

D3DSGR_NO_CALIBRATION=0x00000000
D3DSGR_CALIBRATE=0x00000001

D3DCURSOR_IMMEDIATE_UPDATE=0x00000001

D3DPRESENT_DONOTWAIT=0x00000001
D3DPRESENT_LINEAR_CONTENT=0x00000002

_FACD3D=0x0876

macro MAKE_D3DHRESULT name,code {

	name=(1 shl 31) or (_FACD3D shl 16) or (code)

}

macro MAKE_D3DSTATUS name,code {

	name=(0 shl 31) or (_FACD3D shl 16) or (code)

}

D3D_OK=0

MAKE_D3DHRESULT D3DERR_WRONGTEXTUREFORMAT,2072
MAKE_D3DHRESULT D3DERR_UNSUPPORTEDCOLOROPERATION,2073
MAKE_D3DHRESULT D3DERR_UNSUPPORTEDCOLORARG,2074
MAKE_D3DHRESULT D3DERR_UNSUPPORTEDALPHAOPERATION,2075
MAKE_D3DHRESULT D3DERR_UNSUPPORTEDALPHAARG,2076
MAKE_D3DHRESULT D3DERR_TOOMANYOPERATIONS,2077
MAKE_D3DHRESULT D3DERR_CONFLICTINGTEXTUREFILTER,2078
MAKE_D3DHRESULT D3DERR_UNSUPPORTEDFACTORVALUE,2079
MAKE_D3DHRESULT D3DERR_CONFLICTINGRENDERSTATE,2081
MAKE_D3DHRESULT D3DERR_UNSUPPORTEDTEXTUREFILTER,2082
MAKE_D3DHRESULT D3DERR_CONFLICTINGTEXTUREPALETTE,2086
MAKE_D3DHRESULT D3DERR_DRIVERINTERNALERROR,2087

MAKE_D3DHRESULT D3DERR_NOTFOUND,2150
MAKE_D3DHRESULT D3DERR_MOREDATA,2151
MAKE_D3DHRESULT D3DERR_DEVICELOST,2152
MAKE_D3DHRESULT D3DERR_DEVICENOTRESET,2153
MAKE_D3DHRESULT D3DERR_NOTAVAILABLE,2154
MAKE_D3DHRESULT D3DERR_OUTOFVIDEOMEMORY,380
MAKE_D3DHRESULT D3DERR_INVALIDDEVICE,2155
MAKE_D3DHRESULT D3DERR_INVALIDCALL,2156
MAKE_D3DHRESULT D3DERR_DRIVERINVALIDCALL,2157
MAKE_D3DHRESULT D3DERR_WASSTILLDRAWING,540
MAKE_D3DSTATUS  D3DOK_NOAUTOGEN,2159
