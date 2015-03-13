//Checked 1



#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP


#include "2d.hpp"
#include "controls.hpp"
#include "player.hpp"
#include "map.hpp"
#include "game_object.hpp"
#include "enemy_manager.hpp"
#include "Combat.hpp"



class SpriteManager : private Aaether2D
{


	Player * player;

	Map * map;


	EnemyManager * m_enemies;


	Combat * m_combat;



public:


	inline SpriteManager(GameObject * g_obj){ this->Init(g_obj); }


	inline ~SpriteManager(){ this->Clean(); }



	void Init(GameObject * g_obj);


	void Clean();


	void Render(Controller * ctrl, GameObject * g_obj);


};



#endif