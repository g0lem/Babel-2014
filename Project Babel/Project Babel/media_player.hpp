#ifndef MEDIA_PLAYER_HPP
#define MEDIA_PLAYER_HPP



class MediaPlayer
{







public:


	MediaPlayer(){ this->Init(); }


	~MediaPlayer(){ this->Clean(); }

	void Init();

	void Clean();

};

#endif