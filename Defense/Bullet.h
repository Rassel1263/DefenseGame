#pragma once
class Bullet : public Object
{
public:
	float angle = 0;
	float angleRate = 15;
	float speed = 0;
	int repeat = 0;
	float AliveTime = 0.0f;
	Sprite spr;
	RenderInfo ri;
	Object* target = NULL;

	Bullet(D3DXVECTOR2 pos, float angle, float speed);
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

