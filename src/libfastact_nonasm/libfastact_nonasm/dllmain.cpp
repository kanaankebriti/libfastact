// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" void __declspec(dllexport) fa_pset(IDirect3DDevice9* ddd2, IDirect3DVertexBuffer9* vertex_buffer)
{
#define D3DFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

    struct VERTEX
    {
        FLOAT x, y, z, rhw; // from the D3DFVF_XYZRHW flag
        BYTE b, g, r;       // from the D3DFVF_DIFFUSE flag
    };
    VERTEX p1 = { 10,10,0,1, 255,255,255 };

    ddd2->CreateVertexBuffer(sizeof(VERTEX), 0, D3DFVF, D3DPOOL_MANAGED, &vertex_buffer, NULL);

    void* p1_Void;                                            // the void pointer
    vertex_buffer->Lock(0, 0, &p1_Void, D3DLOCK_READONLY);    // lock the vertex buffer
    memcpy(p1_Void, &p1, sizeof(VERTEX));           // copy the vertices to the locked buffer
    vertex_buffer->Unlock();// unlock the vertex buffer
    ddd2->SetFVF(D3DFVF);
    ddd2->SetStreamSource(0, vertex_buffer, 0, sizeof(VERTEX));
    ddd2->DrawPrimitive(D3DPT_POINTLIST, 0, 1);
}