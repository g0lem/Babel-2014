#include "one_direction.hpp"



void Direction::Init()
{



	this->last_dir = DIR_UP;



}


GLuint Direction::Compute(GLuint type, glm::vec2 position, glm::vec2 target)
{


	if (type == DIR_TYPE_4)
	{



		if (position == target)
			return this->last_dir;
		else
		{


			glm::vec2 dir = glm::normalize(target - position);

			if (!vec2_i(dir))
				return this->last_dir;

			else
			{


				print_vec2(dir);


			}


		}
		



	}
	else if (type == DIR_TYPE_8)
	{






	}



}