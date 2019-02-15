#pragma once
#include "gameNode.h"
#include "boss.h"
#include "magicMgr.h"
#include "skillEffectMgr.h"

class BossStageScene :	public gameNode
{
private:
	BOSS* _boss;

	bool _isShow;

public:
	BossStageScene();
	~BossStageScene();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};

