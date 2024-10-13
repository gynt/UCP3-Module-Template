# UCP3-Module-Template
Module template for UCP3 modules that have dll files.

DLL files are meant to be helper functionality, e.g. when highly performant code is required to do the actual task.
Note that lua should remain responsible for setting up code jumps, detours, modifications, and hooks.

## Bare bones (no DLL)
If you don't need the DLL part, retain description.yml and init.lua and delete the rest.
