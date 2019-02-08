#pragma once

#include "gameNode.h"
#include "stdafx.h"
#include "mapTool.h"
#include "button.h"
#include "camera.h"

class MAPEDIT : public gameNode 
{
private:
	image* RelicUIBG;
	image* RelicUIBG2;
	image* RelicUITypePageBG;
	image* RelicUIDrawer;
	RECT rcRelicUIDrawer[5];
	RECT rcBtnTitle[5];

	MAPTOOL* _pMapTool;

	button* _btnWall;
	button* _btnTerrain;
	button* _btnObject;
	button* _btnSave;
	button* _btnLoad;
	POINT pt[3];

	int _VarationY[2];
	int _onDrawer;
	int _index;
	int _count;
	int _moveY[5];
	bool ptInbtn[5];
public:
	MAPEDIT();
	~MAPEDIT();

	void	callBackMapWall();
	void	callBackMapTerrain();
	void	callBackMapObject();
	void	callBackMapSave();
	void	callBackMapLoad();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};