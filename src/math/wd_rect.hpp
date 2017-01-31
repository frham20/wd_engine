#pragma once

namespace wd 
{
	template<typename T>
	inline rect<T>::rect(T _left, T _top, T _right, T _bottom) :
		left(_left),
		top(_top),
		right(_right),
		bottom(_bottom)
	{
	}


	template<typename T>
	inline T& rect<T>::operator[](int index)
	{
		return static_cast<T*>(&left)[index];
	}

	template<typename T>
	inline T rect<T>::operator[](int index) const
	{
		return static_cast<const T*>(&left)[index];
	}

	template<typename T>
	inline void rect<T>::set(T _left, T _top, T _right, T _bottom)
	{
		left = _left;
		top = _top;,
			right = _right;
		bottom = _bottom;
	}

	template<typename T>
	inline point2<T>& rect<T>::topleft()
	{
		return *reinterpret_cast<point2<T>*>(&left);
	}

	template<typename T>
	inline point2<T>& rect<T>::bottomright()
	{
		return *reinterpret_cast<point2<T>*>(&right);
	}

	template<typename T>
	inline const point2<T>& rect<T>::topleft() const
	{
		return *reinterpret_cast<const point2<T>*>(&left);
	}

	template<typename T>
	inline const point2<T>& rect<T>::bottomright() const
	{
		return *reinterpret_cast<const point2<T>*>(&right);
	}

	template<typename T>
	inline T rect<T>::width() const
	{
		return right - left;
	}

	template<typename T>
	inline T rect<T>::height() const
	{
		return bottom - top;
	}

	template<typename T>
	inline T area(const rect<T>& r)
	{
		return r.width() * r.height();
	}

	template<typename T>
	inline T perimeter(const rect<T>& r)
	{
		const auto width = r.width();
		const auto height = r.height();
		return width + width + height + height;
	}
}