#include "2d.hpp"





GLfloat alpha = 0.0f;


glm::vec2 position(300.f, 300.f);


void Aaether2D::Init()

{

	glGenVertexArrays(1, &m_VAO);


	glBindVertexArray(m_VAO);



	char ** tex_str = new char*[1];
	tex_str[0] = "desertfest.png";
	char ** tex_str2 = new char*[2];
	tex_str2[0] = "image.png";

	this->m_sprite = new Sprite();

	this->m_sprite->Load(1, tex_str);

	this->m_map = new Map();

	this->m_map->Load(1, tex_str2);


	this->program = LoadShaders("data/shaders/2d_vert.txt", "data/shaders/2d_frag.txt");


	this->texID = glGetUniformLocation(this->program, "texture");


	this->ortho = glGetUniformLocation(this->program, "ortho");


	this->u_data = new ScreenUniformData(this->program);



	glBindVertexArray(0);

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


	glm::vec2 pos = glm::vec2(400.0f, 300.0f);
	glm::vec2 scale = glm::vec2(200.0f, 200.0f);
	
	
	this->m_map->Render();


	this->u_data->ApplyMatrix(Shaorma(position, scale, alpha));


	//alpha += 0.3f;



	this->m_move->move(ctrl, position.x, position.y);

	
	
	this->m_sprite->Render(0);

	

	this->LastPass();



}







