#include "stdafx.h"
#include "magicMgr.h"

MAGICMGR::MAGICMGR()
{
}

MAGICMGR::~MAGICMGR()
{
}

void MAGICMGR::init()
{
}

void MAGICMGR::update()
{
	list<MAGIC*>::iterator iter = _lActiveMagic.begin();
	list<MAGIC*>::iterator end = _lActiveMagic.end();
	while (iter != end)
	{
		MAGIC* pMagic = *iter;
		pMagic->update();

		if (!pMagic->getActive())
		{
			iter = _lActiveMagic.erase(iter);
			pMagic->returnPool();
			_mqMagicPool.find(pMagic->getKey())->second.push(pMagic);
		}
		else
		{
			iter++;
		}
		pMagic = nullptr;
	}
}

void MAGICMGR::release()
{
	list<MAGIC*>::iterator iter = _lActiveMagic.begin();
	list<MAGIC*>::iterator end = _lActiveMagic.end();
	while (iter != end)
	{
		MAGIC* pMagic = *iter;
		pMagic->release();
		iter = _lActiveMagic.erase(iter);
		delete pMagic;
		pMagic = nullptr;
	}


	map<string, queue<MAGIC*>>::iterator iterMq = _mqMagicPool.begin();
	map<string, queue<MAGIC*>>::iterator iterMqEnd = _mqMagicPool.end();

	while (iterMq != iterMqEnd)
	{
		while (!((*iterMq).second.empty()))
		{
			MAGIC* pMagic = (*iterMq).second.front();
			pMagic->release();
			(*iterMq).second.pop();
			delete pMagic;
			pMagic = nullptr;
		}
		iterMq = _mqMagicPool.erase(iterMq);
	}

}

void MAGICMGR::render(HDC hdc)
{
	list<MAGIC*>::iterator iter = _lActiveMagic.begin();
	list<MAGIC*>::iterator end = _lActiveMagic.end();
	while (iter != end)
	{
		MAGIC* pMagic = *iter;
		pMagic->render(hdc);

		iter++;
		pMagic = nullptr;
	}
}

void MAGICMGR::useMagic(const string& strKey, float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer)
{
	if (_mqMagicPool.find(strKey) == _mqMagicPool.end())
	{
		return;
	}

	MAGIC* pMagic = _mqMagicPool.find(strKey)->second.front();
	_mqMagicPool.find(strKey)->second.pop();
	pMagic->create(fPosX, fPosY, fMoveAngle, fMoveSpeed, bIsPlayer);
	_lActiveMagic.push_back(pMagic);
	pMagic = nullptr;
}

void MAGICMGR::addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image * pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime)
{
	if (_mqMagicPool.find(strKey) != _mqMagicPool.end())
	{
		return;
	}

	queue<MAGIC*> qMagic;

	for (int i = 0; i < nMagicCount; i++)
	{
		MAGIC* pMagic = new MAGIC();
		pMagic->init(nWidth, nHeight, pImg, nFps, nFrameMaxX, nFrameMaxY, fTotalTime, strKey);	
		qMagic.push(pMagic);
	}

	_mqMagicPool.insert(pair<string, queue<MAGIC*>>(strKey, qMagic));
}