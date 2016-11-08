#pragma once
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "Utility\Log.h"
#include "Utility\Profiler.h"
#include "Graphics\Window.h"

namespace Genesis
{

	class Application
	{
	public:
		Application() { }
		virtual ~Application() { }

		virtual bool Initialize() = 0;
		virtual bool Update() = 0;
		virtual bool Shutdown() = 0;

		void Run();

	protected:
		Graphics::Window window_;

	};

}

#endif