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
#include "stateSkillFive.h"


#include "fireDash.h"
#include "fireStrike.h"
#include "skillnone.h"
#include "shokeNova.h"
#include "chainLightning.h"
#include "stoneShot.h"
#include "shatteringStrike.h"
#include "reboundingIcicles.h"
#include "glacialCross.h"


PLAYER::PLAYER() :
	_fMaxHealthPoint(0.0f),
	_fCurrentHealthPoint(0.0f),
	_fSpeed(0.0f),
	_fArmor(0.0f),
	_fEvasion(0.0f),
	_fCriticalHit(0.0f),
	_arSkillDelayTime{},
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
	_fAttackPosY(0.0f),
	_nNormalSkillCoount(0)
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
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("wizardSprites", "resource/player/wizardSprite.bmp", WIZARD_SPRITE_WIDTH, WIZARD_SPRITE_HEIGHT, WIZARD_SPRITE_MAXFRAMEX, WIZARD_SPRITE_MAXFRAMEY, true, RGB(255, 0, 255)));
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
	
	settingSkill();

	_nNormalSkillCoount = 0;

	_fAttackPosX = 0.0f;
	_fAttackPosY = 0.0f;
}

void PLAYER::update()
{
	for (int i = 0; i < static_cast<int>(PLAYER::SKILL_NAME::MAX); i++)
	{
		if (_arCurrentDelayTime[i] < _arSkillDelayTime[i])
		{
			_arCurrentDelayTime[i] += TIMEMANAGER->getElapsedTime();
		}
	}



	_fAttackDirAngle = getAngle(OBJECT::getPosX(), OBJECT::getPosY() + WIZARD_MOVING_RECT_SIZE / 2.0f, static_cast<float>(_ptMouse.x), static_cast<float>(_ptMouse.y));
	_pCirEffect->update(OBJECT::getPosX(), OBJECT::getPosY() + WIZARD_MOVING_RECT_SIZE / 2.0f, _fAttackDirAngle);

	_fAttackPosX = OBJECT::getPosX() + Mins::presentPowerX(_fAttackDirAngle, 64.0f);
	_fAttackPosY = OBJECT::getPosY() + Mins::presentPowerY(_fAttackDirAngle, 64.0f);

	input();
	_pCurrentSkill->update();
	_pCurrentState->update(this);


	//땜방 ㅋㅋㅋ
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::CHAIN_LIGHTNING)]->update();
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::REBOUNDINGICICLES)]->update();

	//KEYANIMANAGER->update();


	//임시 피담
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		_fCurrentHealthPoint -= 10.0f;
	}
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
	_arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_05)] = "ATTACK_MOTION_05";
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

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 83, 93, 22, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 20, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 20, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_02)], 94, 103, 20, false);

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

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_05)],	217, 227, 22, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_05)],	228, 236, 18, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_05)],		245, 237, 18, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)], _arAction[static_cast<int>(PLAYER::ACTION::ATTACK_MOTION_05)],		246, 253, 16, false);

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

void PLAYER::settingSkill()
{
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::NONE)] = new NONESKILL();
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::FIRE_DASH)] = new FIREDASH();
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::FIRE_STRIKE)] = new FIRESTRIKE();
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::SHOKE_NOVA)] = new SHOKENOVA();
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::CHAIN_LIGHTNING)] = new CHAINLIGHTNING();
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::STONE_SHOT)] = new STONESHOT();
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::SHATTERINGSTRIKE)] = new SHATTERINGSTRIKE();
	_arSkill[static_cast<int>(PLAYER::SKILL_NAME::REBOUNDINGICICLES)] = new REBOUNDINGICICLES();

	for (int i = 0; i < static_cast<int>(PLAYER::SKILL_NAME::MAX); i++)
	{
		_arSkill[i]->init(static_cast<PLAYER::SKILL_NAME>(i));
		_arCurrentDelayTime[i] = 0.0f;
		
	}
	_pCurrentSkill = _arSkill[static_cast<int>(PLAYER::SKILL_NAME::NONE)];



	_arSkillDelayTime[static_cast<int>(PLAYER::SKILL_NAME::NONE)] = 0.0f;
	_arSkillDelayTime[static_cast<int>(PLAYER::SKILL_NAME::FIRE_DASH)] = 5.0f;
	_arSkillDelayTime[static_cast<int>(PLAYER::SKILL_NAME::FIRE_STRIKE)] = 0.5f;

	_arSkillDelayTime[static_cast<int>(PLAYER::SKILL_NAME::SHOKE_NOVA)] = 5.0f;
	_arSkillDelayTime[static_cast<int>(PLAYER::SKILL_NAME::CHAIN_LIGHTNING)] = 5.0f;

	_arSkillDelayTime[static_cast<int>(PLAYER::SKILL_NAME::STONE_SHOT)] = 0.5f;
	_arSkillDelayTime[static_cast<int>(PLAYER::SKILL_NAME::SHATTERINGSTRIKE)] = 5.0f;
	_arSkillDelayTime[static_cast<int>(PLAYER::SKILL_NAME::REBOUNDINGICICLES)] = 4.0f;

	for (int i = 0; i < static_cast<int>(PLAYER::SKILL_NAME::MAX); i++)
	{
		_arCurrentDelayTime[i] = _arSkillDelayTime[i];
	}


	for (int i = 0; i < static_cast<int>(PLAYER::SKILL_KEY::MAX); i++)
	{
		_arSettingSkill[i] = PLAYER::SKILL_NAME::NONE;
	}

	//임시적으로 쓰는것 이제 유아이랑도 엮어서 처리해야함
	_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_SPACE)] = PLAYER::SKILL_NAME::FIRE_DASH;
	_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::LBUTTON)] = PLAYER::SKILL_NAME::FIRE_STRIKE;
	_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_Q)] = PLAYER::SKILL_NAME::SHOKE_NOVA;
	_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::RBUTTON)] = PLAYER::SKILL_NAME::CHAIN_LIGHTNING;
	_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_E)] = PLAYER::SKILL_NAME::SHATTERINGSTRIKE;
	_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_R)] = PLAYER::SKILL_NAME::REBOUNDINGICICLES;

	//
	_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::LBUTTON)] = PLAYER::SKILL_NAME::STONE_SHOT;

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

	for (int i = 0; i < static_cast<int>(PLAYER::SKILL_NAME::MAX); i++)
	{
		_arSkill[i]->setMagicMgr(_pMagicMgr);
		_arSkill[i]->setPlayer(this);
		_arSkill[i]->setSkillEffectMgr(_pSkillEffectMgr);
	}
}

void PLAYER::setSkill(PLAYER::SKILL_NAME eSkillName)
{
	_pCurrentSkill = _arSkill[static_cast<int>(eSkillName)];
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
		setSkill(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_SPACE)]);

	}
	if (_pCurrentState != _arState[static_cast<int>(PLAYER::PLAYER_STATE::DASH)])
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_pCurrentState->onBtnLB(this);
			setSkill(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::LBUTTON)]);
			_pCurrentSkill->pushMagicKey(getAttactPosX(), getAttactPosY());

		}
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_pCurrentSkill->pullMagicKey();
		}
		if (KEYMANAGER->isKeyDown(VK_RBUTTON))
		{
			_pCurrentState->onBtnRB(this);
			if (_arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::RBUTTON)])] >= _arSkillDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::RBUTTON)])])
			{
				setSkill(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::RBUTTON)]);
				_pCurrentSkill->pushMagicKey(getAttactPosX(), getAttactPosY());
				_arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::RBUTTON)])] = 0;
			}
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RBUTTON))
		{
			//발동
			//버튼업도 상태에 넣어야하나?
			_pCurrentState->onBtnRB(this);
			_pCurrentSkill->pullMagicKey();
		}

		if (KEYMANAGER->isKeyDown('Q'))
		{
			_pCurrentState->onBtnQ(this);
			if (_arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_Q)])] >= _arSkillDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_Q)])])
			{
				setSkill(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_Q)]);
				_pCurrentSkill->pushMagicKey(getAttactPosX(), getAttactPosY());
				_arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_Q)])] = 0;
			}

		}
		if (KEYMANAGER->isOnceKeyUp('Q'))
		{
			//발동
			//버튼업도 상태에 넣어야하나?
			//내부에서 처리하자 걍
			_pCurrentState->onBtnQ(this);
			_pCurrentSkill->pullMagicKey();

		}
		if (KEYMANAGER->isKeyDown('E'))
		{
			_pCurrentState->onBtnE(this);
			if (_arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_E)])] >= _arSkillDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_E)])])
			{
				setSkill(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_E)]);
				_pCurrentSkill->pushMagicKey(getAttactPosX(), getAttactPosY());
				_arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_E)])] = 0;
			}
		}
		if (KEYMANAGER->isOnceKeyUp('E'))
		{
			//발동
			//버튼업도 상태에 넣어야하나?
			_pCurrentState->onBtnE(this);
			_pCurrentSkill->pullMagicKey();

		}
		if (KEYMANAGER->isKeyDown('R'))
		{
			_pCurrentState->onBtnR(this);
			if (_arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_R)])] >= _arSkillDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_R)])])
			{
				setSkill(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_R)]);
				_pCurrentSkill->pushMagicKey(getAttactPosX(), getAttactPosY());
				_arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(PLAYER::SKILL_KEY::BTN_R)])] = 0;
			}

		}
		if (KEYMANAGER->isOnceKeyUp('R'))
		{
			//발동
			//버튼업도 상태에 넣어야하나?
			_pCurrentState->onBtnR(this);
			_pCurrentSkill->pullMagicKey();

		}
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
	_arState[static_cast<int>(PLAYER::PLAYER_STATE::SKILL_05)] = new STATE_SKILL_FIVE();

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


