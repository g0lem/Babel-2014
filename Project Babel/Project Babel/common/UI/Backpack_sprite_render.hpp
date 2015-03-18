#pragma once


class BackpackSpriteRender
{


	Sprite * button_skins;


	Button * m_button;
	

	void LoadButtons();


	void LoadSprites();


public:


	inline BackpackSpriteRender(){this->Init();};


	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);


	void Init();





};

