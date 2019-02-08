#pragma once

#include "gameNode.h"
#include "stdafx.h"
#include "mapTool.h"
#include "button.h"
#include "camera.h"

class MAPEDIT : public gameNode 
{
public:
	enum class MAPEDITSTATE
	{
		MAPEDITMENU = 0,
		MAPEDITWALL,
		MAPEDITTERRAIN,
		MAPEDITOBJECT,
		MAX
	};

private:
	image* RelicUIBG;
	image* RelicUIBG2;
	image* RelicUITypePageBG;
	image* RelicUIDrawer;
	image* RelicUISelectPageBG;

	RECT rcRelicUIDrawer[5];
	RECT rcBtnTitle[5];
	RECT rcTypePageVertex[4];
	RECT rcTypePage;
	POINT pt[3];
	POINT movingWindow;

	button* _btnWall;
	button* _btnTerrain;
	button* _btnObject;
	button* _btnSave;
	button* _btnLoad;

	int _drawerVertexSize;
	int _onDrawer;
	int _index;
	int _count;
	int _VarationY[2];
	int _moveY[5];
	bool _ptInbtn[5];
	bool _clickVertex;
	MAPTOOL* _pMapTool;
	MAPEDITSTATE _mapEditstate;

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
	void updateMenu();
	void updateWall();
	void updateTerrain();
	void updateObject();
	void renderMenu();
	void renderWall();
	void renderTerrain();
	void renderObject();
};