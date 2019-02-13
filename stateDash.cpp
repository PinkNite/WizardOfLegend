#include "stdafx.h"
#include "stateDash.h"

STATE_DASH::STATE_DASH():
	fOffset(2.5f)
{
}

STATE_DASH::~STATE_DASH()
{
}

void STATE_DASH::onBtnW(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnA(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnS(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnD(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnQ(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnE(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnSpace(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnLB(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnRB(PLAYER* pPlayer)
{
}

void STATE_DASH::onBtnR(PLAYER * pPlayer)
{
}

void STATE_DASH::update(PLAYER * pPlayer)
{
	if (pPlayer->getDashTime() < 0.5f)
	{
		if (pPlayer->getDashTime() < 0.2f)
		{
			pPlayer->getAni()->stop();
		}
		else {
			if (!pPlayer->getAni()->isPlay()) {
				pPlayer->getAni()->start();
			}
			if (fOffset > 0.1f)
			{
				fOffset -= 0.1f;
			}
		}
		pPlayer->dash(fOffset);
		pPlayer->addDashTime();
	}
	else
	{
		pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
		pPlayer->setAction(PLAYER::ACTION::RUN);
		pPlayer->settingAni();
		fOffset = 2.5f;
	}
	pPlayer->getSkill()->update();

}
