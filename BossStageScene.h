#pragma once
#include "gameNode.h"
#include "boss.h"

class BossStageScene :	public gameNode
{
private:
	BOSS* _boss;

	int _frameCount;
	bool _isShow;

public:
	BossStageScene();
	~BossStageScene();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};

