#pragma once

#include "stdafx.h"
#include "image.h"
#include "object.h"

//������ �ٲپ���Ѵ�.
//y�� ������ ����

//���� y���� ġ�� ���� ���� + ������Ʈ ����
//����� + �÷��̾�
//����̴� ������� ����.
//������Ʈ ���̴� �� �ٸ���.
//y���� Ŭ���� ������ y����ġ�� ��������.


class CAMERA {
private:
	float _posX;			//�߽�x			(��������)
	float _posY;			//�߽�y			(��������)
	int _width;				//ȭ���� ���α���(��������)
	int _height;			//ȭ���� ���α���(��������)
	int	_left;				//�׸� ���� left	(��������)
	int _top;				//�׸����� right	(��������)
	image* _pCameraBuffer;
	HDC		_hdc;
	bool	_isMoving;		
	float	_time;
	float	_travelRangeX;
	float	_travelRangeY;
	RECT	_rcCameraLimit;
	
	list<OBJECT*>		_listRenderObject;
	int		_nMapWidth;		//���� ����	(World)
	int		_nMapHeight;	//���� ����	(World)

	image*	_pBackGroundBuffer;

public:
	CAMERA();
	~CAMERA();
	
	void init(int posX, int posY, int windowWidth, int windowHeight,int mapWidth,int mapHeight);
	void update();

	void render(HDC hdc);
	void release();
	void renderinit();
	void	setting(int nPosX,int nPosY);										//���� ��ǥ�� ��´�
	void	settingCameraRange(int nLeft, int nTop, int nRight, int nBottom);	//ī�޶� �׸��� ������ ����
private:
	void	setLeftTop();

public:

	void	moveRight(float offset);
	void	moveLeft(float offset);
	void	moveUp(float offset);
	void	moveDown(float offset);

	void	outOfRange();

public:
	inline	int	getLeft() { return _left; }
	inline	int	getTop() { return _top; }
	inline	int	getRight() { return _left + _width; }
	inline	int	getBotton() { return _top + _height; }
	inline	int	getWidth() { return _width; }
	inline	int	getHeight() { return _height; }
	inline	bool getMoving() { return _isMoving; }

	inline	RECT getLimitRect() { return _rcCameraLimit; }


public:
	image * getCameraBuffer() { return _pCameraBuffer; }
	HDC getMemDC() { return _pCameraBuffer->getMemDC(); }
	void	setCameraBuffer(image* pImg);
	void	pushRenderObject(OBJECT* pObject);


	HDC	getBackGoroundBuffer() { return _pBackGroundBuffer->getMemDC(); }
};
