#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "map.hpp"
#include "player.hpp"
#include "enemy_manager.hpp"
#include "dice.hpp"


class Combat
{



	void SetPlayerTarget(Player * player, EnemyManager * enemies);


	void PlayerAttack(GameObject * g_obj, Player * player, EnemyManager *enemies);


	void PlayerRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map);



public:



	inline Combat(){ this->Init(); }



	void Init();



	void Action(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map);



};





#endif