//Checked 2014
// Need to improve view distance


#include "application.hpp"




#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600



int Application::Init()
{



	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}



	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);




	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 
		"Project Babel 0.01a", NULL, NULL);




	if (window == NULL){
		fprintf(stderr, "Failed to open GLFW window!\n");
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	glewExperimental = true;



	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}



}

void Application::SetFlags()
{


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);



}

void Application::Load()
{

	ctrl = new Controller(window, WINDOW_WIDTH, WINDOW_HEIGHT);



	tr = new TextRender(ctrl);


	aa_render = new Aaether2D();

	

}

void Application::Render()
{
	do{


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		ctrl->Enable();



		aa_render->Render(ctrl);



		tr->Render(ctrl);



		glfwSwapBuffers(window);
		glfwPollEvents();



	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);


}

void Application::Terminate()
{



	delete ctrl;
	delete aa_render;
	delete tr;


	glfwDestroyWindow(this->window);
	glfwTerminate();



}




