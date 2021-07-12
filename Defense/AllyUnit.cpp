#include "DXUT.h"
#include "AllyUnit.h"

AllyUnit::AllyUnit(D3DXVECTOR2 pos, int index) : Units(pos, index)
{
	spr[0].LoadAll(L"Assets/Sprites/Units/Ally/Idle");
	spr[1].LoadAll(L"Assets/Sprites/Units/Ally/Attack");

	renderNum = 0;

	SetAbility(3, 1.0f, 1.0f, 1000);

	spr[1].aniMaxTime = info.atkSpeed / (spr[1].szScene + 1);

	Collider2D::Circle circle;
	circle.radius = info.atkRange;
	bodies.push_back(Collider2D(this, L"range", nullptr, &circle, D3DCOLOR_ARGB(255, 255, 255, 0)));
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

	if (attack)
	{
		renderNum = 1;

		if (spr[1].scene != 2)
			attack = false;
	}
	else
	{
		if(spr[1].scene >= spr[1].szScene)
			renderNum = 0;
	}

	std::cout << info.hp << std::endl;

	Destroy();
	
	spr[renderNum].Update(deltaTime);
}

void AllyUnit::Render()
{
	Units::Render();

	ri.pos += D3DXVECTOR2(-5, 70);
	shadow.Render(ri);

}

void AllyUnit::OnCollision2D(Collider2D& other)
{
	if (other.tag == L"enemy")
	{
		if (other.obj->pos.y == pos.y)
		{
			if (spr[1].scene == 2 && !attack)
			{
				static_cast<EnemyUnit*>(other.obj)->info.hp--;
				nowScene->obm.AddObject(new Effect(L"Gun", pos + D3DXVECTOR2(-90, -30), false));
			}

			attack = true;
		}
	}
}
