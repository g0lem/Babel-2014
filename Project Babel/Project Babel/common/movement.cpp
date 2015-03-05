#include "movement.hpp"


GLfloat speed = 64.0f;


void Move::TileMove(Controller* ctrl, glm::vec2 &position, glm::vec2 scale, GameObject * g_obj)
{




	glm::vec2 half_screen_vector = GridPosition(glm::vec2(ctrl->GetWindowWidth(), ctrl->GetWindowHeight()) / 2.0f, scale);



	if (ctrl->GetKeyOnce(GLFW_KEY_W))
	{

		position.y -= speed;
		g_obj->GetScroller()->SetOffset(half_screen_vector - position);


	}


	if (ctrl->GetKeyOnce(GLFW_KEY_S))
	{

		position.y += speed;
		g_obj->GetScroller()->SetOffset(half_screen_vector - position);

	}


	if (ctrl->GetKeyOnce(GLFW_KEY_A))
	{

		position.x -= speed;
		g_obj->GetScroller()->SetOffset(half_screen_vector - position);


	}



	if (ctrl->GetKeyOnce(GLFW_KEY_D))
	{

	
		position.x += speed;
		g_obj->GetScroller()->SetOffset(half_screen_vector - position);



	}



}