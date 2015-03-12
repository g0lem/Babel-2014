#ifndef ENEMY_HPP
#define ENEMY_HPP



#include "sprite.hpp"
#include "controls.hpp"
#include "2d_math.hpp"
#include "uniform_2d.hpp"
#include "game_object.hpp"
#include "map.hpp"
#include "physical_attributes.hpp"
#include "stats.hpp"



class Enemy
{

	Stats * m_stats;


	PhysicalAttributes * p_attributes;


	Sprite * m_sprite;


	void LoadSprites();


	void LoadStats();


	void LoadPhysicalAttributes();


	void Update(GameObject * g_obj);


	void RenderMisc(ScreenUniformData * u_data, GameObject * g_obj);


	void RenderHpBar(ScreenUniformData * u_data, GameObject * g_obj);



public:


	inline PhysicalAttributes*GetPAttributes(){ return this->p_attributes; }


	inline Enemy(){ this->Init(); }


	void Init();


	void Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj);



	void SetRandomPosition(Map * map);



};




#endif