#include "font_manager.hpp"


void FontManager::Init()
{


	this->BindCreate("data/shaders/text_vert.txt", "data/shaders/text_frag.txt");


	this->font = new Font();

	this->font->Create("data/fonts/choco.ttf", 48);



	this->UnbindCreate();



}



void FontManager::Clean()
{


	TextRender::Clean();

	this->font->Clean();


}




void FontManager::Render(Controller * ctrl)
{


	this->BindRun(ctrl->GetWindowWidth(), ctrl->GetWindowHeight());


	this->SetColor(1.0f, 1.0f, 1.0f);

	sprintf(this->text, "FPS:%.2f", ctrl->returnFps());
	this->font->Print(this->text, 0, 600, 40);


	this->UnbindRun();


}