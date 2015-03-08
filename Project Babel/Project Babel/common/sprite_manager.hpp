//Checked 1



#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP


#include "2d.hpp"
#include "controls.hpp"
#include "player.hpp"
#include "map.hpp"
#include "game_object.hpp"


class SpriteManager : private Aaether2D
{


	Player * player;

	Map * map;



public:


	inline SpriteManager(){ this->Init(); }


	inline ~SpriteManager(){ this->Clean(); }



	void Init();


	void Clean();


	void Render(Controller * ctrl, GameObject * g_obj);


};



#endif