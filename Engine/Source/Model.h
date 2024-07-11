#pragma once
#include "Transform.h"
#include "Vector2.h"
#include "Color.h"
#include "Renderer.h"
#include <vector>

// * - pointer -> can be null
// & - reference 

class Model {
public:
	Model() = default;
	Model(const std::vector<Vector2>& points, const Color& color) :
		_points {points},
		_color {color}
	{}

	void Draw(Renderer& renderer, const Vector2& position, float angle, float scale);
	void Draw(Renderer& renderer, const Transform& transform);

private:
	std::vector<Vector2> _points;
	Color _color;
};
