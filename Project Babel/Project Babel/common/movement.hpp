#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <glfw3.h>
#include "controls.hpp"
#include "game_object.hpp"
#include "2d_math.hpp"


class Move
{



public:


	void TileMove(Controller* ctrl, glm::vec2 &position, glm::vec2 scale, GameObject * g_obj);

};

#endif