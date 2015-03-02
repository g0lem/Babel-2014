//Checked 2014

#ifndef APPLICATION
#define APPLICATION


#include <GL/glew.h>
#include "controls.hpp"
#include "font_manager.hpp"
#include "sprite_manager.hpp"





class Application : private Controller
{



	FontManager*f_manager;


	SpriteManager * s_manager;



public:




	inline Application() { this->Init(); }



	inline ~Application() { this->Terminate(); }


	void Init();



	void Run();


	void Terminate();


};

#endif