#ifndef ITEM_LIST_HPP
#define ITEM_LIST_HPP



#include "item.hpp"
#include "item_types.hpp"



class ItemList
{



	Item ** list;



	void LoadItems();



public:



	inline Item**GetList(){ return this->list; }


	inline ItemList(){ this->Init(); }



	void Init();



};




#endif