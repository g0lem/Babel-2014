#include <common.hpp>





void BackpackSpriteRender::Init()
{


	this->scale = glm::vec2(300, 400);


	this->button_background_offset = glm::vec2(8.5, 224);


	this->button_background_size = glm::vec2(283, 169);


	this->button_offset = glm::vec2(14.5, 238.5);


	this->button_size = glm::vec2(34, 34);




	this->LoadSprites();


	this->LoadButtons();


}




void BackpackSpriteRender::LoadBackgroundSprite()
{


	this->background = new Sprite();


	char ** tex_str = new char*[2];


	tex_str[0] = "background.png";
	tex_str[1] = "button_background.png";


	this->background->Load(2, "data/UI/Backpack/", tex_str);


}



void BackpackSpriteRender::LoadButtonsSprite()
{



	this->button_skins = new Sprite();


	char **tex_str = new char*[1];


	tex_str[0] = "slot.png";


	this->button_skins->Load(1, "data/UI/Backpack/", tex_str);





}



void BackpackSpriteRender::LoadSprites()
{




	this->LoadBackgroundSprite();


	this->LoadButtonsSprite();


	


}



void BackpackSpriteRender::LoadButtons()
{





	m_button = new Button*[NUM_BUTTONS];


	for (GLuint i = 0; i < NUM_BUTTONS; i++)
	{

		Property * m_prop = new Property();
		m_prop->size = this->button_size;
		m_prop->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

		m_button[i] = new Button(m_prop);

	}

}



void BackpackSpriteRender::Update(Controller * ctrl, GameObject * g_obj)
{


	this->position = (ctrl->GetWindowSize() - this->scale) / 2.0f;



	for (GLuint j = 0; j < BUTTON_ROWS; j++)
	{

		for (GLuint i = 0; i < BUTTON_COLS; i++)
		{



			this->m_button[j*8+i]->GetProperties()->position = this->position + this->button_offset + glm::vec2(i,j)*this->button_size;


		}
		


	}


}




void BackpackSpriteRender::RenderBackground(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{


	u_data->SetAmbientLight(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));






	this->Update(ctrl, g_obj);






	u_data->ApplyMatrix(Translation(this->position)*Scale(this->scale));



	this->background->Render(0);




	u_data->ApplyMatrix(Translation(this->position + this->button_background_offset)*
		Scale(this->button_background_size));


	this->background->Render(1);


}




void BackpackSpriteRender::RenderButtons(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{



	for (GLuint i = 0; i < NUM_BUTTONS; i++)
	{


		g_obj->GetUIState()->GetBackpackState()->GetButtonStates()[i] = UI_helper::GetButtonAction(ctrl, this->m_button[i]->GetProperties());


		this->m_button[i]->Render(ctrl, u_data, this->button_skins, 0,
			g_obj->GetUIState()->GetBackpackState()->GetButtonStates()[i]);


	}

}



void BackpackSpriteRender::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{



	this->RenderBackground(ctrl, u_data, g_obj);


	this->RenderButtons(ctrl, u_data, g_obj);



}



