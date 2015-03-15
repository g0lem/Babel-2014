#include "sound_manager.hpp"

void SoundManager::Init()
{

	this->Sounds = new std::vector<Sound*>;


	char** sound_path = new char*[3];


	sound_path[0] = "./media/spooky.ogg";
	AddSound(sound_path[0], "Horn");

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
	sound->setBuffer(*t_sound->buffer);
	t_sound->sound = sound;
	t_sound->name = name;



	t_sound->sound->play();



	this->Sounds->push_back(t_sound);




}