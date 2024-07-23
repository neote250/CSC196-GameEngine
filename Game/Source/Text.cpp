#include "Text.h"

#include <iostream>
#include <assert.h>


Text::~Text()
{
	if (_texture != nullptr)
	{
		SDL_DestroyTexture(_texture);
	}
}

bool Text::Create(Renderer& renderer, const std::string& text, const Color& color)
{
	// create a surface using the font, text string and color
	SDL_Color c{ Color::ToInt(color.r), Color::ToInt(color.g), Color::ToInt(color.b), Color::ToInt(color.a) };
	SDL_Surface* surface = TTF_RenderText_Solid(_font->_ttfFont, text.c_str(), c);
	if (surface == nullptr)
	{
		std::cerr << "Could not create surface.\n";
		return false;
	}

	// create a texture from the surface, only textures can render to the renderer
	_texture = SDL_CreateTextureFromSurface(renderer._renderer, surface);
	if (surface == nullptr)
	{
		SDL_FreeSurface(surface);
		std::cerr << "Could not create texture" << SDL_GetError() << std::endl;
		return false;
	}


	// free the surface, no longer needed after creating the texture
	SDL_FreeSurface(surface);

	return true;
}

void Text::Draw(Renderer& renderer, int x, int y)
{
	assert(_texture);

	// query the texture for the texture width and height
	int width, height;
	SDL_QueryTexture(_texture, nullptr, nullptr, &width, &height);

	// copy the texture onto the renderer
	SDL_Rect rect{ x, y, width, height };
	SDL_RenderCopy(renderer._renderer, _texture, NULL, &rect);
}

