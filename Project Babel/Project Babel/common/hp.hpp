#ifndef HP_HPP
#define HP_HPP


#include "2d_math.hpp"




class Hp
{


public:


	GLuint hp;

	GLuint max_hp;


	inline Hp(){ this->Init(); }


	inline void Init(){ this->hp = 0; this->max_hp = 0; }


	inline void Buff(GLuint hp){ this->hp += hp; this->max_hp += hp; }


};




#endif