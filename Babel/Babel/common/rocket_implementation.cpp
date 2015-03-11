#include "rocket_implementation.hpp"



void RocketImplementation::Init(Controller * ctrl)
{


	r_manager = new RocketManager(ctrl, "data/shaders/rocket_vert.txt", "data/shaders/rocket_frag.txt");


	ShellFileInterface FileInterface("data/ui/");


	Rocket::Core::SetFileInterface(&FileInterface);



	Rocket::Core::FontDatabase::LoadFontFace("Delicious-Bold.otf");
	Rocket::Core::FontDatabase::LoadFontFace("Delicious-BoldItalic.otf");
	Rocket::Core::FontDatabase::LoadFontFace("Delicious-Italic.otf");
	Rocket::Core::FontDatabase::LoadFontFace("Delicious-Roman.otf");


 
	
	Rocket::Core::Context*Context = Rocket::Core::CreateContext("default",
		Rocket::Core::Vector2i(ctrl->GetWindowWidth(), ctrl->GetWindowHeight()));



	Rocket::Core::ElementDocument *Document = Context->LoadDocument("demo.rml");

	if (Document)
	{
		Document->Show();
		Document->RemoveReference();
	};


}



void RocketImplementation::Render(Controller * ctrl)
{




}