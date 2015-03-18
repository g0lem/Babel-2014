#pragma once




class UIState
{


	GLboolean state;



	BackpackState * b_state;



	void ProcessKeys(Controller * ctrl);


public:


	inline BackpackState*GetBackpackState(){ return this->b_state; }


	inline GLboolean GetState(){ return this->state; }


	inline void SetOpender(GLboolean state){ this->state = state; }



	inline UIState(){ this->Init(); }



	void Init();



	void Update(Controller * ctrl);


};



