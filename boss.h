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
		LEFT,
		RIGHT,
		UP,
		DOWN,
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
	const int BOSS_IMAGE_WIDTH = 990;
	const int BOSS_IMAGE_HEIGHT = 1080;
	const int BOSS_MAX_FRAME_X = 11;
	const int BOSS_MAX_FRAME_Y = 9;
	const int BOSS_RECT_WIDTH = 90;
	const int BOSS_RECT_HEIGHT = 100; // FrameSize: 90, 120

	float _fMaxHP;
	float _fCurrentHP;
	float _fSpeed;

	map<ACTION, string> _mAction;
	map<DIRECTION, string> _mDirection;

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

	const string getAnimationKey(const string& strDir, const string& strAction);

	void addBossKeyAni(const string& strDir, const string& strActoin, int startFrame, int endFrame, int fps, bool isLoop);

public:
	// state pattern
	void initState();
	void setState(BOSS_STATE bossState);
	void setAction(ACTION action);
	void setDirection(DIRECTION direction);
	void handleState(BOSS_STATE bossState);

	void startAnimation();

	void handleInputKey();
	void moveUp(float speed);
	void moveDown(float speed);
	void moveLeft(float speed);
	void moveRight(float speed);

	void dash(float offset);
	void setRect();
	void moveBoss();

	void setDirectUp();
	void setDirectDown();
	void setDirectLeft();
	void setDirectRight();

	inline void setDashTime(float dashTime) { _fDashTime = dashTime; }
	inline float getSpeed() { return _fSpeed; }
	inline float getDashTime() { return _fDashTime; }
	inline DIRECTION getDiretion() { return _direction; }
	inline animation* getAni() { return _pAnimation; }

};

