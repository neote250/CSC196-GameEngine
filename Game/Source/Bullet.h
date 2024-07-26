#pragma once
#include "Actor.h"


class Bullet : public Actor
{
public:
	Bullet() {}
	Bullet(const Transform& transform) :Actor{ transform } {}
	Bullet(const Transform& transform, Model* model) :
		Actor{ transform, model }
	{}
	Bullet(float speed, const Transform& transform, Model* model) :
		Actor{ transform, model }
		, _speed{ speed }
	{}

	void Update(float dt);
	void OnCollision(Actor* actor);

private:
	float _speed = 0;

};