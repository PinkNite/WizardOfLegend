#pragma once

#include "gameNode.h"
#include "stdafx.h"

class MAPEDIT : public gameNode 
{
private:

public:
	MAPEDIT();
	~MAPEDIT();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};