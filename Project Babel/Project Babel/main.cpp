//Checked 1



#include <GL/glew.h>
#include <glfw3.h>
#include "common/controls.hpp"
#include "common/text_render.hpp"
#include "common/application.hpp"

#include <SFML\System.hpp>
#include <SFML\Audio.hpp>


int main(int argc, char *argv[])
{


	Application*app = new Application();



	app->Run();


	delete app;

	


	return 0;



}
