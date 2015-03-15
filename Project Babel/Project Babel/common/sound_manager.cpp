#include "sound_manager.hpp"

void SoundManager::Init()
{

	this->m_sounds = new std::vector<Sound*>;

	this->m_music = new std::vector<Music*> ;

	char** sound_path = new char*[3];


	sound_path[0] = "./media/spooky.ogg";
<<<<<<< HEAD
	AddSound(sound_path[0], "Spooky");
	
=======
	AddSound(sound_path[0], "Horn");
>>>>>>> origin/master

}

void SoundManager::Clean()
{


	delete this->m_sounds;


}

void SoundManager::AddSound(char* p_sound, char *name)
{
	Sound *t_sound = new Sound;

	sf::SoundBuffer *buffer = new sf::SoundBuffer;



	if (!buffer->loadFromFile(p_sound))
		printf("ERROR: Couldn't load sound buffer from %d \n\n", p_sound);




	sf::Sound *sound = new sf::Sound;




	t_sound->buffer = buffer;


	sound->setBuffer(*t_sound->buffer);


	t_sound->sound = sound;


	t_sound->name = name;


	t_sound->volume = t_sound->sound->getVolume();


	t_sound->sound->play();

	this->m_sounds->push_back(t_sound);




}


void SoundManager::AddMusic(char* p_music, char* name)
{
	
	Music *t_music = new Music;



	sf::Music * music = new sf::Music;


	if (music->openFromFile(p_music))
		printf("ERROR: Couldn't load music from %d \n\n", p_music);


	t_music->music = music;


	t_music->name = name;


	t_music->volume = t_music->music->getVolume();


	this->m_music->push_back(t_music);

}