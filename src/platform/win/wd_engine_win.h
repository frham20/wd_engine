#pragma once

namespace wd
{
	class engine_platform : private noncopyable
	{
	public:
		explicit engine_platform(engine& owner);

		bool init();
		bool close();
		bool process_messages();

		static HINSTANCE get_hinstance();

	private:
		engine& owner;
	};
}