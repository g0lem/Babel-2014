//Checked 2014

#ifndef APPLICATION
#define APPLICATION


#include <GL/glew.h>
#include <glfw3.h>
#include "controls.hpp"
#include "text_render.hpp"
#include "2d.hpp"
#include "map.hpp"


class Application
{


	GLFWwindow* window;


	Controller * ctrl;

	Map*map;

	TextRender *tr;


	Aaether2D * aa_render;



public:

	inline Application() { this->Init(); }


	inline ~Application() { this->Terminate(); }


	int Init();


	void SetFlags();


	void Load();


	void Render();


	void Terminate();


};

#endif