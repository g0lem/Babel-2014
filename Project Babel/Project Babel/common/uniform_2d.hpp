//Checked 1



#ifndef UNIFORM_2D_HPP
#define UNIFORM_2D_HPP


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>



class ScreenUniformData
{


	GLuint TransformMatrix;


public:


	inline ScreenUniformData(GLuint program){ this->Init(program); }


	void Init(GLuint program);


	
	inline void ApplyMatrix(glm::mat3 tr){ glUniformMatrix3fv(this->TransformMatrix, 1, GL_FALSE, &tr[0][0]); }



};




#endif