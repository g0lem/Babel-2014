#include <common.hpp>






void EnemyLoader::Init()
{


	this->data = new std::vector < EnemyData* > ;



	EnemyData * temp = new EnemyData();
	temp->num_dirs = 1;



	temp->num_frames = new GLuint[temp->num_dirs];
	temp->num_frames[0] = 1;





	char *** tex_str = new char**[temp->num_dirs];
	for (GLuint i = 0; i < temp->num_dirs; i++)
		tex_str[i] = new char*[temp->num_frames[i]];
	tex_str[0][0] = "1.png";





	temp->m_sprites = new Sprite*[temp->num_dirs];
	for (GLuint i = 0; i < temp->num_dirs; i++)
	{
	
		temp->m_sprites[i] = new Sprite();
		temp->m_sprites[i]->Load(temp->num_frames[i], "data/sprites/mob0/", tex_str[i]);


	}


	temp->m_stats = new Stats();
	temp->m_stats->base_attack = glm::vec2(0.0f, 1.0f);
	temp->m_stats->base_attack_speed = 1.0f;
	temp->m_stats->base_movement_speed = 1.0f;
	temp->m_stats->GetHp()->Buff(8);
	


	this->data->push_back(temp);



}


