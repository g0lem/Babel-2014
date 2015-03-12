#ifndef COLLISION_MAP_HPP
#define COLLISION_MAP_HPP



#include "tile_map.hpp"



class CollisionMap
{



	glm::ivec2 size;


	GLboolean **tiles;



public:


	inline CollisionMap(){ this->Init(); }



	void Init();


	void CreateOutOfMap(Tilemap * map);




	inline glm::ivec2 GetSize(){ return this->size; }


	inline GLboolean **GetTiles(){ return this->tiles; }


};

#endif