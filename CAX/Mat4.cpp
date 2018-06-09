#include "Mat4.h"


#include <cstring>
#include <algorithm>

namespace CAX
{

	template<typename T>
	Mat4<T>::Mat4()
	{
		mat[0][0] = 1.0f;
		mat[0][1] = 0.0f;
		mat[0][2] = 0.0f;
		mat[0][3] = 0.0f;

		mat[1][0] = 0.0f;
		mat[1][1] = 1.0f;
		mat[1][2] = 0.0f;
		mat[1][3] = 0.0f;

		mat[2][0] = 0.0f;
		mat[2][1] = 0.0f;
		mat[2][2] = 1.0f;
		mat[2][3] = 0.0f;

		mat[3][0] = 0.0f;
		mat[3][1] = 0.0f;
		mat[3][2] = 0.0f;
		mat[3][3] = 1.0f;
	}

	template<typename T>
	Mat4<T>::Mat4(
		const T a11, const T a12, const T a13, const T a14,
		const T a21, const T a22, const T a23, const T a24,
		const T a31, const T a32, const T a33, const T a34,
		const T a41, const T a42, const T a43, const T a44)
	{
		mat[0][0] = a11;
		mat[0][1] = a12;
		mat[0][2] = a13;
		mat[0][3] = a14;

		mat[1][0] = a21;
		mat[1][1] = a22;
		mat[1][2] = a23;
		mat[1][3] = a24;

		mat[2][0] = a31;
		mat[2][1] = a32;
		mat[2][2] = a33;
		mat[2][3] = a34;

		mat[3][0] = a41;
		mat[3][1] = a42;
		mat[3][2] = a43;
		mat[3][3] = a44;
	}

	template<typename T>
	Mat4<T>::~Mat4()
	{
	}

	template<typename T>
	Mat4<T>::Mat4(const Mat4<T>& mat4)
	{
		mat[0][0] = mat4.mat[0][0];
		mat[0][1] = mat4.mat[0][1];
		mat[0][2] = mat4.mat[0][2];
		mat[0][3] = mat4.mat[0][3];

		mat[1][0] = mat4.mat[1][0];
		mat[1][1] = mat4.mat[1][1];
		mat[1][2] = mat4.mat[1][2];
		mat[1][3] = mat4.mat[1][3];

		mat[2][0] = mat4.mat[2][0];
		mat[2][1] = mat4.mat[2][1];
		mat[2][2] = mat4.mat[2][2];
		mat[2][3] = mat4.mat[2][3];

		mat[3][0] = mat4.mat[3][0];
		mat[3][1] = mat4.mat[3][1];
		mat[3][2] = mat4.mat[3][2];
		mat[3][3] = mat4.mat[3][3];
	}

	template<typename T>
	Mat4<T>& Mat4<T>::operator = (const Mat4<T>& mat4)
	{
		mat[0][0] = mat4.mat[0][0];
		mat[0][1] = mat4.mat[0][1];
		mat[0][2] = mat4.mat[0][2];
		mat[0][3] = mat4.mat[0][3];

		mat[1][0] = mat4.mat[1][0];
		mat[1][1] = mat4.mat[1][1];
		mat[1][2] = mat4.mat[1][2];
		mat[1][3] = mat4.mat[1][3];

		mat[2][0] = mat4.mat[2][0];
		mat[2][1] = mat4.mat[2][1];
		mat[2][2] = mat4.mat[2][2];
		mat[2][3] = mat4.mat[2][3];

		mat[3][0] = mat4.mat[3][0];
		mat[3][1] = mat4.mat[3][1];
		mat[3][2] = mat4.mat[3][2];
		mat[3][3] = mat4.mat[3][3];

		return *this;
	}

	template<typename T>
	T* Mat4<T>::operator [] (unsigned short index)
	{
		return mat[index];
	}

	template<typename T>
	const T* Mat4<T>::operator [] (unsigned short index) const
	{
		return mat[index];
	}


	template<typename T>
	T Mat4<T>::determinant(void) const
	{
		T fA0 = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
		T fA1 = mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0];
		T fA2 = mat[0][0] * mat[1][3] - mat[0][3] * mat[1][0];
		T fA3 = mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1];
		T fA4 = mat[0][1] * mat[1][3] - mat[0][3] * mat[1][1];
		T fA5 = mat[0][2] * mat[1][3] - mat[0][3] * mat[1][2];
		T fB0 = mat[2][0] * mat[3][1] - mat[2][1] * mat[3][0];
		T fB1 = mat[2][0] * mat[3][2] - mat[2][2] * mat[3][0];
		T fB2 = mat[2][0] * mat[3][3] - mat[2][3] * mat[3][0];
		T fB3 = mat[2][1] * mat[3][2] - mat[2][2] * mat[3][1];
		T fB4 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1];
		T fB5 = mat[2][2] * mat[3][3] - mat[2][3] * mat[3][2];
		T fDet = fA0 * fB5 - fA1 * fB4 + fA2 * fB3 + fA3 * fB2 - fA4 * fB1 + fA5 * fB0;
		return fDet;
	}


	template<typename T>
	void Mat4<T>::transpose(void)
	{
		std::swap(mat[0][1], mat[1][0]);
		std::swap(mat[0][2], mat[2][0]);
		std::swap(mat[0][3], mat[3][0]);
		std::swap(mat[1][2], mat[2][1]);
		std::swap(mat[1][3], mat[3][1]);
		std::swap(mat[2][3], mat[3][2]);
	}


	template<typename T>
	void Mat4<T>::getMatrix(T matrix[16]) const
	{
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				matrix[4 * i + j] = mat[i][j];
			}
		}
	}

	template<typename T>
	void Mat4<T>::setMatrix(const T matrix[16])
	{
		for (int i = 0; i<4; i++)
		{
			for (int j = 0; j<4; j++)
			{
				mat[i][j] = matrix[4 * i + j];
			}
		}
	}



	template<typename T>
	void Mat4<T>::getGLMatrix(T matrix[16]) const
	{
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4; j++)
			{
				matrix[i + 4 * j] = mat[i][j];
			}
		}
	}

	template<typename T>
	void Mat4<T>::setGLMatrix(const T matrix[16])
	{
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4; j++)
			{
				 mat[i][j] = matrix[i + 4 * j];
			}
		}
	}



	// ÏÔÊ¾ÊµÀý»¯
	template class Mat4<float>;
	template class Mat4<double>;

} // namespace CAX
