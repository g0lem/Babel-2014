#include "2d.hpp"





void Aaether2D::Init()

{

	glGenVertexArrays(1, &m_VAO);


	glBindVertexArray(m_VAO);



	this->Load();



	this->program = LoadShaders("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt");


	this->texID = glGetUniformLocation(this->program, "texture");


	this->ortho = glGetUniformLocation(this->program, "ortho");


	this->u_data = new ScreenUniformData(this->program);



	glBindVertexArray(0);

}




void Aaether2D::Load()
{





	this->m_map = new Map();

	this->m_map->Init();



	this->m_player = new Player();


	this->m_player->Load();



}




void Aaether2D::Ortho(GLuint window_width, GLuint window_height)
{


	glUniformMatrix4fv(this->ortho, 1, GL_FALSE, &(glm::ortho<GLfloat>(0, window_width, 0, window_height)[0][0]));


}



void Aaether2D::FirstPass(Controller * ctrl)
{

	glBindVertexArray(this->m_VAO);


	glUseProgram(this->program);


	glUniform1i(this->texID, 0);


	this->Ortho(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);




}



void Aaether2D::LastPass()
{



	glDisable(GL_BLEND);


	glUseProgram(0);



	glBindVertexArray(0);



}


void Aaether2D::Render(Controller * ctrl)
{


	this->FirstPass(ctrl);



	this->m_map->Render(ctrl, this->u_data);


	
	this->m_player->Render(ctrl, this->u_data);
	




	this->LastPass();



}







