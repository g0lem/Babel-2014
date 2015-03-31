//Checked 1



#include <common.hpp>




void Map::Init()
{


	this->LoadSprites();



	this->GenerateContent();



}





void Map::GenerateContent()
{


	this->tilemap = new Tilemap();

	this->tilemap->Init();


	this->AddRooms(15);
	

	this->m_graph = new Graph(this->rooms->size());


	this->FirstTunnelPass();


	this->SecondTunnelPass();


	this->AddDoors();


}






void Map::Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj, glm::vec2 position)
{
	


	this->tilemap->Render(ctrl, u_data, this->m_sprite,
		g_obj->GetScroller()->GetBeginLimit(),g_obj->GetScroller()->GetEndLimit(),
<<<<<<< HEAD
		g_obj->GetScroller()->GetOffset(), fog->GetFOW(g_obj,glm::ivec2(position)));


=======
		g_obj->GetScroller()->GetOffset());
>>>>>>> parent of 8baece7... Merge branch 'master' of https://github.com/projectPJA/projectBabel



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













