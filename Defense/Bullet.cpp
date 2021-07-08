#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet(D3DXVECTOR2 pos, float angle, float speed)
{
	this->pos = pos;
	this->angle = D3DXToRadian(angle);
	this->speed = speed;

	spr.LoadAll(L"a");

	ri.scale = { 0.3f, 0.3f };
	spr.color = D3DCOLOR_RGBA(0, 0, 125, 255);

	float minDistance = 999999;
	for (auto enemy : nowScene->enemysVec)
	{
		float nowDistance = pow(enemy->pos.x - pos.x, 2) + pow(enemy->pos.y + pos.y, 2);

		if (minDistance > nowDistance)
		{
			minDistance = nowDistance;
			target = enemy;
		}

	}
}

void Bullet::Update(float deltaTime)
{
	AliveTime += deltaTime;

	if (AliveTime >= 0.02f && repeat < 150) {
		AliveTime = 0.0f;
		repeat++;
		D3DXVECTOR2 distancePos = target->pos - pos;
		float destAngle = atan2(distancePos.y, distancePos.x);

		float minus = destAngle - angle;
		if (minus <= -D3DX_PI)
			minus += D3DX_PI * 2;
		else if (minus >= D3DX_PI)
			minus -= D3DX_PI * 2;

		if (abs(minus) < 0.25)
		{
			angle = destAngle;
		}
		else
		{
			float angleRateR = D3DXToRadian(angleRate);

			angle += min(max(minus, -angleRateR), angleRateR) * deltaTime * 15;
		}
	}


	pos += D3DXVECTOR2(cosf(angle), sinf(angle)) * deltaTime * speed;
}

void Bullet::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
