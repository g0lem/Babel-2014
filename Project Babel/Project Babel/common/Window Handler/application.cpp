//Checked 2014


#include <common.hpp>





#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640





void Application::Init()
{




    this->CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
		false,
		"Project Babel 0.1.5a",
		4, 0);





	g_object = new GameObject();

	sound_m = new SoundManager();

	g_render = new GameRender(g_object);


	ui = new UIHandler();


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


}



void Application::Run()
{
	

	this->sound_m->setMusicLoop("Green Hills", true);

	do{


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		this->Enable();

		
		g_render->Render(this, g_object);

		if (g_render->GetDrawCode() == true)
			ui->Render(this, g_object);



		g_object->GetUIState()->Update(this);
			
		

		glfwSwapBuffers(this->GetWindow());
		glfwPollEvents();



	} while (!this->GetKey(GLFW_KEY_ESCAPE) &&
		glfwWindowShouldClose(this->GetWindow()) == 0);


}


void Application::Terminate()
{



	delete g_render;
	delete g_object;
	delete sound_m;
	delete ui;



}




