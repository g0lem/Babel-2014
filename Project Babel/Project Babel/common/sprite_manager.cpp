//Checked 1



#include "sprite_manager.hpp"



void SpriteManager::Init(GameObject * g_obj)
{


	this->BindCreate("data/shaders/2d_vert.txt","data/shaders/2d_frag.txt");








	this->map = new Map();



	this->map->Init();



	g_obj->GetCollisionMap()->CreateOutOfMap(this->map->GetTilemap());



	this->player = new Player();



	this->player->Load(g_obj, this->map);



	this->m_enemies = new EnemyManager(10, this->map);



	this->m_combat = new Combat();






	this->UnbindCreate();




}



void SpriteManager::Clean()
{


	Aaether2D::Clean();


	delete player;
	delete map;
	delete m_enemies;
	delete m_combat;



}




void SpriteManager::Render(Controller * ctrl, GameObject * g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());



	g_obj->GetScroller()->ComputeScreenLimits(ctrl, this->map->GetTilemap()->GetSize(), this->map->GetTilemap()->GetTileScale());


	this->map->Render(ctrl, this->GetScreenPointer(), g_obj);


	this->player->Render(ctrl, this->GetScreenPointer(), g_obj, this->map);


	this->m_enemies->Render(ctrl, this->GetScreenPointer(), g_obj);


	this->m_combat->SetPlayerTarget(this->player, this->m_enemies);
  






	this->UnbindRun();


}