#pragma once




class UIHandler
{


	Menu * m_menu;



public:




	inline UIHandler(){ this->Init(); }


	void Init();


	void Render(Controller * ctrl, GameObject * g_obj);



};