//Checked 1


#ifndef CONTROLS_HPP
#define CONTROLS_HPP




#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <time.h>
#include <stdio.h>
#include <cstring>





#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



typedef char GLchar;




class FPS
{


	GLfloat fps;


	GLint frames;


	GLdouble lastTime;


	GLdouble lastTime2;


	GLdouble deltaTime, returnable_deltaTime;






public:




	inline GLfloat Get() { return fps; }

	inline GLdouble Delta() { return this->returnable_deltaTime; }


	void FirstPass();

	void Compute();



};



class Controller
{


	static GLFWwindow* window;


	//Window info

	static GLint window_width, window_height;
	static GLboolean fullscreen;
	static GLchar * title;
	static GLuint opengl_major_version;
	static GLuint opengl_minor_version;


	//---


	FPS * fps;




	static GLvoid key_callback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mods);
	static GLuint keys[512];
	static GLuint keys1[512];
	static GLuint fullscreen_key;



	static void mouse_callback(GLFWwindow* window, GLint button, GLint action, GLint mods);
	static glm::vec2 mouse_position;
	static GLuint mouse_buttons[8];


	static void cursor_callback(GLFWwindow* window, GLdouble x, GLdouble y);



	static void InitCallbacks();


public:




	
	inline GLuint GetKey(GLuint code){ return Controller::keys1[code]; }



	inline GLuint GetKeyOnce(GLuint code){ GLuint result = (Controller::keys[code] == 1); Controller::keys[code]++; return result; }



	inline glm::vec2 GetMousePosition(){ return Controller::mouse_position; }



	inline GLuint GetMouseButton(GLuint code){ return Controller::mouse_buttons[code]; }



	inline GLuint GetMouseButtonOnce(GLuint code){ GLuint result = (Controller::mouse_buttons[code] == 1); Controller::mouse_buttons[code]++; return result; }



	inline FPS*GetFpsPointer(){ return this->fps; }



	inline GLint GetWindowWidth(){ return this->window_width; }


	
	inline GLint GetWindowHeight(){ return this->window_height; }



	inline void SetFullscreenKey(GLuint key){ this->Controller::fullscreen_key = key; }



	inline GLFWwindow * GetWindow(){ return this->window; }



	inline Controller() { this->Init(); }



	inline GLfloat returnFps(){ return this->fps->Get(); }



	static GLboolean CreateWindow(GLuint window_width, GLuint window_height,
		GLboolean fullscreen,
		char * title,
		GLuint opengl_major_version,
		GLuint opengl_minor_version);






	void Init();





	void Enable();




	void Clean();


	inline  ~Controller(){ this->Clean(); }
	

};




#endif