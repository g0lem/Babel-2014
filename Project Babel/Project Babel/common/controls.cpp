#include <GL/glew.h>
#include "controls.hpp"




GLboolean Controller::keys[] = { 0 };


GLuint Controller::fullscreen_key = 0;
GLboolean Controller::fullscreen = false;
GLint Controller::window_width = 0;
GLint Controller::window_height = 0;
GLchar *Controller::title = 0;
GLuint Controller::opengl_major_version = 0;
GLuint Controller::opengl_minor_version = 0;
GLFWwindow*Controller::window = 0;


GLboolean Controller::CreateWindow(GLuint window_width, GLuint window_height,
	GLboolean fullscreen,
	char * title,
	GLuint opengl_major_version,
	GLuint opengl_minor_version)
{



	if (Controller::window)
		glfwDestroyWindow(Controller::window);



	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}



	glfwWindowHint(GLFW_SAMPLES, 0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opengl_major_version);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opengl_minor_version);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	Controller::window_width = window_width;
	Controller::window_height = window_height;
	Controller::fullscreen = fullscreen;
	Controller::opengl_major_version = opengl_major_version;
	Controller::opengl_minor_version = opengl_minor_version;
	Controller::title = new GLchar[strlen(title)];
	strcpy(Controller::title, title);


	Controller::window = glfwCreateWindow(window_width, window_height,
		title, (fullscreen == true) ? glfwGetPrimaryMonitor() : NULL, NULL);




	if (Controller::window == NULL){
		fprintf(stderr, "Failed to open GLFW window!\n");
		glfwTerminate();
		return -1;
	}



	glfwMakeContextCurrent(Controller::window);
	glfwSwapInterval(1);


	glewExperimental = true;



	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}





	Controller::InitCallbacks();


}




void Controller::Init()
{


	srand(time(NULL));


	this->fps = new FPS();


	


}




void Controller::InitCallbacks()
{


	glfwSetKeyCallback(Controller::window, Controller::key_callback);


}




void Controller::Clean()
{




	delete this->fps;

	glfwDestroyWindow(this->window);
	glfwTerminate();


}








void Controller::Enable()
{



	this->fps->FirstPass();




	this->fps->Compute();




}

void FPS::FirstPass()
{



	GLdouble currentTime = glfwGetTime();

	deltaTime = returnable_deltaTime = GLfloat(currentTime - lastTime2);

	lastTime2 = glfwGetTime();



}



void FPS::Compute(){



	frames++;

	GLdouble currentTime = glfwGetTime();

	deltaTime = GLfloat(currentTime - lastTime);

	if (deltaTime > 1.0f){

		fps = GLfloat(frames) / deltaTime;

		lastTime = currentTime;

		frames = 0;

		lastTime = currentTime;
	}



}



GLvoid Controller::key_callback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mods)
{


	for (GLuint i = 0; i < 512; i++)
		Controller::keys[i] = (key == i && action>0);



}


