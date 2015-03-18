#pragma once

class MenuItem: private Aaether2D
{

	struct Property{
		glm::vec2 position;
		int width, height;
		glm::vec4 color;
	};

	struct Mitem{
		Sprite *sprite;
		Property *property;
	};

	
	std::vector<Mitem*> *m_items;

	int num_items;

public:

	inline MenuItem(){ this->Init(); }

	void Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj);


	void AddRect();

	void Init();


	
};