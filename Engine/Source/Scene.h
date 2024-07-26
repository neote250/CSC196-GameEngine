#pragma once

#include <list>
#include <memory>

class Renderer;
class Actor;
class Game;

class Scene
{
public:
	//Scene() {}
	Scene(Game* game) : _game{game}{}

	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddActor(std::unique_ptr<Actor> actor);
	void RemoveAll();

	template<typename T>
	T* GetActor();

	Game* GetGame() { return _game; }

protected:
	std::list<std::unique_ptr<Actor>> _actors;
	Game* _game{ nullptr };

};
//templates need to be in the header
template<typename T>
T* Scene::GetActor() {
	for (auto& actor : _actors) {
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}

	return nullptr;
}