//1




#ifndef APPLICATION
#define APPLICATION




class Application : private Controller
{



	GameRender * g_render;


	GameObject * g_object;

	SoundManager * sound_m;


	UIHandler * ui;



public:




	inline Application() { this->Init(); }



	inline ~Application() { this->Terminate(); }


	void Init();



	void Run();


	void Terminate();


};

#endif