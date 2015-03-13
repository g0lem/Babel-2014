//Checked 1



#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP



#include "map.hpp"
#include <glfw3.h>
#include "controls.hpp"
#include "game_object.hpp"
#include "2d_math.hpp"




class Move
{



public:


	static void TileMove(Controller* ctrl, GameObject * g_obj, glm::vec2 &position);

	
	static void UpdateScroller(Controller * ctrl, GameObject * g_obj, glm::vec2 position, glm::vec2 scale);
	

	static glm::vec2 GetMapPosition(GameObject * g_obj, glm::vec2 position, glm::vec2 scale);


};

#endif