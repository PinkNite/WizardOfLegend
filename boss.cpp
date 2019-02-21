#include "stdafx.h"
#include "boss.h"
#include "BossStateIdle.h"
#include "BossStateRun.h"
#include "BossStateDamage.h"
#include "BossStateDeath.h"
#include "BossStateSkill01.h"
#include "BossStateSkill02.h"
#include "BossStateSkill03.h"
#include "magicMgr.h"
#include "player.h"

BOSS::BOSS() :
	_fMaxHP(0.0f),
	_fCurrentHP(0.0f),
	_fSpeed(0.0f),
	_pAnimation(nullptr),
	_arFrame{ 0, },
	_direction(DIRECTION::RIGHT),
	_action(ACTION::READY),
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
	_pWingImage = IMAGEMANAGER->addFrameImage("IceWings", "resource/boss/ice/IceWings.bmp", 933, 400, 7, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("WaterBounce", "resource/boss/ice/WaterBounce.bmp", 600, 480, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("IceChakram", "resource/boss/ice/IceChakram.bmp", 50, 50, true, RGB(255, 0, 255));


	OBJECT::init(1100, 800, BOSS_RECT_WIDTH, BOSS_RECT_HEIGHT);
	OBJECT::_pImg = IMAGEMANAGER->addFrameImage("iceBossImg", "resource/boss/ice/IceBoss.bmp",
		BOSS_IMAGE_WIDTH, BOSS_IMAGE_HEIGHT, BOSS_MAX_FRAME_X, BOSS_MAX_FRAME_Y, true, RGB(255, 0, 255));

	_pAnimation = new animation();
	_pAnimation->init(BOSS_IMAGE_WIDTH, BOSS_IMAGE_HEIGHT, BOSS_MAX_FRAME_X, BOSS_MAX_FRAME_Y);

	_fMaxHP = 1000.0f;
	_fCurrentHP = 1000.0f;
	_fSpeed = 200.0f;
	_objectName = "IceBoss";
	_timeSet = 0.0f;
	_skillType = SKILL_TYPE::NONE;

	setEnumName();
	createAnimation();

	//_direction = DIRECTION::DOWN;
	//_action = ACTION::READY;
	//startBossAnimation();

	initState();

	_pIceSpear = new throwIceSpear();
	_pIceSpear->init();
}

void BOSS::update()
{
	if (ACTION::READY == _action)
	{
		// ���� ���� ���� �Ÿ�
		float targetDistance = getDistance(OBJECT::getPosX(), OBJECT::getPosY(), _pPlayer->getPosX(), _pPlayer->getPosY());
		if (targetDistance < 400.f)
		{
			showBoss();
		}
	}
	else
	{
		_moveTimeStart += TIMEMANAGER->getElapsedTime();

		if (_moveTimeStart > _moveTimeEnd)
		{
			_moveTimeStart = 0;
			_moveTimeEnd = RND->getFromFloatTo(3.0f, 5.0f);
			dash(_pPlayer->getPosX(), _pPlayer->getPosY());
		}

		if (ACTION::ENTRANCE == _action)
		{
			_timeSet += TIMEMANAGER->getElapsedTime();
		}

		if (ACTION::DASH == _action)
		{
			_dashSpeed -= TIMEMANAGER->getElapsedTime() + 1;

			float distance = getDistance(OBJECT::getPosX(), OBJECT::getPosY(), _pPlayer->getPosX(), _pPlayer->getPosY());
			if (distance > 300.0f)
			{
				OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(_targetAngle, _dashSpeed));
				OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(_targetAngle, _dashSpeed));
				setRect();
			}
			else
			{
				int skillNo = RND->getInt(4);
				switch (skillNo)
				{
				case 0:
					spell01(SKILL_TYPE::BUBBLE);
					break;
				case 1:
					spell01(SKILL_TYPE::CHAKRAM);
					break;
				case 2:
					spell02(SKILL_TYPE::LANCE);
					break;
				default:
					break;
				}
			}
		}

		// skill 2
		_pIceSpear->update();
		if (ACTION::SKILL_02 == _action)
		{
			_timeSet += TIMEMANAGER->getElapsedTime();
			if (_timeSet > 2.3f)
			{
				setBossIdle();
				_pIceSpear->ResetAll();
				_timeSet = 0;
			}
		}

		if (_fCurrentHP < 0 && ACTION::DEATH != _action)
		{
			setDeath();
		}

		//bulletMove();
		handleInputKey();
		_pCamera->pushRenderObject(this);
		if (_pCurrentState != nullptr)
		{
			_pCurrentState->update(this);
		}
	}

}

void BOSS::release()
{
	OBJECT::setImage(nullptr);
	_pWingImage = nullptr;
	_pEffectImage = nullptr;
	_pBlastImage = nullptr;

	_pAnimation = nullptr;
	_pWingsAnimation = nullptr;
	_pEffectAnimation = nullptr;
	_pIceblastAnimation = nullptr;
	_pIceBulletAnimation = nullptr;
}

void BOSS::render(HDC hdc)
{
	if (ACTION::READY == _action)  return;

	//Rectangle(hdc, OBJECT::_rc);
	int renderX = static_cast<int>(OBJECT::getPosX());
	int renderY = static_cast<int>(OBJECT::getPosY());


	// ���� ���� ��
	if (ACTION::ENTRANCE == _action)
	{
		// ice wing
		_pWingImage->aniRenderCenter(hdc, renderX, renderY, _pWingsAnimation);

		if (_timeSet > 1.0f)
		{
			_pBlastImage->renderCenter(hdc, renderX, renderY);
			// boss charater
			OBJECT::getImage()->aniRenderCenter(hdc, renderX, renderY, _pAnimation);
		}
		_pEffectImage->aniRenderCenter(hdc, renderX, renderY, _pEffectAnimation);
	}
	// ���� ����
	else if (ACTION::DEATH == _action)
	{
		// boss charater
		OBJECT::getImage()->aniRenderCenter(hdc, renderX, renderY, _pAnimation);
		_pEffectImage->aniRenderCenter(hdc, renderX, renderY, _pEffectAnimation);
	}
	else
	{
		// ice wing
		_pWingImage->aniRenderCenter(hdc, renderX, renderY - 20, _pWingsAnimation);
		// boss charater
		OBJECT::getImage()->aniRenderCenter(hdc, renderX, renderY, _pAnimation);
	}

	//RectangleMakeCenter(hdc, renderX, renderY, BOSS_RECT_WIDTH, BOSS_RECT_HEIGHT);

	//bulletRender(hdc);

	_pIceSpear->render(hdc);
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

	_mAction.insert(make_pair(ACTION::SKILL_01, "SKILL_01"));
	_mAction.insert(make_pair(ACTION::SKILL_02, "SKILL_02"));
	_mAction.insert(make_pair(ACTION::SKILL_03, "SKILL_03"));

	_mAction.insert(make_pair(ACTION::ENTRANCE, "ENTRANCE"));
	_mAction.insert(make_pair(ACTION::DAMAGE, "DAMAGE"));
	_mAction.insert(make_pair(ACTION::DEATH, "DEATH"));

}

void BOSS::createAnimation()
{
	KEYANIMANAGER->addObject(_objectName);

	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::ENTRANCE], 62, 64, 8, false, nullptr);

	addBossKeyAni(_mDirection[DIRECTION::LEFT], _mAction[ACTION::IDLE], 88, 97, 8, true, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::RIGHT], _mAction[ACTION::IDLE], 88, 97, 8, true, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::UP], _mAction[ACTION::IDLE], 88, 97, 8, true, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::IDLE], 88, 97, 8, true, nullptr);

	addBossKeyAni(_mDirection[DIRECTION::LEFT], _mAction[ACTION::RUN], 0, 0, 1, true, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::RIGHT], _mAction[ACTION::RUN], 1, 1, 1, true, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::RUN], 2, 2, 1, true, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::UP], _mAction[ACTION::RUN], 3, 3, 1, true, nullptr);

	addBossKeyAni(_mDirection[DIRECTION::LEFT], _mAction[ACTION::DASH], 105, 99, 32, false, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::RIGHT], _mAction[ACTION::DASH], 55, 61, 32, false, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::DASH], 105, 99, 32, false, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::UP], _mAction[ACTION::DASH], 55, 61, 32, false, nullptr);

	addBossKeyAni(_mDirection[DIRECTION::LEFT], _mAction[ACTION::SKILL_02], 105, 105, 2, false, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::RIGHT], _mAction[ACTION::SKILL_02], 61, 61, 2, false, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::UP], _mAction[ACTION::SKILL_02], 105, 105, 2, false, nullptr);
	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::SKILL_02], 61, 61, 2, false, nullptr);
	// TODO: �̹��� �߰� 
	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::SKILL_03], 22, 42, 6, false, nullptr);

	addBossKeyAni(_mDirection[DIRECTION::DOWN], _mAction[ACTION::DAMAGE], 66, 68, 8, false, callbackIdle);


	int effectFrame[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "Entrance", "IceCrystals", effectFrame, 8, 6, false, callbackSetBattle, this);

	int idlMaxFrame[7] = { 0, 1, 2, 3, 4, 5, 6 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WingsMaxIdle", "IceWings", idlMaxFrame, 7, 8, true);

	int idlMinFrame[1] = { 14 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WingsMinIdle", "IceWings", idlMinFrame, 1, 8, true);

	int minimize[7] = { 7, 8, 9, 10, 11, 12, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WingsMin", "IceWings", minimize, 7, 8, false, callbackMinWingIdle, this);

	int maximize[7] = { 14, 15, 16, 17, 18, 19, 20 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WingsMax", "IceWings", maximize, 7, 8, false, callbackMaxWingIdle, this);

	// bubble
	int waterBall[10] = { 0, 1, 2, 3, 4 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "WaterBalls", "WaterBounce", waterBall, 5, 8, true);

	int skill01[24] = { 22, 22, 22, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, getAnimationKey(_mDirection[DIRECTION::DOWN], _mAction[ACTION::SKILL_01]), "iceBossImg", skill01, 24, 8, false);

	int death[4] = { 69, 69, 69, 69 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, getAnimationKey(_mDirection[DIRECTION::DOWN], _mAction[ACTION::DEATH]), "iceBossImg", death, 3, 4, false);

	int bossEndFrame[5] = { 0, 1, 2, 3, 4 };
	KEYANIMANAGER->addArrayFrameAnimation(_objectName, "BossEnding", "IceCrystals", bossEndFrame, 5, 2, false);

}

const string BOSS::getAnimationKey(const string & strDir, const string & strAction)
{
	string temp = "";
	temp.append(strDir);
	temp.append("_");
	temp.append(strAction);
	return temp;
}

void BOSS::addBossKeyAni(const string & strDir, const string & strAction, int startFrame, int endFrame, int fps, bool isLoop, void * cbFunction)
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
		KEYANIMANAGER->addArrayFrameAnimation(_objectName, getAnimationKey(strDir, strAction),
			"iceBossImg", _arFrame, nFrameCount, fps, isLoop);
	}
	else
	{
		KEYANIMANAGER->addArrayFrameAnimation(_objectName, getAnimationKey(strDir, strAction),
			"iceBossImg", _arFrame, nFrameCount, fps, isLoop, cbFunction, this);
	}

}

void BOSS::setState(BOSS_STATE bossState)
{
	if (_pCurrentState == _arState[int(bossState)])  return;

	_pCurrentState = _arState[int(bossState)];
	this->handleState(bossState);
}

void BOSS::handleState(BOSS_STATE bossState)
{
	BossState* state = _pCurrentState->handleState(this, bossState);
	/*
	if (state != nullptr)
	{
		_pCurrentState = nullptr;
		_pCurrentState = state;

		_pCurrentState->enter(this);
	}*/
	_pCurrentState->enter(this);
}

void BOSS::setAction(ACTION action, DIRECTION direction)
{
	_action = action;
	setDirection(direction);
	startBossAnimation();
}

void BOSS::setDirection(DIRECTION direction)
{
	_direction = direction;
}

void BOSS::startBossAnimation()
{
	_pAnimation = KEYANIMANAGER->findAnimation(_objectName, getAnimationKey(_mDirection[_direction], _mAction[_action]));
	_pAnimation->start();
}

void BOSS::initState()
{
	_arState[int(BOSS_STATE::IDLE)] = new BossStateIdle();
	_arState[int(BOSS_STATE::RUN)] = new BossStateRun();
	_arState[int(BOSS_STATE::SKILL_01)] = new BossStateSkill01();
	_arState[int(BOSS_STATE::SKILL_02)] = new BossStateSkill02();
	_arState[int(BOSS_STATE::SKILL_03)] = new BossStateSkill01();
}

void BOSS::handleInputKey()
{
	float speed = _fSpeed * TIMEMANAGER->getElapsedTime();

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		setDirection(DIRECTION::UP);
		setState(BOSS_STATE::RUN);
		moveUp(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		//setDirection(DIRECTION::DOWN);
		setState(BOSS_STATE::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		setDirection(DIRECTION::LEFT);
		setState(BOSS_STATE::RUN);
		moveLeft(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		//setDirection(DIRECTION::DOWN);
		setState(BOSS_STATE::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		setDirection(DIRECTION::RIGHT);
		setState(BOSS_STATE::RUN);
		moveRight(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		//setDirection(DIRECTION::DOWN);
		setState(BOSS_STATE::IDLE);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		setDirection(DIRECTION::DOWN);
		setState(BOSS_STATE::RUN);
		moveDown(speed);
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		//setDirection(DIRECTION::DOWN);
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

void BOSS::dash(float targetX, float targetY)
{
	_dashSpeed = 50.0f;
	_targetX = targetX;
	_targetY = targetY;
	_targetAngle = getAngle(OBJECT::getPosX(), OBJECT::getPosY(), _targetX, _targetY);

	if (0.78f < _targetAngle && _targetAngle <= 2.35) _direction = DIRECTION::UP;
	if (2.35f < _targetAngle && _targetAngle <= 3.92) _direction = DIRECTION::LEFT;
	if (3.92f < _targetAngle && _targetAngle <= 4.95) _direction = DIRECTION::DOWN;
	if (4.95f < _targetAngle && _targetAngle <= 6.28) _direction = DIRECTION::RIGHT;
	if (0.0f < _targetAngle && _targetAngle <= 0.78) _direction = DIRECTION::RIGHT;

	setAction(ACTION::DASH, _direction);

	//setAction(ACTION::IDLE, _direction);

	// TODO: Į�� Ű �ִϸ��̼� �� ����  


}

void BOSS::spell01(SKILL_TYPE type)
{
	if (ACTION::ENTRANCE == _action || ACTION::DEATH == _action) return;

	_timeSet = 0;
	_isEndSkill = false;
	float positionAngle = 18.0f;

	setDirection(DIRECTION::DOWN);
	setState(BOSS_STATE::SKILL_01);
	setWings(false);

	_skillType = type;
	string imageName = "";
	if (SKILL_TYPE::BUBBLE == type)
	{
		_bulletSize = 10;
		imageName = "WaterBounce";
		_pIceBulletAnimation = KEYANIMANAGER->findAnimation(_objectName, "WaterBalls");
		_pIceBulletAnimation->start();
	}
	if (SKILL_TYPE::CHAKRAM == type)
	{
		_bulletSize = 18;
		imageName = "IceChakram";
	}

	positionAngle = float(_bulletSize);

	for (int i = 0; i < _bulletSize; i++)
	{
		_bullet[i] = new tagBullet();
		_bullet[i]->iceImage = IMAGEMANAGER->findImage(imageName);
		_bullet[i]->distance = 128.0f;
		_bullet[i]->angle = PI2 / positionAngle * i;
		_bullet[i]->radius = 7;
		_bullet[i]->x = OBJECT::_posX;
		_bullet[i]->y = OBJECT::_posY;
		_bullet[i]->isFire = false;
	}
}

void BOSS::spell02(SKILL_TYPE type)
{
	_timeSet = 0.f;
	POINTFLOAT* bossPoint = new POINTFLOAT{ _posX, _posY };
	POINTFLOAT* targetPoint = new POINTFLOAT{ _pPlayer->getPosX(), _pPlayer->getPosY()};
	_pIceSpear->UseSkill(bossPoint, targetPoint, 3);

	//setState(BOSS_STATE::SKILL_02);
	setAction(ACTION::SKILL_02, _direction);
}

void BOSS::spell03(SKILL_TYPE type)
{
}

void BOSS::skillFire(float x, float y)
{
	_timeSet += TIMEMANAGER->getElapsedTime();

	// ź�� �߻�Ǵ� ���� 
	if (_timeSet > 0.1f)
	{
		int fireCount = 0;
		for (int i = _bulletSize - 1; i >= 0; i--)
		{
			if (_bullet[i]->isFire)
			{
				fireCount++;
				continue;
			}

			_bullet[i]->fireAngle = getAngle(_bullet[i]->x, _bullet[i]->y, _pPlayer->getPosX(), _pPlayer->getPosY());;
			//_bullet[i]->fireAngle = getAngle(_bullet[i]->x, _bullet[i]->y, x, y);;
			_bullet[i]->speed = 18.0f;
			_bullet[i]->isFire = true;

			if (SKILL_TYPE::CHAKRAM == _skillType)
			{
				_pMagicMgr->pushMagicKey("IceChakram", false, getPosX(), getPosY(), _bullet[i]->distance / 2.0f, _bullet[i]->angle);
			}
			else if (SKILL_TYPE::BUBBLE == _skillType)
			{
				_pMagicMgr->pushMagicKey("WaterBalls", false, getPosX(), getPosY(), _bullet[i]->distance / 2.0f, _bullet[i]->angle);
			}
			
			break;
		}

		if (_bulletSize == fireCount)
		{
			_isEndSkill = true;
			if (_timeSet > 2.0f)
			{
				setBossIdle();
				_timeSet = 0;
				_isEndSkill = false;
			}
		}
		else
		{
			_timeSet = 0;
		}
	}
}

void BOSS::bulletMove()
{

	//  rolling circle
	for (int i = 0; i < _bulletSize; i++)
	{
		if (_bullet[i]->isFire) continue;

		_bullet[i]->angle += PI32;
		//Mins::presentPowerX()
		_bullet[i]->x = _posX + cos(_bullet[i]->angle) * _bullet[i]->distance;
		_bullet[i]->y = _posY + -sin(_bullet[i]->angle) * _bullet[i]->distance;
	}

	// moving fired bullet.
	for (int i = 0; i < _bulletSize; i++)
	{
		if (_bullet[i]->isFire == false) continue;

		_bullet[i]->x += cos(_bullet[i]->fireAngle) * _bullet[i]->speed;
		_bullet[i]->y += -sin(_bullet[i]->fireAngle) * _bullet[i]->speed;
	}
}

void BOSS::bulletRender(HDC hdc)
{
	if (SKILL_TYPE::BUBBLE == _skillType)
	{
		for (int i = 0; i < _bulletSize; i++)
		{
			int x = static_cast<int>(_bullet[i]->x);
			int y = static_cast<int>(_bullet[i]->y);
			_bullet[i]->iceImage->aniRenderCenter(hdc, x, y, _pIceBulletAnimation);
		}
	}

	if (SKILL_TYPE::CHAKRAM == _skillType)
	{
		for (int i = 0; i < _bulletSize; i++)
		{
			int x = static_cast<int>(_bullet[i]->x);
			int y = static_cast<int>(_bullet[i]->y);
			_bullet[i]->iceImage->renderCenter(hdc, x, y);
		}
	}
}

void BOSS::setRect()
{
	OBJECT::_rc = RectMakeCenter(
		static_cast<int>(OBJECT::_posX),
		static_cast<int>(OBJECT::_posY),
		BOSS_RECT_WIDTH, BOSS_RECT_HEIGHT);
}

void BOSS::showBoss()
{
	_direction = DIRECTION::DOWN;
	_action = ACTION::ENTRANCE;

	setWings(false);
	startBossAnimation();

	_pEffectAnimation = KEYANIMANAGER->findAnimation(_objectName, "Entrance");
	_pEffectAnimation->start();

}

void BOSS::setBattle()
{
	_action = ACTION::IDLE;
	_direction = DIRECTION::DOWN;

	setState(BOSS_STATE::IDLE);

	setWings(true);
	startBossAnimation();

	_moveTimeEnd = 0.1f;
}

void BOSS::setBossIdle()
{
	if (ACTION::DEATH == _action) return;

	// ��ų �����߿��� Idle ���� ������ ����.
	if (ACTION::SKILL_01 == _action || ACTION::SKILL_03 == _action)
	{
		if (_isEndSkill == true)
		{
			setState(BOSS_STATE::IDLE);
			setAction(ACTION::IDLE, DIRECTION::DOWN);
			setWings(true);
			_isEndSkill = false;
		}
	}
	else
	{
		setState(BOSS_STATE::IDLE);
		setAction(ACTION::IDLE, DIRECTION::DOWN);
		setWings(true);
	}
}

void BOSS::setDamage(float damage)
{
	_fCurrentHP -= damage;
	if (!(ACTION::SKILL_01 == _action || ACTION::SKILL_02 == _action || ACTION::SKILL_02 == _action))
	{
		setAction(ACTION::DAMAGE, DIRECTION::DOWN);
		setWings(false);
	}
}

void BOSS::setDeath()
{
	setAction(ACTION::DEATH, DIRECTION::DOWN);
	startBossAnimation();

	_pEffectAnimation = KEYANIMANAGER->findAnimation(_objectName, "BossEnding");
	_pEffectAnimation->start();
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

void BOSS::callbackIdle(void * obj)
{
	BOSS* pBoss = (BOSS*)obj;
	pBoss->setBossIdle();
}