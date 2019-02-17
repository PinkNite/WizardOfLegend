#include "stdafx.h"
#include "stateSkillThree.h"

STATE_SKILL_THREE::STATE_SKILL_THREE():
	_fTimer(0.0f)
{
}

STATE_SKILL_THREE::~STATE_SKILL_THREE()
{
}

void STATE_SKILL_THREE::onBtnW(PLAYER* pPlayer)
{
}

void STATE_SKILL_THREE::onBtnA(PLAYER* pPlayer)
{
}

void STATE_SKILL_THREE::onBtnS(PLAYER* pPlayer)
{
}

void STATE_SKILL_THREE::onBtnD(PLAYER* pPlayer)
{
}

void STATE_SKILL_THREE::onBtnQ(PLAYER* pPlayer)
{

	switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_Q))
	{
	case PLAYER::SKILL_NAME::SHOKE_NOVA:
		if (KEYMANAGER->isKeyDown('Q'))
		{
			pPlayer->getAni()->stop();
		}
		else
		{
			pPlayer->getAni()->start();
		}
		break;
	}

}

void STATE_SKILL_THREE::onBtnE(PLAYER* pPlayer)
{
}

void STATE_SKILL_THREE::onBtnSpace(PLAYER* pPlayer)
{
}

void STATE_SKILL_THREE::onBtnLB(PLAYER* pPlayer)
{
}

void STATE_SKILL_THREE::onBtnRB(PLAYER* pPlayer)
{
}

void STATE_SKILL_THREE::onBtnR(PLAYER * pPlayer)
{
}

void STATE_SKILL_THREE::update(PLAYER * pPlayer)
{
	_fTimer += TIMEMANAGER->getElapsedTime();

	switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_Q))
	{
	case PLAYER::SKILL_NAME::SHOKE_NOVA:
		if (!KEYMANAGER->isKeyDown('Q'))
		{
			if (!pPlayer->getAni()->isPlay())
			{
				pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
				pPlayer->setAction(PLAYER::ACTION::IDLE);
				pPlayer->settingAni();
				_fTimer = 0.0f;
			}
		}
		else if (KEYMANAGER->isKeyDown('Q'))
		{
			pPlayer->getAni()->stop();
		}

		break;

	case PLAYER::SKILL_NAME::SHATTERINGSTRIKE:
		if (_fTimer >= 0.3f)
		{
			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_05);
			pPlayer->settingAni();


			if (!pPlayer->getAni()->isPlay())
			{
				pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
				pPlayer->setAction(PLAYER::ACTION::IDLE);
				pPlayer->settingAni();
				_fTimer = 0.0f;
			}
		}

		break;
	}
}
