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
		else if (KEYMANAGER->isKeyDown(VK_RBUTTON))
		{
			pPlayer->getAni()->stop();
		}

		break;
	}
}
