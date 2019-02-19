#include "stdafx.h"
#include "stateDamage.h"

STATE_DAMAGE::STATE_DAMAGE():
	_fTimer(0.0f)
{
}

STATE_DAMAGE::~STATE_DAMAGE()
{
}

void STATE_DAMAGE::onBtnW(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnA(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnS(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnD(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnQ(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnE(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnSpace(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnLB(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnRB(PLAYER* pPlayer)
{
}

void STATE_DAMAGE::onBtnR(PLAYER * pPlayer)
{
}

void STATE_DAMAGE::update(PLAYER * pPlayer)
{
	_fTimer += TIMEMANAGER->getElapsedTime();
	if (_fTimer >= 0.3f)
	{
		pPlayer->setState(PLAYER::PLAYER_STATE::IDLE);
		pPlayer->setAction(PLAYER::ACTION::IDLE);
		pPlayer->settingAni();
		_fTimer = 0.0f;
	}
}
