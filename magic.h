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

	image*		_pImg;			//���� �̹���
	animation*	_pEffectAni;	//���� ����Ʈ �ִϸ��̼�

	float	_fTotalTime;	//�� Ȱ�� �ð�
	float	_fActiveTime;	//Ȱ�� �ð�
	
	bool	_bIsActive;		//Ȱ�������� �ƴ���

	float	_fMoveAngle;	//�����̴� ����
	float	_fMoveSpeed;	//�����̴� �ӵ�

	bool	_bIsPlayer;		//�÷��̾��� �������� �ƴ���

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