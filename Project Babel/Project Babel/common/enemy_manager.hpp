#ifndef ENEMY_MANAGER_HPP
#define ENEMY_MANAGER_HPP



#include "enemy.hpp"
#include "2d_math.hpp"




class EnemyManager
{
	


	std::vector<Enemy*>*m_enemies;




public:



	void Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_ocj);



	inline EnemyManager(GLuint num, Map *map){ this->Init(num, map); }



	void Init(GLuint num, Map * map);




};




#endif



