//Checked 1




#include "game_object.hpp"


void GameObject::Init()
{



	this->m_scroller = new Scroller();


	this->c_map = new CollisionMap();


	this->m_misc = new Miscellaneous();


}



void GameObject::Clean()
{



	delete this->m_scroller;


	delete this->c_map;


	delete this->m_misc;


}