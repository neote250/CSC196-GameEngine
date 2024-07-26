#include "Enemy.h"
#include "Player.h"
#include "Scene.h"
#include "Game.h"

void Enemy::Update(float dt)
{
	Player* player = _scene->GetActor<Player>();
	if (player) {
		//arrow pointing to player
		Vector2 direction = player->GetTranform().position - _transform.position;

		_velocity += direction.Normalized() * _speed * dt;
		_transform.rotation = direction.Angle();
	}

	Actor::Update(dt);
}

void Enemy::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player") {
		_scene->GetGame()->AddPoints(_pointsWorth);
		_destroyed = true;
	}
}