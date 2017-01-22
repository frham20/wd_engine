#pragma once
namespace wd {

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

#include "wd_rect.hpp"
