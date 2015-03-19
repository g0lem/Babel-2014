#pragma once





class Menu : public Aaether2D
{


	BackpackSpriteRender * backpack_sr;

	ActionSpriteRender * action_sr;

	public:


		
		inline Menu(char * vertex_shader, char * fragment_shader){ this->Init(vertex_shader, fragment_shader); }



		void Init(char * vertex_shader, char * fragment_shader);



		void Render(Controller *ctrl, GameObject *g_obj);





	};
