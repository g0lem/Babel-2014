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


	void Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite);


	inline glm::ivec2 GetSize(){ return this->size; }


	inline GLint**GetTiles(){ return this->tiles; }


};







#endif