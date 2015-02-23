#ifndef SIMPLE_2D_HPP
#define SIMPLE_2D_HPP


#include <GL/glew.h>
#include "shader.hpp"
#include "sprite.hpp"
#include "uniform_2d.hpp"
#include "2d_math.hpp"
#include "controls.hpp"
#include "map.hpp"


class Aaether2D
{

	ScreenUniformData * u_data;


	Sprite * m_sprite;

	Map* m_map;

	GLuint texID;


	GLuint ortho;


	GLuint program;


	GLuint m_VAO;


	void Ortho(GLuint window_width, GLuint window_height);


	void FirstPass(Controller * ctrl);


	void LastPass();

	
public:



	inline Aaether2D(){this->Init(); }


	void Init();




	void Render(Controller*ctrl);


};



#endif