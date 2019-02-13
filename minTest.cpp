#include "stdafx.h"
#include "minTest.h"


MINTESTSCENE::MINTESTSCENE()
{
}

MINTESTSCENE::~MINTESTSCENE()
{
}

HRESULT MINTESTSCENE::init()
{



	_pPlayer = new PLAYER();
	_pPlayer->init();
	
	_pMagicMgr			= new MAGICMGR();
	_pSkillEffectMgr	= new SKILL_EFFECT_MGR();

	_pMagicMgr->addObject("dashFlame", 100, 64, 64,
		IMAGEMANAGER->addFrameImage("dashFlame", "resource/skill/flame.bmp", 1408, 384, 11, 3, true, RGB(255, 0, 255)),
		6, 128, 128, 2.0f);
	_pSkillEffectMgr->addEffect(IMAGEMANAGER->addFrameImage("flameBurn", "resource/skill/flameBurnMark.bmp", 192, 48, 4, 1, true, RGB(255, 0, 255)),
		1, 48, 48, 1000, "flameBurn");
	
	IMAGEMANAGER->addFrameImage("fireStrike", "resource/skill/fireStrike.bmp", 1280, 128, 10, 1, true, RGB(255, 0, 255));

	_pMagicMgr->addObject("fireStrike", 100, 128, 128, IMAGEMANAGER->findImage("fireStrike"), 20, 128, 128, 0.5f);


	_pPlayer->setLink(_pMagicMgr, _pSkillEffectMgr);
	return S_OK;
}

void MINTESTSCENE::update()
{
	
	_pPlayer->update();
	_pMagicMgr->update();
	_pSkillEffectMgr->update();

}

void MINTESTSCENE::release()
{
	_pPlayer->release();
	_pSkillEffectMgr->release();
	_pMagicMgr->release();

	delete _pPlayer;
	delete _pSkillEffectMgr;
	delete _pMagicMgr;

	_pPlayer = nullptr;
	_pSkillEffectMgr = nullptr;
	_pMagicMgr = nullptr;
}

void MINTESTSCENE::render()
{
	_pSkillEffectMgr->render(getMemDC());
	_pPlayer->render(getMemDC());
	_pMagicMgr->render(getMemDC());



}
