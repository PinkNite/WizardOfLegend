#pragma once

class rotateImgMaker
{
public:
	rotateImgMaker();
	~rotateImgMaker();

	
	image* MakeRotateImg(image* sourImg, int sourX, int sourY, int sourWid, int sourHei, float angle, bool trans, COLORREF transColor);
};

