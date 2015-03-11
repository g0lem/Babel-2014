//Checked 1




#ifndef PLAYER_HPP
#define PLAYER_HPP


#include "sprite.hpp"
#include "controls.hpp"
#include "2d_math.hpp"
#include "uniform_2d.hpp"
#include "movement.hpp"
#include "game_object.hpp"
#include "map.hpp"



class Player
{



	Sprite * m_sprite;




	glm::vec2 position;


	glm::vec2 target;



	glm::vec2 scale;



	GLfloat speed;



	GLfloat rotation_angle;



	void Update(glm::vec2 & position, glm::vec2 target, GLfloat speed, GLfloat delta);



public:



	void Load(Map * current_tilemap);


	void Render(Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj, Map * current_map);





};



#endif