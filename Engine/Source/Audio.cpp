#include "Audio.h"

bool Audio::Initialize()
{
	FMOD::System_Create(&_audio);
	void* extradriverdata = nullptr;
	_audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    return true;
}

void Audio::Shutdown()
{
	_audio->close();
}

void Audio::Update()
{
	_audio->update();
}

bool Audio::AddSound(const std::string& name)
{
	FMOD::Sound* sound = nullptr;
	_audio->createSound(name.c_str(), FMOD_DEFAULT, 0, &sound);

	if (sound == nullptr) {
		std::cerr << "could not load sound: " << name << std::endl;
		return false;
	}

	_sounds[name] = sound;

	return true;
}

bool Audio::PlaySound(const std::string& name)
{
	//check if sound exists
	if (_sounds.find(name) == _sounds.end()) {
		if (!AddSound(name)) return false;
	}

	_audio->playSound(_sounds[name], 0, false, nullptr);

	return true;
}
