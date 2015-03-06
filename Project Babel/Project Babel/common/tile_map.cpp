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


			this->tiles[i][j] = NO_BLOCK;


		}



	}



}





void Tilemap::Init()
{


	this->tile_scale = glm::vec2(64.0f, 64.0f);


	this->size = glm::ivec2(32, 32);



	this->GenerateTileMap();


}



void Tilemap::Render(Controller * ctrl, ScreenUniformData * u_data, Sprite * m_sprite, GameObject * g_obj)
{


	glm::vec2 offset = -GridPosition(g_obj->GetScroller()->GetOffset(), this->tile_scale) / this->tile_scale;


	glm::vec2 screen_limit = GridPosition(glm::vec2(ctrl->GetWindowWidth(), ctrl->GetWindowHeight()), this->tile_scale) / this->tile_scale + glm::vec2(1.0f, 1.0f);


	glm::ivec2 end_limit = glm::min(glm::ivec2(offset + screen_limit), this->size);


	glm::ivec2 begin_limit = glm::max(glm::ivec2(offset), glm::ivec2(0, 0));




	for (int j = begin_limit.y; j < end_limit.y; j++)
	{



		for (int i = begin_limit.x; i < end_limit.x; i++)
		{



			if (this->tiles[i][j] != NO_BLOCK)
			{



				u_data->ApplyMatrix(Translation(glm::vec2(i, j)*tile_scale + g_obj->GetScroller()->GetOffset())*Scale(tile_scale));
				m_sprite->Render(this->tiles[i][j]);



			}



		}



	}



}