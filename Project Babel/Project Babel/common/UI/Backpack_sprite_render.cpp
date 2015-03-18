#include <common.hpp>





void BackpackSpriteRender::Init()
{


	this->LoadSprites();


	this->LoadButtons();


}



void BackpackSpriteRender::LoadSprites()
{


	this->button_skins = new Sprite();


	char ** tex_str = new char*[1];

	tex_str[0] = "button0.png";


	this->button_skins->Load(1, "data/UI/", tex_str);



}



void BackpackSpriteRender::LoadButtons()
{


	Property * m_prop = new Property();
	m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_prop->position = glm::vec2(600, 300);
	m_prop->size = glm::vec2(300 , 300);


	m_button = new Button(m_prop);


}




void BackpackSpriteRender::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{



	this->m_button->Render(ctrl, u_data, this->button_skins, 0, 
		UI_helper::GetButtonAction(ctrl, this->m_button->GetProperties()));




}



