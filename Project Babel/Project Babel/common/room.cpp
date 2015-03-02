#include "room.hpp"


void Room::d_Print()
{


	for (int j = 0; j < this->height; j++)
	{
		for (int i = 0; i < this->width; i++)
		{


			printf("%i ", tile_map[i][j]);


		}


		printf("\n");


	}

	printf("\n");


}



void Room::Create(glm::vec2 start_point, GLfloat width, GLfloat height)
{



	this->points[0] = start_point;
	this->points[1] = start_point + glm::vec2(width, height);


	this->center = GetCenter(this->points);

	this->width = width;
   
	this->height = height;


}


GLboolean Room::Intersects(Room * other)
{


	return (points[0].x < other->points[1].x &&
		points[1].x > other->points[0].x &&
		points[0].y < other->points[1].y &&
		points[1].y > other->points[0].y);
		


}



void Room::Transform(GLuint transform_flag)
{


	this->type = transform_flag;



	this->tile_map = new GLint*[this->width];
	for (GLuint i = 0; i < this->width; i++)
		this->tile_map[i] = new GLint[this->height];




	for (GLuint j = 0; j < this->height; j++)
	{


		for (GLuint i = 0; i < this->width; i++)


		{


			this->tile_map[i][j] = FLOOR_BLOCK;


		}



	}




	if (transform_flag == EMPTY_ROOM)
	{


		for (GLuint i = 0; i < this->width; i++)
		{
			this->tile_map[i][0] = STONE_BLOCK;
			this->tile_map[i][this->height - 1] = STONE_BLOCK;

		}



		for (GLuint j = 0; j < this->height; j++)
		{

			this->tile_map[0][j] = STONE_BLOCK;
			this->tile_map[this->width - 1][j] = STONE_BLOCK;

		}



	}


}




