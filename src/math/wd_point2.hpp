namespace wd 
{
	template<typename T>
	inline point2<T>::point2(T _x, T _y) :
		x(_x),
		y(_y)
	{

	}

	template<typename T>
	inline T& point2<T>::operator[](int index)
	{
		return static_cast<T*>(&x)[index];
	}

	template<typename T>
	inline T point2<T>::operator[](int index) const
	{
		return static_cast<const T*>(&x)[index];
	}
}