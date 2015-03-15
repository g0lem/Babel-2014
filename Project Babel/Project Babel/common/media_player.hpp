#ifndef MEDIA_PLAYER_HPP
#define MEDIA_PLAYER_HPP

#include <GL/glew.h>
#include "controls.hpp"
#include "font_manager.hpp"
#include "sprite_manager.hpp"
#include "sound_manager.hpp"
#include "game_object.hpp"

class MediaPlayer : private Controller
{

	SoundManager* s_manager;

	FontManager* f_manager;

	SpriteManager *sprite_m;

	GameObject *g_object;


public:


	inline MediaPlayer(){ this->Init(); }

	inline ~MediaPlayer(){ this->Terminate(); }



	void Init();



	void Render();
	


	void Run();



	void Terminate();





};

#endif