#pragma once

//////////////////////////////////////////////////////////////////////////
// point2
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	template<typename T>
	class point2
	{
	  public:
		point2() = default;
		point2( T x, T y );
		point2( const point2<T>& other ) = default;
		point2( point2<T>&& other )      = default;

		point2<T>& operator=( const point2<T>& other ) = default;
		point2<T>& operator=( point2<T>&& other ) = default;

		T& operator[]( int index );
		T operator[]( int index ) const;

	  public:
		T x;
		T y;
	};

	typedef point2<int8>  point2i8;
	typedef point2<int16> point2i16;
	typedef point2<int32> point2i;
	typedef point2<int64> point2i64;

	typedef point2<uint8>  point2ui8;
	typedef point2<uint16> point2ui16;
	typedef point2<uint32> point2ui;
	typedef point2<uint64> point2ui64;

	typedef point2<float>  point2f;
	typedef point2<double> point2d;
}

//////////////////////////////////////////////////////////////////////////
// imp
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	template<typename T>
	inline point2<T>::point2( T _x, T _y )
	    : x( _x )
	    , y( _y )
	{
	}

	template<typename T>
	inline T& point2<T>::operator[]( int index )
	{
		return static_cast<T*>( &x )[index];
	}

	template<typename T>
	inline T point2<T>::operator[]( int index ) const
	{
		return static_cast<const T*>( &x )[index];
	}
}
