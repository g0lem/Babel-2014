//Checked 1






#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP


class GameObject
{



	Scroller * m_scroller;


	CollisionMap * c_map;



	Miscellaneous * m_misc;



	ItemList *m_list;



	TurnSystem * t_system;



public:


	inline GameObject(){ this->Init(); }


	inline ~GameObject(){ this->Clean(); }



	inline Scroller * GetScroller(){ return this->m_scroller; }



	inline CollisionMap * GetCollisionMap(){ return this->c_map; }



	inline Miscellaneous * GetMisc(){ return this->m_misc; }



	inline ItemList * GetItemList(){ return this->m_list; }



	inline TurnSystem * GetTurnSystem(){ return this->t_system; }



	void Init();


	void Clean();




};




#endif