#pragma once



class panel_state
{

	int state;


public:



	GLint hp, max_hp;


	inline panel_state(){ this->Init(); }



	void Init();


	inline int GetState(){ return this->state; }

	inline void SetState(int state){ this->state = state; }


};

