#pragma once

class polygon{

	struct p_item{
		int id;
		glm::vec2 position;
		int num_faces;
		GLuint texture;
		float radius;
	};

	struct n_item{
		int id;
		glm::vec2 position;
		int width, height;
		char *texture;
	};

	std::vector<p_item*> *r_list;
	std::vector<n_item*> *n_list;

	GLuint m_vbo;

public:


	inline polygon(){ this->Init(); }

	inline ~polygon(){ this->Clean(); }

	void Init();



	void GeneratePolygon(int index);


	void loadbuffer();




	void LoadPolygon();

	void LoadRect();

	void Clean();

	
};