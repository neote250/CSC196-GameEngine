#include "SpaceGame.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "GameData.h"
#include "Enemy.h"
#include "Pickup.h"
#include "Font.h"
#include "Text.h"

bool SpaceGame::Initialize()
{
    _scene = new Scene(this);


    _font = new Font();
    _fontLarge = new Font();
    
    _font->Load("AlphabetFantasie.ttf", 30);
    _fontLarge->Load("AlphabetFantasie.ttf", 70);

    _textScore = new Text(_font);
    _textLives = new Text(_font);
    _textTitle = new Text(_fontLarge);

    return true;
}

void SpaceGame::Shutdown()
{
}

void SpaceGame::Update(float dt)
{
    switch (_state)
    {
    case eState::Title:
        if (INPUT->GetKeyDown(SDL_SCANCODE_SPACE)) {
            _state = eState::StartGame;
        }
        break;
    case eState::StartGame:
        _score = 0;
        SetLives(3);
        _state = eState::StartLevel;
        break;
    case eState::StartLevel:
        _scene->RemoveAll();
        {
            Model* model = new Model{};
            Transform transform{ {RENDERER->GetWidth() / 2, RENDERER->GetHeight() / 2}, 0, 5 };
            Player* player = new Player(400, transform, model);
            player->SetDamping(2.0f);
            player->SetTag("Player");
            _scene->AddActor(player);
        }

        _spawnTime = 3;
        _spawnTimer = _spawnTime;

        _state = eState::Game;
        break;
    case eState::Game:
        _spawnTimer -= dt;
        if (_spawnTimer <= 0) {
            _spawnTime -= 0.2f;
            _spawnTimer = _spawnTime;

            Model* enemyModel = new Model{ GameData::shipPoints, Color{1,0,0} };
            Enemy* enemy = new Enemy(200, Transform{ {random(RENDERER->GetWidth()), random(RENDERER->GetHeight())}, 0, 2 }, enemyModel);
            enemy->SetDamping(1.0f);
            enemy->SetTag("Enemy");
            _scene->AddActor(enemy);

            //create pickup
            auto* pickupModel = new Model{ GameData::shipPoints, Color{0,1,0} };
            auto* pickup = new Pickup(Transform{ {random(RENDERER->GetWidth()), random(RENDERER->GetHeight())}, 0, 2 }, pickupModel);
            pickup->SetTag("Pickup");
            _scene->AddActor(pickup);
        }

        
        break;
    case eState::PlayerDead:
        _stateTimer -= dt;
        if(_stateTimer<=0) _state = eState::StartLevel;

        break;
    case eState::GameOver:
        _stateTimer -= dt;
        if(_stateTimer<=0) _state = eState::Title;

        break;
    default:
        
        break;
    }

    _scene->Update(dt);
}

void SpaceGame::Draw(Renderer& renderer)
{
    switch (_state)
    {
    case SpaceGame::eState::Title:
        //draw text "game title"
        _textTitle->Create(renderer, "Title", { 0,0,1 });
        _textTitle->Draw(renderer, renderer.GetWidth() / 3, renderer.GetHeight() / 2);
        //text->Draw(*RENDERER, 40, 40);

        break;
    case SpaceGame::eState::Game:


        break;
    case SpaceGame::eState::GameOver:
        //draw text "game over"
        _textTitle->Create(renderer, "Game Over", { 0,0,1 });
        _textTitle->Draw(renderer, renderer.GetWidth() / 3, renderer.GetHeight() / 2);
        break;
    default:
        break;
    }

    //draw score
    std::string text = "Score: " + std::to_string(_score);
    _textScore->Create(renderer, text, { 0,0,1 });
    _textScore->Draw(renderer, 20, 20);
    //draw lives
    text = "Lives: " + std::to_string(GetLives());
    _textLives->Create(renderer, text, { 0,0,1 });
    _textLives->Draw(renderer, renderer.GetWidth() - 100, 20);

    _scene->Draw(renderer);

}

void SpaceGame::OnPlayerDeath()
{
    _lives--;
    _state = (_lives ==0) ? eState::GameOver : eState::PlayerDead;
    _stateTimer = 3;
}
