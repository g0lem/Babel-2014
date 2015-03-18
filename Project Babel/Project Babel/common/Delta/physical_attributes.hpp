#ifndef PHYSICAL_ATTRIBUTES_HPP
#define PHYSICAL_ATTRIBUTES_HPP



class PhysicalAttributes
{


public:



	glm::vec2 position;
	glm::vec2 target;
	glm::vec2 scale;
	GLfloat speed;
	GLfloat rotation_angle;


	inline PhysicalAttributes(){ this->Init(); }


	void Init();


};




#endif