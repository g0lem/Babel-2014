//Checked 2014


#include <common.hpp>

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640



void Application::Init()
{




    this->CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
		false,
		"Project Babel 0.1.0a",
		4, 0);



	g_object = new GameObject();

	p_gon = new polygon();

	sound_m = new SoundManager();

	f_manager = new FontManager();

	s_manager = new SpriteManager(g_object);





	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


}



void Application::Run()
{


	this->sound_m->PlayMusic("Green Hills");

	this->sound_m->setMusicLoop("Green Hills", true);



	do{


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		this->Enable();



		s_manager->Render(this, this->g_object);



		f_manager->Render(this);


		p_gon->GeneratePolygon(0);


		glfwSwapBuffers(this->GetWindow());
		glfwPollEvents();



	} while (!this->GetKey(GLFW_KEY_ESCAPE) &&
		glfwWindowShouldClose(this->GetWindow()) == 0);


}


void Application::Terminate()
{



	delete s_manager;
	delete f_manager;
	delete g_object;
	
	delete sound_m;

}




