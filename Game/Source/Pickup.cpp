#include "Pickup.h"
#include "Player.h"
#include "Enemy.h"

void Pickup::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player") {
		Player* player = dynamic_cast<Player*> (actor);
		if (player)
		{
			player->SetFireMod(0.5f);
			_destroyed = true;
		}
	}
	if (actor->GetTag() == "Enemy") {
		Enemy* enemy = dynamic_cast<Enemy*> (actor);
		if (enemy)
		{
			enemy->IncreasePoints();
			_destroyed = true;
		}
	}
}