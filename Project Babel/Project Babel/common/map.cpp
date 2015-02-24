#include "map.hpp"


char Tmap[4][4] = {
		{ 1, 1, 1, 1},
		{ 1, 0, 0, 0},
		{ 1, 0, 0, 0},
		{ 1, 0, 0, 0},

};

void Map::Load(GLuint num_textures, char ** textures_str)
{


	GLfloat buffer[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
	};



	glGenBuffers(1, &this->m_VBO);


	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);


	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), &buffer, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		0,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);


	glBindBuffer(GL_ARRAY_BUFFER, 0);


	this->num_textures = num_textures;


	this->textures = new GLuint[this->num_textures];


	for (GLuint i = 0; i < this->num_textures; i++)
		this->textures[i] = load_texture(textures_str[i], GL_LINEAR);
}

void Map::Render()
{
	//GLuint tile;

	for (GLint x = 0; x < 4; x++)
		for (GLint y = 0; y < 4; y++)
		{

		glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->textures[0]);
		glPushMatrix(); //push the matrix so that our translations only affect
			glTranslatef(y, -x, 0); //translate the tile to where it should belong

		glBegin(GL_QUADS); //begin drawing our quads
		glTexCoord2d(0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0); //with our vertices we have to assign a texcoord

		glTexCoord2d(1.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0); //so that our texture has some points to draw to

		glTexCoord2d(1.0, 1.0);
		glVertex3f(1.0, 1.0, 0.0);

		glTexCoord2d(0.0, 1.0);
		glVertex3f(0.0, 1.0, 0.0);
		glEnd();
		glPopMatrix();
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);



		}	
	
	

	

}