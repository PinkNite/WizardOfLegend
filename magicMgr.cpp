#include "stdafx.h"
#include "magicMgr.h"
#include "player.h"
#include "Enemy.h"
#include "boss.h"


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

	CollisionPlayerToMagic();
	CollisionEnemyToMagic();
	CollisionBossToMagic();
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

void MAGICMGR::pushMagicKey(const string& strKey, float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer)
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

void MAGICMGR::pushMagicKey(const string & strKey, float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer, int nFrameX, int nFrameY)
{
	if (_mqMagicPool.find(strKey) == _mqMagicPool.end())
	{
		return;
	}

	MAGIC* pMagic = _mqMagicPool.find(strKey)->second.front();
	_mqMagicPool.find(strKey)->second.pop();
	pMagic->create(fPosX, fPosY, fMoveAngle, fMoveSpeed, bIsPlayer,nFrameX,nFrameY);
	_lActiveMagic.push_back(pMagic);
	pMagic = nullptr;

}

void MAGICMGR::pushMagicKey(const string & strKey, bool bIsPlayer, float fCirclePosX, float fCirclePosY, float fRadius, float fAngle)
{
	if (_mqMagicPool.find(strKey) == _mqMagicPool.end())
	{
		return;
	}

	MAGIC* pMagic = _mqMagicPool.find(strKey)->second.front();
	_mqMagicPool.find(strKey)->second.pop();
	pMagic->create(bIsPlayer,fCirclePosX,fCirclePosY,fRadius,fAngle);
	_lActiveMagic.push_back(pMagic);
	pMagic = nullptr;
}

void MAGICMGR::addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image * pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime, float fDamage, bool bIsCollisionRemove)
{
	if (_mqMagicPool.find(strKey) != _mqMagicPool.end())
	{
		return;
	}

	queue<MAGIC*> qMagic;

	for (int i = 0; i < nMagicCount; i++)
	{
		MAGIC* pMagic = new MAGIC();
		pMagic->init(nWidth, nHeight, pImg, nFps, nFrameMaxX, nFrameMaxY, fTotalTime, strKey, bIsCollisionRemove);
		pMagic->setDamage(fDamage);
		pMagic->setMap(_pMap);

		pMagic->setCamera(_pCamera);
		pMagic->setPlayer(_pPlayer);
		
		qMagic.push(pMagic);
	}

	_mqMagicPool.insert(pair<string, queue<MAGIC*>>(strKey, qMagic));
}

void MAGICMGR::addObject(const string & strKey, int nMagicCount, int nWidth, int nHeight, image * pImg, int nFrameX, int nFrameY, float fTotalTime, float fDamage, bool bIsCollisionRemove)
{
	if (_mqMagicPool.find(strKey) != _mqMagicPool.end())
	{
		return;
	}

	queue<MAGIC*> qMagic;

	for (int i = 0; i < nMagicCount; i++)
	{
		MAGIC* pMagic = new MAGIC();
		pMagic->init(nWidth, nHeight, pImg,nFrameX,nFrameY,fTotalTime,strKey, bIsCollisionRemove);
		pMagic->setDamage(fDamage);
		pMagic->setMap(_pMap);

		pMagic->setCamera(_pCamera);
		pMagic->setPlayer(_pPlayer);

		qMagic.push(pMagic);
	}

	_mqMagicPool.insert(pair<string, queue<MAGIC*>>(strKey, qMagic));
}

void MAGICMGR::addObject(animation * pAni, const string & strKey, int nMagicCount, int nWidth, int nHeight, image * pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime, float fDamage, bool bIsCollisionRemove)
{
	if (_mqMagicPool.find(strKey) != _mqMagicPool.end())
	{
		return;
	}

	queue<MAGIC*> qMagic;

	for (int i = 0; i < nMagicCount; i++)
	{
		MAGIC* pMagic = new MAGIC();
		pMagic->init(nWidth, nHeight, pImg, pAni, fTotalTime, strKey, bIsCollisionRemove);
		pMagic->setDamage(fDamage);
		pMagic->setMap(_pMap);

		pMagic->setCamera(_pCamera);
		pMagic->setPlayer(_pPlayer);

		qMagic.push(pMagic);
	}

	_mqMagicPool.insert(pair<string, queue<MAGIC*>>(strKey, qMagic));
}

void MAGICMGR::addObject(const string & strKey, int nMagicCount, int nWidth, int nHeight, image * pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime, float fTurnTime, float fDamage, bool bIsCollisionRemove)
{
	if (_mqMagicPool.find(strKey) != _mqMagicPool.end())
	{
		return;
	}

	queue<MAGIC*> qMagic;

	for (int i = 0; i < nMagicCount; i++)
	{
		MAGIC* pMagic = new MAGIC();
		pMagic->init(nWidth, nHeight, pImg, nFps, nFrameMaxX, nFrameMaxY, fTotalTime,fTurnTime, strKey);
		pMagic->setDamage(fDamage);
		pMagic->setMap(_pMap);

		pMagic->setCamera(_pCamera);
		pMagic->setPlayer(_pPlayer);

		qMagic.push(pMagic);
	}

	_mqMagicPool.insert(pair<string, queue<MAGIC*>>(strKey, qMagic));
}

void MAGICMGR::CollisionPlayerToMagic()
{
	list<MAGIC*>::iterator iter = _lActiveMagic.begin();
	list<MAGIC*>::iterator end = _lActiveMagic.end();
	while (iter != end)
	{
		MAGIC* pMagic = *iter;

		if (!pMagic->getIsPlayer())
		{
			RECT rcTmp;
			if (IntersectRect(&rcTmp, _pPlayer->getCollisionRect(), pMagic->getRect())) 
			{
				iter = _lActiveMagic.erase(iter);
				pMagic->returnPool();
				_mqMagicPool.find(pMagic->getKey())->second.push(pMagic);
				_pPlayer->getDamage(pMagic->getDamage());
			}
			else {
				iter++;
			}
		}
		else
		{
			iter++;
		}
		pMagic = nullptr;
	}
}

void MAGICMGR::CollisionEnemyToMagic()
{
	if (static_cast<int>(_vEnemyList.size()) == 0)
	{
		return;
	}

	list<MAGIC*>::iterator iter = _lActiveMagic.begin();
	list<MAGIC*>::iterator end = _lActiveMagic.end();
	while (iter != end)
	{
		MAGIC* pMagic = *iter;

		if (pMagic->getIsPlayer())
		{
			for (int i = 0; i < _vEnemyList.size(); i++)
			{
				if (_vEnemyList[i]->getActionState() == Enemy::ActionState::DEATH) continue;
				if (_vEnemyList[i]->getActionState() == Enemy::ActionState::DEATH_END) continue;

				RECT rcTmp;
				//에네미 사각형으로 바꿔주세요     여기 플레이어 렉부분 대신
				if (IntersectRect(&rcTmp, _vEnemyList[i]->getCollisionRect(), pMagic->getRect()))
				{
					//에네미 데미지 입는것 해주세요
					_vEnemyList[i]->setDamage(pMagic->getDamage());
					//데미지는 걍 일단 난수처리해주세요
					if (pMagic->getIsCollision())
					{
						pMagic->setIsDamage(true);

					}
				}
			}
		}

		iter++;
		pMagic = nullptr;
	}
}

void MAGICMGR::CollisionBossToMagic()
{
	if (!_pBoss)
	{
		return;
	}
	list<MAGIC*>::iterator iter = _lActiveMagic.begin();
	list<MAGIC*>::iterator end = _lActiveMagic.end();
	while (iter != end)
	{
		MAGIC* pMagic = *iter;

		if (pMagic->getIsPlayer())
		{
			RECT rcTmp;
			//보스 사각형으로 바꿔주세요     여기 플레이어 렉부분 대신
			if (IntersectRect(&rcTmp, _pBoss->getCollisionRect(), pMagic->getRect()))
			{
				//보스 데이미 입는것 해주세요
				_pBoss->setDamage(pMagic->getDamage());
				if (pMagic->getIsCollision())
				{
					pMagic->setIsDamage(true);

				}
			}
		}
		
		iter++;
		pMagic = nullptr;
	}
}
