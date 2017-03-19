namespace wd
{
	template<typename... ARGS>
	inline void event<ARGS...>::operator()(ARGS&&... args) const
	{
		for (auto&& cb : m_callbacks)
			cb(std::forward<ARGS>(args)...);
	}

	template<typename... ARGS>
	inline event<ARGS...>& event<ARGS...>::operator+=(const std::function<void(ARGS...)>& callback)
	{
		m_callbacks.emplace_back(callback);
		return *this;
	}

	template<typename... ARGS>
	inline event<ARGS...>& event<ARGS...>::operator-=(const std::function<void(ARGS...)>& callback)
	{
		auto found_pos = std::find_if(std::begin(m_callbacks), std::end(m_callbacks), [&callback](const auto& fn)
		{
			return fn.target_type() == callback.target_type() && 
				fn.target<void(ARGS...)>() == callback.target<void(ARGS...)>();
		});

		if (found_pos != std::end(m_callbacks))
			m_callbacks.erase(found_pos);

		return *this;
	}

	template<typename... ARGS>
	inline void event<ARGS...>::clear()
	{
		m_callbacks.clear();
	}
}