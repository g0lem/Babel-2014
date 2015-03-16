#include <common.hpp>

void polygon::Init()
{


	this->r_list = new std::vector <p_item*>;
	this->n_list = new std::vector <n_item*>;

	this->LoadPolygon();
}

void polygon::loadbuffer()
{
	float buffer[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
	};

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), &buffer, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void polygon::GeneratePolygon(int index)
{

	glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->r_list->at(index)->texture);
	glDrawArrays(GL_TRIANGLES, 0, this->r_list->at(index)->num_faces*2);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}




void polygon::LoadPolygon()
{

	p_item * t_item = new p_item;
	Player *t_player = new Player;


	t_item->id = 0;
	t_item->position = glm::vec2(0.f, 0.f);
	t_item->num_faces = 3;
	t_item->texture = NULL;
	t_item->radius = 20.f;

	r_list->push_back(t_item);

}

void polygon::LoadRect()
{

	n_item * t_item = new n_item;

	t_item->id = 0;
	t_item->position = glm::vec2(20.f, 20.f);
	t_item->width = 20;
	t_item->height = 10;
	t_item->texture = NULL;

	n_list->push_back(t_item);


}


void polygon::Clean()
{

	delete this->r_list;

	delete this->n_list;

}