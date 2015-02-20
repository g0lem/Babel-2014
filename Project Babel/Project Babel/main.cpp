// Project Babel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void error_callback(int error, const char *description)
{
	fputs(description, stderr);
}

void key_callback(GLFWwindow* m_window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE)
		if (action == GLFW_PRESS)
			glfwSetWindowShouldClose(m_window, GL_TRUE);
}

int _tmain(int argc, char **argv)
{
	GLFWwindow* m_window;

	glfwSetErrorCallback(error_callback);

	glfwInit();
	m_window = glfwCreateWindow(1920, 1080, "GLFW app", glfwGetPrimaryMonitor(), NULL);

	glfwMakeContextCurrent(m_window);
	glfwSetKeyCallback(m_window, key_callback);
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(m_window))
	{
		int width, height;

		glfwGetFramebufferSize(m_window, &width, &height);

		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glBegin(GL_QUADS);
		glVertex2f(-1, -1);
		glVertex2f(-1, 0);
		glVertex2f(0, 0);
		glVertex2f(0, -1);

		glEnd();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	glfwDestroyWindow(m_window);
	glfwTerminate();

	return EXIT_SUCCESS;
}

