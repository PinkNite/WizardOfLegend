#pragma once

#include "stdafx.h"
#include "tile.h"
#include "map.h"

class ASTAR {
public:
	struct TILENODE
	{
		int			nIndexX;
		int			nIndexY;
		int			nPathStartToCurrent;
		int			nPathCurrentToEnd;
		int			nPathToatalCost;
		TILENODE*	parrentNode;
	};

	enum POS
	{
		POSX = 0,
		POSY,
		MAX
	};

	

private:
	list<TILENODE*>				_listOpendNode;		//Ž���� �Ҽ� �ִ� ������ ����.
	list<TILENODE*>				_listClosedyPath;	//Ž���� ���� ������ ����.
	list<TILENODE*>				_listMaximumPath;	//������ ��ε��� ��� ����Ʈ
	vector<vector<TILENODE*>>	_vvTile;			//ã�ƺ� Ÿ�� �迭

												//						  ��		  ��			��		��		�»�    ���   ����     ����
	int	_arInterval[8][2]{ { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 },{ -1,-1 },{ 1,-1 },{ -1,1 },{ 1,1 } };
	int	_arHuristic[8]{ 10,	  10,		10,		10,		14,			14,		14,		14 };

	int				_nTileSizeX;
	int				_nTileSizeY;

	int				_nStartIndexX;
	int				_nStartIndexY;
	int				_nEndIndexX;
	int				_nEndIndexY;

	TILE::OBJECT	_obj;
	int				_nSearchLength;//4�� 8
	MAP*			_pMap;
public:
	ASTAR();
	~ASTAR();
	void	init(int nSearchLength,MAP* pMap);
	//��� Ÿ�Ͽ� �ִ��� �ִ� �Լ�
	void	startFinder(int nStartIndexX, int nStartIndexY, int nEndIndexX, int nEndIndexY);
	void	pathFinder();	// _stackPriority���� �ϼ��� �ȴ�.
	POINT	getTileIndex(RECT& rc);
	POINT	getTileIndex(float x, float y);
	
	void	setObject(TILE::OBJECT obj);
	void	release();


	list<TILENODE*>&		getPath() { return _listMaximumPath; }
	int		getListSize() { return static_cast<int>(_listMaximumPath.size()); }
	TILENODE*	getNode(int nIndex);
	bool	bIsEmety() { return _listMaximumPath.empty(); }

private:
	void	initMap();
};