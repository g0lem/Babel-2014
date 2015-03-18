//1

#ifndef APPLICATION
#define APPLICATION




class Application : private Controller
{



	FontManager*f_manager;

	SpriteManager * s_manager;


	GameObject * g_object;

	SoundManager * sound_m;



public:




	inline Application() { this->Init(); }



	inline ~Application() { this->Terminate(); }


	void Init();



	void Run();


	void Terminate();


};

#endif