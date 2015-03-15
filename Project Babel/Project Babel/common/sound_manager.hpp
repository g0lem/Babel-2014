#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP


#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class SoundManager
{

	struct Sound{
		sf::SoundBuffer *buffer;
		sf::Sound *sound;

		char *name;
	};

	std::vector<Sound*> *Sounds;


public:

	inline SoundManager(){ this->Init(); }

	inline ~SoundManager(){ this->Clean(); }

	void Init();

	void Clean();

	void AddSound(char* Sound, char* name);

	inline std::vector<Sound*> *GetSounds(){ return this->Sounds; }
};





#endif