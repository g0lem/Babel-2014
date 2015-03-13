#ifndef TURN_HPP
#define TURN_HPP



#include "2d_math.hpp"



class TurnSystem
{



	GLfloat turns;



public:



	GLfloat GetTurns(){ return this->turns; }



	void ComputeAttack(GLfloat attack_speed);



	inline TurnSystem(){ this->Init(); }



	void Init();


};




#endif









