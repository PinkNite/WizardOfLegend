#include "stdafx.h"
#include "Enemy.h"
#include "EnemyStateIdle.h"
#include "EnemyStateRun.h"
#include "EnemyStateSkill1.h"
#include "EnemyStateRun.h"
#include "EnemyStateDamage.h"
#include "EnemyStateDeath.h"
#include "player.h"
#include "map.h"

Enemy::Enemy() :
	_fMaxHP(100.0f),
	_fCurrentHP(100.0f),
	_fSpeed(200.0f),
	_pAnimation(nullptr),
	_arFrame{ 0, },
	_direction(DIRECTION::LEFT),
	_state(ActionState::HIDDEN),
	_fAngleX(0.0f),
	_fAngleY(0.0f)
{
}

Enemy::~Enemy()
{
}

void Enemy::init()
{
	IMAGEMANAGER->addFrameImage("Ghoul", "resource/enemy/ghoul.bmp", 1200, 1200, 6, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Golem", "resource/enemy/Golem.bmp", 720, 700, 6, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Summoner", "resource/enemy/SummonerSource.bmp", 750, 1050, 5, 7, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Lancer", "resource/enemy/lancer.bmp", 491, 840, 6, 7, true, RGB(255, 0, 255));

	_timeSet = 0.0f;
	_pAnimation = new animation();

	createStates();
	createEnumNames();
	setState(ActionState::HIDDEN);
}

void Enemy::update()
{
	if (ActionState::HIDDEN == _state)
	{
		// ������ ���� �Ÿ�
		_targetDistance = getDistance(_posX, _posY, _pPlayer->getPosX(), _pPlayer->getPosY());
		if (_targetDistance < 400.f)
		{
			showEnemy();
		}
	}
	else
	{
		_timeSet += TIMEMANAGER->getElapsedTime();

		// ������ ���� �Ÿ�
		_targetDistance = getDistance(_posX, _posY, _pPlayer->getPosX(), _pPlayer->getPosY());
		if (_targetDistance < 100.0f)
		{
			//skillAttack(_pPlayer->getPosX(), _pPlayer->getPosY());
		}
		else
		{
			setBattle();
		}


		if (ActionState::DEATH != _state)
		{
			if (_fCurrentHP < 0) setDeath();

			setRect();
			moveEnemy();
			handleKeyInput();
		}

		_pCurrentState->update(this);
		_pCamera->pushRenderObject(this);
	}
}

void Enemy::release()
{
	OBJECT::setImage(nullptr);
	_pAnimation = nullptr;
}

void Enemy::render(HDC hdc)
{
	if (ActionState::HIDDEN != _state)
	{
		OBJECT::_pImg->aniRenderCenter(hdc, _posX, _posY, _pAnimation);
		//RectangleMakeCenter(hdc, _posX, _posY, MOB_RECT_HEIGHT, MOB_RECT_HEIGHT);
	}
}

void Enemy::createEnumNames()
{
	_mDirection.insert(make_pair(DIRECTION::LEFT, "LEFT"));
	_mDirection.insert(make_pair(DIRECTION::RIGHT, "RIGHT"));

	_mState.insert(make_pair(ActionState::IDLE, "IDLE"));
	_mState.insert(make_pair(ActionState::RUN, "RUN"));
	_mState.insert(make_pair(ActionState::ATTACK1, "ATTACK1"));
	_mState.insert(make_pair(ActionState::ATTACK2, "ATTACK2"));
	_mState.insert(make_pair(ActionState::DAMAGE, "DAMAGE"));
	_mState.insert(make_pair(ActionState::DEATH, "DEATH"));
	_mState.insert(make_pair(ActionState::HIDDEN, "HIDDEN"));

}

void Enemy::createAnimations()
{
	KEYANIMANAGER->addObject(_objName);

	switch (_enType)
	{
	case Enemy::EnemyType::GHOUL:
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::IDLE], 5, 5, 1, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::IDLE], 0, 0, 1, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::RUN], 17, 12, 8, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::RUN], 6, 11, 8, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::ATTACK1], 4, 3, 6, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::ATTACK1], 1, 2, 6, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::ATTACK2], 4, 3, 2, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::ATTACK2], 1, 2, 2, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::DAMAGE], 35, 35, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::DAMAGE], 18, 18, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::DEATH], 35, 27, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::DEATH], 18, 26, 4, false, nullptr);
		break;
	case Enemy::EnemyType::GOLEM:
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::IDLE], 5, 5, 1, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::IDLE], 0, 0, 1, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::RUN], 17, 12, 8, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::RUN], 6, 11, 8, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::ATTACK1], 4, 3, 6, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::ATTACK1], 1, 2, 6, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::ATTACK2], 0, 0, 4, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::ATTACK2], 0, 0, 4, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::DAMAGE], 17, 17, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::DAMAGE], 11, 11, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::DEATH], 29, 24, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::DEATH], 18, 23, 4, false, nullptr);
		break;
	case Enemy::EnemyType::SUMMONER:
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::IDLE], 0, 0, 1, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::IDLE], 10, 10, 1, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::RUN], 0, 2, 4, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::RUN], 10, 12, 4, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::ATTACK1], 3, 9, 6, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::ATTACK1], 13, 19, 6, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::ATTACK2], 0, 0, 4, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::ATTACK2], 0, 0, 4, true, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::DAMAGE], 34, 34, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::DAMAGE], 20, 20, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[ActionState::DEATH], 34, 28, 4, false, nullptr);
		addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[ActionState::DEATH], 20, 26, 4, false, nullptr);
		break;
	}
}

const string Enemy::getAnimaKey(const string & strDir, const string & strAction)
{
	string temp = "";
	temp.append(strDir);
	temp.append("_");
	temp.append(strAction);
	return temp;
}

void Enemy::addAnimaKey(const string & strDir, const string & strAction, int startFrame, int endFrame, int fps, bool isLoop, void * cbFunction)
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

	if (cbFunction == nullptr)
	{
		KEYANIMANAGER->addArrayFrameAnimation(_objName, getAnimaKey(strDir, strAction),
			_objName.c_str(), _arFrame, nFrameCount, fps, isLoop);
	}
	else
	{
		KEYANIMANAGER->addArrayFrameAnimation(_objName, getAnimaKey(strDir, strAction),
			_objName.c_str(), _arFrame, nFrameCount, fps, isLoop, cbFunction, this);
	}
}

void Enemy::setEnemy(EnemyType enType, float x, float y)
{
	_enType = enType;

	switch (_enType)
	{
	case Enemy::EnemyType::GHOUL:
		_objName = "Ghoul";
		_fDamage = 20.0f;
		_fSpeed = 200.0f;
		_fMaxHP = 200.0f;
		_fCurrentHP = _fMaxHP;
		MOB_RECT_WIDTH = 100;
		MOB_RECT_HEIGHT = 140;
		OBJECT::init(x, y, MOB_RECT_WIDTH, MOB_RECT_HEIGHT);
		OBJECT::_pImg = IMAGEMANAGER->findImage("Ghoul");
		break;
	case Enemy::EnemyType::GOLEM:
		_objName = "Golem";
		_fDamage = 30.0f;
		_fSpeed = 100.0f;
		_fMaxHP = 400.0f;
		_fCurrentHP = _fMaxHP;
		MOB_RECT_WIDTH = 100;
		MOB_RECT_HEIGHT = 140;
		OBJECT::init(x, y, MOB_RECT_WIDTH, MOB_RECT_HEIGHT);
		OBJECT::_pImg = IMAGEMANAGER->findImage("Golem");
		break;
	case Enemy::EnemyType::SUMMONER:
		_objName = "Summoner";
		_fDamage = 20.0f;
		_fSpeed = 200.0f;
		_fMaxHP = 300.0f;
		_fCurrentHP = _fMaxHP;
		MOB_RECT_WIDTH = 100;
		MOB_RECT_HEIGHT = 120;
		OBJECT::init(x, y, MOB_RECT_WIDTH, MOB_RECT_HEIGHT);
		OBJECT::_pImg = IMAGEMANAGER->findImage("Summoner");
		break;
	}

	createAnimations();
}

void Enemy::showEnemy()
{
	setState(ActionState::IDLE);
	setAction(ActionState::IDLE, DIRECTION::RIGHT);

	setBattle();
}

void Enemy::setBattle()
{
	
	moveEnemy();
}

void Enemy::createStates()
{
	_arState[int(ActionState::IDLE)] = new EnemyStateIdle();
	_arState[int(ActionState::RUN)] = new EnemyStateRun();
	_arState[int(ActionState::ATTACK1)] = new EnemyStateSkill1();
	_arState[int(ActionState::ATTACK2)] = new EnemyStateSkill1();
	_arState[int(ActionState::DAMAGE)] = new EnemyStateDamage();
	_arState[int(ActionState::DEATH)] = new EnemyStateDeath();
}

void Enemy::setState(ActionState eState)
{
	if (_state == eState) return;

	if (ActionState::HIDDEN != eState)
	{
		_state = eState;
		_pCurrentState = _arState[int(_state)];
		EnemyState* state = _pCurrentState->handleState(this, _state);
		_pCurrentState->enter(this);
	}
}

void Enemy::setDirection(Enemy::DIRECTION eDirection)
{
	_direction = eDirection;
}

void Enemy::setAction(ActionState eState, Enemy::DIRECTION eDirection)
{
	_direction = eDirection;
	_state = eState;
	startAnimation();
}

void Enemy::startAnimation()
{
	_pAnimation = KEYANIMANAGER->findAnimation(_objName, getAnimaKey(_mDirection[_direction], _mState[_state]));
	_pAnimation->start();
}

void Enemy::handleKeyInput()
{
	float speed = _fSpeed * TIMEMANAGER->getElapsedTime();

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_move = MOVE::UP;
		setState(ActionState::RUN);
		moveUp(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		setState(ActionState::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_move = MOVE::LEFT;
		setDirection(DIRECTION::LEFT);
		setState(ActionState::RUN);
		moveLeft(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		setState(ActionState::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_move = MOVE::RIGHT;
		setDirection(DIRECTION::RIGHT);
		setState(ActionState::RUN);
		moveRight(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		setState(ActionState::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_move = MOVE::DOWN;
		setState(ActionState::RUN);
		moveDown(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		setState(ActionState::IDLE);
	}
}

void Enemy::moveUp(float speed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI / 2.0f, speed));
	setRect();
}

void Enemy::moveDown(float speed)
{
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(PI / 2.0f + PI, speed));
	setRect();
}

void Enemy::moveLeft(float speed)
{
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(PI, speed));
	setRect();
}

void Enemy::moveRight(float speed)
{
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(0.0f, speed));
	setRect();
}

void Enemy::moveEnemy()
{
	// Astart �� ã����η� �̵�

	if (_timeSet > 0.5f)
	{

		//_timeSet = 0;
	}

	for (size_t i = 0; i < _pPathList.size(); i++)
	{

		//OBJECT::setPosX();
	}



	/*
	if (_pCurrentState == _arState[static_cast<int>(ActionState::RUN)])
	{
		float speed = _fSpeed * TIMEMANAGER->getElapsedTime();

		switch (_move)
		{
		case Enemy::MOVE::LEFT:
			moveLeft(speed);
			break;
		case Enemy::MOVE::RIGHT:
			moveRight(speed);
			break;
		case Enemy::MOVE::UP:
			moveUp(speed);
			break;
		case Enemy::MOVE::DOWN:
			moveDown(speed);
			break;
		}
	}*/

}

void Enemy::skillAttack(float x, float y)
{
	// ���� ��
 	if (_timeSet > 1.0f)
	{
		setState(ActionState::ATTACK1);
		setAction(ActionState::ATTACK1, _direction);

		
		RECT rcTemp;
		if (IntersectRect(&rcTemp, _pPlayer->getCollisionRect(), &_rc))
		{
			_pPlayer->getDamage(_fDamage);
		}
		/*_targetDistance = getDistance(_posX, _posY, _pPlayer->getPosX(), _pPlayer->getPosY());
		if (_targetDistance < 20.0f)
		{
			_pPlayer->getDamage(_fDamage);
		}*/

		_timeSet = 0;
	}
}

void Enemy::skillMove()
{
}

void Enemy::skillRender(HDC hdc)
{
}

void Enemy::setRect()
{
	OBJECT::_rc = RectMakeCenter(
		static_cast<int>(OBJECT::_posX),
		static_cast<int>(OBJECT::_posY),
		MOB_RECT_WIDTH, MOB_RECT_HEIGHT);
}

void Enemy::setDamage(float damage)
{
	_fCurrentHP -= damage;
	setAction(ActionState::DAMAGE, _direction);
}

void Enemy::setDeath()
{
	setState(ActionState::DEATH);
	setAction(ActionState::DEATH, _direction);
}

