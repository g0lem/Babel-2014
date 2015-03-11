#ifndef PATHFINDING_HPP 
#define PATHFINDING_HPP

#include "cell.hpp"
#include <vector>
#include "glm\glm.hpp"

class Pathfinder
{
    public:
		Pathfinder(void);
		~Pathfinder(void);

		void FindPath(glm::vec3 currentPos, glm::vec3 targetPos);
		glm::vec3 NextPathPos(glm::vec3 position, int range);
		void ClearOpenList(){ openlist.clear(); }
		void ClearVisitedList(){ visitedlist.clear(); }
		void ClearPathtoGoal(){ pathtogoal.clear(); }
		bool StartGoalInit;
		bool FoundGoal;

   private:
	   void SetStartAndGoal(Cell start, Cell goal);
	   void PathOpened(int x, int y, float NewCost, Cell *last);
	   Cell *GetNextCell();
	   void ContinuePath();

	   Cell *StartCell;
	   Cell *EndingCell;

	   std::vector<Cell*> openlist;
	   std::vector<Cell*> visitedlist;
	   std::vector<glm::vec3*> pathtogoal;

};




#endif