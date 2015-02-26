#ifndef MAP_HPP
#define MAP_HPP


#include "sprite.hpp"
#include <GL\glew.h>
#include <glfw3.h>
#include "controls.hpp"
#include "uniform_2d.hpp"
#include "2d_math.hpp"


#define MAP_SIZE_X 30
#define MAP_SIZE_Y 20




class Map
{
public:



	void Render(Controller*ctrl, ScreenUniformData * u_data);

	void GetDistance(int i, int j);

	void ClearDistanceMap();

	void Init();

private:


	glm::vec2 tile_scale;

	glm::ivec2 size;


	GLint **tile_map;


	Sprite * m_sprite;

	int DistanceMap[MAP_SIZE_Y][MAP_SIZE_X];

};

#endif