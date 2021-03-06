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
	pPlayer->setDirectionUp();

}

void STATE_IDLE::onBtnA(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
	pPlayer->setDirection(PLAYER::DIRECTION::LEFT);
	pPlayer->setAction(PLAYER::ACTION::RUN);
	pPlayer->settingAni();
	pPlayer->setDirectionLeft();
}

void STATE_IDLE::onBtnS(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
	pPlayer->setDirection(PLAYER::DIRECTION::FORWARD);
	pPlayer->setAction(PLAYER::ACTION::RUN);
	pPlayer->settingAni();
	pPlayer->setDirectionDown();

}

void STATE_IDLE::onBtnD(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::RUN);
	pPlayer->setDirection(PLAYER::DIRECTION::RIGHT);
	pPlayer->setAction(PLAYER::ACTION::RUN);
	pPlayer->settingAni();
	pPlayer->setDirectionRight();

}

void STATE_IDLE::onBtnQ(PLAYER* pPlayer)
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

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		case PLAYER::SKILL_NAME::REBOUNDINGICICLES:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_03);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();

			break;
		case PLAYER::SKILL_NAME::GLACIALCROSS:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_03);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_01);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		}
	}
}

void STATE_IDLE::onBtnE(PLAYER* pPlayer)
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

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
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
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_04);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_01);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		}
	}
}

void STATE_IDLE::onBtnSpace(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::DASH);
	pPlayer->setAction(PLAYER::ACTION::DASH);
	pPlayer->settingAni();
	pPlayer->setDashTime(0.0f);
	pPlayer->saveDashStartPosX();
	pPlayer->saveDashStartPosY();
	//pPlayer->setSkill(PLAYER::SKILL_NAME::FIRE_DASH);
}

void STATE_IDLE::onBtnLB(PLAYER* pPlayer)
{
	pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_01);
	pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
	pPlayer->setAttactDir();
	pPlayer->settingAni();

	//pPlayer->setSkill(PLAYER::SKILL_NAME::FIRE_STRIKE);
	//pPlayer->getSkill()->pushMagicKey(pPlayer->getAttactPosX(), pPlayer->getAttactPosY());

}

void STATE_IDLE::onBtnRB(PLAYER* pPlayer)
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
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_02);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;

		case PLAYER::SKILL_NAME::REBOUNDINGICICLES:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_02);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_03);

			pPlayer->setAttactDir();
			pPlayer->settingAni();

			break;
		case PLAYER::SKILL_NAME::GLACIALCROSS:
			pPlayer->setState(PLAYER::PLAYER_STATE::SKILL_02);

			pPlayer->setAction(PLAYER::ACTION::ATTACK_MOTION_01);
			pPlayer->setAttactDir();
			pPlayer->settingAni();
			break;
		}
	}

}

void STATE_IDLE::onBtnR(PLAYER * pPlayer)
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

void STATE_IDLE::update(PLAYER * pPlayer)
{
}
