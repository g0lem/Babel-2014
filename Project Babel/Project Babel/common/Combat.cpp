#include "Combat.hpp"



void Combat::Init()
{





}



void Combat::SetPlayerTarget(Player * player, EnemyManager * enemies)
{




	player->SetTarget(NO_TARGET);


	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{




		if (glm::distance(player->GetPAttributes()->position, enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->position) < MIN_DISTANCE)
		{



			player->SetTarget(i);



			if (player->GetAttackingState())
			player->GetDirection()->Compute(DIR_TYPE_4, player->GetPAttributes()->position,
				enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->target);


			break;



		}


	}




}



void Combat::PlayerAttack(GameObject * g_obj, Player * player, EnemyManager *enemies)
{



	if (player->GetTarget() > NO_TARGET && player->GetAttackingState())
	{


		GLuint * hp = &enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetStats()->GetHp()->hp;


		glm::vec2 attack_range = player->GetItems()[ITEM_SLOT_WEAPON]->attack;


		*hp -= glm::min(*hp, Rand(attack_range.x, attack_range.y));


		player->SetAttackingState(false);



		g_obj->GetTurnSystem()->ComputeAttack(player->GetItems()[ITEM_SLOT_WEAPON]->attack_speed);




	}




}




void Combat::PlayerRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{


	this->SetPlayerTarget(player, enemies);


	this->PlayerAttack(g_obj, player, enemies);



}




void Combat::Action(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{


	
	this->PlayerRelated(g_obj, player, enemies, map);




	g_obj->GetTurnSystem()->Reset();


}






