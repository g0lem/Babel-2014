#include "rocket_manager.hpp"



float RocketSystemManager::GetElapsedTime()
{



	return glfwGetTime();



}



void RocketManager::Install()
{


	m_system = new RocketSystemManager();


	Rocket::Core::SetSystemInterface(m_system);




}




void RocketRenderManager::Init()
{


	glGenVertexArrays(1, &this->m_VAO);
	glBindVertexArray(this->m_VAO);
	glGenBuffers(ARRAY_SIZE_IN_ELEMENTS(m_VBOs), m_VBOs);
	glBindVertexArray(0);


}


void RocketRenderManager::RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation)
{


	


	std::vector<Rocket::Core::Vector2f> Positions(num_vertices);
	std::vector<Rocket::Core::Colourb> Colors(num_vertices);
	std::vector<Rocket::Core::Vector2f> TexCoords(num_vertices);



	for (int i = 0; i < num_vertices; i++)
	{
		Positions[i] = vertices[i].position;
		Colors[i] = vertices[i].colour;
		TexCoords[i] = vertices[i].tex_coord;
	};


	glBindVertexArray(this->m_VAO);


	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBOs[POS_VBO]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Positions), &Positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(POSITION_LOCATION);
	glVertexAttribPointer(POSITION_LOCATION, 2, GL_FLOAT, GL_FALSE, 0, 0);



	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBOs[TEX_VBO]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(TexCoords), &TexCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(TEXCOORD_LOCATION);
	glVertexAttribPointer(TEXCOORD_LOCATION, 2, GL_FLOAT, GL_FALSE, 0, 0);


	glBindBuffer(GL_ARRAY_BUFFER, this->m_VBOs[COL_VBO]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), &Colors[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(COLOR_LOCATION);
	glVertexAttribPointer(COLOR_LOCATION, 4, GL_FLOAT, GL_FALSE, 0, 0);




	glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, indices);


	glBindVertexArray(0);

}