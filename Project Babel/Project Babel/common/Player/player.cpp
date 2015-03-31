//Checked 1





#include <common.hpp>


void Player::Load(GameObject * g_obj, Map * current_tilemap)
{



	this->LoadSprites();
	this->LoadPhysicalAttributes(current_tilemap);


	this->a_path = new AutoPath();
	this->m_dir = new Direction();
	this->m_stats = new Stats();
	this->e_near = new EnemiesNear();
	this->h_event = new EventHandler();
	this->fog = new fog_of_war();
	h_event->Init(current_tilemap);
	fog->Init(g_obj);
	this->t_clock = new sf::Clock();
	this->last_wanted_position = glm::vec2(0, 0);


	this->LoadItems(g_obj);
	this->LoadStats();



}




void Player::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, Map * current_map)
{

	


	u_data->ApplyMatrix(Translation(GridPosition(attributes->position*attributes->scale + g_obj->GetScroller()->GetOffset(), attributes->scale))*
		Scale(attributes->scale));



	u_data->SetAmbientLight(glm::vec3(1.0f, 1.0f, 1.0f));



	




	
	if (ctrl->GetKeyOnce(GLFW_KEY_SPACE) && this->target > NO_TARGET && a_path->Finished())
	{
		this->attacking = true;
		
			this->m_sprite[4]->Render(m_dir->Compute(DIR_TYPE_4, attributes->position, attributes->target));
		
	}



	if (attributes->HasReachedTarget())
		Move::TileMove(ctrl, g_obj, attributes->target);
		this->attributes->Update(ctrl->GetFpsPointer()->Delta());
		this->HandleAutoPath(ctrl, g_obj, current_map);
		Move::UpdateScroller(ctrl, g_obj, attributes->position, attributes->scale);





		if (attributes->HasMovedATile(ctrl->GetFpsPointer()->Delta()))
			g_obj->GetTurnSystem()->ComputeMovement(this->m_stats->base_movement_speed);
		else
			if (!attributes->HasReachedTarget())
			this->walk_animation->Update(16.0f, ctrl->GetFpsPointer()->Delta());


		


		if (this->attacking == false)
			this->m_sprite[m_dir->Compute(DIR_TYPE_4, attributes->position, attributes->target)]->Render(this->walk_animation->GetIFrames());
		else{
				this->m_sprite[4]->Render(m_dir->Compute(DIR_TYPE_4, attributes->position, attributes->target));
		}
		this->UpdateUI(g_obj);
		this->fog->Render(u_data, ctrl, g_obj, this->GetPAttributes()->position);

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
	char **atk_str = new char*[4];
	atk_str[0] = "back.png";
	atk_str[1] = "front.png";
	atk_str[2] = "left.png";
	atk_str[3] = "right.png";


	this->m_sprite = new Sprite*[5];
	this->m_sprite[0] = new Sprite();
	this->m_sprite[0]->Load(8, "data/sprites/player0/back/", tex_str);
	this->m_sprite[1] = new Sprite();
	this->m_sprite[1]->Load(8, "data/sprites/player0/front/", tex_str);
	this->m_sprite[2] = new Sprite();
	this->m_sprite[2]->Load(8, "data/sprites/player0/left/", tex_str);
	this->m_sprite[3] = new Sprite();
	this->m_sprite[3]->Load(8, "data/sprites/player0/right/", tex_str);
	this->m_sprite[4] = new Sprite();
	this->m_sprite[4]->Load(4, "data/sprites/player0/attack/", atk_str);




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



GLboolean Player::CheckAdvance(Controller * ctrl, GameObject * g_obj)
{


	GLboolean advance = true;



	if (advance)
		for (GLuint i = 0; i < g_obj->GetUIState()->GetInterHandler()->GetInters()->size(); i++)

		{


		Golem * g = g_obj->GetUIState()->GetInterHandler()->GetInters()[0][i];


		if (g->id == RECT)
		{

			advance = !Contains::Rectangle(ctrl->GetMousePosition(), g->position, g->size);
			break;

		}

		if (g->id == CIRCLE)
		{


			advance = !Contains::Circle(ctrl->GetMousePosition(), g->position, g->size);
			break;

		}


		}



	return advance;


}


void Player::HandleAutoPath(Controller * ctrl, GameObject * g_obj, Map *current_map)
{



	if (ctrl->GetKeyOnce(GLFW_KEY_E))
	{
		h_event->TriggerEvent(attributes->position, current_map, g_obj, this->GetStats());
	}
	

	
	if (ctrl->GetMouseButtonOnce(GLFW_MOUSE_BUTTON_LEFT) && this->CheckAdvance(ctrl, g_obj))
	{

		this->last_wanted_position = Move::GetMapPosition(g_obj, ctrl->GetMousePosition(), attributes->scale);
		a_path->Start(g_obj, attributes->position, last_wanted_position);
	
		//if (current_map->GetTilemap()->GetTiles[attributes->position.x][attributes->position.y] == TABLET_ID)
		//h_event->DisplayTablet(TABLET_ID);
	}
	
	





	if (a_path->IsSet() && !a_path->Finished())
	{


		
		this->attributes->target = a_path->GetStep();
		

		if (attributes->HasMovedATile(ctrl->GetFpsPointer()->Delta()) || attributes->HasReachedTarget())
		{
			a_path->Advance();
			a_path->Start(g_obj, attributes->target, last_wanted_position);
		}



	}
	if (a_path->Finished())
		a_path->GetPathfinder()->Delete();


}



void Player::LoadStats()
{



	this->m_stats->GetHp()->Buff(20);
	this->m_stats->base_movement_speed = 1.0f;

	this->m_stats->GetXp()->max_xp = 0;
	this->m_stats->GetXp()->xp = 0;


}




void Player::UpdateUI(GameObject * g_obj)
{


	g_obj->GetPanelState()->hp = this->m_stats->GetHp()->hp;
	g_obj->GetPanelState()->max_hp = this->m_stats->GetHp()->max_hp;
	
	g_obj->GetPanelState()->xp = this->m_stats->GetXp()->xp;
	g_obj->GetPanelState()->max_xp = this->m_stats->GetXp()->max_xp;
}




