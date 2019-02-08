#include "stdafx.h"
#include "player.h"
#include "state.h"
#include "stateDamage.h"
#include "stateDash.h"
#include "stateIdle.h"
#include "stateRun.h"
#include "stateSkillFour.h"
#include "stateSkillOne.h"
#include "stateSkillThree.h"
#include "stateSkillTwo.h"
#include "stateDeath.h"

PLAYER::PLAYER() :
	_fMaxHealthPoint(0.0f),
	_fCurrentHealthPoint(0.0f),
	_fSpeed(0.0f),
	_fArmor(0.0f),
	_fEvasion(0.0f),
	_fCriticalHit(0.0f),
	_fSkillDelayTime{},
	_arDirection{},
	_arAction{},
	_rcMovingCollision{},
	_rcDamageCollision{},
	_pAnimation(nullptr),
	_arFrame{},
	_direction(PLAYER::DIRECTION::FORWARD),
	_action(PLAYER::ACTION::IDLE),
	_fAngleX(0.0f),
	_fAngleY(0.0f)
{
}

PLAYER::~PLAYER()
{
}

void PLAYER::load()
{
}

void PLAYER::save()
{
}

void PLAYER::init()
{
	//초기 위치 중앙값
	OBJECT::init(200, 200, 100, 100);
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("wizardSprites", "resource/player/wizardSprites.bmp", WIZARD_SPRITE_WIDTH, WIZARD_SPRITE_HEIGHT, WIZARD_SPRITE_MAXFRAMEX, WIZARD_SPRITE_MAXFRAMEY, true, RGB(255, 0, 255)));
	setEnumName();
	_pAnimation = new animation();
	_pAnimation->init(WIZARD_SPRITE_WIDTH, WIZARD_SPRITE_HEIGHT, WIZARD_SPRITE_MAXFRAMEX, WIZARD_SPRITE_MAXFRAMEY);
	_fMaxHealthPoint = 500.0f;
	_fCurrentHealthPoint = 500.0f;
	_fSpeed = 200.0f;
	_fArmor = 0.0f;
	_fEvasion = 0.0f;
	_fCriticalHit = 0.0f;
	_strObjectName = "player";
	setAnimation();
	_direction = PLAYER::DIRECTION::FORWARD;
	_action = PLAYER::ACTION::IDLE;
	_pAnimation = KEYANIMANAGER->findAnimation(_strObjectName, addAniString(_arDirection[static_cast<int>(_direction)], _arAction[static_cast<int>(_action)]));
	_pAnimation->start();
	_eMoveDirection = PLAYER::MOVE_DIRECTION::NONE;
	initState();
}

void PLAYER::update()
{
	//move();

	input();
	_pCurrentState->update(this);

	KEYANIMANAGER->update();

}

void PLAYER::release()
{
	OBJECT::setImage(nullptr);
	_pAnimation = nullptr;
}

void PLAYER::render(HDC hdc)
{
	Rectangle(hdc, _rcMovingCollision);
	OBJECT::getImage()->aniRenderCenter(hdc, static_cast<int>(OBJECT::getPosX()), static_cast<int>(OBJECT::getPosY()), _pAnimation);

}

void PLAYER::setEnumName()
{
	_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)] = "LEFT";
	_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)] = "RIGHT";
	_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)] = "FORWARD";
	_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)] = "BACK";

	_arAction[static_cast<int>(PLAYER::ACTION::IDLE)] = "IDLE";
	_arAction[static_cast<int>(PLAYER::ACTION::RUN)] = "RUN";
	_arAction[static_cast<int>(PLAYER::ACTION::DASH)] = "DASH";
	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)] = "ATTACK_MOTION_01";
	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)] = "ATTACK_MOTION_02";
	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)] = "ATTACK_MOTION_03";
	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)] = "ATTACK_MOTION_04";
	_arAction[static_cast<int>(PLAYER::ACTION::DAMAGE)] = "DAMAGE";
	_arAction[static_cast<int>(PLAYER::ACTION::DEATH)] = "DEATH";
}

void PLAYER::setAnimation()
{
	KEYANIMANAGER->addObject(_strObjectName);

	for (int i = 0; i < static_cast<int>(PLAYER::DIRECTION::MAX); i++)
	{
		addPlayerKeyAni(_arDirection[i], _arAction[static_cast<int>(PLAYER::ACTION::IDLE)], i, i, 1, true);
	}
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)],	_arAction[static_cast<int>(PLAYER::ACTION::RUN)],  4, 13, 12, true);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)],	_arAction[static_cast<int>(PLAYER::ACTION::RUN)], 14, 23, 12, true);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)],	_arAction[static_cast<int>(PLAYER::ACTION::RUN)], 33, 24, 12, true);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)],	_arAction[static_cast<int>(PLAYER::ACTION::RUN)], 34, 43, 12, true);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::DASH)], 44, 47, 8, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)],	_arAction[static_cast<int>(PLAYER::ACTION::DASH)], 48, 53, 12, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)],	_arAction[static_cast<int>(PLAYER::ACTION::DASH)], 59, 54, 12, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)],	_arAction[static_cast<int>(PLAYER::ACTION::DASH)], 60, 62, 6, false);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)], 63, 71, 9, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)], 179, 190, 12, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)], 202, 191, 12, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)], 72, 82, 11, false);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 83, 93, 11, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 10, false);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)], 104, 112, 9, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)], 113, 121, 9, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)], 130, 122, 9, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)], 131, 141, 11, false);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)], 142, 150, 9, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)], 151, 158, 8, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)], 166, 159, 8, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)],	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)], 167, 178, 12, false);

	for (int i = 0; i < static_cast<int>(PLAYER::DIRECTION::MAX); i++)
	{
		addPlayerKeyAni(_arDirection[i], _arAction[static_cast<int>(PLAYER::ACTION::DAMAGE)], i + 203, i+203, 1, true);
	}

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::DEATH)], 207,216,10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)],	_arAction[static_cast<int>(PLAYER::ACTION::DEATH)], 207,216,10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)],	_arAction[static_cast<int>(PLAYER::ACTION::DEATH)], 207,216,10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)],	_arAction[static_cast<int>(PLAYER::ACTION::DEATH)], 207,216,10, false);
}

const string PLAYER::addAniString(const string & strDir, const string & strAction)
{
	string strTmp = "";
	strTmp.append(strDir);
	strTmp.append("_");
	strTmp.append(strAction);
	return strTmp;
}

void PLAYER::addPlayerKeyAni(const string & strDir, const string & strAction, int nStartFrame, int nEndFrame, int nFPS, bool bIsLoop)
{
	int nFrameCount(0);
	int nFrameTmp(0);

	nFrameTmp = nStartFrame;
	if (nStartFrame > nEndFrame)
	{
		//리버스용 주로 L
		while (nFrameTmp >= nEndFrame) {
			_arFrame[nFrameCount] = nFrameTmp;
			nFrameTmp--;
			nFrameCount++;
		}
	}
	else
	{
		while (nFrameTmp <= nEndFrame) {
			_arFrame[nFrameCount] = nFrameTmp;
			nFrameTmp++;
			nFrameCount++;
		}
	}

	KEYANIMANAGER->addArrayFrameAnimation(_strObjectName, addAniString(strDir, strAction), "wizardSprites", _arFrame, nFrameCount, nFPS, bIsLoop);

}


void PLAYER::settingPos()
{
	_rcDamageCollision = RectMakeCenter(static_cast<int>(OBJECT::getPosX()), static_cast<int>(OBJECT::getPosY()),
		WIZARD_COLLISION_RECT_WIDTH, WIZARD_COLLISION_RECT_HEIGHT);

	_rcMovingCollision = RectMakeCenter(static_cast<int>(OBJECT::getPosX()), static_cast<int>(OBJECT::getPosY()) + WIZARD_MOVING_RECT_SIZE/2,
		WIZARD_MOVING_RECT_SIZE, WIZARD_MOVING_RECT_SIZE);
}

void PLAYER::settingAni()
{
	_pAnimation = KEYANIMANAGER->findAnimation(_strObjectName, addAniString(_arDirection[static_cast<int>(_direction)], _arAction[static_cast<int>(_action)]));
	_pAnimation->start();
}

void PLAYER::setAction(PLAYER::ACTION eAction)
{
	_action = eAction;
}

void PLAYER::moveUp(float fSpeed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI/2.0f, fSpeed));
	settingPos();
}

void PLAYER::moveDown(float fSpeed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI / 2.0f + PI, fSpeed));
	settingPos();
}

void PLAYER::moveLeft(float fSpeed)
{
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(PI, fSpeed));
	settingPos();
}

void PLAYER::moveRight(float fSpeed)
{
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(0.0f, fSpeed));
	settingPos();
}

void PLAYER::dash(float fOffset)
{
	float fSpeed = fOffset * _fSpeed * TIMEMANAGER->getElapsedTime();
	
	if (_eMoveDirection == PLAYER::MOVE_DIRECTION::NONE)
	{
		if (_direction == PLAYER::DIRECTION::LEFT)
		{
			_eMoveDirection = PLAYER::MOVE_DIRECTION::LEFT;
		}
		else if (_direction == PLAYER::DIRECTION::RIGHT)
		{
			_eMoveDirection = PLAYER::MOVE_DIRECTION::RIGHT;
		}
		else if (_direction == PLAYER::DIRECTION::FORWARD)
		{
			_eMoveDirection = PLAYER::MOVE_DIRECTION::BOTTOM;
		}
		else if (_direction == PLAYER::DIRECTION::BACK)
		{
			_eMoveDirection = PLAYER::MOVE_DIRECTION::TOP;
		}
	}


	switch (_eMoveDirection)
	{

	case PLAYER::MOVE_DIRECTION::LEFT:
		moveLeft(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT:
		moveRight(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::TOP:
		moveUp(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::BOTTOM:
		moveDown(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::LEFT_TOP:
		moveLeft(fSpeed);
		moveUp(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::LEFT_BOTTOM:
		moveLeft(fSpeed);
		moveDown(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT_TOP:
		moveUp(fSpeed);
		moveRight(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT_BOTTOM:
		moveRight(fSpeed);
		moveDown(fSpeed);
		break;
	}

}



void PLAYER::movePlayer()
{
	float fSpeed = _fSpeed * TIMEMANAGER->getElapsedTime();
	switch (_eMoveDirection)
	{
	case PLAYER::MOVE_DIRECTION::NONE:
		setState(PLAYER::PLAYER_STATE::IDLE);
		setAction(PLAYER::ACTION::IDLE);
		settingAni();
		break;
	case PLAYER::MOVE_DIRECTION::LEFT:
		moveLeft(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT:
		moveRight(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::TOP:
		moveUp(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::BOTTOM:
		moveDown(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::LEFT_TOP:
		moveLeft(fSpeed);
		moveUp(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::LEFT_BOTTOM:
		moveLeft(fSpeed);
		moveDown(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT_TOP:
		moveUp(fSpeed);
		moveRight(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT_BOTTOM:
		moveRight(fSpeed);
		moveDown(fSpeed);
		break;
	}
	

}

void PLAYER::setDirectionUp()
{
	_eMoveDirection = PLAYER::MOVE_DIRECTION::TOP;

}

void PLAYER::setDirectionDown()
{
	_eMoveDirection = PLAYER::MOVE_DIRECTION::BOTTOM;

}

void PLAYER::setDirectionLeft()
{
	if (_eMoveDirection == PLAYER::MOVE_DIRECTION::TOP)
	{
		_eMoveDirection = PLAYER::MOVE_DIRECTION::LEFT_TOP;
	}
	else if (_eMoveDirection == PLAYER::MOVE_DIRECTION::BOTTOM)
	{
		_eMoveDirection = PLAYER::MOVE_DIRECTION::LEFT_BOTTOM;
	}
	else
	{
		_eMoveDirection = PLAYER::MOVE_DIRECTION::LEFT;
	}
}

void PLAYER::setDirectionRight()
{
	if (_eMoveDirection == PLAYER::MOVE_DIRECTION::TOP)
	{
		_eMoveDirection = PLAYER::MOVE_DIRECTION::RIGHT_TOP;
	}
	else if (_eMoveDirection == PLAYER::MOVE_DIRECTION::BOTTOM)
	{
		_eMoveDirection = PLAYER::MOVE_DIRECTION::RIGHT_BOTTOM;
	}
	else
	{
		_eMoveDirection = PLAYER::MOVE_DIRECTION::RIGHT;
	}
}

void PLAYER::input()
{
	if (_pCurrentState == _arState[static_cast<int>(PLAYER::PLAYER_STATE::RUN)])
	{
		_eMoveDirection = PLAYER::MOVE_DIRECTION::NONE;
	}

	if (KEYMANAGER->isKeyDown('W'))
	{
		_pCurrentState->onBtnW(this);
	}
	else if (KEYMANAGER->isKeyDown('S'))
	{
		_pCurrentState->onBtnS(this);
	}
	if (KEYMANAGER->isKeyDown('A'))
	{
		_pCurrentState->onBtnA(this);
	}
	else if (KEYMANAGER->isKeyDown('D'))
	{
		_pCurrentState->onBtnD(this);
	}
	if (KEYMANAGER->isKeyDown(VK_SPACE))
	{
		_pCurrentState->onBtnSpace(this);
	}
}

void PLAYER::initState()
{
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::IDLE)] = new STATE_IDLE();
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::RUN)] = new STATE_RUN();
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::DASH)] = new STATE_DASH();
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::DAMAGE)] = new STATE_DAMAGE();
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::DEATH)] = new STATE_DEATH();
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::SKILL_01)] = new STATE_SKILL_ONE();
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::SKILL_02)] = new STATE_SKILL_TWO();
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::SKILL_03)] = new STATE_SKILL_THREE();
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::SKILL_04)] = new STATE_SKILL_FOUR();
	//
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::SKILL_05)] = new STATE_SKILL_FOUR();

	_pCurrentState = _arState[static_cast<int>(PLAYER::PLAYER_STATE::IDLE)];


}



void PLAYER::setState(PLAYER::PLAYER_STATE ePlayerState)
{
	_pCurrentState = _arState[static_cast<int>(ePlayerState)];
}

void PLAYER::setDirection(PLAYER::DIRECTION eDirection)
{
	_direction = eDirection;
}


