// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// UCP3 and lua header files are available after loading dependencies.
// Run this in the developer command prompt (tools => command line): 
// msbuild /t:restore
#include "ucp3.hpp"
#include "lua.hpp"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // Generally nothing is required in the DllMain. Lua uses its own function to initialize (see below). 
        // For development purposes, let's log when the dll is attached to the program.
        ucp_log(ucp_NamedVerbosity::Verbosity_INFO, "$projectname$ attached");
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// Note that exporting the function with C style naming is required because lua is written in C and uses C style naming for importing dlls.
extern "C" __declspec(dllexport) int luaopen_$safeprojectname$(lua_State * L) {

    // Log here so you know your dll is being loaded into the lua side of your module.
    ucp_log(ucp_NamedVerbosity::Verbosity_INFO, "$projectname$ is being loaded by a require('$safeprojectname$.dll') in the module's init.lua");

    // Generally, it is advised to return a table that exposes the functionality of this dll and callback functions to the lua side.
    // Lua stack: []

    // Create the table. Lua stack after this call: [ table, ]
    lua_newtable(L);
    // Create a value to be put in the table, e.g. a version string. Lua stack after this call: [ table, string, ]
    lua_pushstring(L, "0.0.1");
    // Set the version field in the table. Lua stack after this call: [ table, ]
    lua_setfield(L, -2, "version"); // set the field of the object at stack location -2 to the value at the top of the stack (location -1).

    // Return the table to the lua side. The 1 means we return a single value from the stack to the caller
    return 1;
}
