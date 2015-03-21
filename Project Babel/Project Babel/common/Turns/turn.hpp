#ifndef TURN_HPP
#define TURN_HPP






class TurnSystem
{



	GLfloat turns;



public:



	GLfloat GetTurns(){ return this->turns; }


	void ComputeAttack(GLfloat attack_speed);
	void ComputeMovement(GLfloat movement_speed);


	inline TurnSystem(){ this->Init(); }
	inline void Reset(){ this->turns = 0.0f; }
	inline void Advance(){ if (this->turns >= 1.0f)this->turns--; }


	void Init();


};




#endif









