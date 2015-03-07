#ifndef PLAYER_HPP
#define PLAYER_HPP


#include "sprite.hpp"
#include "controls.hpp"
#include "2d_math.hpp"
#include "uniform_2d.hpp"
#include "movement.hpp"
#include "game_object.hpp"



class Player
{



	Sprite * m_sprite;


	Move* m_move;


	glm::vec2 position;


	glm::vec2 scale;


	GLfloat rotation_angle;


public:



	void Load();


	void Render(Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj);





};



#endif