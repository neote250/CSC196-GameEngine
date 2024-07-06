
#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "EngineTime.h"

#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <vector>



int main(int argc, char* argv[]) {

	//create systems
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;

	std::vector<Particle> particles;
	//for (int i = 0; i < 0; i++)
	//{
	//	particles.push_back(Particle{ { rand() % 800, rand() % 800 }, { randomf(100,300),0.0f}, randomf(1,5) });
	//}




	std::vector<Vector2> points;

	bool quit = false;
	//main loop
	while (!quit)
	{
		time.Tick();

		//INPUT
		input.Update();

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}


		//UPDATE
		Vector2 mousePosition = input.GetMousePosition();
		if (input.GetMouseButtonDown(0)) {
			particles.push_back(Particle{ mousePosition,{ randomf(-300,300), randomf(-200,200)}, randomf(1,5) });
		}

		for (Particle& particle : particles)
		{
			particle.Update(time.GetDeltaTime());

			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;
		}

		//if (input.GetMouseButtonDown(0) && !input.GetPreviousMouseButtonDown(0)) {
		//	std::cout << "Mouse Pressed\n";
		//	points.push_back(mousePosition);
		//}
		//if (input.GetMouseButtonDown(0)&& input.GetPreviousMouseButtonDown(0)){
		//	float distance = (points.back() - mousePosition).Length();
		//	if (distance>25) points.push_back(mousePosition);
		//}

		//DRAW
		// clear screen
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		//Draw line
		
		for (Particle particle : particles)
		{
			renderer.SetColor(particle.red, particle.blue, particle.green, 0);
			particle.Draw(renderer);
		}
		

		// show screen
		renderer.EndFrame();
	}

	return 0;
}