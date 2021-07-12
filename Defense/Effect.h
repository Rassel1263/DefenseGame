#pragma once
class Effect : public Object
{
public:
	Sprite spr;
	RenderInfo ri;

	bool loop;

	Effect(std::wstring filePath, D3DXVECTOR2 pos, bool loop);

	virtual void Update(float deltaTime) override;
	virtual void Render();
};

