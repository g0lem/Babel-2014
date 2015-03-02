#include "map.hpp"






void Map::Init()
{


	//Sprite stuff



	this->m_sprite = new Sprite();


	char ** tex_str = new char*[3];
	tex_str[0] = "floor.png";
	tex_str[1] = "wall1.png";
	tex_str[2] = "wall2.png";


	this->m_sprite->Load(3,"data/tiles/", tex_str);


	

	//Tile map stuff



	this->tilemap = new Tilemap();

	this->tilemap->Init();



	this->expected_rooms = 4;


	while (this->rooms.size() < this->expected_rooms)
	{

		Room * temp = new Room();



		temp->Create(glm::vec2(Rand(this->tilemap->GetSize().x - 1 - MIN_ROOM_WIDTH), Rand(this->tilemap->GetSize().y - 1 - MIN_ROOM_HEIGHT)),
			Rand(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH),
			Rand(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT));


		if (temp->InsideMap(this->tilemap->GetSize().x, this->tilemap->GetSize().y))
		{

			GLboolean result = true;

			for (GLuint i = 0; i < this->rooms.size();i++)
				if (temp->Intersects(this->rooms[i]))
				{
				result = false;
				break;
				}

			if (result)

			{

				temp->Transform(EMPTY_ROOM);


				for (int j = 0; j < temp->GetHeight(); j++)
				{
					for (int i = 0; i < temp->GetWidth(); i++)
					{


						this->tilemap->GetTiles()[i+temp->GetOffset().x][j+temp->GetOffset().y] = temp->GetTileMapPointer()[i][j];
						


					}
				}


				temp->d_Print();


				this->rooms.push_back(temp);

			}


		}

	}


}



void Map::Render(Controller * ctrl , ScreenUniformData * u_data)
{
	


	this->tilemap->Render(ctrl, u_data, this->m_sprite);



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