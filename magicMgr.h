#pragma once
#include "stdafx.h"
#include "magic.h"

class MAGICMGR {
private:
	map<string,queue<MAGIC*>>		_mqMagicPool;
	list<MAGIC*>					_lActiveMagic;


public:
	MAGICMGR();
	~MAGICMGR();

	void init();
	void update();
	void release();
	void render(HDC hdc);

	void useMagic(const string& strKey,float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer);
	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime);
	
	//Ű�ִϸ��̼� ��
	void addObject(animation* pAni,const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime);


	//������ ��ü �浹�� ���⼭ ó������

};