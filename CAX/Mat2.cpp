#include "Mat2.h"


#include <algorithm>

namespace CAX
{

	template<typename T>
	Mat2<T>::Mat2()
	{
		mat[0][0] = 1.0f;
		mat[0][1] = 0.0f;
		mat[1][0] = 0.0f;
		mat[1][1] = 1.0f;
	}

	template<typename T>
	Mat2<T>::Mat2(const T a11, const T a12,
		const T a21, const T a22)
	{
		mat[0][0] = a11;
		mat[0][1] = a12;
		mat[1][0] = a21;
		mat[1][1] = a22;
	}

	template<typename T>
	Mat2<T>::~Mat2()
	{

	}

	template<typename T>
	Mat2<T>::Mat2(const Mat2<T>& mat2)
	{
		mat[0][0] = mat2.mat[0][0];
		mat[0][1] = mat2.mat[0][1];
		mat[1][0] = mat2.mat[1][0];
		mat[1][1] = mat2.mat[1][1];
	}

	template<typename T>
	Mat2<T>& Mat2<T>::operator = (const Mat2<T>& mat2)
	{
		mat[0][0] = mat2.mat[0][0];
		mat[0][1] = mat2.mat[0][1];
		mat[1][0] = mat2.mat[1][0];
		mat[1][1] = mat2.mat[1][1];

		return *this;
	}

	template<typename T>
	inline T* Mat2<T>::operator [] (unsigned short index)
	{
		return mat[index];
	}

	template<typename T>
	inline const T* Mat2<T>::operator [] (unsigned short index) const
	{
		return mat[index];
	}



	template<typename T>
	T Mat2<T>::determinant(void) const
	{
		return (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
	}

	template<typename T>
	void Mat2<T>::transpose(void)
	{
		std::swap(mat[1][0], mat[0][1]);
	}

} // namespace CAX

