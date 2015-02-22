//Checked 2014

#ifndef TEXT_RENDER_HPP
#define TEXT_RENDER_HPP


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "controls.hpp"
#include "text2D.hpp"
#include "shader.hpp"
#include <stdio.h>

class TextRender
{
	char text[256];


	_Text *_text;

	GLuint m_VAO;


	GLuint program;


	GLuint font_texture_uniform;


	GLuint half_screen_uniform;


	GLuint font_color_uniform;


public:

	inline TextRender(Controller * ctrl) { this->Init(ctrl); }


	inline ~TextRender() { this->Clean(); }

	void Init(Controller * ctrl);


	void Render(Controller *ctrl);


	void Clean();




};



#endif






