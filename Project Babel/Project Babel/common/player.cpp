//Checked 1





#include "player.hpp"


void Player::Load(Map * current_tilemap)
{


	this->LoadSprites();


	this->walk_animation = new Animation(8);


	this->LoadPhysicalAttributes(current_tilemap);

}




void Player::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map * current_map)
{

	


	u_data->ApplyMatrix(Translation(GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale))*
		Scale(attributes->scale));



	u_data->SetAmbientLight(glm::vec3(1.0f, 1.0f, 1.0f));



	
	
	




		Move::TileMove(ctrl, g_obj, attributes->target);


		this->Update(attributes->position, attributes->target, ctrl->GetFpsPointer()->Delta(), attributes->speed);


		Move::UpdateScroller(ctrl, g_obj, attributes->position, attributes->scale);






		if (glm::distance(attributes->position, attributes->target) > attributes->speed*ctrl->GetFpsPointer()->Delta())
			this->walk_animation->Update(16.0f, ctrl->GetFpsPointer()->Delta());





		this->m_sprite->Render(this->walk_animation->GetIFrames());



		m_path = new Pathfinder;


		if (ctrl->GetMouseButtonOnce(GLFW_MOUSE_BUTTON_LEFT) && glfwGetTime() > 1.0f)
		{
			//attributes->target = Move::GetMapPosition(g_obj, ctrl->GetMousePosition(), this->attributes->scale);
			m_path->Init(g_obj, this->attributes->position, Move::GetMapPosition(g_obj, ctrl->GetMousePosition(), this->attributes->scale));
			/*for (int i = 0; i < m_path->GetPath().size();i++)
			print_vec2(m_path->GetPath()[i]);*/

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




void Player::LoadSprites()
{


	this->m_sprite = new Sprite();


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

	this->m_sprite->Load(8, "data/sprites/player0/", tex_str);






}



void Player::LoadPhysicalAttributes(Map * current_tilemap)
{


	this->attributes = new PhysicalAttributes();


	this->attributes->scale = glm::vec2(64.0f, 64.0f);


	this->attributes->position = glm::vec2(current_tilemap->GetRoomsPointer()[0][0]->GetInternalCenter());


	this->attributes->target = this->attributes->position;


	this->attributes->speed = 7.5f;


	this->attributes->rotation_angle = 0.0f;



}