#pragma once
class Units : public Object
{
public:
	Sprite spr;
	RenderInfo ri;

	Units(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

