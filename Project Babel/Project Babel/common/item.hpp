#ifndef ITEM_HPP
#define ITEM_HPP



#include "2d_math.hpp"




class Item
{


public:




	GLfloat attack_speed;



	glm::vec2 attack;



	GLfloat armor_penetration;



	GLfloat armor;


    
	GLint effect;



	GLint type;



	inline Item(){ this->Init(); }



	void Init();



	void Set(GLfloat attack_speed,
		glm::vec2 attack,
		GLfloat armor_penetration,
		GLfloat armor,
		GLint effect,
		GLint type);



};





#endif