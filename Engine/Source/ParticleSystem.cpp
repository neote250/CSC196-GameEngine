#include "ParticleSystem.h"

void ParticleSystem::Update(float dt)
{
	for (auto& particle : _particles) {
		if (particle.isActive) particle.Update(dt);
	}
}

void ParticleSystem::Draw(Renderer& renderer)
{
	for (auto& particle : _particles) {
		if (particle.isActive) particle.Draw(renderer);
	}
}

void ParticleSystem::AddParticle(const Particle::Data& data)
{
	Particle* particle = GetFreeParticle();
	if (particle) {
		particle->Initialize(data);
	}
}

Particle* ParticleSystem::GetFreeParticle()
{
	//find first inactive particle
	for (auto& particle : _particles) {
		if (!particle.isActive) return &particle;
	}

	return nullptr;
}
