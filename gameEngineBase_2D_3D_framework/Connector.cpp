
#include "gApp.h"
#include "windowSystem.h"
#include "autoDraw.h"

void gAPP::openTextStream()
{
	base_window::gameWindow->mainKeyboard.openStream();

}
std::string gAPP::closeTextStream()
{
	return base_window::gameWindow->mainKeyboard.closeStream();
}



int gAPP::run(gAPP* mainAPP) {


#ifdef _DEBUG_INFO_
	try {

	mainAPP->initFrameworkResources();

	base_window gWindow(mainAPP->gName, mainAPP->width, mainAPP->height, -1, -1);

	base_window::gameWindow = &gWindow;

	base_window::gameWindowInit = 1;

	initSpriteCreation();

	mainAPP->init();

	while (base_window::getCountOfWindows() != 0) {
		
		gw_object->graphicsStation->startFrame();

		mainAPP->tick();
		
		processMouse(mainAPP);
		processKeyborad(mainAPP);
		
		drawAllStuff();
		
		gWindow.processWindowTick();

		gw_object->graphicsStation->showFrame();

	}


	delete mainAPP;

	return 0;
	}
	catch (std::exception& error) { OutputDebugStringA(error.what()); }
	catch (...) { OutputDebugStringA("\n\n\n\nSomething went badly wrong\n\n\n\n"); }

#endif

	return -1;
}





