#ifndef ANIMATION_HPP
#define ANIMATION_HPP


#include "2d_math.hpp"


class Animation
{


	GLfloat frames;




	GLuint num_frames;




public:


	inline GLfloat GetFrames(){ return this->frames; }
	inline GLuint GetIFrames(){ return GLuint(this->frames); }
	inline GLuint GetNumFrames(){ return this->num_frames; }

	inline Animation(GLuint num_frames){ this->Init(num_frames); }


	void Init(GLuint num_frames);


	void Update(GLfloat speed, GLfloat delta);


};







#endif