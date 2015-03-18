#include <common.hpp>


void MenuItem::Init()
{
	BindCreate("data/shaders/2d_vert.txt","data/shaders/2d_frag.txt");

	this->num_items = 2;

	this->m_items = new std::vector<Mitem*>;

	char ** tex_str = new char*[num_items];

	tex_str[0] = "box.png";
	tex_str[1] = "circle.png";

	for (int index = 0; index < this->num_items; index++)
		m_items->at(index)->sprite->Load("data/UI/", tex_str[index]);



	UnbindCreate();
}



void MenuItem::Render(Controller *ctrl, ScreenUniformData *u_data, GameObject *g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight);


	for (int index = 0; index < this->num_items; index++)
	{




		this->m_items->at(index)->sprite->Render(0);

	}

	



	this->UnbindRun();


}



void MenuItem::AddRect()
{



}
