#include <common.hpp>



void AutoPath::Init()
{


	this->m_path = new Pathfinder();


	this->path_length = 0;

	
	this->current_step = 0;



}



void AutoPath::Start(GameObject * g_obj, glm::vec2 start, glm::vec2 end)
{


	this->GetPathfinder()->Init(g_obj, start, end);


	this->Reset();


	if (this->GetPathfinder()->GetPathFound())
	{


		this->SetPath(this->GetPathfinder()->GetPath());


		this->Advance();



	}


}