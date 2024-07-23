#pragma once
#include <sdl_ttf.h>
#include <string>

class Font
{
public:
	Font() = default;
	~Font();

	bool Load(const std::string& name, int fontSize);
	friend class Text;

protected:
	_TTF_Font* _ttfFont{ nullptr };
};
