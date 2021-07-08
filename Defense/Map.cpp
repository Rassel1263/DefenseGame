#include "DXUT.h"
#include "Map.h"

Map::Map()
{
	eGround.resize(5);
	ri.resize(5);

	for (int i = 0; i < 5; ++i)
	{
		eGround[i].LoadAll(L"Assets/Sprites/EGround.png");
		ri[i].pos = D3DXVECTOR2(-310.0f, 216 * (i - 2));
	}
}

void Map::Update(float deltaTime)
{
	int mousePosY = Input::GetInstance().mousePos.y + Game::GetInstance().destCameraPos.y;

	mousePosY = mousePosY / 108;

	eGround[mousePosY + 2].color = D3DCOLOR_ARGB(255, 0, 0, 0);

	std::cout << mousePosY << std::endl;
}

void Map::Render()
{
	for (int i = 0; i < 5; ++i)
		eGround[i].Render(ri[i]);
}
