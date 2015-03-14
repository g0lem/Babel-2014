#include "pathfinder.hpp"
#include <iostream>




std::vector <glm::vec2> Pathfinder::GetPath()
{
	std::vector <glm::vec2> path;
	node *get=Ending;

	while (get != NULL)
	{
		path.push_back(glm::vec2(get->x, get->y));
		get = get->last;
	}


	std::reverse(path.begin(), path.end());
	return path;
}






void Pathfinder::Init(GameObject *g_obj, glm::vec2 start, glm::vec2 finish)
{

	//std::cout << "Init \n";
	//loading collision map
	this->map = g_obj;

     

	this->PathFound = false;
	this->ending_counter = 0;
	this->openlist.clear();
	this->visitedlist.clear();


	//setting the beginning at the end
	Ending = new node;
	Beginning = new node;
	Ending->x = finish.x;
	Ending->y = finish.y;
	Ending->H = 0;

	Beginning->x = start.x;
	Beginning->y = start.y;
	Beginning->last = NULL;
	Beginning->G = 0;
	Beginning->H = GetDistance(Ending);
	Beginning->F = Beginning->G + Beginning->H;



	openlist.push_back(Beginning);


	//Getting the path

	node *current;

	current = FindBestNode();

	while (PathFound == false)
	{
		FindNewNode(current);
		if (!PathFound)
		current = FindBestNode();
		if (current == NULL){
			PathFound = false;
			break;
		}
	}



	//clear
}



bool Pathfinder::IsVisited(int x, int y)
{
	for (int i = 0; i < visitedlist.size(); i++)
	{
		if (visitedlist[i]->x == x && visitedlist[i]->y == y)
			return true;
	}
	return false;
}

bool Pathfinder::IsOpened(int x, int y)
{
	for (int i = 0; i < openlist.size(); i++)
	{
		if (openlist[i]->x == x && openlist[i]->y == y)
			return true;
	}
	return false;
}


void Pathfinder::FindNewNode(node *currentnode)
{
	if (currentnode->x == Ending->x && currentnode->y == Ending->y)
	{
		PathFound = true;
		Ending->last = currentnode->last;
		return;
	}
	//std::cout << "Find New Node \n";
	int newx, newy;
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
	for (int k = 0; k < 8; k++)
	{
		newx = dx[k] + currentnode->x;
		newy = dy[k] + currentnode->y;
		if (map->GetCollisionMap()->GetTiles()[newx][newy] == 0 && IsVisited(newx, newy) == false && IsOpened(newx, newy) == false)
		{
			node *nextnode = new node;
			nextnode->last = currentnode;
			nextnode->x = newx;
			nextnode->y = newy;
			//std::cout << "Node found at: " << newx << " " << newy << std::endl;
			nextnode->H = GetDistance(nextnode);
			nextnode->G = currentnode->G + 1;
			nextnode->F = nextnode->G + nextnode->H;
			openlist.push_back(nextnode);
		}

	}
}


Pathfinder::node *Pathfinder::FindBestNode()
{
	//std::cout << "Find Best Node \n";
	node *best = openlist[0];
	GLfloat minimum_F= best->F;
	int pozition = 0;
	for (int i = 1; i < openlist.size(); i++)
	{
		if (openlist[i]->F < minimum_F)
		{
			best = openlist[i];
			minimum_F = openlist[i]->F;
			pozition = i;
		}
	}
	//std::cout << "Node selected: " << best->x << " " << best->y << std::endl;

	visitedlist.push_back(best);
	if (openlist.size() == 1)
		ending_counter++;
	if (ending_counter <= 1)
		openlist.erase(openlist.begin() + pozition);
	else
		return NULL;

	return best;

}

