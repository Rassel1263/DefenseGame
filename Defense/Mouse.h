#pragma once
class Mouse : public Object
{
public:
	Sprite spr;
	RenderInfo ri;
	Mouse();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};
