#ifndef METH_2D_HPP
#define METH_2D_HPP


#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#ifndef M_PI
#define M_PI 3.14159265358979
#endif


#ifndef TO_RADIANS(a)
#define TO_RADIANS(a) a/180.0 * M_PI
#endif



glm::mat3 Translation(GLfloat x, GLfloat y);


inline glm::mat3 Translation(glm::vec2 t_vec){return Translation(t_vec.x, t_vec.y); }


glm::mat3 Scale(GLfloat x_scale, GLfloat y_scale);


inline glm::mat3 Scale(GLfloat scale){return Scale(scale, scale); }


inline glm::mat3 Scale(glm::vec2 scale){ return Scale(scale.x, scale.y); }


glm::mat3 Rotation(GLfloat alpha);


inline glm::mat3 Shaorma(glm::vec2 pos, glm::vec2 scale, GLfloat alpha)
{
	return Translation(pos)*Rotation(TO_RADIANS(alpha))*Translation(-scale / 2.0f)*Scale(scale); 
}


#endif