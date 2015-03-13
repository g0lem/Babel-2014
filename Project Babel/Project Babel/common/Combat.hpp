#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "map.hpp"
#include "player.hpp"
#include "enemy_manager.hpp"
#include "dice.hpp"


class Combat
{



public:



	inline Combat(){ this->Init(); }



	void Init();



	void SetPlayerTarget(Player * player, EnemyManager * enemies);




};





#endif