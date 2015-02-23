#include "map.hpp"


char map[4][4] = {
		{ 1, 1, 1, 1},
		{ 1, 0, 0, 0},
		{ 1, 0, 0, 0},
		{ 1, 0, 0, 0},

};

void Map::Load()
{
	char ** tex_str = new char*[2];
	tex_str[0] = "image.png";
	tex_str[1] = "stairs.png";

	this->sprite->Load(2, tex_str);
}

void Map::Render()
{
	GLuint tile;
	GLuint texture[2];

	for (GLuint x = 0; x < 4; x++)
		for (GLuint y = 0; y < 4; y++)
		{
			tile = map[x][y];
			if (texture[tile] == 0)
				glActiveTexture(GL_TEXTURE0);
			else
				glActiveTexture(GL_TEXTURE1);

			glBindTexture(GL_TEXTURE_2D, 0);
			
			glBegin(GL_QUADS);

			glTexCoord2f(0.0f, 0.0f); glVertex3f(float(x), float(y), 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(float(x + 1), float(y), 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(float(x + 1), float(y + 1), 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(float(x), float(y + 1), 0.0f);

			glEnd();

		}
}