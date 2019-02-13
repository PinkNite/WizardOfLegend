#include "stdafx.h"
#include "boss.h"
#include "BossStateIdle.h"
#include "BossStateRun.h"
#include "BossStateDamage.h"
#include "BossStateDeath.h"
#include "BossStateSkill01.h"
#include "BossStateSkill02.h"
#include "BossStateSkill03.h"

BOSS::BOSS() :
	_fMaxHP(0.0f),
	_fCurrentHP(0.0f),
	_fSpeed(0.0f),
	_pAnimation(nullptr),
	_arFrame{ 0, },
	_direction(DIRECTION::RIGHT),
	_action(ACTION::IDLE),
	_fAngleX(0.0f),
	_fAngleY(0.0f)
{
}


BOSS::~BOSS()
{
}

void BOSS::init()
{
	_pBlastImage = IMAGEMANAGER->addFrameImage("IceBlast", "resource/boss/ice/IceBlast.bmp", 256, 256, 1, 1, true, RGB(255, 0, 255));
	_pEffectImage = IMAGEMANAGER->addFrameImage("IceCrystals", "resource/boss/ice/IceCrystals.bmp", 550, 300, 5, 2, true, RGB(255, 0, 255));
	_pWingImage = IMAGEMANAGER->addFrameImage("IceWings", "resource/boss/ice/IceWings.bmp", 840, 360, 7, 4, true, RGB(255, 0, 255));

	OBJECT::init(300, 200, BOSS_RECT_WIDTH, BOSS_RECT_HEIGHT);
	OBJECT::_pImg = IMAGEMANAGER->addFrameImage("iceBossImg", "resource/boss/ice/IceBoss.bmp",
		BOSS_IMAGE_WIDTH, BOSS_IMAGE_HEIGHT, BOSS_MAX_FRAME_X, BOSS_MAX_FRAME_Y, true, RGB(255, 0, 255));

	_pAnimation = new animation();
	_pAnimation->init(BOSS_IMAGE_WIDTH, BOSS_IMAGE_HEIGHT, BOSS_MAX_FRAME_X, BOSS_MAX_FRAME_Y);
	_fMaxHP = 1000.0f;
	_fCurrentHP = 1000.0f;
	_fSpeed = 200.0f;
	_objectName = "IceBoss";
	_timeSet = 0.0f;

	setEnumName();
	setAnimation();

	_direction = DIRECTION::DOWN;
	_action = ACTION::IDLE;

	_pAnimation = KEYANIMANAGER->findAnimation(_objectName, getAnimationKey(_mDirection[_direction], _mAction[_action]));
	_pAnimation->start();

	_pWingsAnimation = KEYANIMANAGER->findAnimation(_objectName, "WingsMin");
	_pWingsAnimation->start();

	initState();
}

void BOSS::update()
{
	_timeSet += TIMEMANAGER->getElapsedTime();

	if (_pCurrentState != nullptr)
	{
		_pCurrentState->update(this);
	}

	handleInputKey();

	KEYANIMANAGER->update();

}

void BOSS::release()
{
	OBJECT::setImage(nullptr);
	_pWingImage = nullptr;
	_pEffectImage = nullptr;
	_pAnimation = nullptr;
	_pWingsAnimation = nullptr;
	_pEffectAnimation = nullptr;
}

void BOSS::render(HDC hdc)
{
	//Rectangle(hdc, OBJECT::_rc);
	int x = static_cast<int>(OBJECT::getPosX());
	int y = static_cast<int>(OBJECT::getPosY());

	// ice wing
	_pWingImage->aniRenderCenter(hdc, x, y, _pWingsAnimation);

	// º¸½º µîÀå ¾À
	if (ACTION::ENTRANCE == _action)
	{
		if (_timeSet > 1.0f)
		{
			_pBlastImage->renderCenter(hdc, x, y);
			// boss charater
			OBJECT::getImage()->aniRenderCenter(hdc, x, y, _pAnimation);
		}
		_pEffectImage->aniRenderCenter(hdc, x, y, _pEffectAnimation);
	}
	else
	{
		// ice wing
		_pWingImage->aniRenderCenter(hdc, x, y, _pWingsAnimation);
		// boss charater
		OBJECT::getImage()->aniRenderCenter(hdc, x, y, _pAnimation);
	}

}

void BOSS::setEnumName()
{
	_mDirection.insert(make_pair(DIRECTION::LEFT, "LEFT"));
	_mDirection.insert(make_pair(DIRECTION::RIGHT, "RIGHT"));
	_mDirection.insert(make_pair(DIRECTION::UP, "BACK"));
	_mDirection.insert(make_pair(DIRECTION::DOWN, "FRONT"));

	_mAction.insert(make_pair(ACTION::IDLE, "IDLE"));
	_mAction.insert(make_pair(ACTION::RUN, "RUN"));
	_mAction.insert(make_pair(ACTION::DASH, "DASH"));

	_mAction.insert(make_pair(ACTION::SPELL_01, "SPELL_01"));
	_mAction.insert(make_pair(ACTION::SPELL_02, "SPELL_02"));
	_mAction.insert(make_pair(ACTION::SPELL_03, "SPELL_03"));

	_mAction.insert(make_pair(ACTION::SKILL_01, "SKILL_01"));
	_mAction.insert(make_pair(ACTION::SKILL_02, "SKILL_02"));
	_mAction.insert(make_pair(ACTION::SKILL_03, "SKILL_03"));

	_mAction.insert(make_pair(ACTION::ENTRANCE, "ENTRANCE"));
	_mAction.insert(make_pair(ACTION::DAMAGE, "DAMAGE"));
	_mAction.insert(make_pair(ACTION::DEATH, "DEATH"));

}

void BOSS::setAnimation()
{
	KEYANIMANAGER->addObject(_objectName);

	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::ENTRANCE], 62, 64, 8, false);
	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::IDLE], 88, 97, 4, true);

	addBossKeyAni(_mDirection[DIRECTION::LEFT], _mAction[ACTION::RUN], 0, 0, 1, true);
	addBossKeyAni(_mDirection[DIRECTION::RIGHT], _mAction[ACTION::RUN], 1, 1, 1, true);
	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::RUN], 2, 2, 1, true);
	addBossKeyAni(_mDirection[DIRECTION::UP], _mAction[ACTION::RUN], 3, 3, 1, true);

	//IMAGEMANAGER->addFrameImage("IceBlast", "resource/boss/ice/IceBlast.bmp", 256, 256, 1, 1, true, RGB(255, 0, 255));

	int effectFrame[10] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "Entrance", "IceCrystals", effectFrame, 8, 4, false, callbackSetBattle, this);

	int idlMaxFrame[10] = { 0, 1, 2, 3, 4, 5, 6 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WingsMaxIdle", "IceWings", idlMaxFrame, 7, 4, true);

	int idlMinFrame[1] = { 14 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WingsMinIdle", "IceWings", idlMinFrame, 1, 2, true);

	int minimize[10] = { 7, 8, 9, 10, 11, 12, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WingsMin", "IceWings", minimize, 7, 4, false, callbackMinWingIdle, this);

	int maximize[10] = { 14, 15, 16, 17, 18, 19, 20 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WingsMax", "IceWings", maximize, 7, 4, false, callbackMaxWingIdle, this);

}

const string BOSS::getAnimationKey(const string & strDir, const string & strAction)
{
	string temp = "";
	temp.append(strDir);
	temp.append("_");
	temp.append(strAction);
	return temp;
}

void BOSS::addBossKeyAni(const string & strDir, const string & strAction, int startFrame, int endFrame, int fps, bool isLoop)
{
	int nFrameCount(0);
	int nFrameTmp(0);

	nFrameTmp = startFrame;
	if (nFrameTmp > endFrame)
	{
		while (nFrameTmp >= endFrame)
		{
			_arFrame[nFrameCount] = nFrameTmp;
			nFrameTmp--;
			nFrameCount++;
		}
	}
	else
	{
		while (nFrameTmp <= endFrame)
		{
			_arFrame[nFrameCount] = nFrameTmp;
			nFrameTmp++;
			nFrameCount++;
		}
	}

	KEYANIMANAGER->addArrayFrameAnimation(_objectName, getAnimationKey(strDir, strAction),
		"iceBossImg", _arFrame, nFrameCount, fps, isLoop);

}

void BOSS::setState(BOSS_STATE bossState)
{
	if (_pCurrentState == _arState[static_cast<int>(bossState)])  return;

	_pCurrentState = _arState[static_cast<int>(bossState)];
	//this->handleState(bossState);
}

void BOSS::setAction(ACTION action)
{
	_action = action;
	startAnimation();
}

void BOSS::setDirection(DIRECTION direction)
{
	_direction = direction;
}

void BOSS::startAnimation()
{
	_pAnimation = KEYANIMANAGER->findAnimation(_objectName, getAnimationKey(_mDirection[_direction], _mAction[_action]));
	_pAnimation->start();
}

void BOSS::handleState(BOSS_STATE bossState)
{
	BossState* state = _pCurrentState->handleState(this, bossState);
	if (state != nullptr)
	{
		delete _pCurrentState;
		_pCurrentState = state;

		_pCurrentState->enter(this);
	}
}

void BOSS::initState()
{
	_arState[int(BOSS_STATE::IDLE)] = new BossStateIdle();
	_arState[int(BOSS_STATE::RUN)] = new BossStateRun();
}

void BOSS::handleInputKey()
{
	float speed = _fSpeed * TIMEMANAGER->getElapsedTime();

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		setState(BOSS_STATE::RUN);
		setDirection(DIRECTION::UP);
		moveUp(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		setState(BOSS_STATE::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		setState(BOSS_STATE::RUN);
		setDirection(DIRECTION::LEFT);
		moveLeft(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		setState(BOSS_STATE::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		setState(BOSS_STATE::RUN);
		setDirection(DIRECTION::RIGHT);
		moveRight(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		setState(BOSS_STATE::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		setState(BOSS_STATE::RUN);
		setDirection(DIRECTION::DOWN);
		moveDown(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		setState(BOSS_STATE::IDLE);
	}

}

void BOSS::moveUp(float speed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI / 2.0f, speed));
	setRect();
}

void BOSS::moveDown(float speed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI / 2.0f + PI, speed));
	setRect();
}

void BOSS::moveLeft(float speed)
{
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(PI, speed));
	setRect();
}

void BOSS::moveRight(float speed)
{
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(0.0f, speed));
	setRect();
}

void BOSS::dash(float offset)
{
}

void BOSS::setRect()
{
	OBJECT::_rc = RectMakeCenter(
		static_cast<int>(OBJECT::_posX),
		static_cast<int>(OBJECT::_posY),
		BOSS_RECT_WIDTH, BOSS_RECT_HEIGHT);
}

void BOSS::moveBoss()
{
	if (_pCurrentState == _arState[static_cast<int>(BOSS_STATE::RUN)])
	{
		float speed = _fSpeed * TIMEMANAGER->getElapsedTime();

		switch (_direction)
		{
		case BOSS::DIRECTION::LEFT:
			moveLeft(speed);
			break;
		case BOSS::DIRECTION::RIGHT:
			moveRight(speed);
			break;
		case BOSS::DIRECTION::UP:
			moveUp(speed);
			break;
		case BOSS::DIRECTION::DOWN:
			moveDown(speed);
			break;
		case BOSS::DIRECTION::L_UP:
			moveLeft(speed);
			moveUp(speed);
			break;
		case BOSS::DIRECTION::L_DOWN:
			moveLeft(speed);
			moveDown(speed);
			break;
		case BOSS::DIRECTION::R_UP:
			moveRight(speed);
			moveUp(speed);
			break;
		case BOSS::DIRECTION::R_DOWN:
			moveRight(speed);
			moveDown(speed);
			break;
		}
	}
}

void BOSS::setDirectUp()
{
}

void BOSS::setDirectDown()
{
}

void BOSS::setDirectLeft()
{
}

void BOSS::setDirectRight()
{
}

void BOSS::showBoss()
{
	_direction = DIRECTION::DOWN;
	_action = ACTION::ENTRANCE;

	_pWingsAnimation = KEYANIMANAGER->findAnimation(_objectName, "WingsMin");
	_pWingsAnimation->start();

	_pAnimation = KEYANIMANAGER->findAnimation(_objectName, getAnimationKey(_mDirection[_direction], _mAction[_action]));
	_pAnimation->start();

	_pEffectAnimation = KEYANIMANAGER->findAnimation(_objectName, "Entrance");
	_pEffectAnimation->start();

}

void BOSS::setBattle()
{
	setState(BOSS_STATE::IDLE);

	_direction = DIRECTION::DOWN;
	_action = ACTION::IDLE;

	_pAnimation = KEYANIMANAGER->findAnimation(_objectName, getAnimationKey(_mDirection[_direction], _mAction[_action]));
	_pAnimation->start();

	_pWingsAnimation = KEYANIMANAGER->findAnimation(_objectName, "WingsMax");
	_pWingsAnimation->start();

}

void BOSS::setWings(bool isMax)
{
	if (isMax)
		_pWingsAnimation = KEYANIMANAGER->findAnimation(_objectName, "WingsMaxIdle");
	else
		_pWingsAnimation = KEYANIMANAGER->findAnimation(_objectName, "WingsMinIdle");

	_pWingsAnimation->start();
}

void BOSS::callbackSetBattle(void * obj)
{
	BOSS* pBoss = (BOSS*)obj;
	pBoss->setBattle();
}

void BOSS::callbackMinWingIdle(void * obj)
{
	BOSS* pBoss = (BOSS*)obj;
	pBoss->setWings(false);
}

void BOSS::callbackMaxWingIdle(void * obj)
{
	BOSS* pBoss = (BOSS*)obj;
	pBoss->setWings(true);
}