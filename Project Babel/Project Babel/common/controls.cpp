//Checked 2014
//DELETE FUNCTION TO BE DONE


#include "controls.hpp"







void Controller::Init(GLFWwindow*wnd, GLint width, GLint height)
{


	this->window = wnd;


	this->width = width;


	this->height = height;




	this->fps = new FPS();




	


}






void Controller::Clean()
{



	delete this->fps;

}



void Controller::ProcessInput(GLfloat deltaTime)
{



}








void Controller::Enable()
{



	this->fps->FirstPass();


	this->ProcessInput(this->fps->Delta());





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


