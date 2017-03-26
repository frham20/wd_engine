#pragma once

//////////////////////////////////////////////////////////////////////////
// vec2
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	template<typename T>
	class vec2
	{
	  public:
		vec2() = default;
		vec2( T x, T y );
		vec2( const vec2<T>& other ) = default;
		vec2( vec2<T>&& other )      = default;

		vec2<T>& operator=( const vec2<T>& other ) = default;
		vec2<T>& operator=( vec2<T>&& other ) = default;

		T& operator[]( int index );
		T operator[]( int index ) const;

		vec2<T>& operator+=( const vec2<T>& other );
		vec2<T>& operator-=( const vec2<T>& other );
		vec2<T>& operator*=( const vec2<T>& other );
		vec2<T>& operator*=( float k );
		vec2<T>& operator/=( const vec2<T>& other );
		vec2<T>& operator/=( float k );

	  public:
		T x;
		T y;
	};

	template<typename T>
	T length( const vec2<T>& v0 );
	template<typename T>
	T length_sqr( const vec2<T>& v0 );
	template<typename T>
	T dot( const vec2<T>& v0, const vec2<T>& v1 );
	template<typename T>
	vec2<T> normalize( const vec2<T>& v0 );
	template<typename T>
	vec2<T> operator+( const vec2<T>& v0, const vec2<T>& v1 );
	template<typename T>
	vec2<T> operator-( const vec2<T>& v0, const vec2<T>& v1 );
	template<typename T>
	vec2<T> operator*( const vec2<T>& v0, float k );
	template<typename T>
	vec2<T> operator*( float k, const vec2<T>& v0 );
	template<typename T>
	vec2<T> operator/( const vec2<T>& v0, float k );
	template<typename T>
	vec2<T> operator/( float k, const vec2<T>& v0 );

	typedef vec2<float>  vec2f;
	typedef vec2<double> vec2d;
	typedef vec2<int8>   vec2i8;
	typedef vec2<int16>  vec2i16;
	typedef vec2<int32>  vec2i;
	typedef vec2<int64>  vec2i64;
	typedef vec2<uint8>  vec2ui8;
	typedef vec2<uint16> vec2ui16;
	typedef vec2<uint32> vec2ui;
	typedef vec2<uint64> vec2ui64;
}

//////////////////////////////////////////////////////////////////////////
// imp
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	template<typename T>
	inline vec2<T>::vec2( T _x, T _y )
	    : x( _x )
	    , y( _y )
	{
	}
}