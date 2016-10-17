#ifndef _SHADER_H_
#define _SHADER_H_

#include <gl\glew.h>
#include <gl\GL.h>

#include <string>

namespace Genesis
{

	namespace Graphics
	{

		class Shader
		{
		public:
			Shader();
			~Shader() { }

			GLuint GetId();
			bool LoadShader(const std::string &filename, GLenum shaderType);
			bool Link();
			const std::string & GetError();

		private:
			GLuint programId_;
			bool linked_;

			std::string errorString_;
		};

	}

}

#endif