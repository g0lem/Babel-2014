//Checked 1




#include "game_object.hpp"


void GameObject::Init()
{



	this->m_scroller = new Scroller();



}



void GameObject::Clean()
{



	delete this->m_scroller;



}