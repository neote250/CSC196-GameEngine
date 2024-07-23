#include "Scene.h"
#include "Actor.h"
#include "Model.h"
#include <algorithm>

void Scene::Update(float dt)
{
	//update
	for (Actor* actor : _actors) {actor->Update(dt);}

	//destroy
	_actors.erase(
		std::remove_if(_actors.begin(), _actors.end(), [](Actor* actor) {return actor->_destroyed; })
		, _actors.end()
	);
	//std::erase_if(_actors, [](Actor* actor) {return actor->_destroyed; });
	
	//auto iter = _actors.begin();
	//while (iter != _actors.end()) {
	//	iter = ((*iter)->_destroyed) ? _actors.erase(iter) : ++iter;
	//}


	//collision
	for (Actor* actor1 : _actors) { 
		for (Actor* actor2 : _actors) {
			if (actor1 == actor2 || (actor1->_destroyed||actor2->_destroyed)) continue;

			Vector2 direction = actor1->GetTranform().position - actor2->GetTranform().position;
			float distance = direction.Length();

			float radius = actor1->GetRadius() + actor2->GetRadius();

			if (distance <= radius) {
				actor1->OnCollision(actor2);
				actor2->OnCollision(actor1);
			}
		}
	}



}

void Scene::Draw(Renderer& renderer)
{
	for (Actor* actor : _actors) {
		actor->Draw(renderer);
	}
}

void Scene::AddActor(Actor* actor)
{
	actor->_scene = this;
	_actors.push_back(actor);
}

void Scene::RemoveAll()
{
	_actors.clear();
}
