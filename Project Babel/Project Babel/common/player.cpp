//Checked 1





#include "player.hpp"


void Player::Load(Map * current_tilemap)
{


	this->m_sprite = new Sprite();
	m_path = new Pathfinder(current_tilemap);

	char ** tex_str = new char*[8];
	tex_str[0] = "1.png";
	tex_str[1] = "2.png";
	tex_str[2] = "3.png";
	tex_str[3] = "4.png";
	tex_str[4] = "5.png";
	tex_str[5] = "6.png";
	tex_str[6] = "7.png";
	tex_str[7] = "8.png";



	this->m_sprite = new Sprite();

	this->m_sprite->Load(8, "data/sprites/", tex_str);


	this->frames = 0;

	this->frame_speed = 16.0f;


	this->scale = glm::vec2(64.0f, 64.0f);


	this->position = glm::vec2(current_tilemap->GetRoomsPointer()[0][0]->GetInternalCenter());


	this->target = this->position;


	this->speed = 7.5f;


	this->rotation_angle = 0.0f;


}




void Player::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map * current_map)
{




	u_data->ApplyMatrix(Translation(GridPosition(position*scale + g_obj->GetScroller()->GetOffset(), scale))*Scale(scale));


	{

		if (ctrl->GetMouseButtonOnce(GLFW_MOUSE_BUTTON_LEFT))
		{
			//target = Move::GetMapPosition(current_map, g_obj, ctrl->GetMousePosition(), this->scale);
			m_path->FindPath(position, Move::GetMapPosition(current_map, g_obj, ctrl->GetMousePosition(), this->scale));
			for (int i = 0; i < m_path->GetPath()->size(); i++)
				print_vec2(m_path->GetPath()[0][i]);
		}


		Move::TileMove(ctrl, target, current_map);


		this->Update(position, target, ctrl->GetFpsPointer()->Delta(), speed);




		Move::UpdateScroller(ctrl, g_obj, position, scale);

	}



	
	{

		if (glm::distance(position, target) > speed*ctrl->GetFpsPointer()->Delta())
			frames += frame_speed*ctrl->GetFpsPointer()->Delta();

		if (frames >= 8)
			frames = 0;


		this->m_sprite->Render(GLuint(frames));


	}
	



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