#pragma once

#include "Renderer.h"
#include "Input.h"
#include "Audio.h"

#include "EngineTime.h"

#include "Vector2.h"
#include "Random.h"
#include "MathUtils.h"

#include "Particle.h"
#include "ParticleSystem.h"
#include "Model.h"
#include "Transform.h"

#include <fmod.hpp>
#include <SDL.h>
#include <memory>

#define RENDERER g_engine.GetRenderer()
#define INPUT g_engine.GetInput()
#define AUDIO g_engine.GetAudio()
#define TIME g_engine.GetTime()

class Engine {
public:
	Engine() = default;
	~Engine(){}

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer& GetRenderer() { return *_renderer; }
	Input& GetInput() { return *_input; }
	Audio& GetAudio() { return *_audio; }
	ParticleSystem& GetParticleSystem() { return *_particleSystem; }
	Time& GetTime() { return *_time; }
	bool IsQuit() { return quit; }

private:
	bool quit{ false };

	std::unique_ptr	<Time> _time;
	std::unique_ptr	<Renderer> _renderer;
	std::unique_ptr	<Input> _input;
	std::unique_ptr	<Audio> _audio;
	std::unique_ptr	<ParticleSystem> _particleSystem;

};

extern Engine g_engine;

