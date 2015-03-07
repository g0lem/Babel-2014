//Checked 1





#include "player.hpp"


void Player::Load(Map * current_tilemap)
{


	this->m_sprite = new Sprite();


	char ** tex_str = new char*[1];
	tex_str[0] = "player0.png";



	this->m_sprite = new Sprite();

	this->m_sprite->Load(1, "data/sprites/", tex_str);





	this->scale = glm::vec2(64.0f, 64.0f);


	this->position = glm::vec2(current_tilemap->GetRoomsPointer()[0][0]->GetInternalCenter());


	this->target = this->position;


	this->speed = 7.5f;


	this->rotation_angle = 0.0f;


}




void Player::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map * current_map)
{




	u_data->ApplyMatrix(Translation(GridPosition(position*scale + g_obj->GetScroller()->GetOffset(), scale))*Scale(scale));



	
	Move::TileMove(ctrl, target, current_map);


	this->Update(position, target, ctrl->GetFpsPointer()->Delta(), speed);


	Move::UpdateScroller(ctrl, g_obj, position, scale);


	this->m_sprite->Render(0);


}




void Player::Update(glm::vec2 & position, glm::vec2 target, GLfloat speed, GLfloat delta)
{



	if (position.y - target.y > speed * delta)
		position.y -= speed * delta;
	else if (target.y - position.y > speed * delta)
		position.y += speed * delta;
	else
		position.y = target.y;



	if (position.x - target.x > speed * delta)
		position.x -= speed * delta;
	else if (target.x - position.x > speed * delta)
		position.x += speed * delta;
	else
		position.x = target.x;




}