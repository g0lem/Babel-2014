#include "uniform_2d.hpp"



void ScreenUniformData::Init(GLuint program)
{


	this->TransformMatrix = glGetUniformLocation(program, "TransformMatrix");



}



