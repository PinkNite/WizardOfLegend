#include "stdafx.h"
#include "stateSkillTwo.h"

STATE_SKILL_TWO::STATE_SKILL_TWO():
	_fTimer(0.0f)
{
}

STATE_SKILL_TWO::~STATE_SKILL_TWO()
{
}

void STATE_SKILL_TWO::onBtnW(PLAYER* pPlayer)
{
}

void STATE_SKILL_TWO::onBtnA(PLAYER* pPlayer)
{
}

void STATE_SKILL_TWO::onBtnS(PLAYER* pPlayer)
{
}

void STATE_SKILL_TWO::onBtnD(PLAYER* pPlayer)
{
}

void STATE_SKILL_TWO::onBtnQ(PLAYER* pPlayer)
{
}

void STATE_SKILL_TWO::onBtnE(PLAYER* pPlayer)
{
}

void STATE_SKILL_TWO::onBtnSpace(PLAYER* pPlayer)
{
}

void STATE_SKILL_TWO::onBtnLB(PLAYER* pPlayer)
{
}

void STATE_SKILL_TWO::onBtnRB(PLAYER* pPlayer)
{
	switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::RBUTTON))
	{
	case PLAYER::SKILL_NAME::SHOKE_NOVA:
		if (KEYMANAGER->isKeyDown(VK_RBUTTON))
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

void STATE_SKILL_TWO::onBtnR(PLAYER * pPlayer)
{
}

void STATE_SKILL_TWO::update(PLAYER * pPlayer)
{
	_fTimer += TIMEMANAGER->getElapsedTime();

	switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::RBUTTON))
	{
	case PLAYER::SKILL_NAME::SHOKE_NOVA:
		if (!KEYMANAGER->isKeyDown(VK_RBUTTON))
		{
			if (!pPlayer->getAni()->isPlay())
			{
				pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
				pPlayer->setAction(PLAYER::ACTION::IDLE);
				pPlayer->settingAni();
				_fTimer = 0.0f;
			}
		}
		else if(KEYMANAGER->isKeyDown(VK_RBUTTON))
		{
			pPlayer->getAni()->stop();
		}

		return;
	case PLAYER::SKILL_NAME::CHAIN_LIGHTNING:
		if (!pPlayer->getAni()->isPlay())
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
			pPlayer->setAction(PLAYER::ACTION::IDLE);
			pPlayer->settingAni();
			_fTimer = 0.0f;
		}
		return;
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
		return;;
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
		}
		return;

	}

	if (!pPlayer->getAni()->isPlay())
	{
		pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
		pPlayer->setAction(PLAYER::ACTION::IDLE);
		pPlayer->settingAni();
		_fTimer = 0.0f;
	}
}
