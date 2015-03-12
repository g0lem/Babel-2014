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
#include "animation.hpp"
#include "physical_attributes.hpp"



class Player
{



	Sprite * m_sprite;


	PhysicalAttributes * attributes;


	Animation * walk_animation;


	void Update(glm::vec2 & position, glm::vec2 target, GLfloat speed, GLfloat delta);


	void LoadSprites();


	void LoadPhysicalAttributes(Map * current_tilemap);


public:



	void Load(Map * current_tilemap);


	void Render(Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj, Map * current_map);





};



#endif