#include "DXUT.h"
#include "Map.h"

Map::Map()
{
	eGround.resize(5);
	eRi.resize(5);

	pGround.resize(5);
	pRi.resize(5);

	int xSize = 3;

	for (int i = 0; i < 5; ++i)
	{
		eGround[i].LoadAll(L"Assets/Sprites/EGround.png");
		eRi[i].pos = D3DXVECTOR2(-360.0f, 216 * (i - 2));

		pGround[i].resize(xSize);
		pRi[i].resize(xSize);

		for (int j = 0; j < xSize; ++j)
		{
			pGround[i][j].LoadAll(L"Assets/Sprites/pGround.png");
			pRi[i][j].pos = D3DXVECTOR2(360 + 240 * j, 216 * (i - 2));
		}
	}

}

void Map::Update(float deltaTime)
{
	float mousePosY = Input::GetInstance().mousePos.y + Game::GetInstance().destCameraPos.y + 1;
	float mousePosX = Input::GetInstance().mousePos.x + Game::GetInstance().destCameraPos.x;

	int yIndex = round(mousePosY / 216) + 2;

	if (mousePosX > 240)
	{
		int xIndex = round((mousePosX - 360) / 240);

		if (pastXIndex == xIndex && pastYIndex == yIndex)
			SetColor(pGround[yIndex][xIndex], D3DCOLOR_ARGB(255, 0, 0, 0));
		else
			SetColor(pGround[pastYIndex][pastXIndex], D3DCOLOR_ARGB(255, 255, 255, 255));

		if (Input::GetInstance().KeyDown(VK_LBUTTON))
			nowScene->obm.AddObject(new Units(D3DXVECTOR2(360 + 240 * xIndex, 216 * (yIndex - 2))));

		pastXIndex = xIndex;
	}
	/*else
	{
		if (pastYIndex == yIndex)
			SetColor(eGround[yIndex], D3DCOLOR_ARGB(255, 0, 0, 0));
		else
			SetColor(eGround[pastYIndex], D3DCOLOR_ARGB(255, 255, 255, 255));
	}*/

	pastYIndex = yIndex;

}

void Map::Render()
{
	for (int i = 0; i < 5; ++i)
	{
		eGround[i].Render(eRi[i]);

		int xSize = pGround[i].size();
		for (int j = 0; j < xSize; ++j)
		{
			pGround[i][j].Render(pRi[i][j]);
		}
	}

}

void Map::SetColor(Sprite& spr, D3DXCOLOR color)
{
	spr.color = color;
}
