#pragma once

#include "object.h"
#include "stdafx.h"
#include "animation.h"
class PLAYER : public OBJECT
{
public:
	enum class DIRECTION
	{
		FORWARD = 0,
		RIGHT,
		LEFT,
		BACK,
		MAX
	};

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
	enum { WIZARD_SPRITE_WIDTH = 1344 };
	enum { WIZARD_SPRITE_HEIGHT = 1536 };
	enum { WIZARD_SPRITE_MAXFRAMEX = 14 };
	enum { WIZARD_SPRITE_MAXFRAMEY = 16 };

private:
	float _fMaxHealthPoint;			//�ִ� �����
	float _fCurrentHealthPoint;		//���� �����
	float _fSpeed;					//�ӵ�
	float _fArmor;					//����
	float _fEvasion;				//ȸ����
	float _fCriticalHit;			//ġ��Ÿ��

	float	_fPosMovingX;				//�����̴� �� x
	float	_fPosMovingY;				//�����̴� �� y
	int		_nCollsionMovingWidth;	//������ �浹�� ����
	int		_nCollsionMovingHeight;	//������ �浹�� ����

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

	

};