#include "Graphics\Window.h"
#include "Utility\Log.h"

using namespace Genesis::Utility;

namespace Genesis
{

	namespace Graphics
	{

		Window::Window()
			: created_(false)
		{

		}

		bool Window::Create(int width, int height, const char * title)
		{
			if(!glfwInit())
			{
				Log::Get().Write(kLogTag, "Failed to initialize GLFW!", Log::LogLevel::Fatal);
				return false;
			}

			const GLFWvidmode * vid = glfwGetVideoMode(glfwGetPrimaryMonitor());

			Logi(kLogTag, "Detected video mode " + std::to_string(vid->width) + " x " + std::to_string(vid->height) + " @ " + std::to_string(vid->refreshRate) + "Hz");
			Logi(kLogTag, "Creating GLFW window with parameters:");
			Logi(kLogTag, "     Width:   " + std::to_string(width));
			Logi(kLogTag, "     Height:  " + std::to_string(height));
			Logi(kLogTag, "     Title:   " + std::string(title));
			Logi(kLogTag, "     OpenGL:  v" + std::to_string(kOpenGLMajor) + "." + std::to_string(kOpenGLMinor));

			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, kOpenGLMajor);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, kOpenGLMinor);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			wnd_ = glfwCreateWindow(width, height, title, NULL, NULL);

			if(!wnd_)
			{
				Log::Get().Write(kLogTag, "Failed to create the application window!", Log::LogLevel::Fatal);
				return false;
			}

			glfwMakeContextCurrent(wnd_);
			glfwSwapInterval(1);

			Log::Get().Write(kLogTag, "Initializing GLEW...", Log::LogLevel::All);

			glewExperimental = GL_TRUE;

			if(GLenum error = glewInit() != GLEW_OK)
			{
				Logf(kLogTag, "Failed to initialize GLEW: " + std::string((char *)glewGetErrorString(error)));
				return false;
			}

			created_ = true;

			// Center the window on the screen
			int windowX = (vid->width / 2) - (width / 2);
			int windowY = (vid->height / 2) - (height / 2);

			glfwSetWindowPos(wnd_, windowX, windowY);

			return (wnd_ != 0);
		}

		void Window::Destroy()
		{
			if(created_)
			{
				glfwDestroyWindow(wnd_);
				wnd_ = 0;
				created_ = false;
			}
		}

		bool Window::Update()
		{
			if(glfwWindowShouldClose(wnd_))
			{
				return false;
			}

			glfwPollEvents();

			return true;
		}

		void Window::Swap()
		{
			glfwSwapBuffers(wnd_);
		}

	}

}