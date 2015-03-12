#include "enemy_manager.hpp"



void EnemyManager::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{




	for (GLuint i = 0; i < this->m_enemies->size(); i++)
		this->m_enemies[0][i]->Render(ctrl, u_data, g_obj);




}



void EnemyManager::Init(GLuint num, Map * map)
{



	this->m_enemies = new std::vector<Enemy*>();


	this->m_enemies->resize(num);



	for (GLuint i = 0; i < this->m_enemies->size(); i++)
	{


		this->m_enemies[0][i] = new Enemy();


		this->m_enemies[0][i]->SetRandomPosition(map);


	}

}