#include "2d.hpp"



void Aaether2D::Init()

{

	glGenVertexArrays(1, &m_VAO);


	glBindVertexArray(m_VAO);


	this->program = LoadShaders("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt");


	this->texID = glGetUniformLocation(this->program, "texture");


	
	glBindVertexArray(0);


	char ** tex_str = new char*[1];
	tex_str[0] = "image.png";


	this->m_sprite = new Sprite();

	this->m_sprite->Load(1, tex_str);


}




void Aaether2D::Render()
{



	glBindVertexArray(this->m_VAO);



	glUseProgram(this->program);

	

	glUniform1i(this->texID, 0);




	this->m_sprite->Render(0);





	glUseProgram(0);



	glBindVertexArray(0);



}







