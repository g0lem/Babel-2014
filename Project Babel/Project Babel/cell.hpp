#ifndef CELL_HPP
#define CELL_HPP

class Cell
{
public:
	float H, F, G;
	int x, y, id;
	float GetF(){ return G + H; }
	Cell() : last(0){}
	Cell(int x, int y, Cell *_last = 0) :x(x), y(y), last(_last), id(y * 64 + y), G(0), H(0){}


	float ManhattanDistance(Cell *cell)
	{
		float x = (float)(fabs((float)(this->x - cell->x)));
		float y = (float)(fabs((float)(this->y - cell->y)));
		return x + y;
	}
	Cell *last;
};

#endif