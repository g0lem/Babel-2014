//Checked 1



#include <common.hpp>




void Map::Init(GameObject *g_obj)
{


	this->LoadSprites();

	

	this->GenerateContent(g_obj);




}





void Map::GenerateContent(GameObject *g_obj)
{


	this->tilemap = new Tilemap();

	this->tilemap->Init();


	this->AddRooms(15);
	

	this->m_graph = new Graph(this->rooms->size());


	this->FirstTunnelPass();


	this->SecondTunnelPass();


	this->AddDoors();

	g_obj->GetCollisionMap()->CreateOutOfMap(this->GetTilemap());

	this->fog = new fog_of_war();
	fog->Init(g_obj);
	


}






void Map::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, glm::vec2 position)
{
	
	//this->fog->Render(ctrl, u_data, glm::vec2((g_obj->GetScroller()->GetBeginLimit() + g_obj->GetScroller()->GetEndLimit())/2), g_obj);

	this->tilemap->Render(ctrl, u_data, this->m_sprite,
		g_obj->GetScroller()->GetBeginLimit(),g_obj->GetScroller()->GetEndLimit(),
		g_obj->GetScroller()->GetOffset(), fog->GetFOW(g_obj,glm::ivec2(position)));





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













