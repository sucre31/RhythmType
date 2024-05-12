#pragma once
class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject() = default;
	virtual bool update() = 0;
	virtual void draw() const = 0;
};

