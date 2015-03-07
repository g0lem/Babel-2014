//Checked 1




#ifndef SCROLLER_HPP
#define SCROLLER_HPP



#include "controls.hpp"



class Scroller
{



	glm::vec2 offset;



public:


	inline Scroller(){ this->Init(); }


	inline ~Scroller(){ this->Clean(); }



	void Init();


	void Clean();



	void Enable(Controller * ctrl);




	inline glm::vec2 GetOffset(){ return this->offset; }



	inline void SetOffset(glm::vec2 offset){ this->offset = offset; }




};




#endif