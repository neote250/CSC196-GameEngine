#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player() {}
	Player(const Transform& transform) :Actor{ transform } {}
	Player(const Transform& transform, Model* model) :
		Actor{ transform, model }
	{}
	Player(float speed, const Transform& transform, Model* model) :
		Actor{ transform, model }
		,_speed {speed}
	{}

	void Update(float dt);
	virtual void OnCollision(Actor* actor);

	void SetFireMod(float modifier) { _fireMod = modifier; }

private:
	float _speed = 0;
	float _fireTimer = 0;
	float _fireMod = 1;
};