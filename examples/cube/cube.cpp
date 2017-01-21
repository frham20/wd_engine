#include "wd.h"
#include <cstdio>


int main(int argc, char** argv)
{
	wd::engine engine;
	engine.init();

	auto seconds = wd::time_s([] 
	{
		for (int i = 0; i < 1000000; i++)
		{
			printf(".");
		}
	});
	printf("\nTook %.5f seconds\n", seconds);


	getchar();


	engine.close();

	return 0;
}