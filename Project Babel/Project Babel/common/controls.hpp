//Checked 2014




#ifndef CONTROLS_HPP
#define CONTROLS_HPP



#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>






#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif





class FPS
{


	GLfloat fps;


	GLint frames;


	GLdouble lastTime;


	GLdouble lastTime2;


	GLdouble deltaTime;




public:




	inline GLfloat Get() { return fps; }

	inline GLdouble Delta() { return deltaTime; }

	void FirstPass();

	void Compute();



};



class Controller
{


	GLFWwindow* window;


	GLint width, height;





	FPS * fps;




public:





	inline GLint GetWindowWidth(){ return this->width; }


	
	inline GLint GetWindowHeight(){ return this->height; }



	inline GLFWwindow * GetWindow(){ return this->window; }


	inline Controller() {};


	inline Controller(GLFWwindow*wnd, GLint width, GLint height) { this->Init(wnd, width, height); }


	inline GLfloat returnFps(){ return this->fps->Get(); }


	void Init(GLFWwindow*wnd, GLint width, GLint height);




	void ProcessInput(GLfloat deltaTime);


	void Enable();




	void Clean();


	inline  ~Controller(){ this->Clean(); }
	

};




#endif