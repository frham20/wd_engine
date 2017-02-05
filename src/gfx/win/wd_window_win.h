#pragma once

namespace wd 
{
	class window;

	class window_platform
	{
	public:
		explicit window_platform(window& owner);
		~window_platform();
		
		bool init(const char* title, const recti& region);

		const char* get_title() const;
		const recti& get_region() const;

		void set_region(const recti& region);
		void set_title(const char* title);

		bool is_visible() const;
		void set_visible(bool state);

		static bool init();

	private:
		bool destroy();

	private:
		LRESULT handle_msg(UINT msg, WPARAM wparam, LPARAM lparam);
		static LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
		
	private:
		window& owner;
		HWND hwnd			= nullptr;
		std::string title	= std::string("WD Window");
		recti region		= recti(0,0,0,0);
		bool visible		= false;
	};
}