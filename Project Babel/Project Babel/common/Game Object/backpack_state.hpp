#pragma once


#define ACTIVE 1


class BackpackState
{


	GLboolean state;


	GLuint * button_states;


public:


	
	inline GLuint * GetButtonStates(){ return this->button_states; }


	inline GLboolean GetState(){ return this->state; }


	inline void SetState(GLboolean state){ this->state = state; }



	inline BackpackState(){ this->Init(); }


	void Init();



};



