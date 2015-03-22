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
	Animation *walk_animation;




	PhysicalAttributes * attributes;
	Stats * m_stats;
	GLboolean attacking;
	GLint target;





	glm::vec2 last_wanted_position;
	Item **items;





	void HandleAutoPath(Controller * ctrl, GameObject * g_obj);
	GLboolean CheckAdvance(Controller * ctrl, GameObject * g_obj);



	void LoadSprites();
	void LoadPhysicalAttributes(Map * current_tilemap);
	void LoadStats();
	void LoadItems(GameObject * g_obj);



	void UpdateUI(GameObject * g_obj);
	GLboolean HasMovedATile(Controller * ctrl);


public:





	void Load(GameObject * g_obj, Map * current_tilemap);
	void Render(Controller * ctrl, ScreenUniformData *u_data, GameObject * g_obj, Map * current_map);
	inline GLboolean GetAttackingState(){ return this->attacking; }
	inline void SetAttackingState(GLboolean attacking){ this->attacking = attacking; }
	inline GLint GetTarget(){ return this->target; }
	inline void SetTarget(GLint target){ this->target = target; }
	inline PhysicalAttributes*GetPAttributes(){ return this->attributes; }
	inline Stats * GetStats(){ return this->m_stats; }
	inline Item**GetItems(){ return this->items; }
	inline Direction * GetDirection(){ return this->m_dir; }


};







#endif



