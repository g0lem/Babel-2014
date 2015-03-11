#include "pathfinding.hpp"

Pathfinder::Pathfinder(Map *map)
{
	StartGoalInit = false;
	pathtogoal = new std::vector < glm::vec2 > ;
	FoundGoal = false;
	this->map = map;
}

Pathfinder::~Pathfinder(void)
{

}

void Pathfinder::FindPath(glm::vec2 currentPos, glm::vec2 targetPos)
{
	if (!StartGoalInit)
	{
		for (int i = 0; i < openlist.size(); i++)
			delete openlist[i];
		openlist.clear();

		for (int i = 0; i < visitedlist.size(); i++)
			delete visitedlist[i];
		visitedlist.clear();

		//for (int i = 0; i < pathtogoal->size(); i++)
			delete pathtogoal;
		pathtogoal->clear();


		//init start
		Cell start;
		start.x = currentPos.x;
		start.y = currentPos.y;
		
		//init goal
		Cell goal;
		goal.x = targetPos.x;
		goal.y = targetPos.y;

		SetStartAndGoal(start, goal);
		StartGoalInit = true;
	}
	else
	{
		ContinuePath();
	}
}

void Pathfinder::SetStartAndGoal(Cell start, Cell goal)
{
	StartCell = new Cell;
	StartCell->x = start.x;
	StartCell->y = start.y;
	StartCell->last = NULL;

	
	EndingCell = new Cell;
	EndingCell->x = goal.x;
	EndingCell->y = goal.y;
	EndingCell->last = &goal;

	StartCell->G = 0;
	StartCell->H = StartCell->ManhattanDistance(&goal);
	StartCell->last = 0;

	openlist.push_back(StartCell);

}

Cell *Pathfinder::GetNextCell()
{
	float bestF = 1.e20f;
	int cellIndex = -1;
	Cell *nextcell = NULL;
	
	for (int i = 0; i < openlist.size(); i++)
	{
		if (openlist[i]->GetF() < bestF)
		{
			bestF = openlist[i]->GetF();
			cellIndex = i;
		}
	}

	if (cellIndex >= 0)
	{
		nextcell = openlist[cellIndex];
		visitedlist.push_back(nextcell); 
		openlist.erase(openlist.begin() + cellIndex);
	}
	return nextcell;
}

void Pathfinder::PathOpened(int x, int y, float NewCost, Cell *last)
{
	if (this->map->GetTilemap()->GetTiles()[x][y] >= SOLID_LIMIT)
		return;
	int id = y * 32 + x; //32 e marimea lumii
	for (int i = 0; i < visitedlist.size(); i++)
	{
		if (id == visitedlist[i]->id)
		{
			return;
		}
	}
	Cell *nextcell = new Cell;
	nextcell->x = x;
	nextcell->y = y;
	nextcell->last = last;

	nextcell->G = NewCost;
	nextcell->H = last->ManhattanDistance(EndingCell);

	for (int i = 0; i < openlist.size(); i++)
	{
		if (id == openlist[i]->id)
		{
			float newF = nextcell->G + NewCost + openlist[i]->H;

			if (openlist[i]->GetF() > newF)
			{
				openlist[i]->G = nextcell->G + NewCost;
				openlist[i]->last = nextcell;
			}
			else
			{
				delete nextcell;
				return;
			}
		}
	}
	openlist.push_back(nextcell);
}

void Pathfinder::ContinuePath()
{
	if (openlist.empty())
		return;

	Cell *currentCell = GetNextCell();
	if (currentCell->id == EndingCell->id)
	{
		EndingCell->last = currentCell->last;
		
		Cell *getpath;
		
		
		for (getpath = EndingCell; getpath != NULL; getpath = getpath->last)
		{
			pathtogoal->push_back(glm::vec2(getpath->x, getpath->y));
		}

		FoundGoal = true;
		return;
	}
	else
	{
		//rightCell
		PathOpened(currentCell->x + 1, currentCell->y, currentCell->G + 1, currentCell->last);

		//left
		PathOpened(currentCell->x - 1, currentCell->y, currentCell->G + 1, currentCell->last);

		//up
		PathOpened(currentCell->x, currentCell->y - 1, currentCell->G + 1, currentCell->last);

		//down
		PathOpened(currentCell->x, currentCell->y + 1, currentCell->G + 1, currentCell->last);

		//adauga diagonale daca vor
		

		for (int i = 0; i < openlist.size(); i++)
		{
			if (currentCell->id == openlist[i]->id)
			{
				openlist.erase(openlist.begin() + i);
			}
		}

	}
}

glm::vec2 Pathfinder::NextPathPos(glm::vec2 position, int range)
{
	int index = 1;

	glm::vec2 nextpos;
	nextpos.x = pathtogoal[0][pathtogoal->size() - index].x;
	nextpos.y = pathtogoal[0][pathtogoal->size() - index].y;
    
	glm::vec2 distance = nextpos - position;

	if (index < pathtogoal->size())
	{
		if (distance.length() < range)
		{
			pathtogoal->erase(pathtogoal->end() - index);
		}
	}
	return nextpos;
}