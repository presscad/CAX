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

		// {{ 属性 }}
		T mat[2][2];

		// {{ 构造函数 和 析构函数 }}
		Mat2();
		Mat2(const T a11, const T a12,
			const T a21, const T a22);
		~Mat2();
		
		// {{ 复制构造函数 和 复制函数 }}
		Mat2(const Mat2<T>& mat2);
		Mat2<T>& operator = (const Mat2<T>& mat2);

		// {{ 索引获取属性 }}
		inline T* operator [] (unsigned short index);
		inline const T* operator [] (unsigned short index) const;


		// {{ 获取 }} 
		// 计算行列式的值
		T determinant(void) const;


		// {{ 修改 }} 
		// 转置 
		void transpose(void);

	}; // namespace CAX

} // namespace CAX


#endif