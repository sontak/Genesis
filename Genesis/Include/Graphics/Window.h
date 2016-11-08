#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <string>

namespace Genesis
{

	namespace Graphics
	{

		class Window
		{
		public:
			Window();
			~Window() { }

			bool Create(int width, int height, const char * title);
			void Destroy();

			bool Update();
			void Swap();

			GLFWwindow * GetRawWindow();

		private:
			const int kOpenGLMajor = 3;
			const int kOpenGLMinor = 2;

			const std::string kLogTag = "Window";

			GLFWwindow * wnd_;

			bool created_;
		};

	}

}

#endif