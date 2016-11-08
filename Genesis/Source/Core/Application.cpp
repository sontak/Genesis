#include "Core\Application.h"

namespace Genesis
{

	void Application::Run()
	{
		window_.Create(1440, 900, "Genesis Application");

		this->Initialize();

		while(window_.Update())
		{
			if(!this->Update())
				break;

			window_.Swap();
		}

		this->Shutdown();

		window_.Destroy();
	}

}