#pragma once
#include "Game.h"

class Font;
class Text;

class SpaceGame : public Game {
public:
	enum class eState {
		Title,
		StartGame,
		StartLevel,
		Game,
		PlayerDead,
		GameOver
	};

public:
	SpaceGame(Engine* engine) : Game{engine}{}

	bool Initialize() override;
	void Shutdown() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	void OnPlayerDeath();

private:
	eState _state{ eState::Title };
	float _spawnTimer{ 0 };
	float _spawnTime{ 0 };
	float _stateTimer{ 0 };
	int _pickupCount{ 0 };
	int _inGameScore{ 0 };

	Font* _font{ nullptr };
	Font* _fontLarge{ nullptr };
	Text* _textScore{ nullptr };
	Text* _textLives{ nullptr };

	Text* _textTitle{ nullptr };
};