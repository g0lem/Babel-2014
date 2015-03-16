#ifndef ITEM_LIST_HPP
#define ITEM_LIST_HPP






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