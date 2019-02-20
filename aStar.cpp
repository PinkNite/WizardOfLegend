#include "stdafx.h"
#include "aStar.h"


ASTAR::TILENODE * ASTAR::getNode(int nIndex)
{
	list<TILENODE*>::iterator iter = _listMaximumPath.begin();
	for (int i = 0; i < nIndex; i++)
	{
		iter++;
	}

	return *iter;
}

void ASTAR::initMap()
{
	for (int j = 0; j < _nTileSizeY; j++)
	{
		for (int i = 0; i <_nTileSizeX; i++)
		{
			_vvTile[j][i]->nIndexX = i;
			_vvTile[j][i]->nIndexY = j;
			_vvTile[j][i]->nPathCurrentToEnd = 0;
			_vvTile[j][i]->nPathStartToCurrent = 0;
			_vvTile[j][i]->nPathToatalCost = 0;
			_vvTile[j][i]->parrentNode = nullptr;
		}
	}
}

ASTAR::ASTAR()
{
}

ASTAR::~ASTAR()
{
}

void ASTAR::init(int nSearchLength, MAP * pMap)
{
	_nSearchLength = nSearchLength;

	//�̻��Ѱ� �ִ� xx���� �����ϱ� ����
	if (_nSearchLength < 7)
	{
		_nSearchLength = 4;
	}
	else
	{
		_nSearchLength = 8;
	}


	_pMap = pMap;

	_vvTile.resize(_pMap->getMapCountY());

	for (int j = 0; j < _vvTile.size(); j++)
	{
		for (int i = 0; i < _pMap->getMapCountX(); i++)
		{
			_vvTile[j].push_back(new TILENODE);
			_vvTile[j][i]->nIndexX = i;
			_vvTile[j][i]->nIndexY = j;
			_vvTile[j][i]->nPathCurrentToEnd = 0;
			_vvTile[j][i]->nPathStartToCurrent = 0;
			_vvTile[j][i]->nPathToatalCost = 0;
			_vvTile[j][i]->parrentNode = nullptr;
		}
	}

	_nTileSizeX = _pMap->getMapCountX();
	_nTileSizeY = _pMap->getMapCountY();
}



void ASTAR::startFinder(int nStartIndexX, int nStartIndexY, int nEndIndexX, int nEndIndexY)
{
	//�������� �����.
	//�θ���� ����
	//���� �߽����� ��´�.
	//�ڽ�Ʈ�� ����Ѵ�.
	_nStartIndexX = nStartIndexX;
	_nStartIndexY = nStartIndexY;
	_nEndIndexX = nEndIndexX;
	_nEndIndexY = nEndIndexY;

	_listOpendNode.clear();
	_listClosedyPath.clear();
	_listMaximumPath.clear(); 
	initMap();
	//���� ��� �����
	//TILENODE* pNode = new TILENODE();
	//pNode->nIndexX = _nStartIndexX;
	//pNode->nIndexY = _nStartIndexY;
	//pNode->nPathCurrentToEnd = 0;
	//pNode->nPathStartToCurrent = 0;
	//pNode->nPathToatalCost = 0;
	//pNode->parrentNode = nullptr;
	
	//���� ��ǥ�� �ִµ� �켱������ ����
	_listOpendNode.push_back(_vvTile[_nStartIndexY][_nStartIndexX]);

}

void ASTAR::pathFinder()
{
	//8���� ��ǥ�� Ž��
	//������ǥ�� �ִµ�
	//���� ��ǥ�� �ִµ� �켱������ ����
	//���� ��ǥ�� ������ ���� �ʴ´�.
	//������ǥ�� ���� ���� ������ �ڽ�Ʈ�� ���Ͽ� ���� ������ �θ�� �ڽ�Ʈ�� �ٲپ ����
	//�ص�� ���� �θ���� �� �ҷ��ͼ� ���� �����.. �̰� ����ũ �н�
	//�ص尡 �ƴϸ� �ٽ� ��������� ������.
	TILENODE* pNode = _listOpendNode.front();
	_listClosedyPath.push_back(pNode);
	_listOpendNode.pop_front();

	//8�� ��ǥŽ��
	for (int i = 0; i < _nSearchLength; i++)
	{
		int nIntervalPosX = pNode->nIndexX + _arInterval[i][static_cast<int>(POS::POSX)];
		int nIntervalPosY = pNode->nIndexY + _arInterval[i][static_cast<int>(POS::POSY)];

		if (nIntervalPosX < 0) continue;
		if (nIntervalPosY < 0) continue;
		if (nIntervalPosX >= _nTileSizeX) continue;
		if (nIntervalPosY >= _nTileSizeY) continue;
		//���߰����� �͸����̳� ������Ʈ�� ó��
		//if (_pMap->getTile(nIntervalPosX, nIntervalPosY)->getIsWall()) continue;
		if (_pMap->getTile(nIntervalPosX, nIntervalPosY)->getTerrian() != TILE::TERRIAN::PASS) continue;

		bool bIsSearch = false;
		list<TILENODE*>::iterator iter = _listOpendNode.begin();
		list<TILENODE*>::iterator end = _listOpendNode.end();
		//////////open�� ������ 
		while (iter != end)
		{
			if ((*iter)->nIndexX == nIntervalPosX && (*iter)->nIndexY == nIntervalPosY)
			{
				if ((*iter)->nPathStartToCurrent > pNode->nPathStartToCurrent + _arHuristic[i])
				{
					//�ٲٰ� �ٽ� �����ؾ��Ѵ�.
					_vvTile[nIntervalPosY][nIntervalPosX]->nIndexX = nIntervalPosX;
					_vvTile[nIntervalPosY][nIntervalPosX]->nIndexY = nIntervalPosY;
					_vvTile[nIntervalPosY][nIntervalPosX]->nPathStartToCurrent = pNode->nPathStartToCurrent + _arHuristic[i];
					_vvTile[nIntervalPosY][nIntervalPosX]->nPathCurrentToEnd = abs(nIntervalPosX - _nEndIndexX) + abs(nIntervalPosY - _nEndIndexY);
					_vvTile[nIntervalPosY][nIntervalPosX]->nPathCurrentToEnd *= 10;
					_vvTile[nIntervalPosY][nIntervalPosX]->nPathToatalCost = _vvTile[nIntervalPosY][nIntervalPosX]->nPathStartToCurrent + _vvTile[nIntervalPosY][nIntervalPosX]->nPathCurrentToEnd;
					_vvTile[nIntervalPosY][nIntervalPosX]->parrentNode = pNode;


					_listOpendNode.erase(iter);

					iter = _listOpendNode.begin();
					while ((*iter)->nPathToatalCost < _vvTile[nIntervalPosY][nIntervalPosX]->nPathToatalCost) {
						iter++;
					}
					_listOpendNode.insert(iter, _vvTile[nIntervalPosY][nIntervalPosX]);
				}

				bIsSearch = true;
				break;
			}
			iter++;
		}
		if (bIsSearch) continue;
		bIsSearch = false;

		//Ŭ��� ������ �Ѱܾ��Ѵ�.
		iter = _listClosedyPath.begin();
		end = _listClosedyPath.end();
		while (iter != end)
		{

			if ((*iter)->nIndexX == nIntervalPosX && (*iter)->nIndexY == nIntervalPosY) {
				bIsSearch = true;
				break;
			}
			iter++;
		}
		if (bIsSearch) continue;

		_vvTile[nIntervalPosY][nIntervalPosX]->nIndexX = nIntervalPosX;
		_vvTile[nIntervalPosY][nIntervalPosX]->nIndexY = nIntervalPosY;
		_vvTile[nIntervalPosY][nIntervalPosX]->nPathStartToCurrent = pNode->nPathStartToCurrent + _arHuristic[i];
		_vvTile[nIntervalPosY][nIntervalPosX]->nPathCurrentToEnd = abs(nIntervalPosX - _nEndIndexX) + abs(nIntervalPosY - _nEndIndexY);
		_vvTile[nIntervalPosY][nIntervalPosX]->nPathCurrentToEnd *= 10;
		_vvTile[nIntervalPosY][nIntervalPosX]->nPathToatalCost = _vvTile[nIntervalPosY][nIntervalPosX]->nPathStartToCurrent + _vvTile[nIntervalPosY][nIntervalPosX]->nPathCurrentToEnd;
		_vvTile[nIntervalPosY][nIntervalPosX]->parrentNode = pNode;

		if (nIntervalPosX == _nEndIndexX && nIntervalPosY == _nEndIndexY)
		{
			//ã�Ҵ�
			_listMaximumPath.push_front(_vvTile[nIntervalPosY][nIntervalPosX]);
			_pMap->getTile(_vvTile[nIntervalPosY][nIntervalPosX]->nIndexX, _vvTile[nIntervalPosY][nIntervalPosX]->nIndexY)->settingTile(28, 0, false, TILE::OBJECT::ENEMY01);

			TILENODE* pTmp = _vvTile[nIntervalPosY][nIntervalPosX]->parrentNode;
			while (pTmp != nullptr) {
				_listMaximumPath.push_front(pTmp);
				_pMap->getTile(pTmp->nIndexX, pTmp->nIndexY)->settingTile(28, 0, false, TILE::OBJECT::ENEMY01);

				pTmp = pTmp->parrentNode;
			}
			//Ż��
			return;
		}
		else
		{
			iter = _listOpendNode.begin();
			while (iter != _listOpendNode.end() && (*iter)->nPathToatalCost < _vvTile[nIntervalPosY][nIntervalPosX]->nPathToatalCost) {
				iter++;
			}
			_listOpendNode.insert(iter, _vvTile[nIntervalPosY][nIntervalPosX]);
		}

	}

	if (_listClosedyPath.size() > 300)
	{

		list<TILENODE*>::iterator iter = _listOpendNode.begin();
		list<TILENODE*>::iterator end = _listOpendNode.end();
		TILENODE* pNode;
		pNode = *iter;
		//���� ����� ��带 Ž���Ѵ�.
		while (iter != end)
		{
			if (pNode->nPathCurrentToEnd > (*iter)->nPathCurrentToEnd)
			{
				pNode = *iter;
			}
			iter++;
		}
		//���� ����� ��忡�� ���� �����
		while (pNode != nullptr) {
			_listMaximumPath.push_front(pNode);

			pNode = pNode->parrentNode;
		}
		
		return;
	}


	pathFinder();
}

POINT ASTAR::getTileIndex(RECT& rcCollision)
{
	POINT point;

	point.x = rcCollision.left / _pMap->getTileSize();
	point.y = rcCollision.top / _pMap->getTileSize();

	return point;
}

POINT ASTAR::getTileIndex(float x, float y)
{
	POINT point;
	point.x = int(x) / _pMap->getTileSize();
	point.y = int(y) / _pMap->getTileSize();
	return POINT();
}


void ASTAR::setObject(TILE::OBJECT obj)
{
}

void ASTAR::release()
{
	while (!_listOpendNode.empty())
	{
		TILENODE* pNode = _listOpendNode.back();
		_listOpendNode.pop_back();
	}
	while (!_listClosedyPath.empty())
	{
		TILENODE* pNode = _listClosedyPath.back();
		_listClosedyPath.pop_back();
	}
	if (!_listMaximumPath.empty())
	{
		TILENODE* pNode = _listMaximumPath.back();
		_listMaximumPath.pop_back();
	}
	_listMaximumPath.clear();

}

