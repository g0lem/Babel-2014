#include "map.hpp"


char Tmap[4][4] = {
		{ 1, 1, 1, 1},
		{ 1, 0, 0, 0},
		{ 1, 0, 0, 0},
		{ 1, 0, 0, 0},

};


void Map::Render()
{
	

}

void Map::GetDistance(int i, int j)
{
	int in, jn, k;
	int di[] = {0,0,-1,1};
	int dj[] = {-1,1,0,0};
	for (k = 0; k < 4; k++)
	{
		in = i + di[k];
		jn = j + dj[k];
		if (in>=0 && jn>=0 && in < MAP_SIZE_Y && jn < MAP_SIZE_X)
			if (DistanceMap[in][jn] == 0 || DistanceMap[i][j] + 1 < DistanceMap[in][jn])
			{
			DistanceMap[in][jn] = DistanceMap[i][j] + 1;
			Map::GetDistance(in, jn);
			}
	}
}

void Map::ClearDistanceMap()
{
	for (int i = 0; i < MAP_SIZE_Y; i++)
		for (int j = 0; j < MAP_SIZE_X; j++)
			DistanceMap[i][j] = 0;

}