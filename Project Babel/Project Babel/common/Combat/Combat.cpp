#include <common.hpp>



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




		enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetStats()->GetHp()->Damage(player->GetItems()[ITEM_SLOT_WEAPON]->attack);
  
       
		player->SetAttackingState(false);


		g_obj->GetTurnSystem()->ComputeAttack(player->GetItems()[ITEM_SLOT_WEAPON]->attack_speed);




	}




}




void Combat::PlayerRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{


	this->SetPlayerTarget(player, enemies);


	this->PlayerAttack(g_obj, player, enemies);



}




void Combat::UpdateTurns(GameObject * g_obj, EnemyManager * enemies)
{


	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
		if (enemies->GetEnemiesPointer()[0][i]->GetTargetPosition() != vec2_0)
			g_obj->GetTurnSystem()->Update(enemies->GetEnemiesPointer()[0][i]->GetTurnSystem());

}




void Combat::SetEnemyTarget(Player * player, EnemyManager * enemies)
{




	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		enemies->GetEnemiesPointer()[0][i]->SetTarget(NO_TARGET);


		if (glm::distance(player->GetPAttributes()->position, enemies->GetEnemiesPointer()[0][i]->GetPAttributes()->position) < MIN_DISTANCE)
			enemies->GetEnemiesPointer()[0][i]->SetTarget(0);



	}


}




void Combat::AquireEnemyTarget(Player * player, EnemyManager * enemies)
{



	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		Enemy * current_enemy = enemies->GetEnemiesPointer()[0][i];


		if (glm::distance(player->GetPAttributes()->position, current_enemy->GetPAttributes()->position))
			current_enemy->SetTargetPosition(player->GetPAttributes()->position);
		else
			current_enemy->SetTargetPosition(vec2_0);



	}




}




void Combat::EnemyAttack(GameObject * g_obj, Player * player, EnemyManager *enemies)
{


	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{


		Enemy * current_enemy = enemies->GetEnemiesPointer()[0][i];


		if (current_enemy->GetTarget() > NO_TARGET)
		{


			while (current_enemy->GetTurnSystem()->GetTurns() >= current_enemy->GetStats()->base_attack_speed)
			{


				player->GetStats()->GetHp()->Damage(current_enemy->GetStats()->base_attack);

				current_enemy->GetTurnSystem()->Add(-current_enemy->GetStats()->base_attack_speed);

			}


		}




	}


}






void Combat::EnemyRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{



	this->UpdateTurns(g_obj, enemies);
	this->SetEnemyTarget(player, enemies);
	this->AquireEnemyTarget(player, enemies);
	this->EnemyAttack(g_obj, player, enemies);



}




void Combat::Action(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{


	
	this->PlayerRelated(g_obj, player, enemies, map);


	this->EnemyRelated(g_obj, player, enemies, map);



	g_obj->GetTurnSystem()->Advance();


}






