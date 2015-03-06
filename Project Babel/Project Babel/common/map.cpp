#include "map.hpp"




void Map::LoadSprites()
{




	this->m_sprite = new Sprite();


	char ** tex_str = new char*[3];
	tex_str[0] = "floor.png";
	tex_str[1] = "wall1.png";
	tex_str[2] = "wall2.png";


	this->m_sprite->Load(3, "data/tiles/", tex_str);






}





void Map::GenerateContent()
{


	this->tilemap = new Tilemap();

	this->tilemap->Init();



	this->expected_rooms = 500;


	GLuint tries = 0;



	while (this->rooms.size() < this->expected_rooms)
	{

		Room * temp = new Room();


		if (tries > 9)
		{
			this->expected_rooms--;
			tries = 0;
		}



		tries++;



		temp->Create(glm::vec2(Rand(this->tilemap->GetSize().x - 1 - MIN_ROOM_WIDTH), Rand(this->tilemap->GetSize().y - 1 - MIN_ROOM_HEIGHT)),
			Rand(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH),
			Rand(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT));


		if (temp->InsideMap(this->tilemap->GetSize().x, this->tilemap->GetSize().y))
		{

			GLboolean result = true;

			for (GLuint i = 0; i < this->rooms.size(); i++)
				if (temp->Intersects(this->rooms[i]))
				{
				result = false;
				break;
				}

			if (result)

			{



				this->TransformAndApplyRoomToTileMap(temp, this->tilemap, EMPTY_ROOM);


				this->rooms.push_back(temp);

			}


		}

	}








}



void Map::Init()
{


	this->LoadSprites();

	

	this->GenerateContent();



}



void Map::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj)
{
	


	this->tilemap->Render(ctrl, u_data, this->m_sprite,g_obj);



}


void Map::TransformAndApplyRoomToTileMap(Room * room, Tilemap * tilemap, GLuint transform_flag)
{



	room->Transform(transform_flag);


	for (int j = 0; j < room->GetHeight(); j++)
	{
		for (int i = 0; i < room->GetWidth(); i++)
		{


			this->tilemap->GetTiles()[i + room->GetOffset().x][j + room->GetOffset().y] = room->GetTileMapPointer()[i][j];



		}
	}




}









//////

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