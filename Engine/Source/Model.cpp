#include "Model.h"

void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
{
	if (_points.empty()) return;

	renderer.SetColor(Color::ToInt(_color.r), Color::ToInt(_color.g), Color::ToInt(_color.b), Color::ToInt(_color.a));
	for (int i = 0; i < _points.size()-1; i++) {
		Vector2 p1 = _points[i].Rotate(angle) * scale + position;
		Vector2 p2 = _points[i+1].Rotate(angle) * scale + position;

		renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

void Model::Draw(Renderer& renderer, const Transform& transform)
{
	if (_points.empty()) return;

	renderer.SetColor(Color::ToInt(_color.r), Color::ToInt(_color.g), Color::ToInt(_color.b), Color::ToInt(_color.a));
	for (int i = 0; i < _points.size() - 1; i++) {
		Vector2 p1 = _points[i].Rotate(transform.rotation) * transform.scale + transform.position;
		Vector2 p2 = _points[i + 1].Rotate(transform.rotation) * transform.scale + transform.position;

		renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

float Model::GetRadius()
{
	float radius = 0;

	for (const Vector2& point : _points) {
		float r = point.Length();
		if (r > radius) {
			radius = r;
		}
	}

	return radius;
}
