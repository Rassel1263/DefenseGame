#include "DXUT.h"
#include "Units.h"

Units::Units(D3DXVECTOR2 pos, int index)
{
	this->pos = pos;
	this->unitIndex = index;

	shadow.LoadAll(L"Assets/Sprites/Units/a.png");
}

void Units::Update(float deltaTime)
{
	Object::Update(deltaTime);
}

void Units::Render()
{
	ri.pos = pos;
	spr[renderNum].Render(ri);

	Object::Render();
}

void Units::OnCollision2D(Collider2D& other)
{
}

void Units::Destroy()
{
	if (info.hp <= 0)
		destroy = true;
}

void Units::SetAbility(float hp, float atkSpeed, float atkPower, float atkRange)
{
	info.hp = hp;
	info.atkSpeed = atkSpeed;
	info.atkPower = atkPower;
	info.atkRange = atkRange;
}
