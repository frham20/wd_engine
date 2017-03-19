#pragma once

namespace wd
{
	template<typename... ARGS>
	class event
	{
	public:
		void operator()(ARGS&&... args) const;
		event& operator+=(const std::function<void(ARGS...)>& callback);
		event& operator-=(const std::function<void(ARGS...)>& callback);

		void clear();

	private:
		std::vector<std::function<void(ARGS...)>> m_callbacks;
	};
}

#include "wd_event.hpp"