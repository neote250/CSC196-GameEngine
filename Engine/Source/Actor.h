#pragma once
#include "Transform.h"
#include "Model.h"
#include <string>

class Renderer;
class Scene;

class Actor {
public:
	Actor() {}
	Actor(const Transform& transform):_transform{ transform }{}
	Actor(const Transform& transform, Model* model) :
		_transform{ transform }
		, _model{ model }
	{}

	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer); //not like abstract method, doesn't need to be overwritten

	void SetDamping(float damping) { _damping = damping; }
	void SetLifespan(float lifespan) { _lifespan = lifespan; }
	const Transform& GetTranform() { return _transform; }
	void SetTag(const std::string tag) { _tag = tag; }
	const std::string& GetTag() { return _tag; }
	float GetRadius() { return (_model) ? _model->GetRadius() * _transform.scale : 0; }

	virtual void OnCollision(Actor* actor) = 0; //abstract function

	friend class Scene;

protected:
	std::string _tag;
	bool _destroyed = false;
	float _lifespan = 0;


	Transform _transform;
	Vector2 _velocity{0,0};
	float _damping{0};

	Model* _model { nullptr };
	Scene* _scene{ nullptr };
};