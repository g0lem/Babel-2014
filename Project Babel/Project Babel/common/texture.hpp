//Checked 2014
//Need to improve Skybox

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <FreeImage.h>
#include <string>
#include <vector>



#define POWER_OF_TWO(x) ( (x > 0) && ((x & (x - 1)) == 0) ) 




GLuint load_texture(char* file, GLint param = GL_NEAREST);


GLuint load_cube_texture(const char *Directory,
	const char *PosXFilename,
	const char *NegXFilename,
	const char *PosYFilename,
	const char *NegYFilename,
	const char *PosZFilename,
	const char *NegZFilename);


GLuint create_texture_array(char *Directory, char ** textures, GLuint num);


GLuint create_texture_from_color(GLfloat r, GLfloat y, GLfloat z);



FIBITMAP *get_dib(char* file);


bool readRawFile(char*path, BYTE * bits);

int getRawSize(char*path);

#endif