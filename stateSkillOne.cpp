#include "stdafx.h"
#include "stateSkillOne.h"

STATE_SKILL_ONE::STATE_SKILL_ONE():
	_fWaitTime(0.0f),
	_nCount(1),
	_bIsUse(true)
{
}

STATE_SKILL_ONE::~STATE_SKILL_ONE()
{
}

void STATE_SKILL_ONE::onBtnW(PLAYER* pPlayer)
{
}

void STATE_SKILL_ONE::onBtnA(PLAYER* pPlayer)
{
}

void STATE_SKILL_ONE::onBtnS(PLAYER* pPlayer)
{
}

void STATE_SKILL_ONE::onBtnD(PLAYER* pPlayer)
{
}

void STATE_SKILL_ONE::onBtnQ(PLAYER* pPlayer)
{
}

void STATE_SKILL_ONE::onBtnE(PLAYER* pPlayer)
{
}

void STATE_SKILL_ONE::onBtnSpace(PLAYER* pPlayer)
{
}

void STATE_SKILL_ONE::onBtnLB(PLAYER* pPlayer)
{
	if (_fWaitTime >= 0.2f  && _nCount < 3)
	{
		if (pPlayer->getIsUsingSkill(PLAYER::SKILL_KEY::LBUTTON))
		{
			switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::LBUTTON))
			{
			case PLAYER::SKILL_NAME::FIRE_STRIKE:
				pPlayer->changeAttactMotion();
				break;
			case PLAYER::SKILL_NAME::STONE_SHOT:
				pPlayer->changeAttactMotion();
				if (_nCount == 2)
				{
					pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_05);
				}
				break;
			}
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			_fWaitTime = 0.0f;
			_nCount++;

		}
	}


	
}

void STATE_SKILL_ONE::onBtnRB(PLAYER* pPlayer)
{
}

void STATE_SKILL_ONE::onBtnR(PLAYER * pPlayer)
{
}

void STATE_SKILL_ONE::update(PLAYER * pPlayer)
{
	_fWaitTime += TIMEMANAGER->getElapsedTime();
	
	//쿨타임사용해서 일정시간지나서 클릭이 없으면


	if (_fWaitTime >= 0.5f && !KEYMANAGER->isKeyDown(VK_LBUTTON))
	{	
 		pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
		pPlayer->setAction(PLAYER::ACTION::IDLE);
		pPlayer->settingAni();
		_fWaitTime = 0.0f;
		_nCount = 1;
		_bIsUse = true;
		pPlayer->setZeroNormalCount();
	}
	if (_nCount  == 3 && _fWaitTime >= 0.5f)
	{
		pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
		pPlayer->setAction(PLAYER::ACTION::IDLE);
		pPlayer->settingAni();
		_fWaitTime = 0.0f;
		_nCount = 1;

		_bIsUse = true;
		pPlayer->setZeroNormalCount();

	}
	
}
