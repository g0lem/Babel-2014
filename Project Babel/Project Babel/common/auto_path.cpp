#include "auto_path.hpp"



void AutoPath::Init()
{


	this->m_path = new Pathfinder();


	this->path_length = 0;

	
	this->current_step = 0;



}