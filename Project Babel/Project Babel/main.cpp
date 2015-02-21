#include <GL/glew.h>
#include <glfw3.h>
#include "common/controls.hpp"
#include "common/text_render.hpp"
#include "common/application.hpp"

void glEnable2D(void)
{
	GLint iViewport[4];

	glGetIntegerv(GL_VIEWPORT, iViewport);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	glOrtho(iViewport[0], iViewport[0] + iViewport[2], iViewport[1] + iViewport[3], iViewport[1], -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
}

void glDisable2D(void)
{
	glPopAttrib();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void InitScene(void)
{
	if (!glh_extension_supported("GL_NV_texture_rectangle"))
	{

	}
}

int main(int argc, char *argv[])
{
	Application*app = new Application();

	app->SetFlags();
	app->Load();
	app->Render();

	delete app;

	return 0;
}
