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

	_pImgMap = IMAGEMANAGER->addFrameImage("map", "image/mapFrame.bmp", 928, 32, 29, 1, true, RGB(255, 0, 255));
	_pObjectImg = IMAGEMANAGER->findImage("mapTiles");

	int nNodeIndex(0);
	_vvMap.resize(_nTileCountY);


	for (int i = 0; i < _nTileCountY; i++)
	{
		for (int j = 0; j < _nTileCountX; j++)
		{
			_vvMap[i].push_back(new TILE());
			_vvMap[i][j]->init(j * _nTileSize, i * _nTileSize, _nTileSize, _pImgMap, nNodeIndex);
			nNodeIndex++;
		}
	}
}

void MAP::init(const char * mapName)
{
	_strMapName = mapName;

	load();
}

void MAP::load()
{
	HANDLE file;
	DWORD read;

	char strTmp[100]{};
	string strNameTmp = _strMapName;
	strNameTmp.append("Full01.map");
	file = CreateFile(strNameTmp.c_str(), GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, strTmp, 100, &read, NULL);
	CloseHandle(file);

	char* temp;
	const char* separator = "/"; //������
	char* token;

	//�������� Ÿ�� ������/ Ÿ�� ���� ����/ Ÿ�� ���� ���� / �ķ�Ʈ �� ����

	token = strtok_s(strTmp, separator, &temp);

	_nTileSize = (atoi(token));
	token = strtok_s(NULL, separator, &temp);
	_nTileCountX = (atoi(token));
	token = strtok_s(NULL, separator, &temp);
	_nTileCountY = atoi(token);


	//�ʸ����
	createMap();

	int nData = _nTileCountX * _nTileCountY * 20;
	char *str = new char[nData];

	strNameTmp = _strMapName;
	strNameTmp.append("01.map");

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

			//����ε���/�ֺ���/��/������x/������y			
			_vvMap[j][i]->setNodeIndex(atoi(tokenMap));
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
			_vvMap[j][i]->render(hdc);
		}
	}
}

void MAP::update()
{

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
