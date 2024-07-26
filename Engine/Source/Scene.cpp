#include "Scene.h"
#include "Actor.h"
#include "Model.h"
#include <algorithm>

void Scene::Update(float dt)
{
	//update
	for (auto& actor : _actors) {actor->Update(dt);}

	//destroy
	_actors.erase(
		std::remove_if(_actors.begin(), _actors.end(), [](auto& actor) {return actor->_destroyed; })
		, _actors.end()
	);
	//std::erase_if(_actors, [](Actor* actor) {return actor->_destroyed; });
	
	//auto iter = _actors.begin();
	//while (iter != _actors.end()) {
	//	iter = ((*iter)->_destroyed) ? _actors.erase(iter) : ++iter;
	//}


	//collision
	for (auto& actor1 : _actors) { 
		for (auto& actor2 : _actors) {
			if (actor1 == actor2 || (actor1->_destroyed||actor2->_destroyed)) continue;

			Vector2 direction = actor1->GetTranform().position - actor2->GetTranform().position;
			float distance = direction.Length();

			float radius = actor1->GetRadius() + actor2->GetRadius();

			if (distance <= radius) {
				actor1->OnCollision(actor2.get());
				actor2->OnCollision(actor1.get());
			}
		}
	}



}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : _actors) {
		actor->Draw(renderer);
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor)
{
	actor->_scene = this;
	_actors.push_back(std::move(actor));
}

void Scene::RemoveAll()
{
	_actors.clear();
}
