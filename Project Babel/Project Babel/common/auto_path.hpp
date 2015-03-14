#ifndef AUTO_PATH_HPP
#define AUTO_PATH_CPP





#include "pathfinder.hpp"
#include "2d_math.hpp"





class AutoPath
{


	Pathfinder * m_path;


	GLuint path_length;


	GLuint current_step;



	std::vector<glm::vec2> path;




public:


	inline AutoPath(){ this->Init(); }



	inline Pathfinder*GetPathfinder(){ return this->m_path; }



	inline void Reset(){ this->current_step = 0; this->path_length = 0; }



	inline void Advance(){ this->current_step++; }



	inline void SetPath(std::vector<glm::vec2> path){ this->path = path; this->path_length = this->path.size(); }

	

	inline glm::vec2 GetStep(){ return this->path[this->current_step]; }



	inline GLuint GetCurrentID(){ return this->current_step; }



	inline GLboolean Finished(){ return this->current_step >= this->path_length; }



	inline GLboolean IsSet(){ return this->path_length > 0; }



	void Init();






};



#endif