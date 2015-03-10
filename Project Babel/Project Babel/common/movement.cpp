//Checked 1




#include "movement.hpp"


void Move::TileMove(Controller* ctrl, glm::vec2 &position, Map * current_tilemap)
{




	



	if (ctrl->GetKeyOnce(GLFW_KEY_W) && position.y > 0)
	{





		if (current_tilemap->GetTilemap()->GetTiles()[GLuint(position.x)][GLuint(position.y - 1)] < 1)
			position.y--;



	}





	if (ctrl->GetKeyOnce(GLFW_KEY_S) && position.y < glm::vec2(current_tilemap->GetTilemap()->GetSize()).y)
	{


	
		if (current_tilemap->GetTilemap()->GetTiles()[GLuint(position.x)][GLuint(position.y + 1)] < 1)
			position.y++;




	}


	if (ctrl->GetKeyOnce(GLFW_KEY_A) && position.x > 0)
	{




		if (current_tilemap->GetTilemap()->GetTiles()[GLuint(position.x - 1)][GLuint(position.y)] < 1)
			position.x--;





	}



	if (ctrl->GetKeyOnce(GLFW_KEY_D) && position.x < glm::vec2(current_tilemap->GetTilemap()->GetSize()).x)
	{




		if (current_tilemap->GetTilemap()->GetTiles()[GLuint(position.x + 1)][GLuint(position.y)] < 1)
			position.x++;




	}



}


void Move::UpdateScroller(Controller * ctrl, GameObject * g_obj, glm::vec2 position, glm::vec2 scale)
{

	glm::vec2 half_screen_vector = GridPosition(glm::vec2(ctrl->GetWindowWidth(), ctrl->GetWindowHeight()) / 2.0f, scale);


	g_obj->GetScroller()->SetOffset(half_screen_vector - position*scale);


}




glm::vec2 Move::GetMapPosition(Map * current_tilemap, GameObject * g_obj, glm::vec2 position, glm::vec2 scale)
{


	position = glm::ivec2(GridPosition(position, scale) / scale - (g_obj->GetScroller()->GetOffset()) / scale);


	if (position.x >= current_tilemap->GetTilemap()->GetSize().x)
		position.x = current_tilemap->GetTilemap()->GetSize().x - 1;
	if (position.y >= current_tilemap->GetTilemap()->GetSize().y)
		position.y = current_tilemap->GetTilemap()->GetSize().y - 1;
	if (position.x < 0)
		position.x = 0;
	if (position.y < 0)
		position.x = 0;


	return position;

}