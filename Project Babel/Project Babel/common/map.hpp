#ifndef MAP_HPP
#define MAP_HPP


#include "uniform_2d.hpp"
#include "controls.hpp"
#include "2d_math.hpp"
#include "room.hpp"
#include "tile_map.hpp"
#include "game_object.hpp"




class Map
{





public:



	void Render(Controller*ctrl, ScreenUniformData * u_data, GameObject * g_obj);

	void GetDistance(int i, int j);

	void ClearDistanceMap();

	void Init();


	void TransformAndApplyRoomToTileMap(Room * room, Tilemap * tilemap, GLuint transform_flag);



	void AddTunnel(glm::ivec2 point_a, glm::ivec2 point_b);



private:





	Tilemap *tilemap;

	Sprite * m_sprite;


	GLuint expected_rooms;

	std::vector<Room*>rooms;


	void LoadSprites();



	void GenerateContent();






};

#endif