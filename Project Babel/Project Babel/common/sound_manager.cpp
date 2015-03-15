#include "sound_manager.hpp"

void SoundManager::Init()
{

	this->Sounds = new std::vector<Sound*>;


	char** sound_path = new char*[3];

	sound_path[0] = "./media/charge.wav";
	AddSound(sound_path[0], "Charge");
	sound_path[1] = "./media/horn.wav";
	AddSound(sound_path[1], "Horn");

}

void SoundManager::Clean()
{


	delete this->Sounds;


}

void SoundManager::AddSound(char* SoundPath, char *name)
{
	Sound *t_sound = new Sound;

	sf::SoundBuffer *buffer = new sf::SoundBuffer;



	if (!buffer->loadFromFile(SoundPath))
		printf("ERROR: Couldn't initialize buffer!!! at %d \n\n", SoundPath);


	sf::Sound *sound = new sf::Sound;

	t_sound->buffer = buffer;
	t_sound->sound = sound;
	t_sound->name = name;

	t_sound->sound->play();

	this->Sounds->push_back(t_sound);




}