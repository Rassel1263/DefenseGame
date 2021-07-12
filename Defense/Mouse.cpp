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
}

void Mouse::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
