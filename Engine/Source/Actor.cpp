#include "Actor.h"
#include "Model.h"

void Actor::Update(float dt)
{
	//check for lifespan
	if (_lifespan != 0) {
		_lifespan -= dt;
		if (_lifespan <= 0) {
			_destroyed = true;
		}
	}

	_transform.position += (_velocity * dt);
	_velocity *= 1.0f / (1.0f + _damping * dt);
}

void Actor::Draw(Renderer& renderer)
{
	if (_destroyed) return;

	if (_model) {
		_model->Draw(renderer, _transform);
	}
}
