#include "stdafx.h"
#include "map.h"

MAP::MAP()
{
}

MAP::~MAP()
{
}



void MAP::createMap()
{
	_nMapWidth = _nTileCountX * _nTileSize;
	_nMapHeight = _nTileCountY * _nTileSize;

	_bIsWall = false;
	_object = TILE::OBJECT::NONE;

	_pImgMap = IMAGEMANAGER->addFrameImage("MapSample2", "resource/UI/eraser2.bmp", 768, 768, 12, 12, true, RGB(255, 0, 255));
	_pObjectImg = IMAGEMANAGER->findImage("mapTiles");

	int nNodeIndex(0);
	_vvMap.resize(_nTileCountY);


	for (int i = 0; i < _nTileCountY; i++)
	{
		for (int j = 0; j < _nTileCountX; j++)
		{
			_vvMap[i].push_back(new TILE());
			_vvMap[i][j]->passInit(j * _nTileSize, i * _nTileSize, _nTileSize, _pImgMap);
			nNodeIndex++;
		}
	}
}

void MAP::init(const char * mapName)
{
	_strMapName = mapName;

	load();

	//오브젝트는 여기서 빼주세요

}

void MAP::initBossMap(const char * mapName)
{
	_strMapName = mapName;

	loadBossMap();
}

void MAP::loadBossMap()
{
	HANDLE file;
	DWORD read;

	char strTmp[100]{};
	string strNameTmp = "";
	strNameTmp.append("mapFull02.map");
	file = CreateFile(strNameTmp.c_str(), GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, strTmp, 100, &read, NULL);
	CloseHandle(file);

	char* temp;
	const char* separator = "/"; //구분자
	char* token;

	//맵툴에는 타일 사이즈/ 타일 가로 갯수/ 타일 세로 갯수 / 파레트 셀 갯수

	token = strtok_s(strTmp, separator, &temp);

	_nTileSize = (atoi(token)) * 2;
	token = strtok_s(NULL, separator, &temp);
	_nTileCountX = (atoi(token));
	token = strtok_s(NULL, separator, &temp);
	_nTileCountY = atoi(token);


	//맵만들기
	createMap();

	int nData = _nTileCountX * _nTileCountY * 80;
	char *str = new char[nData];

	strNameTmp = "";
	strNameTmp.append("map02.map");

	file = CreateFile(strNameTmp.c_str(), GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, nData, &read, NULL);
	CloseHandle(file);


	char* tmp;
	char* tokenMap;

	tokenMap = strtok_s(str, separator, &tmp);

	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{

			//노드인덱스/주변값/벽/프레임x/프레임y			
			/*_vvMap[j][i]->setNodeIndex(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setAroundWall(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setIsWall(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setFrameX(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setFrameY(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setObject(static_cast<TILE::OBJECT>(atoi(tokenMap)));
			_vvMap[j][i]->setttingObject();
			tokenMap = strtok_s(NULL, separator, &tmp);*/
			_vvMap[j][i]->setIsWall(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setFrameX(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setFrameY(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setObjFrameX(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setObjFrameY(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setTerrainPageIndex(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setObject(static_cast<TILE::OBJECT>(atoi(tokenMap)));
			_vvMap[j][i]->setttingObject2();
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setTerrian(static_cast<TILE::TERRIAN>(atoi(tokenMap)));
			_vvMap[j][i]->setttingTerrain2();
			tokenMap = strtok_s(NULL, separator, &tmp);
		}
	}

	delete[] str;
	str = nullptr;
}



void MAP::load()
{
	HANDLE file;
	DWORD read;

	char strTmp[100]{};
	string strNameTmp = "";
	strNameTmp.append("mapFull01.map");
	file = CreateFile(strNameTmp.c_str(), GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, strTmp, 100, &read, NULL);
	CloseHandle(file);

	char* temp;
	const char* separator = "/"; //구분자
	char* token;

	//맵툴에는 타일 사이즈/ 타일 가로 갯수/ 타일 세로 갯수 / 파레트 셀 갯수

	token = strtok_s(strTmp, separator, &temp);

	_nTileSize = (atoi(token)) * 2;
	token = strtok_s(NULL, separator, &temp);
	_nTileCountX = (atoi(token));
	token = strtok_s(NULL, separator, &temp);
	_nTileCountY = atoi(token);


	//맵만들기
	createMap();

	int nData = _nTileCountX * _nTileCountY * 80;
	char *str = new char[nData];

	strNameTmp = "";
	strNameTmp.append("map01.map");

	file = CreateFile(strNameTmp.c_str(), GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, nData, &read, NULL);
	CloseHandle(file);


	char* tmp;
	char* tokenMap;

	tokenMap = strtok_s(str, separator, &tmp);

	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{

			//노드인덱스/주변값/벽/프레임x/프레임y			
			/*_vvMap[j][i]->setNodeIndex(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setAroundWall(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setIsWall(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setFrameX(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setFrameY(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setObject(static_cast<TILE::OBJECT>(atoi(tokenMap)));
			_vvMap[j][i]->setttingObject();
			tokenMap = strtok_s(NULL, separator, &tmp);*/
			_vvMap[j][i]->setIsWall(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setFrameX(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setFrameY(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setObjFrameX(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setObjFrameY(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setTerrainPageIndex(atoi(tokenMap));
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setObject(static_cast<TILE::OBJECT>(atoi(tokenMap)));
			_vvMap[j][i]->setttingObject2();
			tokenMap = strtok_s(NULL, separator, &tmp);
			_vvMap[j][i]->setTerrian(static_cast<TILE::TERRIAN>(atoi(tokenMap)));
			_vvMap[j][i]->setttingTerrain2();
			tokenMap = strtok_s(NULL, separator, &tmp);
		}
	}

	delete[] str;
	str = nullptr;
}


void MAP::release()
{
	_pImgMap = nullptr;
	_pObjectImg = nullptr;

	for (int i = 0; i < _nTileCountY; i++)
	{
		for (int j = 0; j <_nTileCountX; j++)
		{
			TILE * pTile = _vvMap.back().back();
			pTile->release();
			_vvMap.back().pop_back();
			delete pTile;
			pTile = nullptr;
		}
		_vvMap.pop_back();
	}

}

void MAP::render(HDC hdc)
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			_vvMap[j][i]->render(hdc, true);
		}
	}
}

void MAP::update()
{
	//for (int j = 0; j < _nTileCountY; j++)
	//{
	//	for (int i = 0; i < _nTileCountX; i++)
	//	{
	//		_vvMap[j][i]->update();
	//		if (_pCamera->getLeft() - 64.0f < _vvMap[j][i]->getPosX() &&
	//			_pCamera->getRight() + 64.0f > _vvMap[j][i]->getPosX() &&
	//			_pCamera->getTop() - 64.0f < _vvMap[j][i]->getPosY() &&
	//			_pCamera->getBotton() + 64.0f > _vvMap[j][i]->getPosY())
	//		{
	//			_pCamera->pushRenderObject(_vvMap[j][i]);
	//			
	//		}
	//	}
	//}
}


void MAP::settingLimitRect()
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			_vvMap[j][i]->setLimitRect(_pCamera->getLimitRect());
		}
	}
}

bool MAP::getObjectPos(vector<vector<int>>& _vvTileIndex, TILE::OBJECT object)
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			if (_vvMap[j][i]->getObject() == object)
			{
				vector<int> vPos;
				vPos.resize(2);
				vPos[0] = _vvMap[j][i]->getRectTile().left + (_vvMap[j][i]->getRectTile().right - _vvMap[j][i]->getRectTile().left) / 2;
				vPos[1] = _vvMap[j][i]->getRectTile().top + (_vvMap[j][i]->getRectTile().bottom - _vvMap[j][i]->getRectTile().top) / 2;
				_vvTileIndex.push_back(vPos);
				return true;
			}
		}
	}

	return false;
}


void MAP::deleteObject()
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			_vvMap[j][i]->setObject(TILE::OBJECT::NONE);
		}
	}
}

void MAP::drawMap(HDC hdc)
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			_vvMap[j][i]->renderBackGround(hdc);
		}
	}

}
