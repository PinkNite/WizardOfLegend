#pragma once
#include "stdafx.h"
#include "animation.h"

class MAGIC {
private:
	float	_fPosX;
	float	_fPosY;
	int		_nWidth;
	int		_nHeight;
	RECT	_rcCollision;

	image*		_pImg;			//마법 이미지
	animation*	_pEffectAni;	//마법 이펙트 애니메이션

	float	_fTotalTime;	//총 활성 시간
	float	_fActiveTime;	//활동 시간
	
	bool	_bIsActive;		//활동중인지 아닌지

	float	_fMoveAngle;	//움직이는 각도
	float	_fMoveSpeed;	//움직이는 속도

	bool	_bIsPlayer;		//플레이어의 마법인지 아닌지

	string	_strKey;
public:
	MAGIC();
	~MAGIC();


	void	init(int nWidth, int nHeight,image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY,float fTotalTime, const string& strKey);
	void	init(int nWidth, int nHeight, image* pImg, animation* pAni, float fTotalTime, const string& strkey);
	void	release();
	void	update();
	void	render(HDC hdc);

	void	create(float fPosX, float fPosY,float fMoveAngle, float fMoveSpeed,bool bIsPlayer);
	void	returnPool();
	bool	getActive() { return _bIsActive; }
	const string&	getKey() { return _strKey; }

	RECT*	getRect() { return &_rcCollision; }
};