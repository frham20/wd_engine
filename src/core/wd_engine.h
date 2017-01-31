#pragma once
namespace wd {

class engine : private noncopyable
{
public:
	WDAPI engine();
	WDAPI ~engine();
	WDAPI bool init();
	WDAPI bool close();

	WDAPI void run();
	WDAPI void do_frame(float delta_t);

private:
	bool platform_init();
	bool platform_close();
	bool platform_process_messages();

private:
	bool initialized;
};

}
