#pragma once
#include "gameNode.h"
#include "stdafx.h"

class STAGESCENE : public gameNode
{
private:

public:
	STAGESCENE();
	~STAGESCENE();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;

};