//Checked 1



#include "map.hpp"
#include "Database.h"



void Map::LoadSprites()
{




	this->m_sprite = new Sprite();



<<<<<<< HEAD
	char ** tex_str = new char*[3];
=======


	char ** tex_str = new char*[4];
>>>>>>> origin/master
	tex_str[0] = "floor.png";
	tex_str[1] = "wall1.png";
	tex_str[2] = "wall2.png";
	tex_str[3] = "cobweb.png";


	this->m_sprite->Load(4, "data/tiles/", tex_str);






}





void Map::GenerateContent()
{


	this->tilemap = new Tilemap();

	this->tilemap->Init();



	this->expected_rooms = 10;


	GLuint tries = 0;


	this->rooms = new 	std::vector < Room* > ;


	while (this->rooms->size() < this->expected_rooms)
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

			for (GLuint i = 0; i < this->rooms->size(); i++)
				if (temp->Intersects(this->rooms[0][i]))
				{
				result = false;
				break;
				}

			if (result)

			{



				this->TransformAndApplyRoomToTileMap(temp, this->tilemap, EMPTY_ROOM);


				this->rooms->push_back(temp);

		


			}


		}

	}




	for (GLuint i = 1; i < rooms->size(); i++)
		AddTunnel(rooms[0][i]->GetInternalCenter(), rooms[0][i - 1]->GetInternalCenter());
<<<<<<< HEAD
=======

>>>>>>> origin/master



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



void Map::AddTunnel(glm::ivec2 point_a, glm::ivec2 point_b)
{


	glm::ivec2 begin_limit = glm::min(point_a, point_b);

	
	glm::ivec2 end_limit = glm::max(point_a, point_b);




	for (GLuint j = begin_limit.y; j <= end_limit.y; j++)
	{


		if (this->tilemap->GetTiles()[point_a.x - 1][j] == NO_BLOCK)
		this->tilemap->GetTiles()[point_a.x - 1][j] = STONE_BLOCK;


		this->tilemap->GetTiles()[point_a.x][j] = FLOOR_BLOCK;


		if (this->tilemap->GetTiles()[point_a.x + 1][j] == NO_BLOCK)
		this->tilemap->GetTiles()[point_a.x + 1][j] = STONE_BLOCK;




	}



	for (GLuint i = begin_limit.x; i <= end_limit.x; i++)
	{


		if (this->tilemap->GetTiles()[i][point_b.y - 1] == NO_BLOCK)
			this->tilemap->GetTiles()[i][point_b.y - 1] = STONE_BLOCK;


		this->tilemap->GetTiles()[i][point_b.y] = FLOOR_BLOCK;


		if (this->tilemap->GetTiles()[i][point_b.y + 1] == NO_BLOCK)
			this->tilemap->GetTiles()[i][point_b.y + 1] = STONE_BLOCK;




	}



	glm::ivec2 intersection_point;


	if (glm::ivec2(point_a.x, begin_limit.y) == point_a)
		intersection_point = glm::ivec2(point_a.x, end_limit.y);
	else
		intersection_point = glm::ivec2(point_a.x, begin_limit.y);


	if (this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y - 1] = STONE_BLOCK;

	if (this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y - 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y - 1] = STONE_BLOCK;

	if (this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y + 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x - 1][intersection_point.y + 1] = STONE_BLOCK;

	if (this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y + 1] == NO_BLOCK)
		this->tilemap->GetTiles()[intersection_point.x + 1][intersection_point.y + 1] = STONE_BLOCK;


<<<<<<< HEAD
=======


}


void Map::GetDistance(int i, int j)
{
	int in, jn, k;
	int di[] = { 0, 0, -1, 1 };
	int dj[] = { -1, 1, 0, 0 };
	glm::ivec2 size;
	size = this->tilemap->GetSize();
	for (k = 0; k < 4; k++)
	{
		in = i + di[k];
		jn = j + dj[k];
		if (in >= 0 && jn >= 0 && in < size.y && jn < size.y )//add this after the db is ready for testing DB::GetProperty(this->tilemap->GetTiles()[in][jn], 3) == 0
			if (DistanceMap->GetTiles()[in][jn] == 0 || DistanceMap->GetTiles()[i][j] + 1 < DistanceMap->GetTiles()[in][jn])
			{
			DistanceMap->GetTiles()[in][jn] = DistanceMap->GetTiles()[i][j] + 1;
			Map::GetDistance(in, jn);
			}
	}
}

void Map::ClearDistanceMap()
{
	glm::ivec2 size;
	size = this->tilemap->GetSize();
	for (int i = 0; i < size.y; i++)
		for (int j = 0; j < size.x; j++)
			DistanceMap->GetTiles()[i][j] = 0;

}



>>>>>>> origin/master
