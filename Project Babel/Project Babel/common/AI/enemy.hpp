#ifndef ENEMY_HPP
#define ENEMY_HPP





class Enemy
{


	Stats * m_stats;
	PhysicalAttributes * p_attributes;
    Sprite ** m_sprites;
	AutoPath * a_path;


	glm::vec2 last_position;
	glm::vec2 target_position;
	GLint target;


	TurnSystem * turn_system;


	void LoadSprites(EnemyData * data);
	void LoadStats(EnemyData*data);
	void LoadPhysicalAttributes();


	void RenderMisc(ScreenUniformData * u_data, GameObject * g_obj);
	void RenderHpBar(ScreenUniformData * u_data, GameObject * g_obj);


	void HandleAutoPath(Controller * ctrl, GameObject * g_obj);


public:



	inline GLint GetTarget(){ return this->target; }
	inline void SetTarget(GLint target){ this->target = target; }


	inline glm::vec2 GetLastPosition(){ return this->last_position; }
	inline glm::vec2 GetTargetPosition(){ return this->target_position; }
	inline void SetTargetPosition(glm::vec2 target_position){ this->target_position = target_position; }



	inline Stats*GetStats(){ return this->m_stats; }
	inline PhysicalAttributes*GetPAttributes(){ return this->p_attributes; }
	inline TurnSystem * GetTurnSystem(){ return this->turn_system; }


	inline Enemy(EnemyData * data){ this->Init(data); }
	void Init(EnemyData * data);


	void Render(Controller * ctrl, ScreenUniformData * u_data, GameObject * g_obj);
	void SetRandomPosition(Map * map);
	void Update(GameObject * g_obj, GLfloat delta);


};




#endif