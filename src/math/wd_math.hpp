#pragma once

//////////////////////////////////////////////////////////////////////////
// math
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	uint32 bit_count( uint64 value );
	uint32 bit_count( uint32 value );
	uint32 bit_count( uint16 value );
	uint32 bit_count( uint8 value );

	float sqrt( float value );
	double sqrt( double value );
}

//////////////////////////////////////////////////////////////////////////
// imp
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	inline uint32 bit_count( uint64 value )
	{
		uint32 count = 0;
		while ( value > 0 )
		{
			count += value & 0x1;
			value >>= 1;
		}
		return count;
	}

	inline uint32 bit_count( uint32 value )
	{
		uint32 count = 0;
		while ( value > 0 )
		{
			count += value & 0x1;
			value >>= 1;
		}
		return count;
	}

	inline uint32 bit_count( uint16 value )
	{
		uint32 count = 0;
		while ( value > 0 )
		{
			count += value & 0x1;
			value >>= 1;
		}
		return count;
	}

	inline uint32 bit_count( uint8 value )
	{
		return ( ( value & 0x01 ) >> 0 ) + ( ( value & 0x02 ) >> 1 ) + ( ( value & 0x04 ) >> 2 ) +
		       ( ( value & 0x08 ) >> 3 ) + ( ( value & 0x10 ) >> 4 ) + ( ( value & 0x20 ) >> 5 ) +
		       ( ( value & 0x40 ) >> 6 ) + ( ( value & 0x80 ) >> 7 );
	}

	inline float sqrt( float value )
	{
		return std::sqrt( value );
	}

	inline double sqrt( double value )
	{
		return std::sqrt( value );
	}
}
