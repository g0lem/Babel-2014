#include <common.hpp>




#define BACKPACK_KEY GLFW_KEY_C




void UIState::Init()
{



	this->state = false;


	this->b_state = new BackpackState();



}



void UIState::ProcessKeys(Controller * ctrl)
{


	if (ctrl->GetKeyOnce(BACKPACK_KEY))
		this->b_state->SetState(!this->b_state->GetState());


}



void UIState::Update(Controller * ctrl)
{


	this->ProcessKeys(ctrl);


	this->state = this->b_state->GetState();


}
