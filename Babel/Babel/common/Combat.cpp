#include "Combat.hpp"
#include "dice.hpp"

void Combat::Init()
{

}

void Combat::Test()
{

}

void Combat::Hit(Controller *ctrl, Map *map, Player *player)
{
	
	/*
	std::vector<int>::iterator i;

	map->GetDistance(player->GetPlayerPosition().y, player->GetPlayerPosition().x);



	i = Entities.begin();
	Entities.insert(i, 1);
	Entities.insert(i + 1, 1);
	Entities.insert(i + 2, player->GetPlayerPosition().y);
	Entities.insert(i + 3, player->GetPlayerPosition().x - 1);


	for (i = Entities.begin(); i != Entities.end(); i += 4)
	{
		if ((*i) + 1 == 0)
		{
			Entities.erase(i);
			printf("the %d node has been deleted\n", (*i));
		}

		if ((*i) + 2 == (int)(ctrl->GetMousePosition().y / 64) && (*i) + 3 == (int)(ctrl->GetMousePosition().x / 64))
			if (map->GetDistanceMap()->GetTiles()[(int)(ctrl->GetMousePosition().y / 64)][(int)(ctrl->GetMousePosition().x / 64)] <= 2 && ctrl->GetMouseButton(1) != NULL) //replace 2 with the range of the weapon 
				Entities[(*i)] -= 1; //replace 1 with the damage


	}


	*/

}

