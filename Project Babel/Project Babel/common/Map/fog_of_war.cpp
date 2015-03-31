#include "common.hpp"

<<<<<<< HEAD

#define RANGE 7
#define LIT 0.0f
#define SEMILIT 0.2f
#define UNSEEN 0.5f
#define DARK 0.9f
=======
#define RANGE 6
#define LIT 0
#define UNSEEN 1
#define DARK 2
>>>>>>> parent of 8baece7... Merge branch 'master' of https://github.com/projectPJA/projectBabel

void fog_of_war::Init(GameObject *g_obj)
{
	s_map = new int*[g_obj->GetCollisionMap()->GetSize().x];
	for (int i = 0; i < g_obj->GetCollisionMap()->GetSize().x; i++)
		s_map[i] = new int[g_obj->GetCollisionMap()->GetSize().y];

	m_sprite = new Sprite();
	char **tex_str;
	tex_str = new char*[3];
	tex_str[0] = "fog.png";
	tex_str[1] = "fog.png";
	tex_str[2] = "fog.png";
	m_sprite->Load(1,"data/sprites", tex_str);
}

void fog_of_war::Advance(GameObject *g_obj)
{
	for (int i = 0; i < g_obj->GetCollisionMap()->GetSize().x; i++)
		for (int j = 0; j < g_obj->GetCollisionMap()->GetSize().y; j++)
			if (s_map[i][j] == LIT || s_map[i][j] == SEMILIT)
				s_map[i][j] = UNSEEN;
}



void fog_of_war::GetFOW(GameObject *g_obj, glm::ivec2 position)
{
	int SIZE = g_obj->GetCollisionMap()->GetSize().y;

	this->Advance(g_obj);


	//FILL THE X AND Y AXIS

	for (int i = position.y; i < position.y + RANGE; i++)
		if (i < g_obj->GetCollisionMap()->GetSize().y)
		{
		if (g_obj->GetCollisionMap()->GetTiles()[position.x][i] != 1)
			s_map[position.x][i] = LIT;
		else
			break;
		}


	for (int i = position.x; i < position.x + RANGE; i++)
		if (i < g_obj->GetCollisionMap()->GetSize().x)
		if (g_obj->GetCollisionMap()->GetTiles()[i][position.y] != 1)
			s_map[i][position.y] = LIT;
		else
			break;



	for (int i = position.y; i > position.y - RANGE; i--)
		if (i >= 0)
		if (g_obj->GetCollisionMap()->GetTiles()[position.x][i] != 1)
			s_map[position.x][i] = LIT;
		else
			break;

	for (int i = position.x; i > position.x - RANGE; i--)
		if (i>=0)
		if (g_obj->GetCollisionMap()->GetTiles()[i][position.y] != 1)
			s_map[i][position.y] = LIT;
		else
			break;

	//Diagonals

	for (int i = 1; i < RANGE; i++)
	{
		if (i + position.x >= 0 && i + position.x<g_obj->GetCollisionMap()->GetSize().x && position.y + i <g_obj->GetCollisionMap()->GetSize().x && position.y+i>=0)
		if (g_obj->GetCollisionMap()->GetTiles()[position.x + i][position.y + i] != 1)
			s_map[position.x + i][position.y + i] = LIT;
		else
			break;
	}

	for (int i = 1; i < RANGE; i++)
	{
		if ( position.x-i>= 0 && position.x-i<g_obj->GetCollisionMap()->GetSize().x && position.y - i <g_obj->GetCollisionMap()->GetSize().x && position.y - i >= 0)
		if (g_obj->GetCollisionMap()->GetTiles()[position.x - i][position.y - i] != 1)
			s_map[position.x - i][position.y - i] = LIT;
		else
			break;
	}

	for (int i = 1; i < RANGE; i++)
	{
		if (i + position.x >= 0 && i + position.x<g_obj->GetCollisionMap()->GetSize().x && position.y - i <g_obj->GetCollisionMap()->GetSize().x && position.y - i >= 0)
		if (g_obj->GetCollisionMap()->GetTiles()[position.x + i][position.y - i] != 1)
			s_map[position.x + i][position.y - i] = LIT;
		else
			break;
	}

	for (int i = 1; i < RANGE; i++)
	{
		if ( position.x - i >= 0 &&  position.x-i<g_obj->GetCollisionMap()->GetSize().x && position.y + i <g_obj->GetCollisionMap()->GetSize().x && position.y + i >= 0)
		if (g_obj->GetCollisionMap()->GetTiles()[position.x - i][position.y + i] != 1)
			s_map[position.x - i][position.y + i] = LIT;
		else
			break;
	}





	//Cadranul 1\\
		

	for (int i = position.x - 1; i > position.x - RANGE; i--)
		for (int j = position.y + 1; j < position.y + RANGE; j++)
		{
<<<<<<< HEAD

		
		if (i >= 0 && i < g_obj->GetCollisionMap()->GetSize().x && j >= 0 && j < g_obj->GetCollisionMap()->GetSize().y)
		{
			if (g_obj->GetCollisionMap()->GetTiles()[i][j] == false && g_obj->GetCollisionMap()->GetTiles()[i + 1][j] == false && g_obj->GetCollisionMap()->GetTiles()[i][j - 1] == false && g_obj->GetCollisionMap()->GetTiles()[i + 1][j - 1] == false)
				if (s_map[i + 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i + 1][j - 1] == LIT)
				{			
				s_map[i][j] = LIT;
				}
			if (g_obj->GetCollisionMap()->GetTiles()[i][j] == true)
				if (s_map[i + 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i + 1][j - 1] == LIT)
				{				
				s_map[i][j] = LIT;
				}
		}
		
=======
		if (i >= 0 && j >= 0 && i<g_obj->GetCollisionMap()->GetSize().x && j<g_obj->GetCollisionMap()->GetSize().y)
		if (g_obj->GetCollisionMap()->GetTiles()[i][j] == false && s_map[i+1][j] == LIT && s_map[i][j-1] == LIT && s_map[i+1][j-1] == LIT)
		{
			s_map[i][j] = LIT;
		}


>>>>>>> parent of 8baece7... Merge branch 'master' of https://github.com/projectPJA/projectBabel
		}


	//Cadranul 2\\

	for (int i = position.x - 1; i > position.x - RANGE; i--)
		for (int j = position.y - 1; j > position.y - RANGE; j--)
		{
<<<<<<< HEAD
		
		if (i >= 0 && i < g_obj->GetCollisionMap()->GetSize().x && j >= 0 && j < g_obj->GetCollisionMap()->GetSize().y)
		{
			if (g_obj->GetCollisionMap()->GetTiles()[i][j] == false && g_obj->GetCollisionMap()->GetTiles()[i + 1][j] == false && g_obj->GetCollisionMap()->GetTiles()[i][j + 1] == false && g_obj->GetCollisionMap()->GetTiles()[i + 1][j + 1] == false)
			if (s_map[i + 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i + 1][j + 1] == LIT)
			{
				s_map[i][j] = LIT;
			}
			if (g_obj->GetCollisionMap()->GetTiles()[i][j] == true)
				if (s_map[i + 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i + 1][j + 1] == LIT)
				{
				s_map[i][j] = LIT;
				}
=======
		if (i >= 0 && j >= 0 && i<g_obj->GetCollisionMap()->GetSize().x && j<g_obj->GetCollisionMap()->GetSize().y)
		if (g_obj->GetCollisionMap()->GetTiles()[i][j] != 1 && s_map[i + 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i + 1][j + 1] == LIT)
		{
			s_map[i][j] = LIT;
		}
>>>>>>> parent of 8baece7... Merge branch 'master' of https://github.com/projectPJA/projectBabel

		
			
		}
		}

	//Cadranul 3\\
<<<<<<< HEAD
					
	
	for (int i = position.x + 1; i < position.x + RANGE; i++)
		for (int j = position.y - 1; j > position.y - RANGE; j--)
		{

		if (i >= 0 && i < g_obj->GetCollisionMap()->GetSize().x && j >= 0 && j < g_obj->GetCollisionMap()->GetSize().y)
		{
		
			if (g_obj->GetCollisionMap()->GetTiles()[i][j] == false && g_obj->GetCollisionMap()->GetTiles()[i - 1][j] == false && g_obj->GetCollisionMap()->GetTiles()[i][j + 1] == false && g_obj->GetCollisionMap()->GetTiles()[i - 1][j + 1] == false)
		    if(s_map[i - 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i - 1][j + 1] == LIT)
			{
				
				s_map[i][j] = LIT;
			}
			if (g_obj->GetCollisionMap()->GetTiles()[i][j] == true)
				if (s_map[i - 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i - 1][j + 1] == LIT)
				{
				s_map[i][j] = LIT;
				}
=======
				
	

	for (int i = position.x + 1; i < position.x + RANGE; i++)
		for (int j = position.y - 1; j > position.y - RANGE; j--)
		{
		if (i >= 0 && j >= 0 && i<g_obj->GetCollisionMap()->GetSize().x && j<g_obj->GetCollisionMap()->GetSize().y)
		if (g_obj->GetCollisionMap()->GetTiles()[i][j] != 1 && s_map[i - 1][j] == LIT && s_map[i][j + 1] == LIT && s_map[i - 1][j + 1] == LIT)
		{
			s_map[i][j] = LIT;
		}
>>>>>>> parent of 8baece7... Merge branch 'master' of https://github.com/projectPJA/projectBabel

		}
		}





	//Cadranul 4\\
					
	for (int i = position.x + 1; i < position.x + RANGE; i++)
		for (int j = position.y + 1; j < position.y + RANGE; j++)
		{
<<<<<<< HEAD
		if (i >= 0 && i < g_obj->GetCollisionMap()->GetSize().x && j >= 0 && j < g_obj->GetCollisionMap()->GetSize().y)
		{
			if (g_obj->GetCollisionMap()->GetTiles()[i][j] == false && g_obj->GetCollisionMap()->GetTiles()[i - 1][j] == false && g_obj->GetCollisionMap()->GetTiles()[i][j - 1] == false && g_obj->GetCollisionMap()->GetTiles()[i - 1][j - 1] == false)
			if(s_map[i - 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i - 1][j - 1] == LIT)
			{
				s_map[i][j] = LIT;
			}
			if (g_obj->GetCollisionMap()->GetTiles()[i][j] == true)
				if (s_map[i - 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i - 1][j - 1] == LIT)
				{
				s_map[i][j] = LIT;
				}

			

=======
		if (i >= 0 && j >= 0 && i<g_obj->GetCollisionMap()->GetSize().x && j<g_obj->GetCollisionMap()->GetSize().y)
		if (g_obj->GetCollisionMap()->GetTiles()[i][j] != 1 && s_map[i - 1][j] == LIT && s_map[i][j - 1] == LIT && s_map[i - 1][j - 1] == LIT)
		{
			s_map[i][j] = LIT;
>>>>>>> parent of 8baece7... Merge branch 'master' of https://github.com/projectPJA/projectBabel
		}
		}

	
	

}

void fog_of_war::SetUpSprite(float &alpha,int i, int j, ScreenUniformData *u_data)
{
	
	u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, alpha));

	u_data->ApplyMatrix(Translation(glm::vec2(i * 64, j * 64))*Scale(glm::vec2(64, 64)));
	m_sprite->Render(2);
}


void fog_of_war::Render(ScreenUniformData *u_data, Controller *ctrl, GameObject *g_obj, glm::vec2 position)
{
	GetFOW(g_obj, (glm::ivec2)(position.x/64, position.y/64));
	float alpha=1;
	for (int i = 0; i < g_obj->GetCollisionMap()->GetSize().x;i++)
		for (int j = 0; j < g_obj->GetCollisionMap()->GetSize().y; j++)
		{
		alpha = (float)(s_map[i][j] / 2);
		this->SetUpSprite(alpha, i,j, u_data);
		}
}
