//Checked 1



#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP


#include "uniform_2d.hpp"
#include "block.hpp"
#include "controls.hpp"
#include "sprite.hpp"
#include "2d_math.hpp"



class Tilemap
{



	void GenerateTileMap();


	glm::vec2 tile_scale;

	glm::ivec2 size;


	GLint **tiles;



public:



	void Init();


	void Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite,
		glm::ivec2 begin_limit, glm::ivec2 end_limit,
		glm::vec2 offset);


	inline glm::ivec2 GetSize(){ return this->size; }


	inline glm::vec2 GetTileScale(){ return this->tile_scale; }


	inline GLint**GetTiles(){ return this->tiles; }


};







#endif