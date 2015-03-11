#ifndef PATHFINDING_HPP 
#define PATHFINDING_HPP

#include "map.hpp"
#include "cell.hpp"

#include <vector>


class Pathfinder
{
    public:
		Pathfinder(Map *map);
		~Pathfinder(void);

		void FindPath(glm::vec2 currentPos, glm::vec2 targetPos);
		glm::vec2 NextPathPos(glm::vec2 position, int range);
		void ClearOpenList(){ openlist.clear(); }
		void ClearVisitedList(){ visitedlist.clear(); }
		void ClearPathtoGoal(){ pathtogoal->clear(); }
		std::vector <glm::vec2> *GetPath(){ return this->pathtogoal; }
		bool StartGoalInit;
		bool FoundGoal;

   private:
	   void SetStartAndGoal(Cell start, Cell goal);
	   void PathOpened(int x, int y, float NewCost, Cell *last);
	   Cell *GetNextCell();
	   void ContinuePath();

	   Cell *StartCell;
	   Cell *EndingCell;
	   Map *map;

	   std::vector<Cell*> openlist;
	   std::vector<Cell*> visitedlist;
	   std::vector<glm::vec2> *pathtogoal;

};




#endif