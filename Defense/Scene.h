#pragma once

class Scene
{
public:
	Mouse* mouse = NULL;
	ObjectManager obm;
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
};

