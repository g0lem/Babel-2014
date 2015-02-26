#include "movement.hpp"


GLfloat speed = 200.0f;


void Move::move(Controller* ctrl, GLfloat &x, GLfloat &y)
{
	if (GLFW_PRESS == glfwGetKey(ctrl->GetWindow(), GLFW_KEY_W))
		y += speed*ctrl->GetFpsPointer()->Delta();
	if (GLFW_PRESS == glfwGetKey(ctrl->GetWindow(), GLFW_KEY_S))
		y -= speed*ctrl->GetFpsPointer()->Delta();
	if (GLFW_PRESS == glfwGetKey(ctrl->GetWindow(), GLFW_KEY_A))
		x -= speed * ctrl->GetFpsPointer()->Delta();
	if (GLFW_PRESS == glfwGetKey(ctrl->GetWindow(), GLFW_KEY_D))
		x += speed * ctrl->GetFpsPointer()->Delta();
}