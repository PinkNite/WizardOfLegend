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
	image* imgRelicUIBG;
	image* imgRelicUIBG2;
	image* imgRelicUITypePageBG;
	image* imgRelicUIDrawer;
	image* imgRelicUISelectPageBG;
	image* imgMapPalletIce1;
	image* imgMapPalletEarth1;
	image* imgMapPalletFire1;
	image* imgMapPalletCastle1;
	image* imgMapEraser;
	image* imgMapObject;
	image* imgMapObject2;
	image* imgMapPalletIce2;
	image* imgMapPalletCastle2;
	image* imgMapPalletEarth2;
	image* imgMapPalletFire2;
	image* imgMapEraser2;
	
	RECT rcMapPalletIce1;
	RECT rcMapPalletEarth1;
	RECT rcMapPalletFire1;
	RECT rcMapPalletCastle1;
	RECT rcMapPalletEraser;
	RECT rcRelicUIDrawer[5];
	RECT rcBtnTitle[5];
	RECT rcTypePageVertex;
	RECT rcTypePage;
	RECT rcSelectPageVertex;
	RECT rcSelectPage;
	RECT rcMapOBJECT;
	POINT pt[3];
	POINT movingWindow;

	//°ÝÀÚ
	RECT* _rcTileCountX;
	RECT* _rcTileCountY;
	char str[128];

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
	bool _clickMap;
	POINT _clickDownStart;
	POINT _clickDownEnd;
	POINT _clickDownStart2;
	POINT _clickDownEnd2;
	POINT _currentIndex;

	MAPTOOL* _pMapTool;
	TILE::OBJECT _object;

	CAMERA*	 _pCamera;
	MAPEDITSTATE _mapEditstate;
	vector<image *>				 _vTerrainPage;
	vector<image *>::iterator	 _viTerrainPage;
	vector<image *>				 _vObjectPage;
	vector<image *>::iterator	 _viObjectPage;
	vector<image *>				 _vObjectPage2;
	vector<image *>::iterator	 _viObjectPage2;
	int _terrainPageIndex;
	int _objectPageIndex;
	char _pageIndex[128];

public:
	MAPEDIT();
	~MAPEDIT();

	void	callBackMapWall();
	void	callBackMapTerrain();
	void	callBackMapObject();
	void	callBackMapSave();
	void	callBackMapLoad();
	void	callBackMapSizeUp();
	void	callBackMapSizeDown();
	void	callBackMapSizeLeft();
	void	callBackMapSizeRight();

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
	void moveWindow();
};