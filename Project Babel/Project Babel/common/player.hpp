//Checked 1




#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "pathfinding.hpp"
#include "sprite.hpp"
#include "controls.hpp"
#include "2d_math.hpp"
#include "movement.hpp"
#include "game_object.hpp"
#include "map.hpp"
#include "uniform_2d.hpp"


class Player
{



	Sprite * m_sprite;

	Pathfinder *m_path;


	glm::vec2 position;


	glm::vec2 target;



	glm::vec2 scale;



	GLfloat speed;



	GLfloat rotation_angle;


	GLfloat frames;


	GLfloat frame_speed;



	void Update(glm::vec2 & position, glm::vec2 target, GLfloat speed, GLfloat delta);



public:



	void Load(Map * current_tilemap);


	void Render(Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj, Map * current_map);





};



#endif