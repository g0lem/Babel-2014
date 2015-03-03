#include "tile_map.hpp"




void Tilemap::GenerateTileMap()
{




	this->tiles = new GLint*[this->size.x];
	for (GLuint i = 0; i < this->size.x; i++)
		this->tiles[i] = new GLint[this->size.y];



	for (GLuint j = 0; j < this->size.y; j++)
	{


		for (GLuint i = 0; i < this->size.x; i++)


		{


			this->tiles[i][j] = FLOOR_BLOCK;


		}



	}



}





void Tilemap::Init()
{


	this->tile_scale = glm::vec2(64.0f, 64.0f);


	this->size = glm::ivec2(64, 64);



	this->GenerateTileMap();


}



void Tilemap::Render(Controller * ctrl, ScreenUniformData * u_data,Sprite * m_sprite)
{



	for (int j = 0; j < this->size.y; j++)
	{
		for (int i = 0; i < this->size.x; i++)
		{


			u_data->ApplyMatrix(Translation(glm::vec2(i, this->size.y - j - 1)*tile_scale)*Scale(tile_scale));
			m_sprite->Render(this->tiles[i][j]);


		}
	}



}