#include "player.hpp"


void Player::Load()
{


	this->m_sprite = new Sprite();


	char ** tex_str = new char*[1];
	tex_str[0] = "sprite.png";



	this->m_sprite = new Sprite();

	this->m_sprite->Load(1, "data/sprites/", tex_str);



	this->m_move = new Move();




	this->position = glm::vec2(64.0f, 64.0f);


	this->scale = glm::vec2(64.0f, 64.0f);
	

	this->rotation_angle = 0.0f;


}




void Player::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{




	u_data->ApplyMatrix(Translation(GridPosition(position + g_obj->GetScroller()->GetOffset(), scale))*Scale(scale));
	this->m_move->TileMove(ctrl, position, scale, g_obj);
	this->m_sprite->Render(0);


}



