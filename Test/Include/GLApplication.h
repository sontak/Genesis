#pragma once
#ifndef _GLAPPLICATION_H_
#define _GLAPPLICATION_H_

#include <GLM\glm.hpp>

#include "Input\InputManager.h"
#include "Core\Application.h"
#include "Graphics\Shader.h"

namespace Genesis
{

	namespace Test
	{

		class GLApplication
			: public Application
		{
		public:
			bool Initialize();
			bool Update();
			bool Shutdown();

		private:
			const std::string kLogTag = "Test";
			const std::string kVertexShader = "default.vs";
			const std::string kFragmentShader = "default.fs";

			Input::InputManager * input_;

			Graphics::Shader shader_;

			static const GLfloat triangleVertices_[];
			static const GLuint triangleIndices_[];

			GLuint vertexBuffer_;
			GLuint indexBuffer_;

			glm::mat4 model_;
			glm::mat4 view_;
			glm::mat4 proj_;

		};

	}

}

#endif