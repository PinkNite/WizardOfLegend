#pragma once
#include "gameNode.h"
#include "boss.h"

class BossStageScene :	public gameNode
{
private:
	BOSS* _boss;

public:
	BossStageScene();
	~BossStageScene();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};

