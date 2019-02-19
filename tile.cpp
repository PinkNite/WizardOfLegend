#include "stdafx.h"
#include "tile.h"

TILE::TILE()
{
}

TILE::~TILE()
{
}

void TILE::setttingObject()
{
	string strTmp = "";

	switch (_object)
	{
	case TILE::NONE:
		
		break;
	case TILE::PLAYER:
		strTmp.append("pacman32");
		break;
	case TILE::ENEMY01:
		strTmp.append("yellowEnemy32");
		break;
	case TILE::ENEMY02:
		strTmp.append("skyEnemy32");
		break;
	case TILE::ENEMY03:
		strTmp.append("redEnemy32");
		break;
	case TILE::ENEMY04:
		strTmp.append("pinkEnemy32");
		break;
	case TILE::ITEM:
		strTmp.append("item");
		break;
	case TILE::NOMAL_OBJECT:
		strTmp.append("MapOBJECT2");
		break;
	case TILE::MAX:
		break;
	}


	_pObjectImage = IMAGEMANAGER->findImage(strTmp);
}

void TILE::setttingTerrain()
{
	string strTmp = "";

	switch (_terrian)
	{
	case TILE::TERRIAN::NONE:
		break;
	case TILE::TERRIAN::WALL:
		if(_terrainPageIndex == 0)
		{
			strTmp.append("MapPalletIce1");
		}
		else if (_terrainPageIndex == 1)
		{
			strTmp.append("MapPalletCastle1");
		}
		else if (_terrainPageIndex == 2)
		{
			strTmp.append("MapPalletEarth1");
		}
		else if (_terrainPageIndex == 3)
		{
			strTmp.append("MapPalletFire1");
		}
		else if (_terrainPageIndex == 4)
		{
			strTmp.append("MapEraser");
		}
		break;
	case TILE::TERRIAN::PASS:
		if (_terrainPageIndex == 0)
		{
			strTmp.append("MapPalletIce1");
		}
		else if (_terrainPageIndex == 1)
		{
			strTmp.append("MapPalletCastle1");
		}
		else if (_terrainPageIndex == 2)
		{
			strTmp.append("MapPalletEarth1");
		}
		else if (_terrainPageIndex == 3)
		{
			strTmp.append("MapPalletFire1");
		}
		else if (_terrainPageIndex == 4)
		{
			strTmp.append("MapEraser");
		}
		break;
	case TILE::TERRIAN::DMAGE_PASS:
		if (_terrainPageIndex == 0)
		{
			strTmp.append("MapPalletIce1");
		}
		else if (_terrainPageIndex == 1)
		{
			strTmp.append("MapPalletCastle1");
		}
		else if (_terrainPageIndex == 2)
		{
			strTmp.append("MapPalletEarth1");
		}
		else if (_terrainPageIndex == 3)
		{
			strTmp.append("MapPalletFire1");
		}
		else if (_terrainPageIndex == 4)
		{
			strTmp.append("MapEraser");
		}
		break;
	case TILE::TERRIAN::MAX:
		break;
	default:
		break;
	}

	_pImage = IMAGEMANAGER->findImage(strTmp);
}

void TILE::setttingObject2()
{
	string strTmp = "";

	switch (_object)
	{
	case TILE::NONE:

		break;
	case TILE::PLAYER:
		strTmp.append("pacman32");
		break;
	case TILE::ENEMY01:
		strTmp.append("yellowEnemy32");
		break;
	case TILE::ENEMY02:
		strTmp.append("skyEnemy32");
		break;
	case TILE::ENEMY03:
		strTmp.append("redEnemy32");
		break;
	case TILE::ENEMY04:
		strTmp.append("pinkEnemy32");
		break;
	case TILE::ITEM:
		strTmp.append("item");
		break;
	case TILE::NOMAL_OBJECT:
		strTmp.append("MapOBJECT2");
		break;
	case TILE::MAX:
		break;
	}


	_pObjectImage = IMAGEMANAGER->findImage(strTmp);
}

void TILE::setttingTerrain2()
{
	string strTmp = "";

	switch (_terrian)
	{
	case TILE::TERRIAN::NONE:
		break;
	case TILE::TERRIAN::WALL:
		if (_terrainPageIndex == 0)
		{
			strTmp.append("MapPalletIce2");
		}
		else if (_terrainPageIndex == 1)
		{
			strTmp.append("MapPalletCastle2");
		}
		else if (_terrainPageIndex == 2)
		{
			strTmp.append("MapPalletEarth2");
		}
		else if (_terrainPageIndex == 3)
		{
			strTmp.append("MapPalletFire2");
		}
		else if (_terrainPageIndex == 4)
		{
			strTmp.append("MapEraser2");
		}
		break;
	case TILE::TERRIAN::PASS:
		if (_terrainPageIndex == 0)
		{
			strTmp.append("MapPalletIce2");
		}
		else if (_terrainPageIndex == 1)
		{
			strTmp.append("MapPalletCastle2");
		}
		else if (_terrainPageIndex == 2)
		{
			strTmp.append("MapPalletEarth2");
		}
		else if (_terrainPageIndex == 3)
		{
			strTmp.append("MapPalletFire2");
		}
		else if (_terrainPageIndex == 4)
		{
			strTmp.append("MapEraser2");
		}
		break;
	case TILE::TERRIAN::DMAGE_PASS:
		if (_terrainPageIndex == 0)
		{
			strTmp.append("MapPalletIce2");
		}
		else if (_terrainPageIndex == 1)
		{
			strTmp.append("MapPalletCastle2");
		}
		else if (_terrainPageIndex == 2)
		{
			strTmp.append("MapPalletEarth2");
		}
		else if (_terrainPageIndex == 3)
		{
			strTmp.append("MapPalletFire2");
		}
		else if (_terrainPageIndex == 4)
		{
			strTmp.append("MapEraser2");
		}
		break;
	case TILE::TERRIAN::MAX:
		break;
	default:
		break;
	}

	_pImage = IMAGEMANAGER->findImage(strTmp);
}

void TILE::init(int nTileLeft, int nTileTop, int nTileSize, image* pImg, int nNodeIndex)
{
	setAroundWall(PASS);
	setIsWall(false);
	setTerrian(TILE::TERRIAN::PASS);
	setImg(nullptr);
	setFrameX(28);
	//setFrameX(0);
	setFrameY(0);
	setRectTile(nTileLeft, nTileTop, nTileSize, nTileSize);
	setImg(pImg);
	setNodeIndex(nNodeIndex);
	_object = OBJECT::NONE;
	setLimitRect(RectMake(0, 0, WINSIZEX, WINSIZEY));
}

void TILE::passInit(int nTileLeft, int nTileTop, int nTileSize, image* pImg)
{
	//setAroundWall(PASS);
	//setIsWall(true);
	setTerrian(TILE::TERRIAN::WALL);
	setImg(nullptr);
	setFrameX(10);
	setFrameY(0);
	_terrainPageIndex = 4;
	setRectTile(nTileLeft, nTileTop, nTileSize, nTileSize);
	setImg(pImg);
	_object = OBJECT::NONE;
	setLimitRect(RectMake(0, 0, WINSIZEX, WINSIZEY));
}

void TILE::render(HDC hdc)
{
	if (_rcTile.right > _rcCameraLimit.left
		&& _rcTile.left < _rcCameraLimit.right
		&&_rcTile.bottom > _rcCameraLimit.top
		&& _rcTile.top < _rcCameraLimit.bottom
		)
	{
		//_pImage->frameRender(hdc, _rcTile.left, _rcTile.top, _nFrameX, _nFrameY);
		if (_terrian == TERRIAN::WALL)
		{
			_pImage->frameRender(hdc, _rcTile.left, _rcTile.top, _nFrameX, _nFrameY);
			SetTextColor(hdc, RGB(255, 255, 0));
			SetBkMode(hdc, TRANSPARENT);
			sprintf_s(str, "벽");
			TextOut(hdc, _rcTile.left + 8, _rcTile.top + 8, str, strlen(str));
		}
		else if (_terrian == TERRIAN::PASS)
		{
			_pImage->frameRender(hdc, _rcTile.left, _rcTile.top, _nFrameX, _nFrameY);
			SetTextColor(hdc, RGB(0, 255, 0));
			SetBkMode(hdc, TRANSPARENT);
			sprintf_s(str, "길");
			TextOut(hdc, _rcTile.left + 8, _rcTile.top + 8, str, strlen(str));
		}
		else if (_terrian == TERRIAN::DMAGE_PASS)
		{
			_pImage->frameRender(hdc, _rcTile.left, _rcTile.top, _nFrameX, _nFrameY);
			SetTextColor(hdc, RGB(255, 0, 0));
			SetBkMode(hdc, TRANSPARENT);
			sprintf_s(str, "뎀");
			TextOut(hdc, _rcTile.left + 8, _rcTile.top + 8, str, strlen(str));
		}
		/*else if (_object == OBJECT::NOMAL_OBJECT)
		{
			SetTextColor(hdc, RGB(0, 0, 255));
			SetBkMode(hdc, TRANSPARENT);
			sprintf_s(str, "오");
			TextOut(hdc, _rcTile.left + 8, _rcTile.top + 8, str, strlen(str));
		}*/
		if (_object != OBJECT::NONE)
		{
			_pObjectImage->frameRender(hdc, _rcTile.left, _rcTile.top, getFrameX(), setFrameY());
		}
	}

}

void TILE::release()
{
	_pImage = nullptr;
}

void TILE::update()
{
}

void TILE::settingTile(int nFrameX, int nFrameY, bool bIsWall, OBJECT object)
{
	setFrameX(nFrameX);
	setFrameY(nFrameY);
	setIsWall(bIsWall);
	setObject(object);
	if (!_bIsWall)
	{
		//지우는 경우
		//패스를 까는 경우
		setAroundWall(PASS);
	}
	else
	{
		_object = OBJECT::NONE;
	}
	setttingObject();
}

void TILE::readjustWall(int nAroundWall, int nFrameX, int nFrameY)
{
	setAroundWall(nAroundWall);
	setFrameX(nFrameX);
	setFrameY(nFrameY);
}

string TILE::makeSaveString()
{
	//노드인덱스/주변값/벽/프레임x/프레임y
	string strTmp = "";
	/*strTmp.append(to_string(_nNodeIndex));
	strTmp.append("/");
	strTmp.append(to_string(_nAroundWall));
	strTmp.append("/");*/
	strTmp.append(to_string((int)_bIsWall));
	strTmp.append("/");
	strTmp.append(to_string(_nFrameX));
	strTmp.append("/");
	strTmp.append(to_string(_nFrameY));
	strTmp.append("/");
	strTmp.append(to_string(_terrainPageIndex));
	strTmp.append("/");
	strTmp.append(to_string(static_cast<int>(_object)));
	strTmp.append("/");
	strTmp.append(to_string(static_cast<int>(_terrian)));
	strTmp.append("/");

	return strTmp;
}

bool TILE::setObject(OBJECT object)
{
	if (!_bIsWall)
	{
		_object = object;
		return true;
	}

	return false;
}

TILE::OBJECT TILE::getObject()
{
	return _object;
}

void TILE::move(int vertical, int horizontal)
{
	_rcTile.left += horizontal;
	_rcTile.right += horizontal;

	_rcTile.top += vertical;
	_rcTile.bottom += vertical;
}
