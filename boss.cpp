#include "stdafx.h"
#include "boss.h"
#include "BossStateIdle.h"


BOSS::BOSS() :
	_fMaxHP(0.0f),
	_fCurrentHP(0.0f),
	_fSpeed(0.0f),
	_arDirection{ NULL, },
	_arAction{ NULL, },
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
	OBJECT::init(100, 100, 48, 48);
	OBJECT::_pImg = IMAGEMANAGER->addFrameImage("iceBoss", "resource/boss/ice/IceBoss.bmp",
		BOSS_IMAGE_WIDTH, BOSS_IMAGE_HEIGHT, BOSS_MAX_FRAME_X, BOSS_MAX_FRAME_Y, true, RGB(255, 0, 255));

	_pAnimation = new animation();
	_pAnimation->init(BOSS_IMAGE_WIDTH, BOSS_IMAGE_HEIGHT, BOSS_MAX_FRAME_X, BOSS_MAX_FRAME_Y);
	_fMaxHP = 1000.0f;
	_fCurrentHP = 1000.0f;
	_fSpeed = 200.0f;
	_objectName = "IceBoss";

	setEnumName();
	setAnimation();
	_direction = DIRECTION::RIGHT;
	//_action = ACTION::ICED_OUT;
	_action = ACTION::IDLE;

	_pAnimation = KEYANIMANAGER->findAnimation(_objectName, getAniString(_arDirection[static_cast<int>(_direction)], _arAction[static_cast<int>(_action)]));
	_pAnimation->start();
	
	initState();
	setState(BOSS_STATE::IDLE);
}

void BOSS::update()
{
	// TODO: delete test code
	//handleState();

	_pCurrentState->update(this);

	KEYANIMANAGER->update();
}

void BOSS::release()
{
	OBJECT::setImage(nullptr);
	_pAnimation = nullptr;
}

void BOSS::render(HDC hdc)
{
	Rectangle(hdc, _rc);
}

void BOSS::setEnumName()
{
	_arDirection[static_cast<int>(DIRECTION::LEFT)] = "LEFT";
	_arDirection[static_cast<int>(DIRECTION::RIGHT)] = "RIGHT";
	_arDirection[static_cast<int>(DIRECTION::FRONT)] = "FRONT";
	_arDirection[static_cast<int>(DIRECTION::BACK)] = "BACK";

	_arAction[static_cast<int>(ACTION::IDLE)] = "IDLE";
	_arAction[static_cast<int>(ACTION::RUN)] = "RUN";
	_arAction[static_cast<int>(ACTION::DASH)] = "DASH";

	_arAction[static_cast<int>(ACTION::SPELL_01)] = "SPELL_01";
	_arAction[static_cast<int>(ACTION::SPELL_02)] = "SPELL_02";
	_arAction[static_cast<int>(ACTION::SPELL_03)] = "SPELL_03";

	_arAction[static_cast<int>(ACTION::SKILL_01)] = "SKILL_01";
	_arAction[static_cast<int>(ACTION::SKILL_02)] = "SKILL_02";
	_arAction[static_cast<int>(ACTION::SKILL_03)] = "SKILL_03";

	_arAction[static_cast<int>(ACTION::DAMAGE)] = "DAMAGE";
	_arAction[static_cast<int>(ACTION::DEATH)] = "DEATH";

}

void BOSS::setAnimation()
{
	KEYANIMANAGER->addObject(_objectName);


}

const string BOSS::getAniString(const string & strDir, const string & strAction)
{
	string temp = "";
	temp.append(strDir);
	temp.append("_");
	temp.append(strAction);
	return temp;
}

void BOSS::addBossKeyAni(const string & strDir, const string & strActoin, int startFrame, int endFrame, int fps, bool isLoop)
{
	int nFrameCount(0);
}

void BOSS::setState(BOSS_STATE bossState)
{
	_pCurrentState = _arState[static_cast<int>(bossState)];
	this->handleState(bossState);
}

void BOSS::setAction(ACTION action)
{
	_action = action;
	startAnimation();
}

void BOSS::setDirection(DIRECTION direction)
{
}

void BOSS::startAnimation()
{
	_pAnimation = KEYANIMANAGER->findAnimation(_objectName, getAniString(_arDirection[static_cast<int>(_direction)], _arAction[static_cast<int>(_action)]));
	_pAnimation->start();
}

void BOSS::handleState(BOSS_STATE bossState)
{
	BossState* state = _pCurrentState->handleState(this, bossState);
	if (state != NULL)
	{
		delete _pCurrentState;
		_pCurrentState = state;
		_pCurrentState->enter(this);
	}
}

void BOSS::initState()
{
	_arState[int(BOSS_STATE::IDLE)] = new BossStateIdle();
	//_arState[int(BOSS_STATE::RUN)] = new BossStateRun();
}

void BOSS::moveUp(float speed)
{
}

void BOSS::moveDown(float speed)
{
}

void BOSS::moveLeft(float speed)
{
}

void BOSS::moveRight(float speed)
{
}

void BOSS::dash(float offset)
{
}

void BOSS::move()
{
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
