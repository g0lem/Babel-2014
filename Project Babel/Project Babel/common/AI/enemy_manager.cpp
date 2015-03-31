//Checked 2



#include <common.hpp>



void EnemyManager::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{



	g_obj->GetCollisionMap()->ResetList();


	for (GLuint i = 0; i < this->m_enemies->size(); i++)
	{


		if (compare_vec2(this->m_enemies[0][i]->GetPAttributes()->position, glm::vec2(g_obj->GetScroller()->GetBeginLimit())) == V_GREATER
			&& compare_vec2(this->m_enemies[0][i]->GetPAttributes()->position, glm::vec2(g_obj->GetScroller()->GetEndLimit())) == V_LESSER)
		{


			this->m_enemies[0][i]->Render(ctrl, u_data, g_obj);



		}

	}




	this->CheckEnemiesState(g_obj);




}



void EnemyManager::Init(GLuint num, Map * map, GameObject * g_obj)
{



	this->m_enemies = new std::vector<Enemy*>();
	this->m_enemies->resize(num);




	for (GLuint i = 0; i < this->m_enemies->size(); i++)
	{


		this->m_enemies[0][i] = new Enemy(g_obj->GetEnemyLoader()->GetData()[0][0]);
		this->m_enemies[0][i]->SetRandomPosition(map);
		this->m_enemies[0][i]->Update(g_obj, 0);


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