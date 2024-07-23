#include "Player.h"
#include "Engine.h"
#include "Bullet.h"
#include "Scene.h"
#include "GameData.h"
#include "SpaceGame.h"

#include <iostream>



void Player::Update(float dt)
{
	//movement
	float thrust = 0;
	Vector2 direction{ 0,0 };
	if (INPUT->GetKeyDown(SDL_SCANCODE_W)) direction.x = 1;
	if (INPUT->GetKeyDown(SDL_SCANCODE_S)) direction.x = -1;	
	if (INPUT->GetKeyDown(SDL_SCANCODE_Q)) direction.y = -1;
	if (INPUT->GetKeyDown(SDL_SCANCODE_E)) direction.y = 1;


	if (INPUT->GetKeyDown(SDL_SCANCODE_A)) _transform.rotation -= Math::DegToRad(100) * dt;
	if (INPUT->GetKeyDown(SDL_SCANCODE_D)) _transform.rotation += Math::DegToRad(100) * dt;
	
	Vector2 acceleration = direction.Rotate(_transform.rotation) * _speed;
	_velocity += acceleration * dt;
	
	_transform.position.x = Math::Wrap(_transform.position.x, (float)RENDERER->GetWidth());
	_transform.position.y = Math::Wrap(_transform.position.y, (float)RENDERER->GetHeight());

	//fire
	_fireTimer -= dt;
	if (INPUT->GetMouseButtonDown(0) && _fireTimer <=0) {
		//INPUT->GetKeyDown(SDL_SCANCODE_SPACE) !INPUT->GetPreviousKeyDown(SDL_SCANCODE_SPACE)
		_fireTimer = 0.2f*_fireMod;


		//shoots at mouse position
		Vector2 direction = INPUT->GetMousePosition() - _transform.position;
		float angle = direction.Angle();


		// actor
		Model* model = new Model{ GameData::shipPoints, Color{ 1, 0, 0 } };
		Transform transform{ _transform.position, angle, 1.0f };

		Bullet* bullet = new Bullet(400.0f, transform, model);
		bullet->SetLifespan(1);
		bullet->SetTag("Player");
		_scene->AddActor(bullet);
	}


	Actor::Update(dt);
}

void Player::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy") {
		_destroyed = true;
		SpaceGame* game = dynamic_cast<SpaceGame*> (_scene->GetGame());
		if (game) game->OnPlayerDeath();
		//dynamic_cast<SpaceGame*> (_scene->GetGame())->OnPlayerDeath();
	}
}
