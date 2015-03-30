#pragma once
class fog_of_war
{
	int **s_map;
	Sprite *m_sprite;
	void Advance(GameObject *g_obj);
	void SetUpSprite(float &alpha, int i, int j, ScreenUniformData *u_data);
public:
	void Init(GameObject *g_obj);
	void GetFOW(GameObject *g_obj, glm::ivec2 position);
	void Render(ScreenUniformData *u_data, Controller *ctrl, GameObject *g_obj, glm::vec2 position);
};

