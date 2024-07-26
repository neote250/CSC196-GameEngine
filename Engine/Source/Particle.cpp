
#include "Particle.h"

void Particle::Initialize(const Data& data)
{
	isActive = true;
	position = data.position;
	velocity = data.velocity;
	lifespan = data.lifespan;
	red = data.red;
	green = data.green;
	blue = data.blue;
	alpha = data.alpha;
}

void Particle::Update(float dt)
{
	if (lifespan != 0) lifespan -= dt;
	if (lifespan <= 0) isActive = false;
	position = position + (velocity * dt);
}

void Particle::Draw(Renderer& renderer)
{
	if (lifespan >= 0) {
		renderer.DrawPoint(position.x, position.y);
		renderer.DrawRect(position.x, position.y, 5.0f, 5.0f);
	}
}
