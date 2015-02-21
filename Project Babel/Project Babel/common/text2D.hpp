//Checked 2014

#ifndef TEXT2D_HPP
#define TEXT2D_HPP

#include <vector>
#include <cstring>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

class _Text
{


	GLuint Text2DTextureID;
	GLuint Text2DVertexBufferID;
	GLuint Text2DUVBufferID;

	inline GLint next_p2(int a)
	{
		GLint rval = 1;

		while (rval<a) rval <<= 1;
		return rval;
	}


public:


	void initText2D(char * texturePath);
	void printText2D(const char * text, int x, int y, int size);
	void cleanupText2D();




};

#endif