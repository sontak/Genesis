
#include "Utility\Log.h"

#include "Input\Mouse.h"
#include "Windows.h"

namespace Genesis
{

	namespace Input
	{

		const char * Mouse::kLogTag = "Mouse";
		Mouse * Mouse::this_ = 0;

		Mouse::Mouse(Graphics::Window & window)
		{
			if(this_ != 0)
			{
				Loge(kLogTag, "An mouse instance already exists.");
			}
			else
			{
				this_ = this;
			}

			glfwSetCursorPosCallback(window.GetRawWindow(), CursorEventCallback);
			glfwSetInputMode(window.GetRawWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

			mouseInfo_.deltaX = 0.0f;
			mouseInfo_.deltaY = 0.0f;

			glfwGetCursorPos(window.GetRawWindow(), &mouseInfo_.X, &mouseInfo_.Y);
		}

		Mouse::~Mouse()
		{

		}

		Mouse::MouseInfo Mouse::GetMouseInfo()
		{
			MouseInfo result = mouseInfo_;

			mouseInfo_.deltaX = 0.0f;
			mouseInfo_.deltaY = 0.0f;

			return result;
		}

		void Mouse::CursorEventCallback(GLFWwindow * window, double x, double y)
		{
			if(this_)
			{
				this_->NotifyCursorEvent(window, x, y);
			}
		}

		void Mouse::NotifyCursorEvent(GLFWwindow * window, double x, double y)
		{
			mouseInfo_.deltaX = x - mouseInfo_.X;
			mouseInfo_.deltaY = y - mouseInfo_.Y;
			mouseInfo_.X = x;
			mouseInfo_.Y = y;
		}

	}

}