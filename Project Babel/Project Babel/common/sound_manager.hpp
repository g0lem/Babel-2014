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

		float volume;

		char *name;
	};



	struct Music{
		sf::Music *music;

		float volume;

		char *name;
	};




	std::vector<Sound*> *m_sounds;

	std::vector<Music*> *m_music;

public:

	inline SoundManager(){ this->Init(); }

	inline ~SoundManager(){ this->Clean(); }

	void Init();

	void Clean();

	void AddSound(char* p_sound, char* name);


	void AddMusic(char* p_music, char* name);


	inline std::vector<Sound*> *GetSounds(){ return this->m_sounds; }


	inline std::vector<Music*> *GetMusic(){ return this->m_music; }


};





#endif