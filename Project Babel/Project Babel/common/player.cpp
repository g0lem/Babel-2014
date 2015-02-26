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




void Player::Render(Controller * ctrl, ScreenUniformData * u_data)
{




	u_data->ApplyMatrix(Translation(GridPosition(position, scale))*Scale(scale));
	this->m_move->move(ctrl, position.x, position.y);
	this->m_sprite->Render(0);


}



