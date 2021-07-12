#include "DXUT.h"
#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(D3DXVECTOR2 pos, int index) : Units(pos, index)
{
	spr[0].LoadAll(L"Assets/Sprites/Units/Enemy/Move");
	spr[1].LoadAll(L"Assets/Sprites/Units/Enemy/Attack");
	spr[1].LoadAll(L"Assets/Sprites/Units/Enemy/Die");

	renderNum = 0;
	speed = 200;

	SetAbility(5, 1.0f, 1, 50);

	Collider2D::Circle circle;
	circle.radius = info.atkRange;

	bodies.push_back(Collider2D(this, L"enemy", nullptr, &circle));
}

void EnemyUnit::Update(float deltaTime)
{
	if (attack)
	{
		renderNum = 1;

		if (spr[1].scene != 4)
			attack = false;
	}
	else
	{
		if (spr[1].scene >= spr[1].szScene)
			renderNum = 0;

		pos.x += speed * deltaTime;
	}

	Destroy();

	spr[renderNum].Update(deltaTime);
}

void EnemyUnit::Render()
{
	Units::Render();

	ri.pos += D3DXVECTOR2(5, 70);
	shadow.Render(ri);
}

void EnemyUnit::OnCollision2D(Collider2D& other)
{
	if (other.tag == L"ally")
	{
		if (spr[1].scene == 4 && !attack)
			static_cast<AllyUnit*>(other.obj)->info.hp--;

		attack = true;
	}
}

void EnemyUnit::Destroy()
{
	if (info.hp <= 0)
	{
		renderNum = 2;
		spr[2].Reset();

		if(spr[2].scene >= spr[2].szScene)
			destroy = true;
	}
}
