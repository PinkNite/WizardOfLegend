#pragma once

#include "stdafx.h"
#include "gameNode.h"
#include "player.h"

class MINTESTSCENE : public gameNode
{
private:
	PLAYER * _pPlayer;

public:
	MINTESTSCENE();
	~MINTESTSCENE();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};