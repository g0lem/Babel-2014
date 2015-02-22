#include <GL/glew.h>
#include <glfw3.h>
#include "common/controls.hpp"
#include "common/text_render.hpp"
#include "common/application.hpp"

int main(int argc, char *argv[])
{



	Application*app = new Application();


	app->SetFlags();


	app->Load();


	app->Render();


	delete app;


	return 0;



}
