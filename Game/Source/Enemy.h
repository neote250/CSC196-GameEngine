#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:
	Enemy() {}
	Enemy(const Transform& transform) :Actor{ transform } {}
	Enemy(const Transform& transform, Model* model) :
		Actor{ transform, model }
	{}
	Enemy(float speed, const Transform& transform, Model* model) :
		Actor{ transform, model }
		, _speed{ speed }
	{}

	void Update(float dt);
	virtual void OnCollision(Actor* actor);

private:
	float _speed = 0;
	float _fireTimer = 0;
};