#pragma once
#include "tile.h"
#include "camera.h"


class MAP
{
public:
	MAP();
	~MAP();
private:
	//한 타일의 사이즈는 64로 한다. 64 X 64
	int		_nTileSize;

	//타일 갯수는 가로 25 / 세로 14
	int		_nTileCountX;
	int		_nTileCountY;

	//타일 총 사이즈
	int		_nMapWidth;
	int		_nMapHeight;

							
	vector<vector<TILE*>>	_vvMap;//맵

	//맵 frame
	image*	_pImgMap;
	image*	_pObjectImg;

	//카메라
	CAMERA*	_pCamera;

	int		_nVertical;
	int		_nHorizontal;
	bool	_bIsWall;
	TILE::OBJECT	_object;

	string	_strMapName;

private:
	void	createMap();
	
public:
	//기본 셋
	void	init(const char* mapName);
	void	initBossMap(const char* mapName);
	void	release();
	void	render(HDC hdc);
	void	update();
	//추가분

	void	load();
	void	loadBossMap();

	void	settingLimitRect();

	
	//오브젝트의 타일 좌표를 얻는데 
	bool	getObjectPos(vector<vector<int>>& _vvTileIndex, TILE::OBJECT object);

	void	deleteObject();

	inline	int		getMapCountX() { return _nTileCountX; }
	inline	int		getMapCountY() { return _nTileCountY; }
	inline	int		getTileSize() { return _nTileSize; }
	inline	void	setisWall(bool bIsWall) { _bIsWall = bIsWall; }
	inline	void	setCamera(CAMERA* pCamera) { _pCamera = pCamera; }

	inline	TILE*	getTile(int nX, int nY) { return _vvMap[nY][nX]; }


	void	drawMap(HDC hdc);
};
