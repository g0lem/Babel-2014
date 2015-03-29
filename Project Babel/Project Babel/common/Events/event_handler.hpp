#pragma once




class EventHandler
{
	int **e_map;
	
	void Load(Map *current_map);
	void Door(glm::vec2 position, Map *current_map, GameObject *g_obj);
	void Health(glm::vec2 position, Map *current_map, Stats *m_stats);

public:
	void Init(Map *current_map);
	void TriggerEvent(glm::vec2 position, Map *current_map, GameObject *g_obj, Stats *m_stats);
    int **GetEventMapTiles(){ return this->e_map; }
	static void DisplayTablet(int id);

};

