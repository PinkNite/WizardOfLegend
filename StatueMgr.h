#pragma once
#include "stdafx.h"
#include "stoneStatue.h"
#include "map.h"
#include "camera.h"

class STATUEMGR
{
private:
	MAP * _pMap;
	vector<STONESTATUE*>	_vStoneStatue;
	CAMERA*	_pCamera;

	vector<vector<int>>		_vvStatueIndex;
public:
	STATUEMGR();
	~STATUEMGR();


	void init(MAP * pMap, CAMERA * pCamera);
	void update();
	void release();
	void addStatue(float fLeft,float fTop,int nWidth,int nHeight,image* pimage);
	


	void setLink(MAP* pMap, CAMERA* pCamera);
};
