#ifndef COMBAT_HPP
#define COMBAT_HPP




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