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

	stairs_position = glm::vec2(164, 89);
	stairs_size = glm::vec2(31, 29);

	floor_1_position = glm::vec2(207, 90);
	floor_1_size = glm::vec2(9, 22);

	LoadButtonsSprite();


}

void PanelRender::LoadButtonsSprite()
{
	this->button_skins = new Sprite();

	char **tex_str = new char*[6];

	tex_str[0] = "portrait.png";
	tex_str[1] = "level.png";

	this->button_skins->Load(2, "data/UI/Action/", tex_str);
}




void PanelRender::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{
	u_data->SetAmbientLight(glm::vec4(1.f, 1.f, 1.f, 1.f));

	u_data->ApplyMatrix(Translation(this->portrait_position)*Scale(this->portrait_size));

	//this->button_skins->Render(0);
}