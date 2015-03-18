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



class UI_helper
{


public:



	static GLuint GetButtonAction(Controller * ctrl,Property * m_prop);



};