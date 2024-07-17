#pragma once
#include <Windows.h>
#include <psapi.h>
#include <stdio.h>
#include <tchar.h>


void printProcessInfo(DWORD ProcessId);
int enumerate();