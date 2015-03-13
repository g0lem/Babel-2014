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
#include "pathfinder.hpp"



#define NO_TARGET -1
#define MIN_DISTANCE 2.0




class Player
{

	Pathfinder *m_path;

	Sprite * m_sprite;


	PhysicalAttributes * attributes;


	Animation * walk_animation;



	GLboolean attacking;



	GLint target;



	Item **items;







	void Update(glm::vec2 & position, glm::vec2 target, GLfloat speed, GLfloat delta);


	void LoadSprites();


	void LoadPhysicalAttributes(Map * current_tilemap);


	void LoadItems(GameObject * g_obj);




public:





	void Load(GameObject * g_obj, Map * current_tilemap);


	void Render(Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj, Map * current_map);


	inline GLboolean GetAttackingState(){ return this->attacking; }


	inline void SetAttackingState(GLboolean attacking){ this->attacking = attacking; }


	inline GLint GetTarget(){ return this->target; }


	inline void SetTarget(GLint target){ this->target = target; }


	inline PhysicalAttributes*GetPAttributes(){ return this->attributes; }


	inline Item**GetItems(){ return this->items; }


};





#endif



