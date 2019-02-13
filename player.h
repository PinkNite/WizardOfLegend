#pragma once

#include "object.h"
#include "stdafx.h"
#include "animation.h"
#include "circleEffect.h"

class STATE;
class SKILL;
class MAGICMGR;
class SKILL_EFFECT_MGR;


class PLAYER : public OBJECT
{
public:
	//�ִϸ��̼� ��
	enum class DIRECTION
	{
		FORWARD = 0,
		RIGHT,
		LEFT,
		BACK,
		MAX
	};
	//�ִϸ��̼� ��
	enum class ACTION
	{
		IDLE = 0,
		RUN,
		DASH,
		ATTACK_MOTION_01,
		ATTACK_MOTION_02,
		ATTACK_MOTION_03,
		ATTACK_MOTION_04,
		DAMAGE,
		DEATH,
		MAX
	};

	//���¿�
	enum class PLAYER_STATE
	{
		IDLE = 0,
		RUN,
		DASH,
		SKILL_01,
		SKILL_02,
		SKILL_03,
		SKILL_04,
		SKILL_05,
		DAMAGE,
		DEATH,
		MAX
	};

	//�̵���
	enum class MOVE_DIRECTION
	{
		NONE = 0,
		LEFT,
		RIGHT,
		TOP,
		BOTTOM,
		LEFT_TOP,
		LEFT_BOTTOM,
		RIGHT_TOP,
		RIGHT_BOTTOM,
		MAX
	};


	enum { WIZARD_SPRITE_WIDTH = 2688 };
	enum { WIZARD_SPRITE_HEIGHT = 3072 };
	enum { WIZARD_SPRITE_MAXFRAMEX = 14 };
	enum { WIZARD_SPRITE_MAXFRAMEY = 16 };

	enum { WIZARD_MOVING_RECT_SIZE = 64};

	enum { WIZARD_COLLISION_RECT_WIDTH = 64};
	enum { WIZARD_COLLISION_RECT_HEIGHT = 128 };

	
private:
	float _fMaxHealthPoint;			//�ִ� �����
	float _fCurrentHealthPoint;		//���� �����
	float _fSpeed;					//�ӵ�
	float _fArmor;					//����
	float _fEvasion;				//ȸ����
	float _fCriticalHit;			//ġ��Ÿ��


	//���ڵ���극����� �̵� Ÿ���� Ȯ���ϴ� ���� �簢���� �߾Ӱ��� ���� ������ �־���Ѵ�.
	//�÷��̾ ������ ���Ϸ� �����ϰ� �Ʒ� �簢���� �̵��� �浹 ��Ʈ�� �Ѵ�

	float _fSkillDelayTime[6];			//��ų ������ �ð�//��ų ���õȰ��� 6�� �ִٰ� ġ��...

	// ����� �׼��� �̸�
	string _arDirection[static_cast<const int>(DIRECTION::MAX)];
	string _arAction[static_cast<const int>(ACTION::MAX)];

	RECT	_rcMovingCollision;
	RECT	_rcDamageCollision;
	//������Ʈ�� �簢���� ���� ��� �Ұ��̴�.
	//�̹��� ����� ������Ʈ�� ���� ������ ũ�� �����̴�.

	animation* _pAnimation;
	
	//������
	int _arFrame[12];

	DIRECTION	_direction;
	ACTION		_action;
	string		_strObjectName;

	//�̵�����
	float		_fAngleX;
	float		_fAngleY;

	float		_fDashTime;


	STATE*		_pCurrentState;
	STATE*		_arState[static_cast<const int>(PLAYER::PLAYER_STATE::MAX)];


	MOVE_DIRECTION			_eMoveDirection;
	CIRCLEEFFECT*		_pCirEffect;
	
	float		_fAttackDirAngle;

	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;

	//�ӽ�
	SKILL*		_pFireDash;
public:
	PLAYER();
	~PLAYER();

	//���� ������ �ٸ� ���� ���� �Ǿ� �� �� �ֱ⿡ �ʿ�
	void load();
	//���� ������ ������ �ʿ��ϴ�. ��ų�� ������ ��� �ִ��� ����� �������� ����� ������ �����Ѵ�.
	void save();
	//�ʱ�ȭ
	void init();


	//�ڽĵ鿡�� ������ �ʼ�
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;


private:
	void setEnumName();
	void setAnimation();

	const string addAniString(const string& strDir, const string& strAction);

	void addPlayerKeyAni(const string & strDir, const string & strAction, int nStartFrame,int nEndFrame, int nFPS, bool bIsLoop);

	//��ų���� ��ų ���� �ð��� ������ �� �ð��� ������ �ִϸ��̼��� �ٲٰ� ����

	void settingPos();
	


public:
//state pattern��
//skill�� ���� ������ �ʿ䰡 �ִ�.
//��ų�� ���� �˾ƾ��Ѵ�.

	void setState(PLAYER::PLAYER_STATE ePlayerState);
	void setDirection(PLAYER::DIRECTION eDirection);
	void settingAni();
	void setAction(PLAYER::ACTION eAction);
	void input();
	void initState();
public:
	void moveUp(float fSpeed);
	void moveDown(float fSpeed);
	void moveLeft(float fSpeed);
	void moveRight(float fSpeed);
	void moveUpLeft(float fSpeed);
	void moveUpRight(float fSpeed);
	void moveDownLeft(float fSpeed);
	void moveDownRight(float fSpeed);



	inline float getSpeed() { return _fSpeed; }
	void dash(float fOffset);
	void movePlayer();

	void setDirectionUp();
	void setDirectionDown();
	void setDirectionLeft();
	void setDirectionRight();

public:
	inline void setDashTime(float fDashTime) { _fDashTime = fDashTime; }
	inline float getDashTime() { return _fDashTime; }
	void addDashTime() { _fDashTime += TIMEMANAGER->getElapsedTime(); }

public:
	inline PLAYER::DIRECTION getDrection() { return _direction; }
	inline animation* getAni() { return _pAnimation; }



	void setLink(MAGICMGR* pMagicMgr, SKILL_EFFECT_MGR* pSkillEffectMgr);


	//�ӽ�
	SKILL*	getSkill() { return _pFireDash; }
};