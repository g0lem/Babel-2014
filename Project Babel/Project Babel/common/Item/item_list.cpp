#include <common.hpp>




void ItemList::Init()
{



	this->LoadItems();



}



void ItemList::LoadItems()
{


   
	GLuint num_items = 2;


	this->list = new Item*[num_items];


	this->list[0] = new Item();
	this->list[0]->Set(1.0f,
		glm::vec2(1, 5),
		0.0f,
		0.0f,
		NO_EFFECT,
		ITEM_TYPE_WEAPON);




	this->list[1] = new Item();
	this->list[1]->Set(0.0f,
		vec2_0,
		0.0f,
		2.0f,
		NO_EFFECT,
		ITEM_TYPE_ARMOR);




}


