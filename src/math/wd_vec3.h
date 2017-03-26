#pragma once

//////////////////////////////////////////////////////////////////////////
// vec3
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	template<typename T>
	class vec3
	{
	  public:
		vec3() = default;
		vec3( T x, T y, T z );
		vec3( const vec3<T>& other ) = default;
		vec3( vec3<T>&& other )      = default;

		vec3& operator=( const vec3<T>& other ) = default;
		vec3& operator=( vec3<T>&& other ) = default;
		vec3& operator+=( const vec3<T>& other );
		vec3& operator-=( const vec3<T>& other );
		vec3& operator*=( T k );
		vec3& operator/=( T k );

	  public:
		T x;
		T y;
		T z;
	};

	template<typename T>
	T length( const vec3<T>& v );
	template<typename T>
	T length_sqr( const vec3<T>& v );
	template<typename T>
	vec3<T> normalize( const vec3<T>& v );
	template<typename T>
	T dot( const vec3<T>& v0, const vec3<T>& v1 );
	template<typename T>
	vec3<T> cross( const vec3<T>& v0, const vec3<T>& v1 );
	template<typename T>
	vec3<T> operator+( const vec3<T>& v0, const vec3<T>& v1 );
	template<typename T>
	vec3<T> operator-( const vec3<T>& v0, const vec3<T>& v1 );
	template<typename T>
	vec3<T> operator*( const vec3<T>& v0, T k );
	template<typename T>
	vec3<T> operator*( T k, const vec3<T>& v0 );
	template<typename T>
	vec3<T> operator/( const vec3<T>& v0, T k );
	template<typename T>
	vec3<T> operator/( T k, const vec3<T>& v0 );

	typedef vec3<float>  vec3f;
	typedef vec3<double> vec3d;
	typedef vec3<int8>   vec3i8;
	typedef vec3<int16>  vec3i16;
	typedef vec3<int32>  vec3i;
	typedef vec3<int64>  vec3i64;
	typedef vec3<uint8>  vec3ui8;
	typedef vec3<uint16> vec3ui16;
	typedef vec3<uint32> vec3ui;
	typedef vec3<uint64> vec3ui64;
}

//////////////////////////////////////////////////////////////////////////
// imp
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	template<typename T>
	inline vec3<T>::vec3( T _x, T _y, T _z )
	    : x( _x )
	    , y( _y )
	    , z( _z )
	{
	}

	template<typename T>
	inline vec3<T>& vec3<T>::operator+=( const vec3<T>& other )
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	template<typename T>
	inline vec3<T>& vec3<T>::operator-=( const vec3<T>& other )
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	template<typename T>
	inline vec3<T>& vec3<T>::operator*=( T k )
	{
		x *= k;
		y *= k;
		z *= k;
		return *this;
	}

	template<typename T>
	inline vec3<T>& vec3<T>::operator/=( T k )
	{
		x /= k;
		y /= k;
		z /= k;
		return *this;
	}

	template<typename T>
	inline T length( const vec3<T>& v )
	{
		return sqrt( length_sqr( v ) );
	}

	template<typename T>
	inline T length_sqr( const vec3<T>& v )
	{
		return dot( v, v );
	}

	template<typename T>
	inline vec3<T> normalize( const vec3<T>& v )
	{
		const auto len = length( v );
		assert( len != T( 0 ) );
		return {v.x / len, v.y / len, v.z / len};
	}

	template<>
	inline vec3<float> normalize( const vec3<float>& v )
	{
		const auto len = length( v );
		assert( len != 0.0f );
		const auto invLen = 1.0f / len;
		return {v.x * invLen, v.y * invLen, v.z * invLen};
	}

	template<>
	inline vec3<double> normalize( const vec3<double>& v )
	{
		const auto len = length( v );
		assert( len != 0.0 );
		const auto invLen = 1.0 / len;
		return {v.x * invLen, v.y * invLen, v.z * invLen};
	}

	template<typename T>
	inline T dot( const vec3<T>& v0, const vec3<T>& v1 )
	{
		return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
	}

	template<typename T>
	vec3<T> cross( const vec3<T>& v0, const vec3<T>& v1 );

	template<typename T>
	inline vec3<T> operator+( const vec3<T>& v0, const vec3<T>& v1 )
	{
		return {v0.x + v1.x, v0.y + v1.y, v0.z + v1.z};
	}

	template<typename T>
	inline vec3<T> operator-( const vec3<T>& v0, const vec3<T>& v1 )
	{
		return {v0.x - v1.x, v0.y - v1.y, v0.z - v1.z};
	}

	template<typename T>
	inline vec3<T> operator*( const vec3<T>& v0, T k )
	{
		return {v0.x * k, v0.y * k, v0.z * k};
	}

	template<typename T>
	inline vec3<T> operator*( T k, const vec3<T>& v0 )
	{
		return v0 * k;
	}

	template<typename T>
	inline vec3<T> operator/( const vec3<T>& v0, T k )
	{
		return {v0.x / k, v0.y / k, v0.z / k};
	}

	template<>
	inline vec3<float> operator/( const vec3<float>& v0, float k )
	{
		const auto invK = 1.0f / k;
		return v0 * invK;
	}

	template<>
	inline vec3<double> operator/( const vec3<double>& v0, double k )
	{
		const auto invK = 1.0 / k;
		return v0 * invK;
	}

	template<typename T>
	inline vec3<T> operator/( T k, const vec3<T>& v0 )
	{
		return v0 / k;
	}
}