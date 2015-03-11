//Checked 1



#ifndef SPRITE_HPP
#define SPRITE_HPP


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include "texture.hpp"


class Sprite
{


	GLuint *textures;

	GLuint num_textures;


	GLuint m_VBO;


public:


	void Load(GLuint num_textures, char * dir, char **textures_str);

	

	void Render(GLuint current_frame);



};




#endif