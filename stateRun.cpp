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
		pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
		pPlayer->setDirection(PLAYER::DIRECTION::BACK);
		pPlayer->setAction(PLAYER::ACTION::RUN);
		pPlayer->settingAni();
	}
	
}

void STATE_RUN::onBtnA(PLAYER* pPlayer)
{
}

void STATE_RUN::onBtnS(PLAYER* pPlayer)
{
}

void STATE_RUN::onBtnD(PLAYER* pPlayer)
{
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
}

void STATE_RUN::onBtnLB(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_01);
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
}
