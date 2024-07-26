#pragma once
#include "Vector2.h"
#include "Renderer.h"
#include "Random.h"

struct Particle
{
	struct Data {
		Vector2 position{ 0,0 };
		Vector2 velocity{ 0,0 };
		float lifespan = 0;
		uint8_t red{ 255 }, green{ 255 }, blue{ 255 }, alpha{ 0 };
	};

	Vector2 position{ 0,0 };
	Vector2 velocity{ 0,0 };
	float lifespan = 0;
	uint8_t red{ 255 }, green{ 255 }, blue{ 255 }, alpha{ 0 };
	bool isActive{ false };

	Particle() = default;
	Particle(Vector2 position, Vector2 velocity) : 
		position{position}
		, velocity{velocity}
	{
		red = random(255);
		green = random(255);
		blue = random(255);
	}
	Particle(Vector2 position, Vector2 velocity, float lifespan) :
		position{ position }
		, velocity{ velocity }
		, lifespan{ lifespan }
	{
		red = random(255);
		green = random(255);
		blue = random(255);
	}

	void Initialize(const Data& data);

	void Update(float dt);
	void Draw(Renderer& renderer);
};