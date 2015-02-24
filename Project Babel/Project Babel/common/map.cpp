#include "map.hpp"


char Tmap[4][4] = {
		{ 1, 1, 1, 1},
		{ 1, 0, 0, 0},
		{ 1, 0, 0, 0},
		{ 1, 0, 0, 0},

};

void Map::Load(GLuint num_textures, char ** textures_str)
{
	this->map->Load(num_textures, textures_str);
}

void Map::Render()
{
	GLuint tile;

	for (GLuint x = 0; x < 4; x++)
		for (GLuint y = 0; y < 4; y++)
		{
			tile = Tmap[x][y];
			

			this->map->Render(0);
		}	
	
	

}