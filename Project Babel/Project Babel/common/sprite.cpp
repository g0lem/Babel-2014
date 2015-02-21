#include "sprite.hpp"



void Sprite::Load(GLuint num_textures, char ** textures_str)
{


	GLfloat buffer[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
	};



	glGenBuffers(1, &this->m_VBO);


	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);


	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), &buffer, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);


	glBindBuffer(GL_ARRAY_BUFFER, 0);


	this->num_textures = num_textures;


	this->textures = new GLuint[this->num_textures];


	for (GLuint i = 0; i < this->num_textures; i++)
		this->textures[i] = load_texture(textures_str[i]);



}





void Sprite::Render(GLuint current_frame)
{


	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);


	glActiveTexture(GL_TEXTURE0);


	glBindTexture(GL_TEXTURE_2D, current_frame);


	glDrawArrays(GL_TRIANGLES, 0, 6);


	glBindTexture(GL_TEXTURE_2D, 0);

}



