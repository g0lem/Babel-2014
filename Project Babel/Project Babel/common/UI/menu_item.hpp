#pragma once



#define NONE 0
#define HOVER 1
#define PRESSED 2




struct Property
{


	glm::vec2 position;
	glm::vec2 size;
	glm::vec4 color;


};



class Button
{


	Property * m_prop;


public:


	inline Property * GetProperties(){ return this->m_prop; }


	inline Button(Property * m_prop){ this->Init(m_prop); }
	

	void Init(Property * m_prop);


	void Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GLuint frame, GLuint action);


};


