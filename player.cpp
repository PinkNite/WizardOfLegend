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

#include "fireDash.h"
#include "fireStrike.h"

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
	_fAngleY(0.0f),
	_pCurrentState(nullptr),
	_arState{},
	_eMoveDirection(PLAYER::MOVE_DIRECTION::NONE),
	_pCirEffect(nullptr),
	_fAttackDirAngle(0.0f),
	_arStandardAngle{},
	_fAttackPosX(0.0f),
	_fAttackPosY(0.0f)
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
	_fSpeed = 400.0f;
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
	_pCirEffect = new CIRCLEEFFECT();
	_pCirEffect->init();
	_fAttackDirAngle = PI + PI / 2.0f;

	float fTmpAngle = PI / 4.0f;
	for (int i = 0; i < 4; i++)
	{
		_arStandardAngle[i] = fTmpAngle;
		fTmpAngle += PI / 2.0f;
	}

	//임시
	_pFireDash = new FIREDASH();
	_pFireDash->init();
	_pFireStrike = new FIRESTRIKE();
	_pFireStrike->init();

	_fAttackPosX = 0.0f;
	_fAttackPosY = 0.0f;
}

void PLAYER::update()
{

	_fAttackDirAngle = getAngle(OBJECT::getPosX(), OBJECT::getPosY() + WIZARD_MOVING_RECT_SIZE / 2.0f, static_cast<float>(_ptMouse.x), static_cast<float>(_ptMouse.y));
	_pCirEffect->update(OBJECT::getPosX(), OBJECT::getPosY() + WIZARD_MOVING_RECT_SIZE / 2.0f, _fAttackDirAngle);

	_fAttackPosX = OBJECT::getPosX() + Mins::presentPowerX(_fAttackDirAngle, 64.0f);
	_fAttackPosY = OBJECT::getPosY() + Mins::presentPowerY(_fAttackDirAngle, 64.0f);

	input();
	_pCurrentState->update(this);

	KEYANIMANAGER->update();

}

void PLAYER::release()
{
	OBJECT::setImage(nullptr);
	_pAnimation = nullptr;

	_pCirEffect->release();
	delete _pCirEffect;
	_pCirEffect = nullptr;

}

void PLAYER::render(HDC hdc)
{
	_pCirEffect->render(hdc);
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
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::RUN)], 4, 13, 12, true);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::RUN)], 14, 23, 12, true);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::RUN)], 33, 24, 12, true);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::RUN)], 34, 43, 12, true);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::DASH)], 44, 47, 8, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::DASH)], 48, 53, 12, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::DASH)], 59, 54, 12, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::DASH)], 60, 62, 6, false);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)], 63, 71, 9, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)], 179, 190, 12, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)], 202, 191, 12, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_01)], 72, 82, 11, false);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 83, 93, 11, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 10, false);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)], 104, 112, 18, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)], 113, 121, 18, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)], 130, 122, 18, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_03)], 131, 141, 22, false);

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)], 142, 150, 18, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)], 151, 158, 16, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)], 166, 159, 16, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_04)], 167, 178, 24, false);

	for (int i = 0; i < static_cast<int>(PLAYER::DIRECTION::MAX); i++)
	{
		addPlayerKeyAni(_arDirection[i], _arAction[static_cast<int>(PLAYER::ACTION::DAMAGE)], i + 203, i + 203, 1, true);
	}

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::DEATH)], 207, 216, 10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::DEATH)], 207, 216, 10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::DEATH)], 207, 216, 10, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::DEATH)], 207, 216, 10, false);
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

	_rcMovingCollision = RectMakeCenter(static_cast<int>(OBJECT::getPosX()), static_cast<int>(OBJECT::getPosY()) + WIZARD_MOVING_RECT_SIZE / 2,
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

void PLAYER::changeAttactMotion()
{
	if (_action == PLAYER::ACTION::ATTACK_MOTION_03)
	{
		_action = PLAYER::ACTION::ATTACK_MOTION_04;
	}
	else if (_action == PLAYER::ACTION::ATTACK_MOTION_04) {
		_action = PLAYER::ACTION::ATTACK_MOTION_03;

	}
}

void PLAYER::moveUp(float fSpeed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI / 2.0f, fSpeed));
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

void PLAYER::moveUpLeft(float fSpeed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI / 2.0f + PI / 4.0f, fSpeed));
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(PI / 2.0f + PI / 4.0f, fSpeed));
	settingPos();
}

void PLAYER::moveUpRight(float fSpeed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI / 4.0f, fSpeed));
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(PI / 4.0f, fSpeed));
	settingPos();
}

void PLAYER::moveDownLeft(float fSpeed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI + PI / 4.0f, fSpeed));
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(PI + PI / 4.0f, fSpeed));
	settingPos();
}

void PLAYER::moveDownRight(float fSpeed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI + PI / 2.0f + PI / 4.0f, fSpeed));
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(PI + PI / 2.0f + PI / 4.0f, fSpeed));
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
		moveUpLeft(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::LEFT_BOTTOM:
		moveDownLeft(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT_TOP:
		moveUpRight(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT_BOTTOM:
		moveDownRight(fSpeed);
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
		moveUpLeft(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::LEFT_BOTTOM:
		moveDownLeft(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT_TOP:
		moveUpRight(fSpeed);
		break;
	case PLAYER::MOVE_DIRECTION::RIGHT_BOTTOM:
		moveDownRight(fSpeed);
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

void PLAYER::moveAttack()
{
	float fSpeed = 500.0f * TIMEMANAGER->getElapsedTime();
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(_fAttackDirAngle, fSpeed));
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(_fAttackDirAngle, fSpeed));
	settingPos();
}

void PLAYER::setAttactDir()
{
	//_direction
	//0~1 -> up
	//1~2 -> left
	//2~3 -> down
	//3~0 ->right
	if (_arStandardAngle[0] <= _fAttackDirAngle &&
		_arStandardAngle[1] > _fAttackDirAngle)
	{
		_direction = PLAYER::DIRECTION::BACK;
	}
	else if (_arStandardAngle[1] <= _fAttackDirAngle &&
		_arStandardAngle[2] > _fAttackDirAngle)
	{
		_direction = PLAYER::DIRECTION::LEFT;
	}
	else if (_arStandardAngle[2] <= _fAttackDirAngle &&
		_arStandardAngle[3] > _fAttackDirAngle)
	{
		_direction = PLAYER::DIRECTION::FORWARD;
	}
	else if (_arStandardAngle[3] >= _fAttackDirAngle ||
		_arStandardAngle[1] < _fAttackDirAngle)
	{
		_direction = PLAYER::DIRECTION::RIGHT;
	}
}

void PLAYER::setLink(MAGICMGR * pMagicMgr, SKILL_EFFECT_MGR * pSkillEffectMgr)
{
	_pMagicMgr = pMagicMgr;
	_pSkillEffectMgr = pSkillEffectMgr;

	_pFireDash->setMagicMgr(_pMagicMgr);
	_pFireDash->setPlayer(this);
	_pFireDash->setSkillEffectMgr(_pSkillEffectMgr);
	
	_pFireStrike->setMagicMgr(_pMagicMgr);
	_pFireStrike->setPlayer(this);
	_pFireStrike->setSkillEffectMgr(_pSkillEffectMgr);


}

void PLAYER::setSkill(PLAYER::SKILL_NAME eSkillName)
{
	switch (eSkillName)
	{
	case PLAYER::SKILL_NAME::NONE:
		break;
	case PLAYER::SKILL_NAME::FIRE_DASH:
		_pCurrentSkill = _pFireDash;
		break;
	case PLAYER::SKILL_NAME::FIRE_STRIKE:
		_pCurrentSkill = _pFireStrike;
		break;
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
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_pCurrentState->onBtnLB(this);
	}
	if (KEYMANAGER->isKeyDown(VK_RBUTTON))
	{
		_pCurrentState->onBtnRB(this);
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RBUTTON))
	{
		//발동
		//버튼업도 상태에 넣어야하나?
		_pCurrentState->onBtnRB(this);
	}
	if (KEYMANAGER->isKeyDown('Q'))
	{
		_pCurrentState->onBtnQ(this);

	}
	if (KEYMANAGER->isOnceKeyUp('Q'))
	{
		//발동
		//버튼업도 상태에 넣어야하나?
		//내부에서 처리하자 걍
		_pCurrentState->onBtnQ(this);

	}
	if (KEYMANAGER->isKeyDown('E'))
	{
		_pCurrentState->onBtnE(this);
	}
	if (KEYMANAGER->isOnceKeyUp('E'))
	{
		//발동
		//버튼업도 상태에 넣어야하나?
		_pCurrentState->onBtnE(this);
	}
	if (KEYMANAGER->isKeyDown('R'))
	{
		_pCurrentState->onBtnR(this);

	}
	if (KEYMANAGER->isOnceKeyUp('R'))
	{
		//발동
		//버튼업도 상태에 넣어야하나?
		_pCurrentState->onBtnR(this);

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


