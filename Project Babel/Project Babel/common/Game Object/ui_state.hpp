#pragma once



#define ACTIVE 1
#define NOT_ACTIVE 0



#define BACKPACK_KEY GLFW_KEY_C




class UIState
{



	CharPanState * char_panel;


	UI_intersect * inter_handler;


	void ProcessKeys(Controller * ctrl);


	void ManageQuits();


public:


	inline CharPanState*GetCharPanState(){ return this->char_panel; }


	inline UI_intersect * GetInterHandler(){ return this->inter_handler; }


	inline UIState(){ this->Init(); }



	void Init();



	void Update(Controller * ctrl);



};



