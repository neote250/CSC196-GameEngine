#pragma once
#include <fmod.hpp>
#include <map>
#include <string>
#include <iostream>

class Audio {
public:
	Audio() = default;
	~Audio() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	bool AddSound(const std::string& name);
	bool PlaySound(const std::string& name);

private:
	FMOD::System* _audio{ nullptr };
	std::map<std::string, FMOD::Sound*> _sounds;


};