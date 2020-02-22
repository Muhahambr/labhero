//#include "LabHero.h"
#include "LabMap.h"

//hide console window: stackoverflow.com/questions/2139637/hide-console-of-windows-application
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")



int main()
{
	
	LabMap * game = new LabMap();
	game->Run();

	return 0;
}
