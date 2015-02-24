#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <glfw3.h>
#include "controls.hpp"



class Move
{
public:
	void move(Controller* ctrl, GLfloat &x, GLfloat &y);

};

#endif