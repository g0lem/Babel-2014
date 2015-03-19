//Checked 1





#include <common.hpp>


void Player::Load(GameObject * g_obj, Map * current_tilemap)
{



	this->LoadSprites();


	this->a_path = new AutoPath();

	this->ai = new ActionProperties();

	this->m_dir = new Direction();


	this->LoadPhysicalAttributes(current_tilemap);


	this->LoadItems(g_obj);



}




void Player::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map * current_map)
{

	


	u_data->ApplyMatrix(Translation(GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale))*
		Scale(attributes->scale));



	u_data->SetAmbientLight(glm::vec3(1.0f, 1.0f, 1.0f));



	




	
	if (ctrl->GetKeyOnce(GLFW_KEY_SPACE) && this->target > NO_TARGET && a_path->Finished())
		this->attacking = true;




		Move::TileMove(ctrl, g_obj, attributes->target);


		this->Update(attributes->position, attributes->target, ctrl->GetFpsPointer()->Delta(), attributes->speed);


		this->HandleAutoPath(ctrl, g_obj);


		Move::UpdateScroller(ctrl, g_obj, attributes->position, attributes->scale);







		if (glm::distance(attributes->position, attributes->target) > attributes->speed*ctrl->GetFpsPointer()->Delta())
			this->walk_animation->Update(16.0f, ctrl->GetFpsPointer()->Delta());



		this->m_sprite[m_dir->Compute(DIR_TYPE_4, attributes->position, attributes->target)]->Render(this->walk_animation->GetIFrames());







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



	this->walk_animation = new Animation(8);



	char ** tex_str;


	tex_str = new char*[8];
	tex_str[0] = "1.png";
	tex_str[1] = "2.png";
	tex_str[2] = "3.png";
	tex_str[3] = "4.png";
	tex_str[4] = "5.png";
	tex_str[5] = "6.png";
	tex_str[6] = "7.png";
	tex_str[7] = "8.png";




	this->m_sprite = new Sprite*[4];




	this->m_sprite[0] = new Sprite();

	this->m_sprite[0]->Load(8, "data/sprites/player0/back/", tex_str);




	this->m_sprite[1] = new Sprite();

	this->m_sprite[1]->Load(8, "data/sprites/player0/front/", tex_str);





	this->m_sprite[2] = new Sprite();

	this->m_sprite[2]->Load(8, "data/sprites/player0/left/", tex_str);




	this->m_sprite[3] = new Sprite();

	this->m_sprite[3]->Load(8, "data/sprites/player0/right/", tex_str);






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





void Player::LoadItems(GameObject * g_obj)
{



	this->items = new Item*[5];

	this->items[ITEM_SLOT_WEAPON] = g_obj->GetItemList()->GetList()[0];



}



void Player::HandleAutoPath(Controller * ctrl, GameObject * g_obj)
{

	glm::vec2 iPosition = glm::vec2(1.65f, 1.f)*(ctrl->GetWindowSize() - glm::vec2(300, 400)) / 2.0f;

	
	if (ctrl->GetMouseButtonOnce(GLFW_MOUSE_BUTTON_LEFT) &&
		attributes->position == attributes->target)
		if ((Contains::Rectangle(ctrl->GetMousePosition(), iPosition, glm::vec2(300, 400))
			&& !g_obj->GetUIState()->GetState()) 
			|| !Contains::Rectangle(ctrl->GetMousePosition(), iPosition, glm::vec2(300, 400)))
			if (!Contains::Circle(ctrl->GetMousePosition(), glm::vec2(-120.f, 480.f), glm::vec2(240, 240))
				&& !Contains::Circle(ctrl->GetMousePosition(), glm::vec2(840.f, 480.f), glm::vec2(240, 240)))
		{


		a_path->GetPathfinder()->Init(g_obj, this->attributes->position, Move::GetMapPosition(g_obj, ctrl->GetMousePosition(), this->attributes->scale));


		a_path->Reset();


		if (a_path->GetPathfinder()->GetPathFound())
		{


			a_path->SetPath(a_path->GetPathfinder()->GetPath());


			a_path->Advance();



		}


		}
	
	





	if (a_path->IsSet() && !a_path->Finished())
	{


		
		this->attributes->target = a_path->GetStep();
		

		if (glm::distance(attributes->position, attributes->target) <= attributes->speed*ctrl->GetFpsPointer()->Delta())
			a_path->Advance();


	}




}