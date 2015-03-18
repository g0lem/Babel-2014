#include <common.hpp>




GLuint UI_helper::GetButtonAction(Controller * ctrl, Property * m_prop)
{

	if (compare_vec2(ctrl->GetMousePosition(), m_prop->position) != V_GREATER ||
		compare_vec2(ctrl->GetMousePosition(), m_prop->position + m_prop->size) != V_LESSER)
	return NONE;


	if (ctrl->GetMouseButton(GLFW_MOUSE_BUTTON_LEFT))
		return PRESSED;
	else
		return HOVER;


}
