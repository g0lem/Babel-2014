#ifndef COMBAT_HPP
#define COMBAT_HPP




#define MIN_AQUIRE_DISTANCE 8.0f





class Combat
{




	void SetPlayerTarget(Player * player, EnemyManager * enemies);
	void PlayerAttack(GameObject * g_obj, Player * player, EnemyManager *enemies);
	void PlayerRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map);






	void SetEnemyTarget(Player * player, EnemyManager * enemies);
	void AquireEnemyTarget(Player * player, EnemyManager * enemies);
	void EnemyAttack(GameObject * g_obj, Player * player, EnemyManager *enemies);
	void EnemyMovement(GameObject * g_obj, EnemyManager * enemies);
	void EnemyRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map);




public:



	inline Combat(){ this->Init(); }



	void Init();



	void Action(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map);



};





#endif