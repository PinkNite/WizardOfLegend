#include "stdafx.h"
#include "StatueMgr.h"

STATUEMGR::STATUEMGR()
{
}

STATUEMGR::~STATUEMGR()
{
}

void STATUEMGR::init(MAP * pMap, CAMERA * pCamera)
{

	setLink(pMap, pCamera);

	IMAGEMANAGER->addImage("iceStatue", "resource/object/iceStatue.bmp", 128, 320, true, Mins::getMazenta());
	IMAGEMANAGER->addImage("largeWizardStatue", "resource/object/largeWizardStatue.bmp", 192, 256, true, Mins::getMazenta());

	for (int j = 0; j < _pMap->getMapCountY(); j++)
	{
		for (int i = 0; i < _pMap->getMapCountX(); i++)
		{
			if (_pMap->getTile(i, j)->getObject() == TILE::OBJECT::NOMAL_OBJECT) 
			{
				int nXLength = 0;
				while (_pMap->getTile(i + nXLength, j)->getObject() == TILE::OBJECT::NOMAL_OBJECT)
				{
					nXLength++;
					
				}
				int nYLength = 0;
				while (_pMap->getTile(i, j + nYLength)->getObject() == TILE::OBJECT::NOMAL_OBJECT)
				{
					nYLength++;
				}

				for (int k = 0; k < nXLength; k++)
				{
					for (int p = 0; p < nYLength; p++)
					{
						_pMap->getTile(i + k, j+p)->setObject(TILE::OBJECT::ITEM);
					}
				}

				if (nXLength == 2)
				{
					addStatue(_pMap->getTile(i, j)->getRectTile().left, _pMap->getTile(i, j)->getRectTile().top, _pMap->getTileSize()*2, _pMap->getTileSize()*5,
						IMAGEMANAGER->findImage("iceStatue"));
				}
				else if (nXLength == 3)
				{
					addStatue(_pMap->getTile(i, j)->getRectTile().left, _pMap->getTile(i, j)->getRectTile().top, _pMap->getTileSize()*3, _pMap->getTileSize()*4,
						IMAGEMANAGER->findImage("largeWizardStatue"));
				}
			}
		}
	}
}

void STATUEMGR::update()
{
	int nLength = static_cast<int>(_vStoneStatue.size());
	for (int i = 0; i < nLength; i++)
	{
		STONESTATUE* pStatue = _vStoneStatue[i];
		pStatue->update();
	}

}

void STATUEMGR::release()
{
	int nLength = static_cast<int>(_vStoneStatue.size());
	for (int i = 0; i < nLength; i++)
	{
		STONESTATUE* pStatue = _vStoneStatue.back();
		pStatue->release();
		_vStoneStatue.pop_back();
		delete pStatue;
		pStatue = nullptr;
	}
}

void STATUEMGR::addStatue(float fLeft, float fTop, int nWidth, int nHeight, image * pimage)
{
	_vStoneStatue.push_back(new STONESTATUE);
	_vStoneStatue.back()->init(fLeft, fTop, nWidth, nHeight, pimage);
	_vStoneStatue.back()->setLink(_pCamera);
}

void STATUEMGR::setLink(MAP * pMap, CAMERA * pCamera)
{
	_pMap = pMap;
	_pCamera = pCamera;
}
