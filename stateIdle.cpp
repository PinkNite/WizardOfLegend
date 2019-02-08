#include "stdafx.h"
#include "stateIdle.h"

STATE_IDLE::STATE_IDLE()
{
}

STATE_IDLE::~STATE_IDLE()
{
}

void STATE_IDLE::onBtnW(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
	pPlayer->setDirection(PLAYER::DIRECTION::BACK);
	pPlayer->setAction(PLAYER::ACTION::RUN);
	pPlayer->settingAni();
}

void STATE_IDLE::onBtnA(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
	pPlayer->setDirection(PLAYER::DIRECTION::LEFT);
	pPlayer->setAction(PLAYER::ACTION::RUN);
	pPlayer->settingAni();
}

void STATE_IDLE::onBtnS(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
	pPlayer->setDirection(PLAYER::DIRECTION::FORWARD);
	pPlayer->setAction(PLAYER::ACTION::RUN);
	pPlayer->settingAni();
}

void STATE_IDLE::onBtnD(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
	pPlayer->setDirection(PLAYER::DIRECTION::RIGHT);
	pPlayer->setAction(PLAYER::ACTION::RUN);
	pPlayer->settingAni();
}

void STATE_IDLE::onBtnQ(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_03);
}

void STATE_IDLE::onBtnE(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_04);
}

void STATE_IDLE::onBtnSpace(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::DASH);
	pPlayer->setAction(PLAYER::ACTION::DASH);
	pPlayer->settingAni();
}

void STATE_IDLE::onBtnLB(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_01);
}

void STATE_IDLE::onBtnRB(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_02);
}

void STATE_IDLE::onBtnR(PLAYER * pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);
}

void STATE_IDLE::update(PLAYER * pPlayer)
{
}
