#include "enemy_manager.hpp"



void EnemyManager::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{





	for (GLuint i = 0; i < this->m_enemies->size(); i++)
		this->m_enemies[0][i]->Render(ctrl, u_data, g_obj);





	this->CheckEnemiesState(g_obj);




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



void EnemyManager::CheckEnemiesState(GameObject * g_obj)
{


	for (GLuint i = 0; i < this->m_enemies->size(); i++)
	{


		if (this->m_enemies[0][i]->GetStats()->GetHp()->hp == 0)
		{


			this->Kill(g_obj, i);


		}



	}


}



void EnemyManager::Kill(GameObject * g_obj, GLuint enemy_id)
{


	glm::vec2 last_position = this->m_enemies[0][enemy_id]->GetLastPosition();


	g_obj->GetCollisionMap()->GetTiles()[GLuint(last_position.x)][GLuint(last_position.y)] = 0;


	this->m_enemies->erase(this->m_enemies->begin() + enemy_id);




}