#pragma once

#include "object.h"
#include "stdafx.h"

class PLAYER : public OBJECT
{
private:
	float _fMaxHealthPoint;			//�ִ� �����
	float _fCurrentHealthPoint;		//���� �����
	float _fSpeed;					//�ӵ�
	float _fArmor;					//����
	float _fEvasion;				//ȸ����
	float _fCriticalHit;			//ġ��Ÿ��

	float _fPosMovingX;				//�����̴� �� x
	float _fPosMovingY;				//�����̴� �� y
	int		_nCollsionMovingWidth;	//������ �浹�� ����
	int		_nCollsionMovingHeight;	//������ �浹�� ����

	//���ڵ���극����� �̵� Ÿ���� Ȯ���ϴ� ���� �簢���� �߾Ӱ��� ���� ������ �־���Ѵ�.
	//�÷��̾ ������ ���Ϸ� �����ϰ� �Ʒ� �簢���� �̵��� �浹 ��Ʈ�� �Ѵ�

	float _fSkillDelayTime[6];			//��ų ������ �ð�//��ų ���õȰ��� 6�� �ִٰ� ġ��...
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