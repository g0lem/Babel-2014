#pragma once



#define PANEL_PORTRAIT 0
#define PANEL_LEVEL 1
#define PANEL_HP 2
#define PANEL_HP_BORDER 3
#define PANEL_ENERGY 4
#define PANEL_STAIRS 5
#define PANEL_ONE 6



class PanelRender
{

	Sprite * button_skins;

	Button ** a_button;

	glm::vec2 energy_position = glm::vec2(0, 0);
	glm::vec2 energy_size = glm::vec2(208, 43);

	glm::vec2 health_position = glm::vec2(154, 0);
	glm::vec2 health_size = glm::vec2(308, 43);

	glm::vec2 health_border_position = glm::vec2(154, 0);
	glm::vec2 health_border_size = glm::vec2(308, 43);

	glm::vec2 level_position = glm::vec2(120, 120);
	glm::vec2 level_size = glm::vec2(38, 38);

	glm::vec2 portrait_position = glm::vec2(0, 0);
	glm::vec2 portrait_size = glm::vec2(158, 158);

	glm::vec2 stairs_position = glm::vec2(164, 89);
	glm::vec2 stairs_size = glm::vec2(31, 29);

	glm::vec2 floor_1_position = glm::vec2(207, 90);
	glm::vec2 floor_1_size = glm::vec2(9, 22);

	void LoadButtons();

	void LoadButtonsSprite();

	void RenderButtons(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void Update(Controller *ctrl, GameObject * g_obj);


public:

	inline PanelRender() { this->Init(); }

	void Init();

	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

};

