#include "Pickup.h"
#include "Player.h"

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
}
