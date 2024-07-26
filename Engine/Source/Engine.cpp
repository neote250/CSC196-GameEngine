#include "Engine.h"

Engine g_engine;

bool Engine::Initialize()
{
    _renderer = std::make_unique<Renderer>();
    _input = std::make_unique<Input>();
    _audio = std::make_unique<Audio>();
    _particleSystem = std::make_unique<ParticleSystem>();
    
    _renderer->Initialize();
    _renderer->CreateWindow("Game Engine", 800, 600);

    _input->Initialize();

    _audio->Initialize();

    _time = std::make_unique<Time>();

    return true;
}

void Engine::Shutdown()
{
    _renderer->Shutdown();
    _input->Shutdown();
    _audio->Shutdown();
}

void Engine::Update()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        quit = true;
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        quit = true;
    }

    _time->Tick();
    _input->Update();
    _particleSystem->Update(_time->GetDeltaTime());
    _audio->Update();
}
