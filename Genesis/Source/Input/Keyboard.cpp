#include <sstream>
#include "Utility\Log.h"

#include "Input\Keyboard.h"

namespace Genesis
{

	namespace Input
	{

		const char * Keyboard::kLogTag = "Keyboard";
		Keyboard * Keyboard::this_ = 0;

		Keyboard::Keyboard(Graphics::Window & window)
		{
			if(this_ != 0)
			{
				Loge(kLogTag, "An keyboard instance already exists.");
			}
			else
			{
				this_ = this;
			}

			glfwSetKeyCallback(window.GetRawWindow(), KeyEventCallback);

			keyStates_ = new KeyState[GLFW_KEY_LAST];

			for(int i = 0; i < GLFW_KEY_LAST; ++i)
				keyStates_[i] = Inactive;
		}

		Keyboard::~Keyboard()
		{
			delete[] keyStates_;
		}

		Keyboard::KeyState Keyboard::GetKeyState(int keyCode) const
		{
			if(keyCode <= 0 || keyCode >= GLFW_KEY_LAST)
			{
				std::stringstream errorStream;
				errorStream << "Invalid key code: " << keyCode;

				Loge(kLogTag, errorStream.str());
			}

			return keyStates_[keyCode];
		}

		void Keyboard::NotifyKeyEvent(int key, int action, int mods)
		{
			if(key == GLFW_KEY_UNKNOWN)
			{
				Logw(kLogTag, "An event from an unknown key was received.");
				return;
			}

			switch(action)
			{
				case GLFW_PRESS:
					keyStates_[key] = Down;
					break;

				case GLFW_RELEASE:
					keyStates_[key] = Up;
					break;
			}
		}

		void Keyboard::KeyEventCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
		{
			if(this_)
			{
				this_->NotifyKeyEvent(key, action, mods);
			}
		}



	}

}