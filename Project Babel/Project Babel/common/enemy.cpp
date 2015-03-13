#include "enemy.hpp"


void Enemy::Init()
{


	this->p_attributes = new PhysicalAttributes();


	this->m_stats = new Stats();


	this->LoadPhysicalAttributes();


	this->LoadStats();


	this->LoadSprites();


}



void Enemy::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{


	this->last_position = this->p_attributes->position;



	u_data->ApplyMatrix(Translation(p_attributes->position * p_attributes->scale + g_obj->GetScroller()->GetOffset())*
		Scale(p_attributes->scale));



	u_data->SetAmbientLight(glm::vec3(1.0f, 1.0f, 1.0f));




	this->Update(g_obj);




	this->m_sprite->Render(0);




	this->RenderMisc(u_data, g_obj);


}




void Enemy::LoadSprites()
{



	this->m_sprite = new Sprite();


	char ** tex_str = new char*[1];
	tex_str[0] = "1.png";



	this->m_sprite->Load(1, "data/sprites/mob0/", tex_str);




}




void Enemy::SetRandomPosition(Map * map)
{


	GLboolean ok = false;

	while (!ok)
	{


		this->p_attributes->position = glm::vec2(Rand(map->GetTilemap()->GetSize().x), Rand(map->GetTilemap()->GetSize().y));
		this->p_attributes->target = this->p_attributes->position;


		GLint result = map->GetTilemap()->GetTiles()[GLuint(this->p_attributes->position.x)][GLuint(this->p_attributes->position.y)];


		if (result >= 0 && result < SOLID_LIMIT)
		ok = true;



	}


}



void Enemy::LoadPhysicalAttributes()
{


	this->p_attributes->position = this->p_attributes->target = vec2_0;


	this->p_attributes->scale = glm::vec2(64.0f, 64.0f);


	this->p_attributes->speed = 7.5f;


	this->p_attributes->rotation_angle - 0.0f;




}



void Enemy::Update(GameObject * g_obj)
{



	g_obj->GetCollisionMap()->GetTiles()[GLuint(this->p_attributes->position.x)][GLuint(this->p_attributes->position.y)] = 1;



}



void Enemy::RenderMisc(ScreenUniformData * u_data, GameObject * g_obj)
{



	if (this->m_stats->GetHp()->hp < this->m_stats->GetHp()->max_hp)
	this->RenderHpBar(u_data, g_obj);



}



void Enemy::RenderHpBar(ScreenUniformData * u_data, GameObject * g_obj)
{




	glm::vec2 hp_factor = glm::vec2(GLfloat(this->m_stats->GetHp()->hp) / GLfloat(this->m_stats->GetHp()->max_hp), 1.0f);



	u_data->ApplyMatrix(Translation(p_attributes->position * p_attributes->scale + g_obj->GetScroller()->GetOffset()
		- glm::vec2(0, 1)*p_attributes->scale)*
		Scale(p_attributes->scale*hp_factor));



	u_data->SetAmbientLight(glm::vec3(0.0f, 1.0f, 0.0f));



	g_obj->GetMisc()->GetSprites()[0]->Render(0);



	u_data->ApplyMatrix(Translation(p_attributes->position * p_attributes->scale + g_obj->GetScroller()->GetOffset()
		- glm::vec2(0, 1)*p_attributes->scale + glm::vec2(hp_factor.x, 0.0f)*p_attributes->scale)*
		Scale(p_attributes->scale*glm::vec2(1 - hp_factor.x, 1.0f)));



	u_data->SetAmbientLight(glm::vec3(1.0f, 0.0f, 0.0f));



	g_obj->GetMisc()->GetSprites()[0]->Render(0);



}





void Enemy::LoadStats()
{



	this->m_stats->GetHp()->Buff(8);

    

}