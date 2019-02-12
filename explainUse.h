#pragma once
#include "explainUse.h"
#include "object.h"
class EXPLAINUSE:public OBJECT
{
public:
	EXPLAINUSE();
	~EXPLAINUSE();
	HRESULT init();
	void release();
	void update();
	void render();
};

