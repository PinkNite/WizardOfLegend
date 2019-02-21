#pragma once
#include "stdafx.h"
#include "magic.h"
#include "map.h"

class CAMERA;
class PLAYER;
class Enemy;
class BOSS;

class MAGICMGR {
private:
	map<string,queue<MAGIC*>>		_mqMagicPool;
	list<MAGIC*>					_lActiveMagic;
	vector<Enemy*>					_vEnemyList;

	CAMERA*					_pCamera;
	PLAYER*					_pPlayer;
	Enemy*					_pEnemy;
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
	
	//��ȣ����
	void pushMagicKey(const string& strKey, bool bIsPlayer,float fCirclePosX, float fCirclePosY, float fRadius, float fAngle);

	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime,float fDamage, bool bIsCollisionRemove);
	//�ִϸ��̼� �Ⱦ��� �ֵ��
	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFrameX, int nFrameY, float fTotalTime, float fDamage, bool bIsCollisionRemove);
	//Ű�ִϸ��̼� ��
	void addObject(animation* pAni,const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime, float fDamage, bool bIsCollisionRemove);
	//��ȣ����
	void addObject(const string& strKey, int nMagicCount, int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime,float fTurnTime, float fDamage, bool bIsCollisionRemove);

	void setLink(CAMERA* pCamera) { _pCamera = pCamera; }
	void setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }
	void setBoss(BOSS* pBoss) { _pBoss = pBoss; }
	void setMap(MAP* pMap) { _pMap = pMap; }
	void setEnemy(Enemy* pEnemy) { _pEnemy = pEnemy; }
	void setEnemyList(vector<Enemy*> vEnemyList) { _vEnemyList = vEnemyList; }

	//������ ��ü �浹�� ���⼭ ó������
private:
	void CollisionPlayerToMagic();
	void CollisionEnemyToMagic();
	void CollisionBossToMagic();
};