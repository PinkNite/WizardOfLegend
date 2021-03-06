// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <functional>
#include <queue>
#include <list>
#include <algorithm>
#include <stack>
using namespace std;

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "iniDataManager.h"
#include "soundManager.h"
#include "sceneManager.h"
#include "keyAniManager.h"
#include "utils.h"
#include "txtData.h"
#include "aStar.h"
#include "FrameWork.h"

using namespace BRAVO_UTIL;

//====================================
// ## 18.11.20 ## - 디파인문 -
//====================================

#define WINNAME (LPCTSTR)(TEXT("Pink Nite"))
#define WINSTARTX 50		//윈도우 시작 X좌표 
#define WINSTARTY 50		//윈도우 시작 Y좌표
#define WINSIZEX 1600		//윈도우 가로크기
#define WINSIZEY 900		//윈도우 세로크기
#define WINSTYLE WS_CAPTION | WS_SYSMENU
#define	CAMERASIZEX	2480
#define	CAMERASIZEY	2480

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define KEYANIMANAGER keyAniManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define INIDATA iniDataManager::getSingleton()

//맵툴 좌표계 탐색용
//벽이 어디에 있는지
#define	MAP_TOP				0x01
#define	MAP_BOTTOM			0x02
#define	MAP_LEFT			0x04
#define	MAP_RIGHT			0x08
#define	MAP_LEFT_TOP		0x10
#define	MAP_RIGHT_TOP		0x20
#define	MAP_LEFT_BOTTOM		0x40
#define	MAP_RIGHT_BOTTOM	0x80


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

#define SAFE_DELETE(p) {if(p) { delete(p); (p) = NULL; }}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); }}
#define SAFE_DELETE_ARRAY(p) {if(p) { delete[](p); (p) = NULL;}}

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;
extern BOOL _leftButtonDown;

//bool	operator<(const ASTAR::TILENODE& sDstTile, const ASTAR::TILENODE& sSrcTile) { return sDstTile.nPathCost > sSrcTile.nPathCost; }
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
