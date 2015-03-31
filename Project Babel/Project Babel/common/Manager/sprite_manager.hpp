//Checked 1



#ifndef SPRITE_MANAGER_HPP
#define SPRITE_MANAGER_HPP




class SpriteManager : private Aaether2D
{


	Player * player;

	Map * map;


	EnemyManager * m_enemies;


	Combat * m_combat;


	bool finished = false;

public:
	bool canDraw = false;
	SplashScreen * s_screen;
	inline SpriteManager(GameObject * g_obj){ this->Init(g_obj); }


	inline ~SpriteManager(){ this->Clean(); }



	void Init(GameObject * g_obj);


	void Clean();


	void Render(Controller * ctrl, GameObject * g_obj);


};



#endif