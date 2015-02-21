#ifndef SIMPLE_2D_HPP
#define SIMPLE_2D_HPP


#include <GL/glew.h>
#include "shader.hpp"
#include "sprite.hpp"



class Aaether2D
{


	Sprite * m_sprite;


	GLuint texID;


	GLuint program;


	GLuint m_VAO;


	
public:



	inline Aaether2D(){this->Init(); }


	void Init();



	void Render();


};



#endif