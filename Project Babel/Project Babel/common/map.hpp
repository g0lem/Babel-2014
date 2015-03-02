#ifndef MAP_HPP
#define MAP_HPP


#include "uniform_2d.hpp"
#include "controls.hpp"
#include "2d_math.hpp"
#include "room.hpp"
#include "tile_map.hpp"


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



	Tilemap *tilemap;

	Sprite * m_sprite;


	GLuint expected_rooms;

	std::vector<Room*>rooms;





	GLint DistanceMap[MAP_SIZE_Y][MAP_SIZE_X];



};

#endif