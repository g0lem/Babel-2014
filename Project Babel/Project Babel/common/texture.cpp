//Checked 2014

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <glfw3.h>
#include <assert.h>
#include "texture.hpp"
#include <fstream>


#define ANISO 4.0f



FIBITMAP *get_dib(char* file)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP *dib(0);
	fif = FreeImage_GetFileType(file, 0);
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(file);
	if (fif == FIF_UNKNOWN)
		return NULL;
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, file);
	if (!dib)
		return NULL;
	FreeImage_FlipVertical(dib);
	return dib;
}

GLuint load_texture(char* file, GLint param)
{
	BYTE* bits(0);
	unsigned int width(0), height(0);
	GLuint gl_texID;
	FIBITMAP *dib = get_dib(file);
	if (!dib)
		return -1;
	bits = FreeImage_GetBits(dib);
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	if ((bits == 0) || (width == 0) || (height == 0))
		return -1;
	glGenTextures(1, &gl_texID);
	glBindTexture(GL_TEXTURE_2D, gl_texID);
	if (FreeImage_GetBPP(dib) == 24){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, bits);
	}
	else if (FreeImage_GetBPP(dib) == 32){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bits);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, param);
	glBindTexture(GL_TEXTURE_2D,0);
	FreeImage_Unload(dib);
	return gl_texID;
}

GLuint create_texture_from_color(GLfloat r, GLfloat g, GLfloat b){
	GLuint gl_texID;
	BYTE * bits = new BYTE[3];
	bits[0] = (r * 255);
	bits[1] = (g * 255);
	bits[2] = (b * 255);
	glGenTextures(1, &gl_texID);
	glBindTexture(GL_TEXTURE_2D, gl_texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, bits);
	glBindTexture(GL_TEXTURE, 0);
	delete bits;
	return gl_texID;
}

GLuint load_cube_texture(const char *Directory,
	const char *PosXFilename,
	const char *NegXFilename,
	const char *PosYFilename,
	const char *NegYFilename,
	const char *PosZFilename,
	const char *NegZFilename)
{

	std::string files[6];
	files[0] += Directory;
	files[0] += PosXFilename;
	files[1] += Directory;
	files[1] += NegXFilename;
	files[2] += Directory;
	files[2] += PosYFilename;
	files[3] += Directory;
	files[3] += NegYFilename;
	files[4] += Directory;
	files[4] += PosZFilename;
	files[5] += Directory;
	files[5] += NegZFilename;

	FIBITMAP * dib(0);
	BYTE* bits(0);
	unsigned int width(0), height(0);
	GLuint gl_texID;

	glGenTextures(1, &gl_texID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, gl_texID);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	for (int i = 0; i<6; i++) {
		std::vector<char> writable(files[i].begin(), files[i].end());
		writable.push_back('\0');
		dib = get_dib(&writable[0]);
		bits = FreeImage_GetBits(dib);
		width = FreeImage_GetWidth(dib);
		height = FreeImage_GetHeight(dib);
		if ((bits == 0) || (width == 0) || (height == 0))
			return -1;
		if (FreeImage_GetBPP(dib) == 24){
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT + i, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, bits);
		}
		else if (FreeImage_GetBPP(dib) == 32)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT + i, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bits);
		}
		FreeImage_Unload(dib);
	}
	glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	return gl_texID;
}

GLuint create_texture_array(char *Directory, char ** textures, GLuint num)
{
	GLuint gl_texID(0), width(0), height(0);
	FIBITMAP ** dibs = 0;
	BYTE ** bits = 0;
	dibs = new FIBITMAP*[num];
	bits = new BYTE*[num];
	for (GLuint i = 0; i < num; i++){
		std::string file_path = std::string(std::string(Directory) + std::string(textures[i]));
		std::vector<char> writable(file_path.begin(), file_path.end());
		writable.push_back('\0');
		dibs[i] = get_dib(&writable[0]);
		assert(dibs[i]);
		bits[i] = FreeImage_GetBits(dibs[i]);
	}

	width = FreeImage_GetWidth(dibs[0]);
	height = FreeImage_GetHeight(dibs[0]);


	glGenTextures(1, &gl_texID);
	glBindTexture(GL_TEXTURE_2D_ARRAY, gl_texID);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAX_ANISOTROPY_EXT, ANISO);


	glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, width, height, num, 0, GL_BGRA, GL_UNSIGNED_BYTE, 0);


	for (GLuint i = 0; i < num; i++)
			glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, width, height, 1, GL_BGRA, GL_UNSIGNED_BYTE, bits[i]);


	glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
	glBindTexture(GL_TEXTURE_2D_ARRAY, 0);

	for (GLuint i = 0; i < num; i++)
		FreeImage_Unload(dibs[i]);

	return gl_texID;
}


bool readRawFile(char* path, BYTE*bits)
{

	std::ifstream inputFile(path, std::ios::binary);

	int size = getRawSize(path);

	for (int j = size - 1; j >= 0; j--)
	{


		for (int i = 0; i < size; i++)

		{

			int current_index = j*size + i;
			int current_index2 = (size - 1 - j)*size + i;

			inputFile.seekg(current_index * 2 + 0, std::ios::beg);
			bits[current_index2 * 2 + 0] = inputFile.get();
			inputFile.seekg(current_index*2 + 1, std::ios::beg);
			bits[current_index2*2 + 1] = inputFile.get();

		}

	}

	inputFile.close();


	return true;
}


int getRawSize(char * path)
{

	std::ifstream inputFile(path, std::ios::binary);


	int size;


	inputFile.seekg(0, std::ios::end);

	if (!POWER_OF_TWO(int(sqrt((long)inputFile.tellg()))-1))
		size = sqrt((long)inputFile.tellg() / 2);
	else
		size = sqrt((long)inputFile.tellg());

	inputFile.close();

	return size;

}