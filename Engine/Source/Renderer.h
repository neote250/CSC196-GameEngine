#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Renderer {
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();

	bool CreateWindow(std::string title, int width, int height);
	void BeginFrame();
	void EndFrame();

	void DrawRect(int x, int y, int w, int h);
	void DrawRect(float x, float y, float w, float h);
	

	void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a=0);//unsigned int 8 bit // ctrl click to get the info
	void DrawLine(int x1, int y1, int x2, int y2);
	void DrawLine(float x1, float y1, float x2, float y2);
	void DrawPoint(int x, int y);
	void DrawPoint(float x, float y);

	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }

	friend class Text;

protected:
	SDL_Window* _window{ nullptr };
	SDL_Renderer* _renderer{ nullptr };

	int _width{ 0 };
	int _height{ 0 };
};