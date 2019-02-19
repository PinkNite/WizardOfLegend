#pragma once
#include "mapTool.h"
#include "stdafx.h"
#include "gameNode.h"
#include "camera.h"

class GAMESCENE : public gameNode
{
public:
	GAMESCENE();
	~GAMESCENE();

	virtual HRESULT init()	override;
	virtual void release()	override;
	virtual void update()	override;
	virtual void render()	override;

private:
	MAPTOOL*	_pMapTool;
	CAMERA*		_pCamera;
	MAP*		_pMap;
};

