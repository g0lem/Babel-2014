//Checked 1


#include <common.hpp>



void SpriteManager::Init(GameObject * g_obj)
{


	this->BindCreate("data/shaders/2d_vert.txt","data/shaders/2d_frag.txt");








	this->map = new Map();



<<<<<<< HEAD
	
g_obj->GetCollisionMap()->CreateOutOfMap(this->map->GetTilemap());
 
	
=======
	this->map->Init();

	this->s_screen = new SplashScreen();

	this->s_screen->Init();

	g_obj->GetCollisionMap()->CreateOutOfMap(this->map->GetTilemap());
>>>>>>> parent of 8baece7... Merge branch 'master' of https://github.com/projectPJA/projectBabel



	this->player = new Player();



	this->player->Load(g_obj, this->map);



	this->m_enemies = new EnemyManager(10, this->map, g_obj);



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


	if (this->s_screen->Update() == false)
	{
		this->s_screen->Render(ctrl, this->GetScreenPointer());


<<<<<<< HEAD
	this->map->Render(ctrl, this->GetScreenPointer(), g_obj, player->GetPAttributes()->position);
=======
		if (ctrl->GetKey(GLFW_KEY_ENTER) == 1)
			this->s_screen->m_screens->at(0)->alpha = 0;
	}
	else
	{
		g_obj->GetScroller()->ComputeScreenLimits(ctrl, this->map->GetTilemap()->GetSize(), this->map->GetTilemap()->GetTileScale());
>>>>>>> parent of 8baece7... Merge branch 'master' of https://github.com/projectPJA/projectBabel


		this->map->Render(ctrl, this->GetScreenPointer(), g_obj);


		this->player->Render(ctrl, this->GetScreenPointer(), g_obj, this->map);


		this->m_enemies->Render(ctrl, this->GetScreenPointer(), g_obj);


		this->m_combat->Action(ctrl, g_obj, this->player, this->m_enemies, this->map);

		this->s_screen->Render(ctrl, this->GetScreenPointer());
	}


	this->UnbindRun();


}