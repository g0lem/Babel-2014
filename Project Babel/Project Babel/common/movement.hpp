#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "application.hpp"

class Move
{
public:
	void move(GLuint x, GLuint y);

	GLFWwindow* window;
};

#endif