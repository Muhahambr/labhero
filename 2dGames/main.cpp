#include "LabHero.h"

//hide console window: stackoverflow.com/questions/2139637/hide-console-of-windows-application
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")



int main()
{
	
	LabHeroGame * game = new LabHeroGame();
	game->Run();

	return 0;
}
