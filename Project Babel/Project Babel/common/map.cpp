#include "map.hpp"




void Map::Init()
{


	//Sprite stuff



	this->m_sprite = new Sprite();


	char ** tex_str = new char*[4];
	tex_str[0] = "tile1.jpg";
	tex_str[1] = "tile2.jpg";
	tex_str[2] = "tile3.jpg";
	tex_str[3] = "tile4.jpg";


	this->m_sprite->Load(4,"data/tiles/", tex_str);


	

	//Tile map stuff


	this->tile_scale = glm::vec2(64.0f, 64.0f);


	this->size = glm::ivec2(15, 10);




	this->tile_map = new GLint*[this->size.x];
	for (GLuint i = 0; i < this->size.x; i++)
		this->tile_map[i] = new GLint[this->size.y];



	for (GLuint j = 0; j < this->size.y; j++)
	{


		for (GLuint i = 0; i < this->size.x; i++)


		{


			this->tile_map[i][j] = Rand(4);


		}



	}



}



void Map::Render(Controller * ctrl , ScreenUniformData * u_data)
{
	


	for (int j = 0; j < this->size.y; j++)
	{
		for (int i = 0; i < this->size.x; i++)
		{


			u_data->ApplyMatrix(Translation(glm::vec2(i, this->size.y-j-1)*tile_scale)*Scale(tile_scale));
			this->m_sprite->Render(this->tile_map[i][j]);


		}
	}



}

void Map::GetDistance(int i, int j)
{
	int in, jn, k;
	int di[] = {0,0,-1,1};
	int dj[] = {-1,1,0,0};
	for (k = 0; k < 4; k++)
	{
		in = i + di[k];
		jn = j + dj[k];
		if (in>=0 && jn>=0 && in < MAP_SIZE_Y && jn < MAP_SIZE_X)
			if (DistanceMap[in][jn] == 0 || DistanceMap[i][j] + 1 < DistanceMap[in][jn])
			{
			DistanceMap[in][jn] = DistanceMap[i][j] + 1;
			Map::GetDistance(in, jn);
			}
	}
}

void Map::ClearDistanceMap()
{
	for (int i = 0; i < MAP_SIZE_Y; i++)
		for (int j = 0; j < MAP_SIZE_X; j++)
			DistanceMap[i][j] = 0;

}