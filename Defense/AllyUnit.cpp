#include "DXUT.h"
#include "AllyUnit.h"

AllyUnit::AllyUnit(D3DXVECTOR2 pos, int index) : Units(pos, index)
{
	spr.LoadAll(L"Assets/Sprites/Units/Ally/" + std::to_wstring(unitIndex));

	Collider2D::Circle circle;
	circle.radius = 100;

	bodies.push_back(Collider2D(this, L"ally", nullptr, &circle));
}

void AllyUnit::Update(float deltaTime)
{
	if (Input::GetInstance().KeyDown(VK_RBUTTON))
	{
		if (pos.x - 120 < Input::GetInstance().GetFixedMPos().x && pos.x + 120 > Input::GetInstance().GetFixedMPos().x &&
			pos.y - 108 < Input::GetInstance().GetFixedMPos().y && pos.y + 108 > Input::GetInstance().GetFixedMPos().y)
		{
			int xIndex = (pos.x - 360) / 240;
			int yIndex = pos.y / 216 + 2;

			static_cast<GameScene*>(nowScene)->map->useGround[yIndex][xIndex] = false;
			destroy = true;
		}
	}


	spr.Update(deltaTime);
}

void AllyUnit::Render()
{
	Units::Render();
}
