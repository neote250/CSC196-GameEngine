#pragma once

#include <list>

class Renderer;
class Actor;//ask about forward declaration
class Game;

class Scene
{
public:
	//Scene() {}
	Scene(Game* game) : _game{game}{}

	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddActor(Actor* actor);
	void RemoveAll();

	template<typename T>
	T* GetActor();

	Game* GetGame() { return _game; }

protected:
	std::list<Actor*> _actors;
	Game* _game{ nullptr };

};
//templates need to be in the header
template<typename T>
T* Scene::GetActor() {
	for (Actor* actor : _actors) {
		T* result = dynamic_cast<T*>(actor);
		if (result) return result;
	}

	return nullptr;
}