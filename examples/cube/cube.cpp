#include "wd.h"
#include <cstdio>

int main(int argc, char** argv)
{
	wd::engine engine;
	engine.init();

	//create our main window
	wd::window wnd;
	if (!wnd.init("WD Engine Cube Demo", wd::recti(50, 50, 690, 530)))
		return 0;

	wnd.set_visible(true);

	engine.run();
	engine.close();

	return 0;
}