#include "common.hpp"

#define RANGE 6
#define LIT 0
#define DARK 255



char *fog_of_war::GetFOW(GameObject *g_obj, glm::ivec2 position)
{
	int SIZE = g_obj->GetCollisionMap()->GetSize().x;

	char *s_map; 

	s_map = (char*)malloc(SIZE*g_obj->GetCollisionMap()->GetSize().y);


	//FILL THE X AND Y AXIS

	for (int i = position.y; i < position.y + RANGE; i++)
	if (g_obj->GetCollisionMap()->GetTiles()[position.x][i] != 1)
		s_map[position.x*SIZE + i] = LIT;
		else
			break;



	for (int i = position.x; i < position.x + RANGE; i++)
		if (g_obj->GetCollisionMap()->GetTiles()[i][position.y] != 1)
			s_map[i*SIZE + position.y] = LIT;
		else
			break;



	for (int i = position.y; i > position.y - RANGE; i--)
		if (g_obj->GetCollisionMap()->GetTiles()[position.x][i] != 1)
			s_map[position.x*SIZE + i] = LIT;
		else
			break;

	for (int i = position.x; i > position.x - RANGE; i--)
		if (g_obj->GetCollisionMap()->GetTiles()[i][position.y] != 1)
			s_map[i*SIZE + position.y] = LIT;
		else
			break;

	//Diagonals

	for (int i = 1; i < RANGE; i++)
	{
		if (g_obj->GetCollisionMap()->GetTiles()[position.x + i][position.y + i] != 1)
			s_map[(position.x+i)*SIZE + position.y + i] = LIT;
		else
			break;
	}

	for (int i = 1; i < RANGE; i++)
	{
		if (g_obj->GetCollisionMap()->GetTiles()[position.x - i][position.y - i] != 1)
			s_map[(position.x - i)*SIZE + position.y - i] = LIT;
		else
			break;
	}

	for (int i = 1; i < RANGE; i++)
	{
		if (g_obj->GetCollisionMap()->GetTiles()[position.x + i][position.y - i] != 1)
			s_map[(position.x + i)*SIZE + position.y - i] = LIT;
		else
			break;
	}

	for (int i = 1; i < RANGE; i++)
	{
		if (g_obj->GetCollisionMap()->GetTiles()[position.x - i][position.y + i] != 1)
			s_map[(position.x - i)*SIZE + position.y + i] = LIT;
		else
			break;
	}





	//Cadranul 1\\
		

	for (int i = position.x - 1; i > position.x - RANGE; i--)
		for (int j = position.y + 1; j < position.y - RANGE; j++)
		{

		if (g_obj->GetCollisionMap()->GetTiles()[i][j] != 1 && s_map[(i + 1)*SIZE+j] == LIT && s_map[i*SIZE + j - 1] == LIT && s_map[(i + 1)*SIZE + j - 1] == LIT)
		{
			s_map[i*SIZE+j] = LIT;
		}


		}


	//Cadranul 2\\

	for (int i = position.x - 1; i > position.x - RANGE; i--)
		for (int j = position.y - 1; j > position.y - RANGE; j--)
		{

		if (g_obj->GetCollisionMap()->GetTiles()[i][j] != 1 && s_map[(i + 1)*SIZE + j] == LIT && s_map[i*SIZE + j + 1] == LIT && s_map[(i + 1)*SIZE + j + 1] == LIT)
		{
			s_map[i*SIZE + j] = LIT;
		}

		}

	//Cadranul 3\\
				
	

	for (int i = position.x + 1; i < position.x + RANGE; i++)
		for (int j = position.y - 1; j > position.y - RANGE; j--)
		{

		if (g_obj->GetCollisionMap()->GetTiles()[i][j] != 1 && s_map[(i - 1)*SIZE + j] == LIT && s_map[i*SIZE + j + 1] == LIT && s_map[(i - 1)*SIZE + j + 1] == LIT)
		{
			s_map[i*SIZE + j] = LIT;
		}

		}


	//Cadranul 4\\
					
	for (int i = position.x + 1; i < position.x + RANGE; i++)
		for (int j = position.y + 1; j < position.y + RANGE; j++)
		{

		if (g_obj->GetCollisionMap()->GetTiles()[i][j] != 1 && s_map[(i - 1)*SIZE + j] == LIT && s_map[i*SIZE + j - 1] == LIT && s_map[(i - 1)*SIZE + j - 1] == LIT)
		{
			s_map[i*SIZE + j] = LIT;
		}
		}

	return s_map;
	

}