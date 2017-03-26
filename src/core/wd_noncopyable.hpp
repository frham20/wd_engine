#pragma once
namespace wd
{
	class noncopyable
	{
	  protected:
		noncopyable()                = default;
		noncopyable( noncopyable&& ) = default;
		noncopyable& operator=( noncopyable&& ) = default;

	  private:
		noncopyable( const noncopyable& ) = delete;
		noncopyable& operator=( const noncopyable& ) = delete;
	};
}
