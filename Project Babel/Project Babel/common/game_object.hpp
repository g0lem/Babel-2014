//Checked 1






#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP





#include "collision_map.hpp"
#include "scroller.hpp"
#include "miscellaneous.hpp"




class GameObject
{



	Scroller * m_scroller;


	CollisionMap * c_map;



	Miscellaneous * m_misc;


public:


	inline GameObject(){ this->Init(); }


	inline ~GameObject(){ this->Clean(); }



	inline Scroller * GetScroller(){ return this->m_scroller; }



	inline CollisionMap * GetCollisionMap(){ return this->c_map; }



	inline Miscellaneous * GetMisc(){ return this->m_misc; }



	void Init();


	void Clean();




};




#endif