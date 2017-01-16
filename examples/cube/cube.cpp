#include "wd.h"
#include <cstdio>


int main(int argc, char** argv)
{
	wd::engine engine;
	engine.init();

	wd::timer timer;
	timer.start();

	for (int i = 0; i < 1000000; i++)
	{
		printf(".");
	}

	timer.stop();
	printf("\nTook %.5f seconds\n", timer.get_s());


	getchar();


	engine.close();

	return 0;
}