#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "GameData.h"
#include "SpaceGame.h"

#include "Font.h"
#include "Text.h"

#include <iostream>
#include <cstdlib>
#include <vector>

int main(int argc, char* argv[]) {
	g_engine.Initialize();

	SpaceGame* game = new SpaceGame(&g_engine);
	game->Initialize();

	while (!g_engine.IsQuit())
	{
		g_engine.Update();
		game->Update(TIME.GetDeltaTime());

		RENDERER.SetColor(0, 0, 0);
		RENDERER.BeginFrame();

		game->Draw(RENDERER);
		//text->Draw(*RENDERER, 40, 40);
		g_engine.GetParticleSystem().Draw(RENDERER);

		RENDERER.EndFrame();

	}

	g_engine.Shutdown();

	return 0;
}
/*
	std::vector<Particle> particles;

	//create sound here
	g_engine.GetAudio()->AddSound("bass.wav");
	g_engine.GetAudio()->AddSound("snare.wav");
	g_engine.GetAudio()->AddSound("clap.wav");
	g_engine.GetAudio()->AddSound("open-hat.wav");
	g_engine.GetAudio()->AddSound("close-hat.wav");


	//actor
	Model* model = new Model{};
	Transform transform{ {RENDERER->GetWidth() / 2, RENDERER->GetHeight() / 2}, 0, 5}; // >>1 is the same as /2 in binary

	Player* player = new Player(200, transform, model);
	player->SetDamping(2.0f);
	player->SetTag("Player");

	Scene* scene = new Scene();
	scene->AddActor(player);

	//enemy

	Color enemyC{};
	Model* enemyModel = new Model{ GameData::shipPoints, Color{1,0,0} };//TODO insert enemy info
	//TODO change enemy color
	Enemy* enemy = new Enemy(400, Transform{ {RENDERER->GetWidth()/3,RENDERER->GetHeight()/4},0,2}, enemyModel);
	enemy->SetDamping(1.0f);
	enemy->SetTag("Enemy");
	scene->AddActor(enemy);

	


	//info for program
	float offset = 0;
	bool quit = false;

	float spawnTimer = 2;


	//main loop
	while (!g_engine.IsQuit())
	{
		g_engine.Update();

		//INPUT
		INPUT->Update();
		
		spawnTimer -= g_engine.GetTime().GetDeltaTime();
		if (spawnTimer <= 0) {
			spawnTimer = 2;
			scene->AddActor(enemy);
		}


		if (INPUT->GetKeyDown(SDL_SCANCODE_Q) && !INPUT->GetPreviousKeyDown(SDL_SCANCODE_Q)) AUDIO->PlaySound("bass.wav");
		if (INPUT->GetKeyDown(SDL_SCANCODE_W) && !INPUT->GetPreviousKeyDown(SDL_SCANCODE_W)) AUDIO->PlaySound("snare.wav");
		if (INPUT->GetKeyDown(SDL_SCANCODE_E) && !INPUT->GetPreviousKeyDown(SDL_SCANCODE_E)) AUDIO->PlaySound("clap.wav");
		if (INPUT->GetKeyDown(SDL_SCANCODE_A) && !INPUT->GetPreviousKeyDown(SDL_SCANCODE_A)) AUDIO->PlaySound("open-hat.wav");
		if (INPUT->GetKeyDown(SDL_SCANCODE_S) && !INPUT->GetPreviousKeyDown(SDL_SCANCODE_S)) AUDIO->PlaySound("close-hat.wav");

		//UPDATE
		scene->Update(g_engine.GetTime().GetDeltaTime());

		Vector2 mousePosition = INPUT->GetMousePosition();
		if (INPUT->GetMouseButtonDown(0)) {
			//Vector2 velocity = {0,0};
			particles.push_back(Particle{ mousePosition, randomOnUnitCircle() * randomf(10, 200), randomf(1, 3)});
		}

		for (Particle& particle : particles)
		{
			particle.Update(g_engine.GetTime().GetDeltaTime());

			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;
		}

		//audio->update();


		//DRAW
		// clear screen
		RENDERER->SetColor(0, 0, 0);
		RENDERER->BeginFrame();

		RENDERER->SetColor(255, 255, 255);
		float radius = 60;
		offset += (90 * g_engine.GetTime().GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360 / 30) {
			float x = Math::Cos(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.1f) * radius;
			float y = Math::Sin(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.1f) * radius;
		}



		//Draw Particles
		
		for (Particle particle : particles)
		{
			RENDERER->SetColor(particle.red, particle.blue, particle.green);
			particle.Draw(*RENDERER);
		}
		
		scene->Draw(*RENDERER);


		// show screen
		RENDERER->EndFrame();
	}

	return 0;
}
*/