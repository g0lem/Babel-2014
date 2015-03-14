#ifndef PATHFINDER_HPP
#define PATHFINDER_HPP
  
#include <math.h>    
#include <vector>   
#include "collision_map.hpp"
#include "game_object.hpp"




class Pathfinder
{
private:
	GameObject *map;
	
	struct node
	{
		GLint x, y;
		GLfloat G, H, F;// distance from start H distance to end
		node *last;
	};
	node *Beginning, *Ending;
	GLfloat GetDistance(node *targetnode){ return abs(Ending->x - targetnode->x) + abs(Ending->y - targetnode->y); }
	
	std::vector < node* > openlist;
	std::vector < node* > visitedlist;

	bool PathFound;
	void FindNewNode(node *currentnode);
	node *FindBestNode();

	int ending_counter;

	
	bool IsOpened(int x, int y);
	bool IsVisited(int x, int y);



	void Delete(node * node);



public:
std::vector <glm::vec2> GetPath();
void Init(GameObject *g_obj, glm::vec2 start, glm::vec2 finish);
inline bool GetPathFound(){ return this->PathFound; }

};






#endif