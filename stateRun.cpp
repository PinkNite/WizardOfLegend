#include "stdafx.h"
#include "stateRun.h"

STATE_RUN::STATE_RUN()
{
}

STATE_RUN::~STATE_RUN()
{
}

void STATE_RUN::onBtnW(PLAYER* pPlayer)
{
	if (!KEYMANAGER->isKeyDown('A') && !KEYMANAGER->isKeyDown('D')) {
		if (pPlayer->getDrection() != PLAYER::DIRECTION::BACK)
		{
			pPlayer->setDirection(PLAYER::DIRECTION::BACK);
			
			pPlayer->settingAni();
		}
	}
	pPlayer->setDirectionUp();
}

void STATE_RUN::onBtnA(PLAYER* pPlayer)
{
	if (pPlayer->getDrection() != PLAYER::DIRECTION::LEFT)
	{
		pPlayer->setDirection(PLAYER::DIRECTION::LEFT);
		pPlayer->settingAni();
	}
	pPlayer->setDirectionLeft();
}

void STATE_RUN::onBtnS(PLAYER* pPlayer)
{
	if (!KEYMANAGER->isKeyDown('A') && !KEYMANAGER->isKeyDown('D')) {
		if (pPlayer->getDrection() != PLAYER::DIRECTION::FORWARD)
		{
			pPlayer->setDirection(PLAYER::DIRECTION::FORWARD);
			pPlayer->settingAni();
		}
	}
	pPlayer->setDirectionDown();
}

void STATE_RUN::onBtnD(PLAYER* pPlayer)
{
	if (pPlayer->getDrection() != PLAYER::DIRECTION::RIGHT) 
	{
		pPlayer->setDirection(PLAYER::DIRECTION::RIGHT);
		pPlayer->settingAni();
	}
	pPlayer->setDirectionRight();
}

void STATE_RUN::onBtnQ(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_03);
}

void STATE_RUN::onBtnE(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_04);
}

void STATE_RUN::onBtnSpace(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::DASH);
	pPlayer->setDashTime(0.0f);
	pPlayer->setAction(PLAYER::ACTION::DASH);
	pPlayer->settingAni();

	pPlayer->setSkill(PLAYER::SKILL_NAME::FIRE_DASH);
}

void STATE_RUN::onBtnLB(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_01);
	pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
	pPlayer->setAttactDir();
	pPlayer->settingAni();

	pPlayer->setSkill(PLAYER::SKILL_NAME::FIRE_STRIKE);
	pPlayer->getSkill()->useMagic(pPlayer->getAttactPosX(), pPlayer->getAttactPosY());
}

void STATE_RUN::onBtnRB(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_02);
}

void STATE_RUN::onBtnR(PLAYER * pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);
}

void STATE_RUN::update(PLAYER * pPlayer)
{
	pPlayer->movePlayer();
}
