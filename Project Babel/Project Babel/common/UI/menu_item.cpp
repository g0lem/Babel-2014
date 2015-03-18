#include <common.hpp>



void Button::Init(Property * m_prop)
{


	this->m_prop = m_prop;



}



void Button::Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GLuint frame, GLuint action)
{


	u_data->ApplyMatrix(Translation(this->m_prop->position)*Scale(this->m_prop->size));



	u_data->SetAmbientLight(this->m_prop->color);


	m_sprite->Render(0);


}