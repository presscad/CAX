#pragma once


#ifndef _MAT4_H_
#define _MAT4_H_


namespace CAX
{
	
	template<typename T>
	class Mat4
	{
	public:
		typedef T value_type;
		

		/* {{ �����ֵ }} */
		T mat[4][4];


		/* ���캯������������ */
		Mat4();
		Mat4(const T a11, const T a12, const T a13, const T a14,
			const T a21, const T a22, const T a23, const T a24,
			const T a31, const T a32, const T a33, const T a34,
			const T a41, const T a42, const T a43, const T a44);
		~Mat4();

		/* ���ƹ��캯���͸�ֵ���� */
		Mat4(const Mat4<T>& mat4);
		Mat4<T>& operator = (const Mat4<T>& mat4);

		/* ������������ָ�� ����ȡֵ0~3*/
		inline T* operator [] (unsigned short index);
		inline const T* operator [] (unsigned short index) const;


		/* ��������ʽ��ֵ */
		T determinant(void) const;

	}; // class Mat4



	typedef Mat4<float> Mat4f;
	typedef Mat4<double> Mat4d;


} // namespace CAX


#endif