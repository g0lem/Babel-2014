#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "controls.hpp"
#include "text_render.hpp"
#include "text2D.hpp"


class FontManager : private TextRender
{


	char text[256];


	Font * font;


public:


	inline FontManager(){ this->Init(); }


	inline ~FontManager(){ this->Clean(); }

	
	void Init();


	void Render(Controller * ctrl);


	void Clean();


};



#endif