#ifndef MAP_HPP
#define MAP_HPP


#include "sprite.hpp"
#include <GL\glew.h>
#include <glfw3.h>

#define MAP_SIZE_X 30;
#define MAP_SIZE_Y 20;

class Map
{
public:

	Sprite *sprite;

	void Load();

	void GetNext();

	void Render();

private:
	GLuint *texture;
	GLuint num_textures;

	GLuint m_VBO;
};

#endif