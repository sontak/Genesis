#pragma once
#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include "Input\Keyboard.h"
#include "Input\Mouse.h"
#include "Graphics\Window.h"

namespace Genesis
{

	namespace Input
	{
		
		class InputManager
		{
		public:
			InputManager(Graphics::Window & window);
			~InputManager();

			const Keyboard & GetKeyboard();
			Mouse & GetMouse();

		private:
			Keyboard * keyboard_;
			Mouse * mouse_;
		};

	}

}

#endif