//Checked 1




#ifndef PLAYER_HPP
#define PLAYER_HPP



#define NO_TARGET -1
#define MIN_DISTANCE 2.0




class Player
{


	Direction * m_dir;


	AutoPath * a_path;



	Sprite ** m_sprite;


	PhysicalAttributes * attributes;


	Animation *walk_animation;



	GLboolean attacking;



	GLint target;



	Item **items;







	void Update(glm::vec2 & position, glm::vec2 target, GLfloat speed, GLfloat delta);


	void LoadSprites();


	void LoadPhysicalAttributes(Map * current_tilemap);


	void LoadItems(GameObject * g_obj);



	void HandleAutoPath(Controller * ctrl, GameObject * g_obj);



public:





	void Load(GameObject * g_obj, Map * current_tilemap);


	void Render(Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj, Map * current_map);


	inline GLboolean GetAttackingState(){ return this->attacking; }


	inline void SetAttackingState(GLboolean attacking){ this->attacking = attacking; }


	inline GLint GetTarget(){ return this->target; }


	inline void SetTarget(GLint target){ this->target = target; }


	inline PhysicalAttributes*GetPAttributes(){ return this->attributes; }


	inline Item**GetItems(){ return this->items; }


	inline Direction * GetDirection(){ return this->m_dir; }


};





#endif



