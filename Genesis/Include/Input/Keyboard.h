#pragma once
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "Graphics\Window.h"

namespace Genesis
{

	namespace Input
	{

		class Keyboard
		{
		public:
			Keyboard(Graphics::Window & window);
			~Keyboard();

			enum KeyState
			{
				Inactive = 0,
				Down = 1,
				Pressed = 2,
				Up = 4,
				Unknown = 8
			};

			KeyState GetKeyState(int keyCode) const;

		private:
			static const char * kLogTag;
			static Keyboard * this_;

			static void KeyEventCallback(GLFWwindow * window, int key, int scancode, int action, int mods);

			void NotifyKeyEvent(int key, int action, int mods);

			KeyState * keyStates_;


		};

	}

}

#endif