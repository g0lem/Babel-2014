#include <common.hpp>




#define BACKPACK_KEY GLFW_KEY_I




void UIState::Init()
{



	this->opened = false;


	this->b_state = new BackpackState();



}



void UIState::ProcessKeys(Controller * ctrl)
{


	if (ctrl->GetKeyOnce(BACKPACK_KEY))
		this->b_state->SetOpended(!this->b_state->GetOpened());


}



void UIState::Update(Controller * ctrl)
{


	this->ProcessKeys(ctrl);


	this->opened = this->b_state->GetOpened();


}
