#include "Main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
#ifdef _DEBUG
	Genesis::Utility::Log::Get().SetLogLevel(Genesis::Utility::Log::Verbose);
#endif

	Genesis::Application * app = new GLApplication;
	app->Run();
}