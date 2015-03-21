#include "common.hpp"

void PanelRender::Init()
{
	energy_position = glm::vec2(154, 40);
	energy_size = glm::vec2(208, 43);

	health_position = glm::vec2(154, 0);
	health_size = glm::vec2(308, 43);

	level_position = glm::vec2(120, 120);
	level_size = glm::vec2(38, 38);

	portrait_position = glm::vec2(0, 0);
	portrait_size = glm::vec2(158, 158);

	stairs_position = glm::vec2(164, 46);
	stairs_size = glm::vec2(31, 29);

	floor_1_position = glm::vec2(207, 47);
	floor_1_size = glm::vec2(9, 22);

	LoadButtonsSprite();


}

void PanelRender::LoadButtonsSprite()
{
	this->button_skins = new Sprite();

	char **tex_str = new char*[6];

	tex_str[PANEL_PORTRAIT] = "portrait.png";
	tex_str[PANEL_LEVEL] = "level.png";
	tex_str[PANEL_HP] = "health.png";
	tex_str[PANEL_ENERGY] = "energy.png";
	tex_str[PANEL_STAIRS] = "stairs.png";
	tex_str[PANEL_ONE] = "floor_1.png";

	this->button_skins->Load(6, "data/UI/CPanel/", tex_str);
}




void PanelRender::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{
	u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));

	u_data->ApplyMatrix(Translation(this->portrait_position)*Scale(this->portrait_size));

	this->button_skins->Render(PANEL_PORTRAIT);



	u_data->ApplyMatrix(Translation(this->level_position)*Scale(this->level_size));

	this->button_skins->Render(PANEL_LEVEL);






	glm::vec2 hp_factor = glm::vec2(GLfloat(g_obj->GetPanelState()->hp) / GLfloat(g_obj->GetPanelState()->max_hp), 1.0f);
	u_data->ApplyMatrix(Translation(this->health_position)*Scale(this->health_size*hp_factor));
	this->button_skins->Render(PANEL_HP);





	/*
	u_data->ApplyMatrix(Translation(this->energy_position)*Scale(this->energy_size));

	this->button_skins->Render(PANEL_ENERGY);
	*/


	u_data->ApplyMatrix(Translation(this->stairs_position)*Scale(this->stairs_size));

	this->button_skins->Render(PANEL_STAIRS);


	u_data->ApplyMatrix(Translation(this->floor_1_position)*Scale(this->floor_1_size));

	this->button_skins->Render(PANEL_ONE);


    
}