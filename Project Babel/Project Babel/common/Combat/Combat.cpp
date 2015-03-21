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


			GLfloat turn_th = g_obj->GetTurnSystem()->GetTurns();


			while (turn_th >= current_enemy->GetStats()->base_attack_speed)
			{


				player->GetStats()->GetHp()->Damage(current_enemy->GetStats()->base_attack);

				turn_th -= current_enemy->GetStats()->base_attack_speed;

			}

		}




	}


}



void Combat::EnemyMovement(GameObject * g_obj, EnemyManager * enemies)
{



	for (GLuint i = 0; i < enemies->GetEnemiesPointer()->size(); i++)
	{



		Enemy * current_enemy = enemies->GetEnemiesPointer()[0][i];

		printf("%.2f\n", g_obj->GetTurnSystem()->GetTurns());


		if (g_obj->GetTurnSystem()->GetTurns() > current_enemy->GetStats()->base_movement_speed && current_enemy->GetMovingState() == COULD_MOVE)
		{

			
			current_enemy->SetMovingState(SHOULD_MOVE);


		}



	}



}



void Combat::EnemyRelated(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{


	this->SetEnemyTarget(player, enemies);
	this->AquireEnemyTarget(player, enemies);
	this->EnemyAttack(g_obj, player, enemies);
	this->EnemyMovement(g_obj, enemies);



}




void Combat::Action(GameObject * g_obj, Player * player, EnemyManager * enemies, Map * map)
{


	
	this->PlayerRelated(g_obj, player, enemies, map);


	this->EnemyRelated(g_obj, player, enemies, map);



}






