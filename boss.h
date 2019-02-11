#pragma once
#include "object.h"
#include "stdafx.h"
#include "animation.h"

class BossState;

class BOSS : public OBJECT
{
public:
	enum class DIRECTION
	{
		FRONT = 0,
		LEFT,
		RIGHT,
		TOP,
		BOTTOM,
		BACK,
		MAX
	};
	//
	enum class ACTION
	{
		IDLE = 0,
		RUN,
		DASH,
		// 마법 시전 준비
		SPELL_01,
		SPELL_02,
		SPELL_03,
		// 마법 모션
		SKILL_01,
		SKILL_02,
		SKILL_03,

		ICED_IN,
		ICED_OUT,
		DAMAGE,
		DEATH,
		MAX
	};

	enum class SKILL_TYPE
	{
		CHAKRAM,
		LANCE,
		DAGGER,
		BLIZZARD,
		BUBBLE,
	};

	enum class BOSS_STATE
	{
		IDLE = 0,
		RUN,
		DASH,
		SKILL_01,
		SKILL_02,
		SKILL_03,
		DAMAGE,
		DEATH,
		MAX
	};


private:
	const int BOSS_IMAGE_WIDTH = 528;
	const int BOSS_IMAGE_HEIGHT = 512;
	const int BOSS_MAX_FRAME_X = 11;
	const int BOSS_MAX_FRAME_Y = 8;

	float _fMaxHP;
	float _fCurrentHP;
	float _fSpeed;

	string _arDirection[static_cast<const int>(DIRECTION::MAX)];
	string _arAction[static_cast<const int>(ACTION::MAX)];

	animation* _pAnimation;

	// 프레임
	int _arFrame[20];

	DIRECTION	_direction;
	ACTION		_action;
	string		_objectName;

	// 이동 방향
	float		_fAngleX;
	float		_fAngleY;

	float		_fDashTime;

	BossState*		_pCurrentState;
	BossState*		_arState[static_cast<const int>(BOSS_STATE::MAX)];

public:
	BOSS();
	~BOSS();

	void init();

	// object 함수
	void update()			override;
	void release()			override;
	void render(HDC hdc)	override;

private:
	void setEnumName();
	void setAnimation();

	const string getAniString(const string& strDir, const string& strAction);

	void addBossKeyAni(const string& strDir, const string& strActoin, int startFrame, int endFrame, int fps, bool isLoop);

public:
	// state pattern

	void setState(BOSS_STATE bossState);
	void setAction(ACTION action);
	void setDirection(DIRECTION direction);
	void startAnimation();
	void handleState(BOSS_STATE bossState);
	void initState();

	void moveUp(float speed);
	void moveDown(float speed);
	void moveLeft(float speed);
	void moveRight(float speed);

	inline float getSpeed() { return _fSpeed; }
	void dash(float offset);
	void move();

	void setDirectUp();
	void setDirectDown();
	void setDirectLeft();
	void setDirectRight();

	inline void setDashTime(float dashTime) { _fDashTime = dashTime; }
	inline float getDashTime() { return _fDashTime; }
	inline DIRECTION getDiretion() { return _direction; }
	inline animation* getAni() { return _pAnimation; }

};

