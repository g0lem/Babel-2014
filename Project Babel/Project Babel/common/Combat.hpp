#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "Database.h"
#include "map.hpp"
#include "tile_map.hpp"
#include "2d_math.hpp"
#include "player.hpp"
#include <stdio.h>

class Combat
{
public:
	void Init();
	void Test();
	void Hit(Controller *ctrl, Map *map, Player *player);
	

private:
	std::vector <int> Entities;



};





#endif