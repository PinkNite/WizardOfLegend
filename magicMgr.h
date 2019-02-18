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

	void pushMagicKey(const string& strKey,float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer);
	void pushMagicKey(const string& strKey, float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer,int nFrameX,int nFrameY);


	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime);
	//애니메이션 안쓰는 애들용
	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFrameX, int nFrameY, float fTotalTime);
	//키애니메이션 용
	void addObject(animation* pAni,const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime);




	//마법과 객체 충돌은 여기서 처리하자

};