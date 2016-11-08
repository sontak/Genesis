#pragma once
#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "Graphics\Window.h"

namespace Genesis
{

	namespace Input
	{

		class Mouse
		{
		public:
			Mouse(Graphics::Window & window);
			~Mouse();

			struct MouseInfo
			{
				double X;
				double Y;
				double deltaX;
				double deltaY;
			};

			MouseInfo GetMouseInfo();

		private:
			static const char * kLogTag;
			static Mouse * this_;

			MouseInfo mouseInfo_;

			static void CursorEventCallback(GLFWwindow * window, double x, double y);

			void NotifyCursorEvent(GLFWwindow * window, double x, double y);
		};

	}

}

#endif