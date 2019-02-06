#pragma once

#include "object.h"
#include "stdafx.h"

class PLAYER : public OBJECT
{
public:
	enum class DIRECTION
	{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
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

};