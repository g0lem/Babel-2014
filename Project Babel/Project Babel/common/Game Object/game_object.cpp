//Checked 1




#include <common.hpp>


void GameObject::Init()
{



	this->m_scroller = new Scroller();


	this->c_map = new CollisionMap();


	this->m_misc = new Miscellaneous();


	this->m_list = new ItemList();


	this->t_system = new TurnSystem();


	this->ui_state = new UIState();


}



void GameObject::Clean()
{



	delete this->m_scroller;


	delete this->c_map;


	delete this->m_misc;


	delete this->m_list;


	delete this->t_system;
	

	delete this->ui_state;


}