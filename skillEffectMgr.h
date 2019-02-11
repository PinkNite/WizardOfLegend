#pragma once
#include "stdafx.h"
#include "skillEffect.h"

class SKILL_EFFECT_MGR
{
private:
	map<string,queue<SKILL_EFFECT*>>	_mqEffectPool;
	list<SKILL_EFFECT*>					_lPlayList;

	

public:
	SKILL_EFFECT_MGR();
	~SKILL_EFFECT_MGR();

	bool addEffect(image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, int nEffectCount, string strEffecKey);
	void release();
	void update();
	void render(HDC hdc);
	
	bool activityEffect(string strEffectKey,float fPosX, float fPosY);
	
};
