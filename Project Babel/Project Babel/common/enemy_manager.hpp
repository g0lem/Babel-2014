#ifndef ENEMY_MANAGER_HPP
#define ENEMY_MANAGER_HPP



#include "enemy.hpp"
#include "2d_math.hpp"




class EnemyManager
{
	


	std::vector<Enemy*>*m_enemies;



	void CheckEnemiesState(GameObject * g_obj);


	void Kill(GameObject * g_obj, GLuint enemy_id);



public:



	void Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj);



	inline EnemyManager(GLuint num, Map *map){ this->Init(num, map); }



	void Init(GLuint num, Map * map);



	inline std::vector<Enemy*>*GetEnemiesPointer(){ return this->m_enemies; }



};




#endif


