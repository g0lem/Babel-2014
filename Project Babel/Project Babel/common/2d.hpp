#ifndef SIMPLE_2D_HPP
#define SIMPLE_2D_HPP


#include <GL/glew.h>
#include "shader.hpp"
#include "map.hpp"
#include "player.hpp"


class Aaether2D 
{


	//mess it up!


	Map * m_map;


	Player * m_player;


	//things not to mess up with

	ScreenUniformData * u_data;

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



	void Load();



	void Render(Controller*ctrl);


};



#endif