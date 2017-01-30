#include "wd.h"
#include <cstdio>

namespace
{
	auto print_time_s = [](auto seconds)
	{
		printf("\nTook %.5f seconds\n", seconds);
	};
}

int main(int argc, char** argv)
{
	wd::engine engine;
	engine.init();

	//create our main window
	wd::window wnd;
	if (!wnd.init("WD Engine Cube Demo", wd::recti(50, 50, 690, 530)))
		return 0;

	wnd.set_visible(true);

	wd::point2f pt(23.0f, 34.5f);
	printf("%.5f %.5f", pt.x, pt.y);
	pt[0] = 12.0f;
	pt[1] = 234.3f;
	printf("%.5f %.5f", pt.x, pt.y);

	wd::time_s([] 
	{
		for (int i = 0; i < 1000000; i++)
			printf(".");

	}, print_time_s);

	getchar();


	engine.close();

	return 0;
}