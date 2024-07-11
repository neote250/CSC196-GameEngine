#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "EngineTime.h"
#include "MathUtils.h"
#include "Model.h"
#include "Transform.h"

#include <fmod.hpp>
#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <vector>

int main(int argc, char* argv[]) {

	// create audio system
	FMOD::System* audio;
	FMOD::System_Create(&audio);
	void* extradriverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

	//create systems
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;

	std::vector<Particle> particles;

	//create sound here
	FMOD::Sound* sound = nullptr;

	std::vector<FMOD::Sound*> sounds;

	audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("clap.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);
	
	audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);


	//Triangle points for the player ship
	std::vector<Vector2> points;
	points.push_back(Vector2{ 5,0 });
	points.push_back(Vector2{ -5,-5 });
	points.push_back(Vector2{ -5,5 });
	points.push_back(Vector2{ 5,0 });

	//set up model using points and other data
	Model model{ points, Color{1,1,1,0} };
	Transform transform{ {renderer.GetWidth() / 2,renderer.GetHeight() / 2}, 0, 5 }; // >>1 is the same as /2 in binary

	//info for program
	float offset = 0;
	bool quit = false;

	//main loop
	while (!quit)
	{
		time.Tick();

		//INPUT
		input.Update();
		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {quit = true;}

		float thrust = 0;
		if (input.GetKeyDown(SDL_SCANCODE_UP)) thrust = 400;
		if (input.GetKeyDown(SDL_SCANCODE_DOWN)) thrust  = -400;
		if (input.GetKeyDown(SDL_SCANCODE_LEFT)) transform.rotation -= Math::DegToRad(100) * time.GetDeltaTime();
		if (input.GetKeyDown(SDL_SCANCODE_RIGHT)) transform.rotation += Math::DegToRad(100) * time.GetDeltaTime();

		Vector2 velocity = Vector2{ thrust, 0.0f }.Rotate(transform.rotation);
		transform.position += velocity * time.GetDeltaTime();
		transform.position.x = Math::Wrap(transform.position.x, (float)renderer.GetWidth());
		transform.position.y = Math::Wrap(transform.position.y, (float)renderer.GetHeight());

		if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPreviousKeyDown(SDL_SCANCODE_Q)) { audio->playSound(sounds[0], 0, false, nullptr); }
		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPreviousKeyDown(SDL_SCANCODE_W)) { audio->playSound(sounds[1], 0, false, nullptr); }
		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPreviousKeyDown(SDL_SCANCODE_E)) { audio->playSound(sounds[2], 0, false, nullptr); }
		if (input.GetKeyDown(SDL_SCANCODE_A) && !input.GetPreviousKeyDown(SDL_SCANCODE_A)) { audio->playSound(sounds[3], 0, false, nullptr); }
		if (input.GetKeyDown(SDL_SCANCODE_S) && !input.GetPreviousKeyDown(SDL_SCANCODE_S)) { audio->playSound(sounds[4], 0, false, nullptr); }

		//UPDATE
		Vector2 mousePosition = input.GetMousePosition();
		if (input.GetMouseButtonDown(0)) {
			//Vector2 velocity = {0,0};
			particles.push_back(Particle{ mousePosition, randomOnUnitCircle() * randomf(10, 200), randomf(1, 3)});
		}

		for (Particle& particle : particles)
		{
			particle.Update(time.GetDeltaTime());

			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;
		}

		//audio->update();


		//DRAW
		// clear screen
		renderer.SetColor(0, 0, 0);
		renderer.BeginFrame();

		renderer.SetColor(255, 255, 255);
		float radius = 60;
		offset += (90 * time.GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360 / 30) {
			

			float x = Math::Cos(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.1f) * radius;
			float y = Math::Sin(Math::DegToRad(angle + offset)) * Math::Sin((offset + angle) * 0.1f) * radius;

			//renderer.DrawRect(400 + x, 300 + y, 4.0f, 4.0f);
		}



		//Draw Particles
		
		for (Particle particle : particles)
		{
			renderer.SetColor(particle.red, particle.blue, particle.green);
			particle.Draw(renderer);
		}
		
		model.Draw(renderer, transform);


		// show screen
		renderer.EndFrame();
	}

	return 0;
}