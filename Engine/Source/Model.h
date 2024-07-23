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
	Model() {
		_points.push_back(Vector2{ -1,2 });
		_points.push_back(Vector2{ 0,2 });
		_points.push_back(Vector2{ 2,1 });
		_points.push_back(Vector2{ 1,0 });
		_points.push_back(Vector2{ 2,0 });
		_points.push_back(Vector2{ 3,1 });
		_points.push_back(Vector2{ 4,0 });
		_points.push_back(Vector2{ 3,2 });
		_points.push_back(Vector2{ 1,3 });
		_points.push_back(Vector2{ -3,3 });
		_points.push_back(Vector2{ -4,2 });
		_points.push_back(Vector2{ -4,-2 });
		_points.push_back(Vector2{ -3,-3 });
		_points.push_back(Vector2{ 1,-3 });
		_points.push_back(Vector2{ 3,-2 });
		_points.push_back(Vector2{ 4,0 });
		_points.push_back(Vector2{ 3,-1 });
		_points.push_back(Vector2{ 2,0 });
		_points.push_back(Vector2{ 1,0 });
		_points.push_back(Vector2{ 2,-1 });
		_points.push_back(Vector2{ 0,-2 });
		_points.push_back(Vector2{ -1,-2 });

		//set the color for ship
		_color = { 1,0,1 };
	}
	Model(const std::vector<Vector2>& points, const Color& color) :
		_points {points},
		_color {color}
	{
	}

	void Draw(Renderer& renderer, const Vector2& position, float angle, float scale);
	void Draw(Renderer& renderer, const Transform& transform);
	std::vector<Vector2> GetShipPoints() { return _points; }

	float GetRadius();
private:
	std::vector<Vector2> _points;
	//std::vector<Vector2> _ship;
	Color _color;
};
