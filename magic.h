#pragma once
#include "stdafx.h"
#include "animation.h"
#include "object.h"
#include "map.h"

class CAMERA;
class PLAYER;

class MAGIC : public OBJECT{
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
	
	bool	_bIsAnimation;	//에니메이션이 있고 없고
	
	string	_strKey;

	int		_nFrameX;			//프레임 렌더용
	int		_nFrameY;			//프레임 렌더용
	
	CAMERA*					_pCamera;
	PLAYER*					_pPlayer;

	float	_fCirclePosX;
	float	_fCirclePosY;
	
	bool	_bIsTrun;			//턴이 있는지 없는지
	float	_fTurnTime;

	bool	_bIsDamage;			//에네미나 보스한테 데미지를 준 마법이다

	float	_fDamage;			//데미지
	MAP*	_pMap;

	bool	_bIsCollisionRemove;

public:
	MAGIC();
	~MAGIC();


	void	init(int nWidth, int nHeight,image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY,float fTotalTime, const string& strKey,bool bIsCollisionRemove);
	void	init(int nWidth, int nHeight, image* pImg, animation* pAni, float fTotalTime, const string& strkey, bool bIsCollisionRemove);
	void	init(int nWidth, int nHeight, image* pImg, int nFrameX,int nFrameY, float fTotalTime, const string& strkey, bool bIsCollisionRemove);
	//수호형용 사각형 가로 세로 이미지 FPS 이미지 가로 이미지 세로 총 렌더 시간 중간에 운동 바뀌는 시간 키값
	void	init(int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime,float fTurnTime, const string& strKey);
	
	void	release()		override;
	void	update()		override;
	void	render(HDC hdc)	override;

	void	create(float fPosX, float fPosY,float fMoveAngle, float fMoveSpeed,bool bIsPlayer);

	void	create(float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer, int nFrameX, int nFrameY);
	
	//수호형용 원 중심 x y 반지름 플레이어 꺼인지
	void	create(bool bIsPlayer,float fCirclePosX, float fCirclePosY, float fRadius,float fAngle);

	void	returnPool();
	bool	getActive() { return _bIsActive; }
	const string&	getKey() { return _strKey; }

	RECT*	getRect() { return &_rcCollision; }
	bool	getIsAni() { return _bIsAnimation; }

	void	setCamera(CAMERA*	pCamera) { _pCamera = pCamera; }
	void	setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }

	bool	getIsPlayer() { return _bIsPlayer; }

	void	setIsDamage(bool bIsDamage) { _bIsDamage = bIsDamage; }
	
	float	getDamage() { return _fDamage; }
	void	setDamage(float fDamage) { _fDamage = fDamage; }

	void	setMap(MAP* pMap) { _pMap = pMap; }

private:
	bool	isCollisionWall();
};