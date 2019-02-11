#pragma once

#include "stdafx.h"
#include "animation.h"
class SKILL_EFFECT 
{
private:
	float		_fPosX;
	float		_fPosY;
	image*		_pImg;
	bool		_bIsActive;
	animation*	_pAni;
	string		_strEffectKey;
public:
	SKILL_EFFECT();
	~SKILL_EFFECT();

	//�޸� Ǯ�� ������ ���� �ʱ�ȭ �Լ�
	void init(image* pImg,int nFPS, int nFrameMaxX,int nFrameMaxY, string strEffectKey);

	//���� �Ѹ��� ���� �ʱ�ȭ �Լ�
	void create(float fPosX, float fPosY);
	
	void update();
	//�޸� ������ ���
	void release();

	void render(HDC hdc);

	//�޸����� ������ ���� �Լ�
	bool deleteEffect();

	inline const string& getEffectKEy() { return _strEffectKey; }
};