#include "stdafx.h"
#include "player.h"

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
	//ÃÊ±â À§Ä¡ Áß¾Ó°ª
	OBJECT::init(200, 200, 100, 100);
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("wizardSprites", "resource/player/wizardSprites.bmp", WIZARD_SPRITE_WIDTH, WIZARD_SPRITE_HEIGHT, WIZARD_SPRITE_MAXFRAMEX, WIZARD_SPRITE_MAXFRAMEY, true, RGB(255, 0, 255)));
	setEnumName();
	_pAnimation = new animation();
	_pAnimation->init(WIZARD_SPRITE_WIDTH, WIZARD_SPRITE_HEIGHT, WIZARD_SPRITE_MAXFRAMEX, WIZARD_SPRITE_MAXFRAMEY);
	_fMaxHealthPoint = 500.0f;
	_fCurrentHealthPoint = 500.0f;
	_fSpeed = 100.0f;
	_fArmor = 0.0f;
	_fEvasion = 0.0f;
	_fCriticalHit = 0.0f;
	_strObjectName = "player";
	setAnimation();
	_direction = PLAYER::DIRECTION::FORWARD;
	_action = PLAYER::ACTION::IDLE;
	_pAnimation = KEYANIMANAGER->findAnimation(_strObjectName, addAniString(_arDirection[static_cast<int>(_direction)], _arAction[static_cast<int>(_action)]));
	_pAnimation->start();
}

void PLAYER::update()
{
	move();

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

	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::FORWARD)], _arAction[static_cast<int>(PLAYER::ACTION::DASH)], 44, 47, 4, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::RIGHT)],	_arAction[static_cast<int>(PLAYER::ACTION::DASH)], 48, 53, 6, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::LEFT)],	_arAction[static_cast<int>(PLAYER::ACTION::DASH)], 59, 54, 6, false);
	addPlayerKeyAni(_arDirection[static_cast<int>(PLAYER::DIRECTION::BACK)],	_arAction[static_cast<int>(PLAYER::ACTION::DASH)], 60, 62, 3, false);

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
		//¸®¹ö½º¿ë ÁÖ·Î L
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

void PLAYER::move()
{
	_fAngleX = PI/2.0f;
	_fAngleY = 0.0f;
	_fSpeed = 0.0f;
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		//ÁÂ¿ì »óÅÂ¸é ¹ê

		if (_action != PLAYER::ACTION::RUN)
		{
			_direction = PLAYER::DIRECTION::BACK;
		}
		_action = PLAYER::ACTION::RUN;
		
		settingAni();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		//ÁÂ¿ì »óÅÂ¸é ¹ê
		if (_action != PLAYER::ACTION::RUN)
		{
			_direction = PLAYER::DIRECTION::FORWARD;
		}
		_action = PLAYER::ACTION::RUN;
		settingAni();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_direction = PLAYER::DIRECTION::LEFT;
		_action = PLAYER::ACTION::RUN;
		settingAni();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_direction = PLAYER::DIRECTION::RIGHT;
		_action = PLAYER::ACTION::RUN;
		settingAni();
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_fAngleY = PI / 2.0f;
		_fSpeed = 1.0f;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_fAngleY = PI / 2.0f + PI;
		_fSpeed = 1.0f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_fAngleX = PI;
		_fSpeed = 1.0f;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{

		_fAngleX = 0.0f;
		_fSpeed = 1.0f;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		if (_direction != PLAYER::DIRECTION::LEFT &&
			_direction != PLAYER::DIRECTION::RIGHT)
		{
			_action = PLAYER::ACTION::IDLE;
			settingAni();
		}
		
	}

	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		if (_direction != PLAYER::DIRECTION::LEFT &&
			_direction != PLAYER::DIRECTION::RIGHT)
		{
			_action = PLAYER::ACTION::IDLE;
			settingAni();
		}		
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_action = PLAYER::ACTION::IDLE;
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_direction = PLAYER::DIRECTION::BACK;
			_action = PLAYER::ACTION::RUN;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_direction = PLAYER::DIRECTION::FORWARD;
			_action = PLAYER::ACTION::RUN;
		}
		settingAni();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_action = PLAYER::ACTION::IDLE;
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_direction = PLAYER::DIRECTION::BACK;
			_action = PLAYER::ACTION::RUN;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_direction = PLAYER::DIRECTION::FORWARD;
			_action = PLAYER::ACTION::RUN;
		}
		settingAni();
	}
	

	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(_fAngleX, _fSpeed) );
	OBJECT::setPosY(OBJECT::getPosY() + Mins::presentPowerY(_fAngleY, _fSpeed) );
	settingPos();
}

void PLAYER::settingPos()
{
	_rcDamageCollision = RectMakeCenter(static_cast<int>(OBJECT::getPosX()), static_cast<int>(OBJECT::getPosY()),
		WIZARD_COLLISION_RECT_WIDTH, WIZARD_COLLISION_RECT_HEIGHT);

	_rcMovingCollision = RectMakeCenter(static_cast<int>(OBJECT::getPosX()), static_cast<int>(OBJECT::getPosY()) + 16,
		WIZARD_MOVING_RECT_SIZE, WIZARD_MOVING_RECT_SIZE);
}

void PLAYER::settingAni()
{
	_pAnimation = KEYANIMANAGER->findAnimation(_strObjectName, addAniString(_arDirection[static_cast<int>(_direction)], _arAction[static_cast<int>(_action)]));
	_pAnimation->start();
}


