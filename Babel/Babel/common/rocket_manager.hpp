#ifndef ROCKET_MANAGER_HPP
#define ROCKET_MANAGER_HPP



#include <Rocket/Core.h>
#include <GL/glew.h>
#include "controls.hpp"
#include "shader.hpp"


#define POSITION_LOCATION 0
#define TEXCOORD_LOCATION 1
#define COLOR_LOCATION 2



#define ARRAY_SIZE_IN_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))





class RocketSystemManager : public Rocket::Core::SystemInterface
{




	virtual float GetElapsedTime();


	virtual bool LogMessage(Rocket::Core::Log::Type type, const Rocket::Core::String& message);


};




class RocketRenderManager : public Rocket::Core::RenderInterface
{





	enum m_VBOs
	{

		INDEX_BUFFER,
		POS_VBO,
		TEX_VBO,
		COL_VBO,
		NUM_VBS



	};


	GLuint m_VBOs[NUM_VBS];


	GLuint m_VAO;


	GLuint m_program;


	GLuint offset_uniform_location, textureID;


	Controller * ctrl;


	virtual void RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, 
		int* indices, int num_indices, Rocket::Core::TextureHandle texture, 
		const Rocket::Core::Vector2f& translation);


	virtual void EnableScissorRegion(bool enable);


	virtual void SetScissorRegion(int x, int y, int width, int height);



	virtual bool LoadTexture(Rocket::Core::TextureHandle& texture_handle,
		Rocket::Core::Vector2i& texture_dimensions,
		const Rocket::Core::String& source);


	virtual bool GenerateTexture(Rocket::Core::TextureHandle& texture_handle,
		const Rocket::Core::byte* source,
		const Rocket::Core::Vector2i& source_dimensions);


	virtual void ReleaseTexture(Rocket::Core::TextureHandle texture_handle);


public:


	inline RocketRenderManager(Controller * ctrl, char * vertex_shader, char * fragment_shader){ this->Init(ctrl, vertex_shader, fragment_shader); }


	void Init(Controller * ctrl, char * vertex_shader, char * fragment_shader);


};



class RocketManager
{


	RocketSystemManager * m_system;


	RocketRenderManager * m_render;



public:


	inline RocketManager(Controller * ctrl, char * vertex_shader, char*fragment_shader){ this->Install(ctrl, vertex_shader, fragment_shader); }


	void Install(Controller * ctrl, char * vertex_shader, char*fragment_shader);

};



#endif