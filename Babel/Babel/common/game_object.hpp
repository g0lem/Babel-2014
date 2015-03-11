//Checked 1




#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP



#include "scroller.hpp"




class GameObject
{



	Scroller * m_scroller;



public:


	inline GameObject(){ this->Init(); }


	inline ~GameObject(){ this->Clean(); }



	inline Scroller * GetScroller(){ return this->m_scroller; }



	void Init();


	void Clean();




};




#endif