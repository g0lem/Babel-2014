#include "sound_manager.hpp"

void SoundManager::Init()
{

	m_playing.playing = false;
	s_playing.playing = false;


	this->m_sounds = new std::vector<Sound*>;

	this->m_music = new std::vector<Music*> ;

	char** sound_path = new char*[3];


	sound_path[0] = "./media/spooky.ogg";
	AddSound(sound_path[0], "Spooky");
	sound_path[1] = "./media/crow.wav";
	AddSound(sound_path[1], "Crow");

}

void SoundManager::Clean()
{


	delete this->m_sounds;

	delete this->m_music;


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



	this->m_music->push_back(t_music);

}


inline int SoundManager::GetSoundIndex(char *p_sound)
{
	for (int i = 0; i < this->m_sounds->size(); i++)
		if (strcmp(p_sound, this->m_sounds->at(i)->name) == 0)
			return i;
}


inline int SoundManager::GetMusicIndex(char *p_music)
{
	for (int i = 0; i < this->m_music->size(); i++)
		if (strcmp(p_music, this->m_music->at(i)->name) == 0)
			return i;

}



void SoundManager::PlaySound(char* p_sound)
{
	if (!s_playing.playing)
	{

		currentIndex = GetSoundIndex(p_sound);

		this->m_sounds->at(currentIndex)->sound->play();

		s_playing.playing = true;
	}
	else
	{
		printf("%c, is currently playing\n", p_sound);
	}


}



void SoundManager::PlayMusic(char *p_music)
{
	if (!m_playing.playing)
	{

		currentIndex = GetSoundIndex(p_music);

		this->m_music->at(currentIndex)->music->play();

		m_playing.playing = true;
	}
	else
	{
		printf("%c, is currently playing\n", p_music);
	}

}

void SoundManager::StopSound(char *name)
{


	this->m_sounds->at(GetSoundIndex(name))->sound->stop();


}


void SoundManager::StopMusic(char* name)
{

	this->m_music->at(GetMusicIndex(name))->music->stop();

}


void SoundManager::PauseSound(char *name)
{


	this->m_sounds->at(GetSoundIndex(name))->sound->pause();


}

void SoundManager::PauseMusic(char *name)
{


	this->m_music->at(GetMusicIndex(name))->music->pause();

}

bool SoundManager::getSoundLoop(char *name)
{

	return this->m_sounds->at(GetSoundIndex(name))->sound->getLoop();

}


bool SoundManager::getMusicLoop(char *name)
{


	return this->m_music->at(GetMusicIndex(name))->music->getLoop();

}


void SoundManager::setSoundLoop(char *name, bool value)
{

	this->m_sounds->at(GetSoundIndex(name))->sound->setLoop(value);

}

void SoundManager::setMusicLoop(char *name, bool value)
{

	this->m_music->at(GetMusicIndex(name))->music->setLoop(value);

}

int SoundManager::getSoundStatus(char* name)
{

	return this->m_sounds->at(GetSoundIndex(name))->sound->getStatus();

}

int SoundManager::getMusicStatus(char* name)
{



	return this->m_music->at(GetMusicIndex(name))->music->getStatus();


}


float SoundManager::getSoundDuration(char* name)
{


	return this->m_sounds->at(GetSoundIndex(name))->buffer->getDuration().asSeconds();


}


float SoundManager::getMusicDuration(char *name)
{


	return this->m_music->at(GetMusicIndex(name))->music->getDuration().asSeconds();


}

void SoundManager::setSoundPitch(char *name, float value)
{


	this->m_sounds->at(GetSoundIndex(name))->sound->setPitch(value);


}

void SoundManager::setMusicPitch(char *name, float value)
{


	this->m_music->at(GetMusicIndex(name))->music->setPitch(value);


}

void SoundManager::setSoundVolume(char *name, float value)
{


	this->m_sounds->at(GetSoundIndex(name))->sound->setVolume(value);


}

void SoundManager::setMusicVolume(char *name, float value)
{



	this->m_music->at(GetMusicIndex(name))->music->setVolume(value);



}


float SoundManager::getSoundVolume(char *name)
{


	return this->m_sounds->at(GetSoundIndex(name))->sound->getVolume();


}

float SoundManager::getMusicVolume(char *name)
{


	return this->m_music->at(GetMusicIndex(name))->music->getVolume();


}


void SoundManager::SetSoundOffset(char* name, float value)
{

	sf::Time time;

	time = sf::seconds(value);


	this->m_sounds->at(GetSoundIndex(name))->sound->setPlayingOffset(time);


}


void SoundManager::SetMusicOffset(char *name, float value)
{

	sf::Time time;

	time = sf::seconds(value);


	this->m_music->at(GetMusicIndex(name))->music->setPlayingOffset(time);


}


float SoundManager::getSoundOffset(char *name)
{


	return this->m_sounds->at(GetSoundIndex(name))->sound->getPlayingOffset().asSeconds();



}

float SoundManager::getMusicOffset(char *name)
{


	return this->m_music->at(GetMusicIndex(name))->music->getPlayingOffset().asSeconds();



}