#pragma once
#ifndef _ICAMERA_H_
#define _ICAMERA_H_

#include <GLM\glm.hpp>

namespace Genesis
{

	namespace Graphics
	{

		class ICamera
		{
		public:
			virtual const glm::mat4 & GetProjectionMatrix() = 0;
			virtual const glm::mat4 & GetViewMatrix() = 0;
		};

	}

}

#endif