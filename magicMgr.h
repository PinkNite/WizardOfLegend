#pragma once
#include "stdafx.h"
#include "magic.h"
#include "map.h"

class CAMERA;
class PLAYER;
class BOSS;

class MAGICMGR {
private:
	map<string,queue<MAGIC*>>		_mqMagicPool;
	list<MAGIC*>					_lActiveMagic;

	CAMERA*					_pCamera;
	PLAYER*					_pPlayer;
	BOSS*					_pBoss;
	MAP*					_pMap;

public:
	MAGICMGR();
	~MAGICMGR();

	void init();
	void update();
	void release();
	void render(HDC hdc);

	void pushMagicKey(const string& strKey,float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer);
	void pushMagicKey(const string& strKey, float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer,int nFrameX,int nFrameY);
	
	//수호형용
	void pushMagicKey(const string& strKey, bool bIsPlayer,float fCirclePosX, float fCirclePosY, float fRadius, float fAngle);

	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime,float fDamage);
	//애니메이션 안쓰는 애들용
	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFrameX, int nFrameY, float fTotalTime, float fDamage);
	//키애니메이션 용
	void addObject(animation* pAni,const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime, float fDamage);
	//수호형용
	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime,float fTurnTime, float fDamage);

	void setLink(CAMERA* pCamera) { _pCamera = pCamera; }
	void setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }
	void setBoss(BOSS* pBoss) { _pBoss = pBoss; }
	void setMap(MAP* pMap) { _pMap = pMap; }

	//마법과 객체 충돌은 여기서 처리하자
private:
	void CollisionPlayerToMagic();
	void CollisionEnemyToMagic();
	void CollisionBossToMagic();
};