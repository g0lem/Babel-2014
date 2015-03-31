#pragma once



class panel_state
{




public:



	GLint hp, max_hp, xp, max_xp;


	inline panel_state(){ this->Init(); }



	void Init();



};

