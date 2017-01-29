#pragma once

namespace wd {

template<typename T>
class vec2
{
public:
	vec2() = default;
	vec2(T x, T y);
	vec2(const vec2<T>& other) = default;
	vec2(vec2<T>&& other) = default;

	vec2<T>& operator=(const vec2<T>& other) = default;
	vec2<T>& operator=(vec2<T>&& other) = default;

	T& operator[](int index);
	T operator[](int index) const;

	vec2<T>& operator+=(const vec2<T>& other);
	vec2<T>& operator-=(const vec2<T>& other);
	vec2<T>& operator*=(const vec2<T>& other);
	vec2<T>& operator*=(float k);
	vec2<T>& operator/=(const vec2<T>& other);
	vec2<T>& operator/=(float k);

	float normalize();
	float length() const;

public:
	T x;
	T y;
};

template<typename T> vec2<T> operator+(const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> operator-(const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> operator*(const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> operator*(const vec2<T>& v0, float k);
template<typename T> vec2<T> operator*(float k, const vec2<T>& v0);
template<typename T> vec2<T> operator/(const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> operator/(const vec2<T>& v0, float k);
template<typename T> vec2<T> operator/(float k, const vec2<T>& v0);

template<typename T> vec2<T> add(const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> sub(const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> mul (const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> mul(const vec2<T>& v0, float k);
template<typename T> vec2<T> mul(float k, const vec2<T>& v0);
template<typename T> vec2<T> div(const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> div(const vec2<T>& v0, float k);
template<typename T> vec2<T> div(float k, const vec2<T>& v0);

template<typename T> float dot(const vec2<T>& v0, const vec2<T>& v1);
template<typename T> vec2<T> normalize(const vec2<T>& v0);
template<typename T> float length(const vec2<T>& v0);


typedef vec2<int8>  vec2i8;
typedef vec2<int16> vec2i16;
typedef vec2<int32> vec2i;
typedef vec2<int64> vec2i64;

typedef vec2<uint8>  vec2ui8;
typedef vec2<uint16> vec2ui16;
typedef vec2<uint32> vec2ui;
typedef vec2<uint64> vec2ui64;

typedef vec2<float>  vec2f;
typedef vec2<double> vec2d;

}
