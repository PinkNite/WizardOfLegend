#include "stdafx.h"
#include "stateSkillFive.h"

STATE_SKILL_FIVE::STATE_SKILL_FIVE():
	_fTimer(0.0f)
{
}

STATE_SKILL_FIVE::~STATE_SKILL_FIVE()
{
}

void STATE_SKILL_FIVE::onBtnW(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::onBtnA(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::onBtnS(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::onBtnD(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::onBtnQ(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::onBtnE(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::onBtnLB(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::onBtnRB(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::onBtnR(PLAYER * pPlayer)
{
	switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_R))
	{
	case PLAYER::SKILL_NAME::SHOKE_NOVA:
		if (KEYMANAGER->isKeyDown('R'))
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

void STATE_SKILL_FIVE::onBtnSpace(PLAYER * pPlayer)
{
}

void STATE_SKILL_FIVE::update(PLAYER * pPlayer)
{
	_fTimer += TIMEMANAGER->getElapsedTime();

	switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_R))
	{
	case PLAYER::SKILL_NAME::SHOKE_NOVA:
		if (!KEYMANAGER->isKeyDown('R'))
		{
			if (!pPlayer->getAni()->isPlay())
			{
				pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
				pPlayer->setAction(PLAYER::ACTION::IDLE);
				pPlayer->settingAni();
				_fTimer = 0.0f;
			}
		}
		else if (KEYMANAGER->isKeyDown('R'))
		{
			pPlayer->getAni()->stop();
		}

		break;

	case PLAYER::SKILL_NAME::SHATTERINGSTRIKE:
		if (_fTimer >= 0.3f &&
			_fTimer < 5.0f)
		{
			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_05);
			pPlayer->settingAni();
			_fTimer = 5.0f;
		}

		if (!pPlayer->getAni()->isPlay() && _fTimer >= 5.0f)
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
			pPlayer->setAction(PLAYER::ACTION::IDLE);
			pPlayer->settingAni();
			_fTimer = 0.0f;
		}
		break;

	case PLAYER::SKILL_NAME::REBOUNDINGICICLES:
		if (!pPlayer->getAni()->isPlay())
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
			pPlayer->setAction(PLAYER::ACTION::IDLE);
			pPlayer->settingAni();
			_fTimer = 0.0f;
		}

		break;

	case PLAYER::SKILL_NAME::GLACIALCROSS:
		if (!pPlayer->getAni()->isPlay())
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
			pPlayer->setAction(PLAYER::ACTION::IDLE);
			pPlayer->settingAni();
			_fTimer = 0.0f;
			
		}
		if (_fTimer <= 0.3f)
		{
			pPlayer->moveAttack(300.0f);
		}		break;
	}
}
