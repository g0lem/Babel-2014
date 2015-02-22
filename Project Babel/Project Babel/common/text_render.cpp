//Checked 2014

#include <GL/glew.h>
#include "text_render.hpp"

void TextRender::Init(Controller *ctrl)
{


	glGenVertexArrays(1, &m_VAO);


	glBindVertexArray(m_VAO);


	this->_text = new _Text();


	this->_text->initText2D("data/fonts/choco.ttf");


	this->program = LoadShaders("data/shaders/text_vert.txt", "data/shaders/text_frag.txt");


	this->font_texture_uniform = glGetUniformLocation(this->program, "myTextureSampler");


	this->half_screen_uniform = glGetUniformLocation(this->program, "half_screen_size");


	this->font_color_uniform = glGetUniformLocation(this->program, "fontColor");


	glBindVertexArray(0);



}




void TextRender::Render(Controller *ctrl)
{



	glBindVertexArray(m_VAO);


	glUseProgram(this->program);


	glUniform1i(this->font_texture_uniform, 0);


	glUniform2f(this->half_screen_uniform, ctrl->GetWindowWidth() / 2, ctrl->GetWindowHeight() / 2);


	glUniform4f(this->font_color_uniform, 0.5f, 0.5f, 0.5f, 1.0f);
	


	sprintf(text, "FPS:%.2f", ctrl->returnFps());
	this->_text->printText2D(text, 0, 580, 20);





	glUseProgram(0);


	glBindVertexArray(0);


}

void TextRender::Clean()
{


	this->_text->cleanupText2D();


	glDeleteProgram(this->program);


	glDeleteVertexArrays(1, &m_VAO);




}






