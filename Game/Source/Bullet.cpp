#include "Bullet.h"
#include "ParticleSystem.h"
#include "Particle.h"
#include "Engine.h"

void Bullet::Update(float dt)
{
	//create particle trail
	Particle::Data data{
		_transform.position,
		Vector2{1,0}.Rotate(randomf(Math::TwoPi)) * 50,
		randomf(0.5f,1.0f),
		255,255,255
	};
	g_engine.GetParticleSystem().AddParticle(data);

	_velocity = Vector2{ 1,0 }.Rotate(_transform.rotation) * _speed;
	Actor::Update(dt);
}

void Bullet::OnCollision(Actor* actor)
{

}
