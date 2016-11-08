#include <GLM\gtc\type_ptr.hpp>
#include <GLM\gtc\matrix_transform.hpp>

#include "GLApplication.h"

namespace Genesis
{

	namespace Test
	{

		const GLfloat GLApplication::triangleVertices_[] = {
			-1.0f, -1.0f, -5.0f,
			1.0f, -1.0f, -5.0f,
			0.0f, 1.0f, -5.0f
		};

		const GLuint GLApplication::triangleIndices_[] = { 
			0, 1, 2 
		};

		bool GLApplication::Initialize()
		{
			input_ = new Input::InputManager(window_);

			GLuint arrayBuffer;
			glGenVertexArrays(1, &arrayBuffer);
			glBindVertexArray(arrayBuffer);

			if(!shader_.LoadShader(kVertexShader, GL_VERTEX_SHADER) ||
			   !shader_.LoadShader(kFragmentShader, GL_FRAGMENT_SHADER) ||
			   !shader_.Link())
			{
				Loge(kLogTag, "Failed to create the shader program:\n\n" + shader_.GetError());
				return false;
			}

			glClearColor(0.6f, 0.2f, 0.2f, 1.0f);

			glGenBuffers(1, &vertexBuffer_);
			glGenBuffers(1, &indexBuffer_);

			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer_);

			glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices_), (const void *)triangleVertices_, GL_STATIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleIndices_), (const void *)triangleIndices_, GL_STATIC_DRAW);

			GLuint vsPosition = glGetAttribLocation(shader_.GetId(), "v3_Position");

			glEnableVertexAttribArray(vsPosition);
			glVertexAttribPointer(vsPosition, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, NULL);

			proj_ = glm::perspectiveFov(45.0f, 1440.0f, 900.0f, 1.0f, 1000.0f);
			view_ = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));

			return true;
		}

		bool GLApplication::Update()
		{
			const Input::Keyboard & keyboard = input_->GetKeyboard();

			if(keyboard.GetKeyState(GLFW_KEY_ESCAPE) == Input::Keyboard::Down)
			{
				return false;
			}

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram(shader_.GetId());

			glm::mat4 mvp = model_ * view_ * proj_;

			GLuint mvpPos = glGetUniformLocation(shader_.GetId(), "m4_MVP");
			glUniformMatrix4fv(mvpPos, 1, GL_FALSE, glm::value_ptr(mvp));

			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

			return true;
		}

		bool GLApplication::Shutdown()
		{
			return true;
		}

	}

}