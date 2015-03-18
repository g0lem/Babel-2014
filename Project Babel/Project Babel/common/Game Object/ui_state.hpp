#pragma once




class UIState
{


	GLboolean opened;



	BackpackState * b_state;



	void ProcessKeys(Controller * ctrl);


public:


	inline BackpackState*GetBackpackState(){ return this->b_state; }


	inline GLboolean GetOpened(){ return this->opened; }


	inline void SetOpender(GLboolean opened){ this->opened = opened; }



	inline UIState(){ this->Init(); }



	void Init();



	void Update(Controller * ctrl);


};



