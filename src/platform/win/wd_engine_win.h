#pragma once
namespace wd
{
	class engine;

	class engine_win : private noncopyable
	{
	public:
		explicit engine_win(engine& owner);

		bool init();
		bool close();
		bool process_messages();

		static HINSTANCE get_hinstance();

	private:
		engine& owner;
	};

	typedef engine_win engine_platform;
}