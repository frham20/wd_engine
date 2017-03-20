#pragma once

//////////////////////////////////////////////////////////////////////////
// rect
//////////////////////////////////////////////////////////////////////////
namespace wd 
{
	template<typename T>
	class rect
	{
	public:
		rect() = default;
		rect(const rect<T>& other) = default;
		rect(rect<T>&& other) = default;
		rect(T left, T top, T right, T bottom);

		rect<T>& operator=(const rect<T>& other) = default;
		rect<T>& operator=(rect<T>&& other) = default;

		T& operator[](int index);
		T operator[](int index) const;

		void set(T left, T top, T right, T bottom);

		point2<T>& topleft();
		point2<T>& bottomright();

		const point2<T>& topleft() const;
		const point2<T>& bottomright() const;

		T width() const;
		T height() const;

	public:
		T left;
		T top;
		T right;
		T bottom;
	};

	template<typename T> T area(const rect<T>& r);
	template<typename T> T perimeter(const rect<T>& r);


	typedef rect<int8>  recti8;
	typedef rect<int16> recti16;
	typedef rect<int32> recti;
	typedef rect<int64> recti64;

	typedef rect<uint8>  rectui8;
	typedef rect<uint16> rectui16;
	typedef rect<uint32> rectui;
	typedef rect<uint64> rectui64;

	typedef rect<float>  rectf;
	typedef rect<double> rectd;
}

//////////////////////////////////////////////////////////////////////////
// imp
//////////////////////////////////////////////////////////////////////////
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
