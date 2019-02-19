#pragma once
#include "gameNode.h"
#include "boss.h"
#include "skillEffectMgr.h"
#include "magicMgr.h"
#include "camera.h"

class BossStageScene :	public gameNode
{
private:
	BOSS* _pBoss;
	CAMERA*				_pCamera;
	MAGICMGR*			_pMagicMgr;

	bool _isShow;

public:
	BossStageScene();
	~BossStageScene();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};

