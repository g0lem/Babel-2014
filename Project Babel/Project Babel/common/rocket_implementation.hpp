#ifndef ROCKET_IMPLEMENTATION_HPP
#define ROCKET_IMPLEMENTATION_HPP


#include "rocket_manager.hpp"
#include "controls.hpp"
#include <ShellFileInterface.h>


class RocketImplementation
{



	RocketManager * r_manager;



public:


	inline RocketImplementation(Controller * ctrl){this->Init(ctrl); }



	void Init(Controller * ctrl);


	void Render(Controller * ctrl);


};




#endif