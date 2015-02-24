#include "movement.hpp"


void Move::move(Controller* ctrl, GLfloat &x, GLfloat &y)
{
	if (GLFW_PRESS == glfwGetKey(ctrl->GetWindow(), GLFW_KEY_W))
		y += 4;
	if (GLFW_PRESS == glfwGetKey(ctrl->GetWindow(), GLFW_KEY_S))
		y -= 4;
	if (GLFW_PRESS == glfwGetKey(ctrl->GetWindow(), GLFW_KEY_A))
		x -= 4;
	if (GLFW_PRESS == glfwGetKey(ctrl->GetWindow(), GLFW_KEY_D))
		x += 4;
}