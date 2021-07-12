#pragma once

struct UnitInfo
{
	float hp, atkSpeed, atkPower, atkRange;
};

class Units : public Object
{
public:
	std::map<int, Sprite> spr;
	Sprite shadow;

	RenderInfo ri;

	UnitInfo info;

	bool attack = false;

	int unitIndex = 1;
	int renderNum = 0;

	Units(D3DXVECTOR2 pos, int index);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision2D(Collider2D& other) override;
	virtual void Destroy();
	void SetAbility(float hp, float atkSpeed, float atkPower, float atkRange);
};

