#include <common.hpp>




void UIHandler::Init()
{


	this->m_menu = new Menu("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt");



}



void UIHandler::Render(Controller * ctrl, GameObject * g_obj)
{


	this->m_menu->Render(ctrl, g_obj);



}
