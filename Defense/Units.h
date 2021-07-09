#pragma once

struct UnitInfo
{
	float hp, atkSpeed, atkPower, atkRange;
};

class Units : public Object
{
public:
	Sprite spr;
	RenderInfo ri;
	UnitInfo info;

	int unitIndex = 1;

	Units(D3DXVECTOR2 pos, int index);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

