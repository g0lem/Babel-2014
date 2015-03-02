//Checked 2014
// Need to improve view distance


#include "application.hpp"




#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640



void Application::Init()
{




    this->CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
		false,
		"Project Babel 0.0.5a",
		4, 0);



	f_manager = new FontManager();


	s_manager = new SpriteManager();


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


}



void Application::Run()
{


	do{


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		this->Enable();



		s_manager->Render(this);



		f_manager->Render(this);



		glfwSwapBuffers(this->GetWindow());
		glfwPollEvents();



	} while (!this->GetKey(GLFW_KEY_ESCAPE) &&
		glfwWindowShouldClose(this->GetWindow()) == 0);


}


void Application::Terminate()
{



	delete s_manager;
	delete f_manager;


}




