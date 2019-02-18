#include "stdafx.h"
#include "stateSkillFour.h"

STATE_SKILL_FOUR::STATE_SKILL_FOUR():
	_fTimer(0.0f)
{
}

STATE_SKILL_FOUR::~STATE_SKILL_FOUR()
{
}

void STATE_SKILL_FOUR::onBtnW(PLAYER* pPlayer)
{
}

void STATE_SKILL_FOUR::onBtnA(PLAYER* pPlayer)
{
}

void STATE_SKILL_FOUR::onBtnS(PLAYER* pPlayer)
{
}

void STATE_SKILL_FOUR::onBtnD(PLAYER* pPlayer)
{
}

void STATE_SKILL_FOUR::onBtnQ(PLAYER* pPlayer)
{
}

void STATE_SKILL_FOUR::onBtnE(PLAYER* pPlayer)
{
	switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_E))
	{
	case PLAYER::SKILL_NAME::SHOKE_NOVA:
		if (KEYMANAGER->isKeyDown('E'))
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

void STATE_SKILL_FOUR::onBtnSpace(PLAYER* pPlayer)
{
}

void STATE_SKILL_FOUR::onBtnLB(PLAYER* pPlayer)
{
}

void STATE_SKILL_FOUR::onBtnRB(PLAYER* pPlayer)
{
}

void STATE_SKILL_FOUR::onBtnR(PLAYER * pPlayer)
{
}

void STATE_SKILL_FOUR::update(PLAYER * pPlayer)
{
	_fTimer += TIMEMANAGER->getElapsedTime();

	switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_E))
	{
	case PLAYER::SKILL_NAME::SHOKE_NOVA:
		if (!KEYMANAGER->isKeyDown('E'))
		{
			if (!pPlayer->getAni()->isPlay())
			{
				pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
				pPlayer->setAction(PLAYER::ACTION::IDLE);
				pPlayer->settingAni();
				_fTimer = 0.0f;
			}
		}
		else if (KEYMANAGER->isKeyDown('E'))
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
