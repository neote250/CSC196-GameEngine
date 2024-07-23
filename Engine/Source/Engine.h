#pragma once

#include "Renderer.h"
#include "Input.h"
#include "Audio.h"

#include "EngineTime.h"

#include "Vector2.h"
#include "Random.h"
#include "MathUtils.h"

#include "Particle.h"
#include "Model.h"
#include "Transform.h"

#include <fmod.hpp>
#include <SDL.h>

#define RENDERER g_engine.GetRenderer()
#define INPUT g_engine.GetInput()
#define AUDIO g_engine.GetAudio()

class Engine {
public:
	Engine(){}
	~Engine(){}

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer* GetRenderer() { return _renderer; }
	Input* GetInput() { return _input; }
	Audio* GetAudio() { return _audio; }
	Time& GetTime() { return *_time; }
	bool IsQuit() { return quit; }

private:
	bool quit{ false };

	Time* _time{ nullptr };
	Renderer* _renderer{ nullptr };
	Input* _input{ nullptr };
	Audio* _audio{ nullptr };

};

extern Engine g_engine;

