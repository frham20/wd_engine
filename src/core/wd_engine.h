#pragma once
namespace wd {

class engine : private noncopyable
{
public:
	WDAPI engine();
	WDAPI ~engine();
	WDAPI bool init();
	WDAPI bool close();

private:
	bool platform_init();
	bool platform_close();

private:
	bool initialized;
};

}
