#ifndef STATS_HPP
#define STATS_HPP


class Stats
{


	Hp * m_hp;


public:



	inline  Hp * GetHp(){ return this->m_hp; }


	inline Stats(){ this->Init(); }



	void Init();



};




#endif