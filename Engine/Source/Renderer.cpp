#include "Renderer.h"
#include <iostream>

bool Renderer::Initialize()
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Renderer::Shutdown()
{

}

bool Renderer::CreateWindow(std::string title, int width, int height)
{
	// create window
	// returns pointer to window if successful or nullptr if failed
	_window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN);
	if (_window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	// create renderer
	_renderer = SDL_CreateRenderer(_window, -1, 0);

	return true;
}

void Renderer::BeginFrame()
{
	SDL_RenderClear(_renderer);
}

void Renderer::EndFrame()
{
	SDL_RenderPresent(_renderer);
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void Renderer::DrawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
	SDL_RenderDrawLineF(_renderer, x1, y1, x2, y2);
}

void Renderer::DrawPoint(int x, int y)
{
	SDL_RenderDrawPoint(_renderer, x, y);
}

void Renderer::DrawPoint(float x, float y)
{
	SDL_RenderDrawPointF(_renderer, x, y);
}