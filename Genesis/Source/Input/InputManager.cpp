#include "Input\InputManager.h"

namespace Genesis
{
	
	namespace Input
	{

		InputManager::InputManager(Graphics::Window & window)
		{
			keyboard_ = new Keyboard(window);
			mouse_ = new Mouse(window);
		}

		InputManager::~InputManager()
		{
			delete keyboard_;
			delete mouse_;
		}

		const Keyboard & InputManager::GetKeyboard()
		{
			return (*keyboard_);
		}

		Mouse & InputManager::GetMouse()
		{
			return (*mouse_);
		}


	}

}