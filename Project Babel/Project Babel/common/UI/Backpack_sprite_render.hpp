#pragma once




#define NUM_BUTTONS 32
#define BUTTON_COLS 8
#define BUTTON_ROWS 4



class BackpackSpriteRender
{


	Sprite * button_skins;


	Sprite * background;


	Button ** m_button;
	





	glm::vec2 position;


	glm::vec2 scale;


	glm::vec2 button_background_offset;


	glm::vec2 button_background_size;


	glm::vec2 button_offset;


	glm::vec2 button_size;




	void LoadButtons();


	void LoadSprites();


	void LoadBackgroundSprite();


	void LoadButtonsSprite();






	void RenderBackground(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);


	void RenderButtons(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);



	void Update(Controller * ctrl, GameObject * g_obj);


public:




	inline BackpackSpriteRender(){this->Init();};


	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);


	void Init();





};

