#ifndef ROCKET_MANAGER_HPP
#define ROCKET_MANAGER_HPP



#include <Rocket/Core.h>
#include <GL/glew.h>
#include "controls.hpp"



#define POSITION_LOCATION 0
#define TEXCOORD_LOCATION 1
#define COLOR_LOCATION 2



#define ARRAY_SIZE_IN_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))





class RocketSystemManager : public Rocket::Core::SystemInterface
{




	virtual float GetElapsedTime();


};




class RocketRenderManager : public Rocket::Core::RenderInterface
{





	enum m_VBOs
	{

		POS_VBO,
		TEX_VBO,
		COL_VBO



	};


	GLuint m_VBOs[3];


	GLuint m_VAO;


	virtual void RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation);


	inline RocketRenderManager(){ this->Init(); }


	void Init();


};



class RocketManager
{


	RocketSystemManager * m_system;



public:


	inline RocketManager(){ this->Install(); }


	void Install();

};



#endif