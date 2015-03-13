#include "item.hpp"



void Item::Init()
{


	this->armor = 0.0f;


	this->armor_penetration = 0.0f;


	this->attack = vec2_0;


	this->attack_speed = 0.0f;


	this->effect = 0;


	this->type = 0;


}



void Item::Set(GLfloat attack_speed,
	glm::vec2 attack,
	GLfloat armor_penetration,
	GLfloat armor,
	GLint effect,
	GLint type)
{


	this->attack_speed = attack_speed;


	this->attack = attack;


	this->armor_penetration = armor_penetration;


	this->armor = armor;


	this->effect = effect;


	this->type = type;


}
