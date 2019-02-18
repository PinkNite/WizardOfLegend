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
	if (pPlayer->getIsUsingSkill(PLAYER::SKILL_KEY::BTN_Q))
	{
		switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_Q))
		{
		case PLAYER::SKILL_NAME::SHOKE_NOVA:
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_03);
			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_02);
			pPlayer->settingAni();
		}

		break;

		case PLAYER::SKILL_NAME::SHATTERINGSTRIKE:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_03);
			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_04);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		case PLAYER::SKILL_NAME::REBOUNDINGICICLES:

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();

			break;
		case PLAYER::SKILL_NAME::GLACIALCROSS:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_01);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		}
	}
	
}

void STATE_RUN::onBtnE(PLAYER* pPlayer)
{
	if (pPlayer->getIsUsingSkill(PLAYER::SKILL_KEY::BTN_E))
	{
		switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_E))
		{
		case PLAYER::SKILL_NAME::SHOKE_NOVA:
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_04);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_02);
			pPlayer->settingAni();
		}

		break;

		case PLAYER::SKILL_NAME::SHATTERINGSTRIKE:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_04);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_04);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;

		case PLAYER::SKILL_NAME::REBOUNDINGICICLES:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_04);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();

			break;
		case PLAYER::SKILL_NAME::GLACIALCROSS:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_01);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		}
	}
}

void STATE_RUN::onBtnSpace(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::DASH);
	pPlayer->setDashTime(0.0f);
	pPlayer->setAction(PLAYER::ACTION::DASH);
	pPlayer->settingAni();

	//pPlayer->setSkill(PLAYER::SKILL_NAME::FIRE_DASH);
}

void STATE_RUN::onBtnLB(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_01);
	pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
	pPlayer->setAttactDir();
	pPlayer->settingAni();

	//pPlayer->setSkill(PLAYER::SKILL_NAME::FIRE_STRIKE);
	//pPlayer->getSkill()->pushMagicKey(pPlayer->getAttactPosX(), pPlayer->getAttactPosY());
}

void STATE_RUN::onBtnRB(PLAYER* pPlayer)
{
	if (pPlayer->getIsUsingSkill(PLAYER::SKILL_KEY::RBUTTON))
	{
		switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::RBUTTON))
		{
		case PLAYER::SKILL_NAME::SHOKE_NOVA:
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_02);
			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_02);
			pPlayer->settingAni();

		}

		break;

		case PLAYER::SKILL_NAME::CHAIN_LIGHTNING:
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_02);
			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
		}

		break;

		case PLAYER::SKILL_NAME::SHATTERINGSTRIKE:

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;

		case PLAYER::SKILL_NAME::REBOUNDINGICICLES:

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();

			break;
		case PLAYER::SKILL_NAME::GLACIALCROSS:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_01);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		}

	}
}

void STATE_RUN::onBtnR(PLAYER * pPlayer)
{
	if (pPlayer->getIsUsingSkill(PLAYER::SKILL_KEY::BTN_R))
	{
		switch (pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_R))
		{
		case PLAYER::SKILL_NAME::SHOKE_NOVA:
		{
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_02);
			pPlayer->settingAni();
		}

		break;

		case PLAYER::SKILL_NAME::SHATTERINGSTRIKE:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;

		case PLAYER::SKILL_NAME::REBOUNDINGICICLES:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();

			break;
		case PLAYER::SKILL_NAME::GLACIALCROSS:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_05);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_01);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		}
	}
}

void STATE_RUN::update(PLAYER * pPlayer)
{
	pPlayer->movePlayer();
}
