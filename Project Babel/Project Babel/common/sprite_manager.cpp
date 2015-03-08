//Checked 1



#include "sprite_manager.hpp"



void SpriteManager::Init()
{


	this->BindCreate("data/shaders/2d_vert.txt","data/shaders/2d_frag.txt");




	this->map = new Map();


	this->map->Init();



	this->player = new Player();


	this->player->Load(this->map);



	this->combat = new Combat();


	this->UnbindCreate();




}



void SpriteManager::Clean()
{


	Aaether2D::Clean();


	delete player;
	delete map;


}




void SpriteManager::Render(Controller * ctrl, GameObject * g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	this->map->Render(ctrl, this->GetScreenPointer(), g_obj);


	this->player->Render(ctrl, this->GetScreenPointer(), g_obj, this->map);


	combat->Hit(ctrl, this->map, this->player);


	this->UnbindRun();


}