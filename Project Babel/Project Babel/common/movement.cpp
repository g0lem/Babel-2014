#include "movement.hpp"


GLfloat speed = 64.0f;


void Move::move(Controller* ctrl, GLfloat &x, GLfloat &y)
{


	if (ctrl->GetKeyOnce(GLFW_KEY_W))
		y += speed;
	if (ctrl->GetKeyOnce(GLFW_KEY_S))
		y -= speed;
	if (ctrl->GetKeyOnce(GLFW_KEY_A))
		x -= speed;
	if (ctrl->GetKeyOnce(GLFW_KEY_D))
		x += speed;
}