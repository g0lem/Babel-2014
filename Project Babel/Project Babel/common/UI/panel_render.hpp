#pragma once



#define MENUBUTTON 0
#define WIREFRAME 1
#define HEALTHBAR 2
#define XPBAR 3



class PanelRender
{

	Sprite * button_skins;

	Button ** a_button;

	glm::vec2 wireframe_position;
	glm::vec2 wireframe_size;

	glm::vec2 menu_position;
	glm::vec2 menu_size;

	glm::vec2 xp_bar_position;
	glm::vec2 xp_bar_size;

	glm::vec2 hp_bar_position;
	glm::vec2 hp_bar_size;

	void LoadButtons();

	void LoadButtonsSprite();

	void RenderButtons(Controller *ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void Update(Controller *ctrl, GameObject * g_obj);

	float eAlpha = 1.0f;

	bool turn;

	bool pressed = false;

	sf::Clock *t_clock;

public:

	inline PanelRender() { this->Init(); }

	void Init();

	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);

};

