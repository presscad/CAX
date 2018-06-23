#pragma once


#ifndef _MAT2_H_
#define _MAT2_H_


namespace CAX
{

	template<typename T>
	class Mat2
	{
	public:
		typedef T value_type;

		// {{ ���� }}
		T mat[2][2];

		// {{ ���캯�� �� �������� }}
		Mat2();
		Mat2(const T a11, const T a12,
			const T a21, const T a22);
		~Mat2();
		
		// {{ ���ƹ��캯�� �� ���ƺ��� }}
		Mat2(const Mat2<T>& mat2);
		Mat2<T>& operator = (const Mat2<T>& mat2);

		// {{ ������ȡ���� }}
		inline T* operator [] (unsigned short index);
		inline const T* operator [] (unsigned short index) const;


		// {{ ��ȡ }} 
		// ��������ʽ��ֵ
		T determinant(void) const;


		// {{ �޸� }} 
		// ת�� 
		void transpose(void);

	}; // namespace CAX

} // namespace CAX


#endif