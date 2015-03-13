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
			break;



		}


	}


	if (player->GetTarget() > NO_TARGET && player->GetAttackingState())
	{


		GLuint * hp = &enemies->GetEnemiesPointer()[0][player->GetTarget()]->GetStats()->GetHp()->hp;


		glm::vec2 attack_range = player->GetItems()[ITEM_SLOT_WEAPON]->attack;


		*hp -= glm::min(*hp, Rand(attack_range.x,attack_range.y));


		player->SetAttackingState(false);


	}



}