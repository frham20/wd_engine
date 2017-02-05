namespace wd
{
	template<typename... ARGS>
	inline void event<ARGS...>::operator()(ARGS&&... args) const
	{
		for (auto&& cb : this->callbacks)
			cb(std::forward<ARGS>(args)...);
	}

	template<typename... ARGS>
	inline event<ARGS...>& event<ARGS...>::operator+=(const std::function<void(ARGS...)>& callback)
	{
		this->callbacks.emplace_back(callback);
		return *this;
	}

	template<typename... ARGS>
	inline event<ARGS...>& event<ARGS...>::operator-=(const std::function<void(ARGS...)>& callback)
	{
		auto found_pos = std::find_if(std::begin(this->callbacks), std::end(this->callbacks), [&callback](const auto& fn)
		{
			return fn.target_type() == callback.target_type() && fn.target() == callback.target();
		});

		if (found_pos != std::end(this->callbacks))
			this->callbacks.erase(found_pos);

		return *this;
	}

	template<typename... ARGS>
	inline void event<ARGS...>::clear()
	{
		this->callbacks.clear();
	}
}