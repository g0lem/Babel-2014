#pragma once




class BackpackState
{


	GLboolean opened;


	GLuint * button_states;


public:


	
	inline GLuint * GetButtonStates(){ return this->button_states; }


	inline GLboolean GetOpened(){ return this->opened; }


	inline void SetOpended(GLboolean opened){ this->opened = opened; }



	inline BackpackState(){ this->Init(); }


	void Init();



};



