#include <fstream>
#include <sstream>

#include "Graphics\Shader.h"

namespace Genesis
{

	namespace Graphics
	{

		Shader::Shader()
			: linked_(false), programId_(0)
		{
			
		}

		GLuint Shader::GetId()
		{
			return programId_;
		}

		bool Shader::LoadShader(const std::string &filename, GLenum shaderType)
		{
			if(linked_)
				return false;

			if(programId_ == 0)
				programId_ = glCreateProgram();

			std::ifstream inFile(filename);

			if(!inFile.is_open())
			{
				errorString_ = "Could not find the file '" + filename + "'";
				return false;
			}

			std::stringstream inStream;
			inStream << inFile.rdbuf();

			std::string source = inStream.str();
			const char * sourceBuffer = source.c_str();

			int shaderId = glCreateShader(shaderType);

			glShaderSource(shaderId, 1, &sourceBuffer, NULL);
			glCompileShader(shaderId);

			GLint compileResult = 0;
			glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileResult);

			if(compileResult != GL_TRUE)
			{
				GLint errorLength = 0;
				glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &errorLength);

				char * errorString = new char[errorLength];
				glGetShaderInfoLog(shaderId, errorLength, &errorLength, errorString);
				errorString_ = errorString;
				delete[] errorString;

				glDeleteShader(shaderId);

				return false;
			}

			glAttachShader(programId_, shaderId);

			return true;
		}

		bool Shader::Link()
		{
			glLinkProgram(programId_);

			GLint compileResult = 0;
			glGetProgramiv(programId_, GL_LINK_STATUS, &compileResult);

			if(compileResult != GL_TRUE)
			{
				GLint errorLength = 0;
				glGetProgramiv(programId_, GL_INFO_LOG_LENGTH, &errorLength);

				char * errorString = new char[errorLength];
				glGetProgramInfoLog(programId_, errorLength, &errorLength, errorString);
				errorString_ = errorString;
				delete[] errorString;

				return false;
			}

			return true;
		}

		const std::string & Shader::GetError()
		{
			return errorString_;
		}

	}

}