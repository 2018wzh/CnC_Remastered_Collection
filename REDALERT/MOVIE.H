//
// Copyright 2020 Electronic Arts Inc.
//
// TiberianDawn.DLL and RedAlert.dll and corresponding source code is free 
// software: you can redistribute it and/or modify it under the terms of 
// the GNU General Public License as published by the Free Software Foundation, 
// either version 3 of the License, or (at your option) any later version.

// TiberianDawn.DLL and RedAlert.dll and corresponding source code is distributed 
// in the hope that it will be useful, but with permitted additional restrictions 
// under Section 7 of the GPL. See the GNU General Public License in LICENSE.TXT 
// distributed with this program. You should have received a copy of the 
// GNU General Public License along with permitted additional restrictions 
// with this program. If not, see https://github.com/electronicarts/CnC_Remastered_Collection

#ifndef _MPGMOVIE_H_
#define _MPGMOVIE_H_
/****************************************************************************
*
* FILE
*     MpgMovie.h
*
* DESCRIPTION
*     Movie playback using DirectShow Multimedia streaming and DirectDraw
*
* PROGRAMMER
*     Denzil E. Long, Jr.
*
* DATE
*     May 27, 1998
*
****************************************************************************/

#include <windows.h>
#include <ddraw.h>

 
#ifdef _MSC_VER //用于判断是否是 vs 平台
    #define CROSS_PLATFORM_HIDDEN_API
	#ifdef MPGEXPORT	
        #define CROSS_PLATFORM_API __declspec(dllexport)
    #else
        #define CROSS_PLATFORM_API __declspec(dllimport)
    #endif
#else // 说明是 OSX 或者 Linux
    #define CROSS_PLATFORM_API __attribute((visibility("default"))) // 明确指示，这个函数在动态库中可见
    #define CROSS_PLATFORM_HIDDEN_API __attribute((visibility("hidden"))) // 明确指示，这个函数在动态库中不可见
#endif

#define DLLCALL CROSS_PLATFORM_API

typedef enum
	{
	MPGCMD_ERROR = -1,
	MPGCMD_INIT = 0,
	MPGCMD_CLEANUP,
	MPGCMD_PALETTE,
	MPGCMD_UPDATE
	} MPG_CMD;

typedef enum
	{
	MPGRES_QUIT = -1,
	MPGRES_CONTINUE = 0,
	MPGRES_LOSTFOCUS,
	} MPG_RESPONSE;

typedef MPG_RESPONSE (far __stdcall *LPMPGCALLBACK)(MPG_CMD cmd, LPVOID data, LPVOID user);

extern "C"
	{
	DLLCALL void __stdcall MpgPlay(const char* name, IDirectDraw* dd,
		IDirectDrawSurface* surface, RECT* dstRect);
	DLLCALL void __stdcall MpgPause(void);
	DLLCALL void __stdcall MpgResume(void);
	DLLCALL void __stdcall MpgSetCallback(LPMPGCALLBACK callback, LPVOID user);
	}

#endif // _MPGMOVIE_H_
