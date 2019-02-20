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

	image*		_pImg;			//���� �̹���
	animation*	_pEffectAni;	//���� ����Ʈ �ִϸ��̼�

	float	_fTotalTime;	//�� Ȱ�� �ð�
	float	_fActiveTime;	//Ȱ�� �ð�
	
	bool	_bIsActive;		//Ȱ�������� �ƴ���

	float	_fMoveAngle;	//�����̴� ����
	float	_fMoveSpeed;	//�����̴� �ӵ�

	bool	_bIsPlayer;		//�÷��̾��� �������� �ƴ���
	
	bool	_bIsAnimation;	//���ϸ��̼��� �ְ� ����
	
	string	_strKey;

	int		_nFrameX;			//������ ������
	int		_nFrameY;			//������ ������
	
	CAMERA*					_pCamera;
	PLAYER*					_pPlayer;

	float	_fCirclePosX;
	float	_fCirclePosY;
	
	bool	_bIsTrun;			//���� �ִ��� ������
	float	_fTurnTime;

	bool	_bIsDamage;			//���׹̳� �������� �������� �� �����̴�

	float	_fDamage;			//������
	MAP*	_pMap;

	bool	_bIsCollisionRemove;

public:
	MAGIC();
	~MAGIC();


	void	init(int nWidth, int nHeight,image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY,float fTotalTime, const string& strKey,bool bIsCollisionRemove);
	void	init(int nWidth, int nHeight, image* pImg, animation* pAni, float fTotalTime, const string& strkey, bool bIsCollisionRemove);
	void	init(int nWidth, int nHeight, image* pImg, int nFrameX,int nFrameY, float fTotalTime, const string& strkey, bool bIsCollisionRemove);
	//��ȣ���� �簢�� ���� ���� �̹��� FPS �̹��� ���� �̹��� ���� �� ���� �ð� �߰��� � �ٲ�� �ð� Ű��
	void	init(int nWidth, int nHeight, image* pImg, int nFps, int nFrameMaxX, int nFrameMaxY, float fTotalTime,float fTurnTime, const string& strKey);
	
	void	release()		override;
	void	update()		override;
	void	render(HDC hdc)	override;

	void	create(float fPosX, float fPosY,float fMoveAngle, float fMoveSpeed,bool bIsPlayer);

	void	create(float fPosX, float fPosY, float fMoveAngle, float fMoveSpeed, bool bIsPlayer, int nFrameX, int nFrameY);
	
	//��ȣ���� �� �߽� x y ������ �÷��̾� ������
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