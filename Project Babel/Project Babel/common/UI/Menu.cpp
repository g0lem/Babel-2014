#include <common.hpp>




void Menu::Init(char * vertex_shader, char * fragment_shader)
{



	this->BindCreate(vertex_shader, fragment_shader);



	this->backpack_sr = new BackpackSpriteRender();



	this->UnbindCreate();

}





void Menu::Render(Controller *ctrl,GameObject *g_obj)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	if (g_obj->GetUIState()->GetBackpackState()->GetState())
	this->backpack_sr->Render(ctrl, this->GetScreenPointer(), g_obj);



	this->UnbindRun();


}
