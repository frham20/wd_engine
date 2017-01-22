#pragma once

namespace wd {

class window_base : private noncopyable
{
public:



	uint32 get_width() const;
	uint32 get_height() const;

protected:
	window_base();
	~window_base();

private:
	uint32 width;
	uint32 height;

};

}
