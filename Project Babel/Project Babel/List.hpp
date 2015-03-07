#ifndef LIST_HPP
#define LIST_HPP

//daca stergi asta, Cristi, te bat de te rup
class List
{
public:

	EntityList *GetBeginning(){ return this->Start; }
	EntityList *GetEnding(){ return this->End; }
	
	
	
	void PushBack(int id, int health, int x, int y)
	{
		if (this->Start == NULL)
		{
			Start = new EntityList;
			Start->last = NULL;
			Start->next = NULL;
			
			Start->health = health;
			Start->id = id;
			Start->x = x;
			Start->y = y;



		}

	}
	
	
	
	void DeleteNod(EntityList *nod);
	EntityList *Next(EntityList *nod){ return this->next; }
	EntityList *Last(EntityList *nod){ return this->last; }


private:
	struct EntityList 
	{
		int health, id, x, y;
		EntityList *last, *next;
	}*Start, *End;
};
#endif