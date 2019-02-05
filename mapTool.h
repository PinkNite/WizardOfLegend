#pragma once

#include "stdafx.h"
#include "tile.h"
#include "camera.h"



class  MAPTOOL{
public:
	MAPTOOL();
	~MAPTOOL();
private:
	//�� Ÿ���� ������� 32�� �Ѵ�. 32 X 32
	int		_nTileSize;

	//Ÿ�� ������ ���� 20 / ���� 20
	int		_nTileCountX;
	int		_nTileCountY;

	//Ÿ�� �� ������� 640 X 640
	int		_nMapWidth;
	int		_nMapHeight;

	//Ÿ�ϼ� ����(Ÿ���� ���� �ȷ�Ʈ ���� ����)
	int		_nPalletSellCount = 2;

	int		_arFrameNum[141];//������ Ž�� �迭

	int		_nCurrentTileX;	//���� ���õǾ��ִ� Ÿ��x
	int		_nCurrentTileY;	//���� ���õǾ��ִ� Ÿ��y
	//��
	vector<vector<TILE*>>	_vvMap;
	//�� frame
	image*	_pImgMap;
	image*	_pObjectImg;

	//ī�޶�
	CAMERA*	_pCamera;

	int		_nVertical;
	int		_nHorizontal;
	bool	_bIsWall;
	TILE::OBJECT	_object;

private:
	void	createMap();
	void	setResizeNodeIndex();
	void	initFrameBit();

	string	setSaveMapTool();
	string	makeSaveMap();
public:
	//�⺻ ��
	void	init(int nTileCountX,int nTileCountY,int nTileSize);
	void	release();
	void	render(HDC hdc);
	void	update();
	//�߰���
	void	mapResize(int nTileCountX,int nTileCountY);
	void	readjustMap();

	void	save();
	void	load();
	
	void	settingLimitRect();

	int		getPacManPosX();
	int		getPacManPosY();
	void	deleteObject();
	bool	getItemPos(int* pPosX, int * pPosY);

	void	getEnemyPos(int* pPosX, int * pPosY,TILE::OBJECT enemy);

	inline	int		getMapCountX() { return _nTileCountX; }
	inline	int		getMapCountY() { return _nTileCountY; }
	inline	int		getTileSize() { return _nTileSize; }
	inline	void	setCurrentX(int nCurrentX) {_nCurrentTileX = nCurrentX;}
	inline	void	setCurrentY(int nCurrentY){ _nCurrentTileY = nCurrentY; }
	inline	void	setisWall(bool bIsWall) { _bIsWall = bIsWall; }
	inline	void	setObject(TILE::OBJECT object) { _object = object; }
	inline	void	setCamera(CAMERA* pCamera) { _pCamera = pCamera; }

	inline	TILE*	getTile(int nX, int nY) { return _vvMap[nY][nX]; }
	
	int		getEnemyPosX(TILE::OBJECT enemy);
	int		getEnemyPosY(TILE::OBJECT enemy);
};