#include "Bullet.h"

void Bullet::Update(float dt)
{
	_velocity = Vector2{ 1,0 }.Rotate(_transform.rotation) * _speed;
	Actor::Update(dt);
}

void Bullet::OnCollision(Actor* actor)
{
}
