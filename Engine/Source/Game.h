#pragma once

class Engine;
class Renderer;
class Scene;


class Game {
public:
	Game() {}
	Game(Engine* engine) : _engine{ engine } {}

	virtual bool Initialize() = 0;
	virtual void Shutdown() = 0;

	virtual void Update(float dt) = 0;
	virtual void Draw(Renderer& renderer) = 0;

	int GetScore() const { return _score; }
	void AddPoints(int points) { _score += points; }
	
	int GetLives() const { return _lives; }
	void SetLives(int lives) { _lives = lives; }

protected:
	int _score = 0;
	int _lives = 0;

	Engine* _engine{ nullptr };
	Scene* _scene{ nullptr };

};