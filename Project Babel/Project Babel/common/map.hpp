#ifndef MAP_HPP
#define MAP_HPP


#include "sprite.hpp"
#include <GL\glew.h>
#include <glfw3.h>

#define MAP_SIZE_X 30
#define MAP_SIZE_Y 20

class Map
{
public:


	void GetNext();

	void Render();

	void GetDistance(int i, int j);

	void ClearDistanceMap();

private:

	GLuint *textures;

	GLuint num_textures;

	int DistanceMap[MAP_SIZE_Y][MAP_SIZE_X];

	GLuint m_VBO;
};

#endif