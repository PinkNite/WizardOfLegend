#include "stdafx.h"
#include "skillEffectMgr.h"

SKILL_EFFECT_MGR::SKILL_EFFECT_MGR()
{
}

SKILL_EFFECT_MGR::~SKILL_EFFECT_MGR()
{
}

bool SKILL_EFFECT_MGR::addEffect(image * pImg, int nFps, int nFrameMaxX, int nFrameMaxY, int nEffectCount, string strEffecKey)
{
	if (_mqEffectPool.find(strEffecKey) == _mqEffectPool.end())
	{
		queue<SKILL_EFFECT*> queEffect;
		//¾ø´Â ÀÌÆåÆ® 
		for (int i = 0; i < nEffectCount; i++)
		{
			SKILL_EFFECT* pSkillEffect = new SKILL_EFFECT();
			pSkillEffect->init(pImg, nFps, nFrameMaxX, nFrameMaxY);
			queEffect.push(pSkillEffect);
		}

		_mqEffectPool.insert(pair<string, queue<SKILL_EFFECT*>>(strEffecKey, queEffect));

		return true;
	}
	return false;
}


void SKILL_EFFECT_MGR::release()
{
}

void SKILL_EFFECT_MGR::update()
{
	list<SKILL_EFFECT*>::iterator iter = _lPlayList.begin();
	list<SKILL_EFFECT*>::iterator end = _lPlayList.end();
	while (iter != end)
	{
		SKILL_EFFECT* pEffect = *iter;
		pEffect->update();
		pEffect = nullptr;
	}
}

void SKILL_EFFECT_MGR::render(HDC hdc)
{

}

bool SKILL_EFFECT_MGR::activityEffect(string strEffectKey)
{
	return false;
}
