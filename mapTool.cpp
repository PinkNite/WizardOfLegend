#include "stdafx.h"
#include "mapTool.h"

MAPTOOL::MAPTOOL():
	_nTileSize(0),
	_nTileCountX(0),
	_nTileCountY(0),
	_nMapWidth(0),
	_nMapHeight(0),
	_nPalletSellCount(0),
	_arFrameNum{},
	_nCurrentTileX(0),
	_nCurrentTileY(0),
	_pImgMap(nullptr)
{
}

MAPTOOL::~MAPTOOL()
{
}

void MAPTOOL::createMap()
{
	//���η� �׸��� �״��� ���η� �ϳ���
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

void MAPTOOL::setResizeNodeIndex()
{
	int nIndex(0);
	for (int i = 0; i < _nTileCountY; i++)
	{
		for (int j = 0; j < _nTileCountX; j++)
		{
			_vvMap[i][j]->setNodeIndex(nIndex);
			nIndex++;
		}
	}
}

void MAPTOOL::init(int nTileCountX, int nTileCountY, int nTileSize)
{
	initFrameBit();

	_nTileCountX = nTileCountX;
	_nTileCountY = nTileCountY;
	_nTileSize = nTileSize;

	_nMapWidth = _nTileCountX * _nTileSize;
	_nMapHeight = _nTileCountY * _nTileSize;

	_nCurrentTileX = 28;
	_nCurrentTileY = 0;
	_bIsWall = false;
	_object = TILE::OBJECT::NONE;

	_pImgMap = IMAGEMANAGER->addFrameImage("map", "image/mapFrame.bmp", 928, 32, 29, 1, true, RGB(255, 0, 255));
	_pObjectImg = IMAGEMANAGER->findImage("mapTiles");
	
	createMap();
}

void MAPTOOL::release()
{
	_pImgMap = nullptr;

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

void MAPTOOL::render(HDC hdc)
{

	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			_vvMap[j][i]->render(hdc);
		}
	}
	//for (int j = 0; j < _nTileCountY; j++)
	//{
	//	for (int i = 0; i < _nTileCountX; i++)
	//	{
	//		char str[32];
	//		sprintf_s(str, "%d,%d", i, j);
	//		TextOut(hdc, _vvMap[j][i]->getRectTile().left , _vvMap[j][i]->getRectTile().top , str, strlen(str));
	//	}
	//}

	
}

void MAPTOOL::update()
{
	_nVertical = 0;
	_nHorizontal = 0;

	if (KEYMANAGER->isStayKeyDown(VK_UP))	
	{
		//_pCamera->moveUp(10);
		_nVertical += 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))	
	{
		//_pCamera->moveDown(10);
		_nVertical -= 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))	
	{
		//_pCamera->moveLeft(10);
		_nHorizontal += 10;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		//_pCamera->moveRight(10);
		_nHorizontal -= 10;
	}


	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			_vvMap[j][i]->move(_nVertical, _nHorizontal);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && _ptMouse.x < 900) {
		for (int j = 0; j < _nTileCountY; j++)
		{
			for (int i = 0; i < _nTileCountX; i++)
			{
				TILE* pTile = _vvMap[j][i];
				
				if (PtInRect(&(pTile->getRectTile()),_ptMouse))
				{
					pTile->settingTile(_nCurrentTileX, _nCurrentTileY, _bIsWall,_object);
				}
			}
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		readjustMap();
	}
}

void MAPTOOL::initFrameBit()
{
	_arFrameNum[0]		= 0;
	_arFrameNum[19]		= 1;
	_arFrameNum[76]		= 2;
	_arFrameNum[44]		= 3;
	_arFrameNum[131]	= 4;
	_arFrameNum[35]		= 5;
	_arFrameNum[28]		= 6;
	_arFrameNum[140]	= 7;
	_arFrameNum[67]		= 8;
	_arFrameNum[16]		= 9;
	_arFrameNum[64]		= 10;
	_arFrameNum[32]		= 11;
	_arFrameNum[12]		= 12;
	_arFrameNum[11]		= 13;
	_arFrameNum[14]		= 14;
	_arFrameNum[7]		= 15;
	_arFrameNum[13]		= 16;
	_arFrameNum[15]		= 17;
	_arFrameNum[10]		= 18;
	_arFrameNum[6]		= 19;
	_arFrameNum[9]		= 20;
	_arFrameNum[5]		= 21;
	_arFrameNum[8]		= 22;
	_arFrameNum[2]		= 23;
	_arFrameNum[4]		= 24;
	_arFrameNum[1]		= 25;
	_arFrameNum[3]		= 26;
	_arFrameNum[12]		= 27;
	_arFrameNum[139]	= 28;
}

string MAPTOOL::setSaveMapTool()
{
	//�������� Ÿ�� ������/ Ÿ�� ���� ����/ Ÿ�� ���� ���� / �ķ�Ʈ �� ����
	string strTmp = "";
	strTmp.append(to_string(_nTileSize));
	strTmp.append("/");
	strTmp.append(to_string(_nTileCountX));
	strTmp.append("/");
	strTmp.append(to_string(_nTileCountY));
	strTmp.append("/");

	return strTmp;
}

string MAPTOOL::makeSaveMap()
{
	string strTmp = "";
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			strTmp.append(_vvMap[j][i]->makeSaveString());
		}
	}

	return strTmp;
}

void MAPTOOL::mapResize(int nTileCountX, int nTileCountY)
{
	if (_nTileCountX <= nTileCountX)
	{
		//�߰��ϸ� �ȴ�!!
		int nOffset = nTileCountX - _nTileCountX;
		
		//int nLeft = _vvMap[0][_nTileCountX - 1]->getRectTile().right;

		for (int j = 0; j < _nTileCountY; j++)
		{
			for (int i = 0; i < nOffset; i++)
			{
				int nLeft = _vvMap[j].back()->getRectTile().right;
				int nTop = _vvMap[j].back()->getRectTile().top;
				_vvMap[j].push_back(new TILE());
				TILE* pTile = _vvMap[j].back();
				pTile->init((i+1)*nLeft, nTop, _nTileSize, _pImgMap, 0);
				pTile = nullptr;
			}
		}

	}
	else
	{
		//�����Ѵ�!!!
		int nOffset = _nTileCountX - nTileCountX;

		for (int j = 0; j < _nTileCountY; j++)
		{
			for (int i = 0; i < nOffset; i++)
			{
				TILE* pTile = _vvMap[j].back();
				pTile->release();
				_vvMap[j].pop_back();
				delete pTile;
				pTile = nullptr;
			}
		}
	}
	_nTileCountX = nTileCountX;

	if (_nTileCountY <= nTileCountY)
	{
		//�߰��ϸ� �ȴ�.

		int nOffset = nTileCountY - _nTileCountY;

		int nLeft = _vvMap[_nTileCountY - 1].front()->getRectTile().left;
		int nTop = _vvMap[_nTileCountY - 1].front()->getRectTile().bottom;

		for (int j = 0; j < nOffset; j++)
		{
			vector<TILE*> vMapLine;
			for (int i = 0; i < _nTileCountX; i++)
			{
				vMapLine.push_back(new TILE());
				TILE* pTile = vMapLine.back();
				pTile->init((i )*_nTileSize + nLeft,(j+1)* nTop, _nTileSize, _pImgMap, 0);
				pTile = nullptr;
			}
			_vvMap.push_back(vMapLine);
		}
	}
	else
	{
		//�����Ѵ�.
		int nOffset = _nTileCountY - nTileCountY;

		for (int j = 0; j < nOffset; j++)
		{
			for (int i = 0; i < _nTileCountX; i++)
			{
				TILE* pTile = _vvMap.back().back();
				pTile->release();
				_vvMap.back().pop_back();
				delete pTile;
				pTile = nullptr;
			}
			_vvMap.pop_back();
		}
	}
	_nTileCountY = nTileCountY;
	setResizeNodeIndex();
}

void MAPTOOL::readjustMap()
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			//���̸� �˻�
			if (_vvMap[j][i]->getIsWall()) {
				unsigned int nFrame(0);
				
				if (j > 0)
				{
					//���� Ž�� ����
					if (_vvMap[j-1][i]->getIsWall())
					{
						nFrame |= TOP;
					}
				}

				if (j < _nTileCountY - 1)
				{
					//�Ʒ� Ž�� ����
					if (_vvMap[j + 1][i]->getIsWall())
					{
						nFrame |= BOTTOM;
					}
					
				}

				if (i > 0)
				{
					//���� Ž�� ����
					if (_vvMap[j][i - 1]->getIsWall())
					{
						nFrame |= LEFT;
					}
				}

				if (i < _nTileCountX - 1)
				{
					//���� Ž�� ����
					
					if (_vvMap[j][i + 1]->getIsWall())
					{
						nFrame |= RIGHT;
					}
				}

				//if (j > 0 && i > 0)
				//{
				//	//�»� Ž�� ����
				//	if (_vvMap[j-1][i-1]->getIsWall())
				//	{
				//		nFrame |= LEFT_TOP;
				//	}
				//}

				//if (j > 0 && i < _nTileCountX - 1)
				//{
				//	//��� Ž�� ����
				//	if (_vvMap[j - 1][i + 1]->getIsWall())
				//	{
				//		nFrame |= RIGHT_TOP;
				//	}
				//}

				//if (j < _nTileCountY - 1 && i > 0)
				//{
				//	//���� Ž�� ����
				//	if (_vvMap[j + 1][i - 1]->getIsWall())
				//	{
				//		nFrame |= LEFT_BOTTOM;
				//	}
				//}

				//if (j < _nTileCountY - 1 && i < _nTileCountX - 1)
				//{
				//	//���� Ž�� ����
				//	if (_vvMap[j + 1][i + 1]->getIsWall())
				//	{
				//		nFrame |= RIGHT_BOTTOM;
				//	}
				//}
				
				_vvMap[j][i]->readjustWall((int)nFrame, _arFrameNum[(int)nFrame], 0);
			}
		}
	}
}

void MAPTOOL::save()
{
	//���̺�� ũ�� �ΰ������Ѵ�.
	//���� ������ �ִ� �����Ϳ�
	//Ÿ�ϵ鿡 �ִ� �����ͷ� �����ؼ� �����Ѵ�.
	//�������� Ÿ�� ������/ Ÿ�� ���� ����/ Ÿ�� ���� ���� / �ķ�Ʈ �� ����
	//Ÿ�Ͽ��� �ֺ�����/ ������ �ƴ���/ �̹��� Ű��/ ������ x/ ������ y/ �����/ ��� �ε���

	HANDLE file;
	DWORD write;
	
	string strTmp = makeSaveMap();
	
	file = CreateFile("map01.map", GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(file, strTmp.c_str(), static_cast<DWORD>(strTmp.length()), &write, NULL);
	CloseHandle(file);

	strTmp.clear();
	strTmp.append(setSaveMapTool());
	file = CreateFile("mapFull01.map", GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(file, strTmp.c_str(), static_cast<DWORD>(strTmp.length()), &write, NULL);
	CloseHandle(file);
}

void MAPTOOL::load()
{
	HANDLE file;
	DWORD read;

	char strTmp[100]{};

	file = CreateFile("mapFull01.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//ReadFile(file, str, 5000, &read, NULL);
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

	this->init(_nTileCountX, _nTileCountY,_nTileSize);

	int nData = _nTileCountX * _nTileCountY * 20;
	char* strs = new char[nData];
	
	file = CreateFile("map01.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, strs, 20000, &read, NULL);
	//ReadFile(file, strTmp, 100, &read, NULL);
	CloseHandle(file);


	char* tmp;
	char* tokenMap;

	tokenMap = strtok_s(strs, separator, &tmp);

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

	delete[] strs;
	strs = nullptr;
}

void MAPTOOL::settingLimitRect()
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			_vvMap[j][i]->setLimitRect(_pCamera->getLimitRect());
		}
	}

}

int MAPTOOL::getPacManPosX()
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			if (_vvMap[j][i]->getObject() == TILE::OBJECT::PACMAN)
			{
				return _vvMap[j][i]->getRectTile().left + (_vvMap[j][i]->getRectTile().right - _vvMap[j][i]->getRectTile().left) / 2;
			}
		}
	}

	return 0;
}

int MAPTOOL::getPacManPosY()
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			if (_vvMap[j][i]->getObject() == TILE::OBJECT::PACMAN)
			{
				return _vvMap[j][i]->getRectTile().top + (_vvMap[j][i]->getRectTile().bottom - _vvMap[j][i]->getRectTile().top) / 2;
			}
		}
	}
	return 0;
}

void MAPTOOL::deleteObject()
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			_vvMap[j][i]->setObject(TILE::OBJECT::NONE);
		}
	}
}

bool MAPTOOL::getItemPos(int * pPosX, int * pPosY)
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			if (_vvMap[j][i]->getObject() == TILE::OBJECT::ITEM)
			{
				(*pPosX) = _vvMap[j][i]->getRectTile().left;
				(*pPosY) = _vvMap[j][i]->getRectTile().top;
				_vvMap[j][i]->setObject(TILE::OBJECT::NONE);
				return true;
			}
		}
	}

	return false;
}

void MAPTOOL::getEnemyPos(int * pPosX, int * pPosY, TILE::OBJECT enemy)
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			if (_vvMap[j][i]->getObject() == enemy)
			{
				(*pPosX) = _vvMap[j][i]->getRectTile().left + (_vvMap[j][i]->getRectTile().right - _vvMap[j][i]->getRectTile().left) / 2;
				(*pPosY) = _vvMap[j][i]->getRectTile().top + (_vvMap[j][i]->getRectTile().bottom - _vvMap[j][i]->getRectTile().top) / 2;
				//_vvMap[j][i]->setObject(TILE::OBJECT::NONE);
				return;
			}
		}
	}
}

int MAPTOOL::getEnemyPosX(TILE::OBJECT enemy)
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			if (_vvMap[j][i]->getObject() == enemy)
			{
				return _vvMap[j][i]->getRectTile().left + (_vvMap[j][i]->getRectTile().right - _vvMap[j][i]->getRectTile().left) / 2;

			}
		}
	}
	return 0;
}

int MAPTOOL::getEnemyPosY(TILE::OBJECT enemy)
{
	for (int j = 0; j < _nTileCountY; j++)
	{
		for (int i = 0; i < _nTileCountX; i++)
		{
			if (_vvMap[j][i]->getObject() == enemy)
			{
				return  _vvMap[j][i]->getRectTile().top + (_vvMap[j][i]->getRectTile().bottom - _vvMap[j][i]->getRectTile().top) / 2;

			}
		}
	}
	return 0;
}

