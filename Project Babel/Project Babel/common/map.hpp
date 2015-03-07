//Checked 1




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



	void Init();


	void TransformAndApplyRoomToTileMap(Room * room, Tilemap * tilemap, GLuint transform_flag);

	
	void GetDistance(int i, int j);



	void ClearDistanceMap();


	inline Tilemap *GetDistanceMap(){ return this->DistanceMap; }




	inline Tilemap * GetTilemap(){ return this->tilemap; }



	inline 	std::vector<Room*>* GetRoomsPointer(){ return this->rooms; }


private:






	Tilemap *tilemap, *DistanceMap;

	Sprite * m_sprite;


	GLuint expected_rooms;

	std::vector<Room*>*rooms;


	void LoadSprites();



	void GenerateContent();


	void AddTunnel(glm::ivec2 point_a, glm::ivec2 point_b);



};

#endif