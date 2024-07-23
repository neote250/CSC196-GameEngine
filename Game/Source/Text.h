#pragma once

#include "Font.h"
#include "Renderer.h"
#include "Color.h"

class Text
{
public:
	Text() = default;
	Text(Font* font) : _font{ font } {}
	~Text();

	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, int x, int y);

private:
	Font* _font{ nullptr };
	SDL_Texture* _texture{ nullptr };
};