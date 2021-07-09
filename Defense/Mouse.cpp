#include "DXUT.h"
#include "Mouse.h"

Mouse::Mouse()
{
	spr.LoadAll(L"Assets/Sprites/mouse.png");

	layer = 99;
}

void Mouse::Update(float deltaTime)
{
	pos = Input::GetInstance().mousePos + Game::GetInstance().destCameraPos;

	std::cout << Input::GetInstance().GetFixedMPos().x << "          " << Input::GetInstance().GetFixedMPos().y << std::endl;
}

void Mouse::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
