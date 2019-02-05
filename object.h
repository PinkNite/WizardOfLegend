#pragma once

#include "stdafx.h"


class OBJECT abstract {


protected:
	float		_posX;		//�߽���ǥ x
	float		_posY;		//�߽���ǥ y
	int			_width;		//���α���
	int			_height;	//���α���
	int			_left;		//�簢�� ����
	int			_top;		//�簢�� ��
	image*		_pImg;		//�̹��� ����
	RECT		_rc;		//�簢��

public:
	//x,y���α��� ���α��� �ʱ�ȭ
	virtual void init(float posX, float posY, int width, int height);

	//�ڽĵ鿡�� ������ �ʼ�
	virtual void update()			abstract;
	virtual void release()			abstract;
	virtual void render(HDC hdc)	abstract;

	void setImage(image* pImage);
	int getLeft();
	int getTop();

public:
	//get set inline����
	inline float getPosX() { return _posX; }
	inline float getPosY() { return _posY; }
	inline int getWidth() { return _width; }
	inline int getHeight() { return _height; }
	inline image* getImage() { return _pImg; }


	inline void setPosX(float posX) { _posX = posX; }
	inline void setPosY(float posY) { _posY = posY; }
	inline void setWidth(int width) { _width = width; }
	inline void setHeight(int height) { _height = height; }
	

};

