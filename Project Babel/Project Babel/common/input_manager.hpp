#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "application.hpp"

class InputManager {
public:
	InputManager(Controller *ctrl) : m_renderWindow(ctrl) {
		std::fill(m_keys, m_keys + sf::Keyboard::KeyCount, false);
		std::fill(m_lastKeys, m_lastKeys + sf::Keyboard::KeyCount, false);
		std::fill(m_buttons, m_buttons + sf::Mouse::ButtonCount, false);
		std::fill(m_lastbuttons, m_lastbuttons + sf::Mouse::ButtonCount, false);
	}
	~InputManager(){}

	bool Capture(){
		memcpy(m_lastKeys, m_keys, sizeof(bool) * sf::Keyboard::KeyCount);
		memcpy(m_lastbuttons, m_buttons, sizeof(bool) * sf::Mouse::ButtonCount);
		sf::Event evt;
		while(m_renderWindow->pollEvent(evt)){
			switch(evt.type){
			case sf::Event::Closed:
				return false;
				break;
			case sf::Event::KeyPressed:
				m_keys[evt.key.code] = true;
				break;
			case sf::Event::KeyReleased:
				m_keys[evt.key.code] = false;
				break;
			case sf::Event::MouseButtonPressed:
				m_buttons[evt.key.code] = true;
			case sf::Event::MouseButtonReleased:
				m_buttons[evt.key.code] = false;
			default:
				break;
			}
		}
		return true;
	}

	bool isMouseDown(int key) const{
		return m_buttons[key];
	}

	bool isMousePressed(int key) const{
		if (!m_lastbuttons[key] && m_buttons[key])
			return true;
		return false;
	}

	bool isMouseReleased(int key) const{
		if (m_lastbuttons[key] && !m_buttons[key])
			return true;
		return false;
	}

	bool IsKeyDown(int key) const {
		return m_keys[key];
	}

	bool IsKeyPressed(int key) const {
		if (!m_lastKeys[key] && m_keys[key])
			return true;
		return false;
	}

	bool IsKeyReleased(int key){
		if (m_lastKeys[key] && !m_keys[key])
			return true;
		return false;
	}

private:
	bool m_keys[sf::Keyboard::KeyCount];
	bool m_lastKeys[sf::Keyboard::KeyCount];
	bool m_buttons[sf::Mouse::ButtonCount];
	bool m_lastbuttons[sf::Mouse::ButtonCount];
	Controller* m_renderWindow;
};

#endif