#pragma once




#ifndef _VEC3_H_
#define _VEC3_H_

namespace CAX {


	template<typename T>
	class Vec3
	{
	public:
		typedef T value_type;

		T x;
		T y;
		T z;

		/* 构造函数 */
		Vec3(void);
		explicit Vec3(T value);
		Vec3(T fx, T fy);
		Vec3(T fx, T fy, T fz);
		/* 复制构造函数 */
		Vec3(const Vec3<T>& v);
		Vec3<T>& operator = (const Vec3<T>& v);
		~Vec3(void);



		/* {{ 运算符重载 }} */
		/* 返回坐标值的reference */
		T& operator[] (unsigned short index);
		/* 返回坐标值的const reference */
		const T& operator[] (unsigned short index) const;
		/* 加法(对应元素相加) */
		Vec3<T> operator + (const Vec3<T>& v) const;
		Vec3<T> operator + (const T value) const;
		//friend Vec3<T> operator + (const T value, const Vec3<T>& v);
		/* 减法(对应元素相减) */
		Vec3<T> operator - (const Vec3<T>& v) const;
		Vec3<T> operator - (const T value) const;
		//friend Vec3<T> operator - (const T value, const Vec3<T>& v);
		/* 乘法(对应元素相乘) */
		Vec3<T> operator * (const Vec3<T>& v) const;
		Vec3<T> operator * (const T value) const;
		//friend Vec3<T> operator * (const T value, const Vec3<T>& v);
		/* 除法(对应元素相除) */
		Vec3<T> operator / (const Vec3<T>& v) const;
		Vec3<T> operator / (const T value) const;
		//friend Vec3<T> operator / (const T value, const Vec3<T>& v);
		/* 负号 */
		Vec3<T> operator - (void) const;
		/* 自加 */
		Vec3<T>& operator += (const Vec3<T>& v);
		Vec3<T>& operator += (const T value);
		/* 自减 */
		Vec3<T>& operator -= (const Vec3<T>& v);
		Vec3<T>& operator -= (const T value);
		/* 自乘 */
		Vec3<T>& operator *= (const Vec3<T>& v);
		Vec3<T>& operator *= (const T value);
		/* 自除 */
		Vec3<T>& operator /= (const Vec3<T>& v);
		Vec3<T>& operator /= (const T value);
		/* 相等判断 */
		bool operator == (const Vec3<T>& v) const;
		bool operator != (const Vec3<T>& v) const;


		/* 长度 */
		T length(void) const;
		T length(const Vec3<T>& v) const;

		/* 长度的平方 */
		T squareLength(void) const;
		T squareLength(const Vec3<T>& v) const;

		/* 点积 */
		T dot(const Vec3<T>& v) const;

		/* 叉积 */
		Vec3<T> cross(const Vec3<T>& v) const;


		/* 对向量的修改 */
		void set(T fx, T fy, T fz);
		void scaleX(T sx);
		void scaleY(T sy);
		void scaleZ(T sz);
		void scale(T sx, T sy, T sz);
		void translateX(T tx);
		void translateY(T ty);
		void translateZ(T tz);
		void translate(T tx, T ty, T tz);
		void rotateX(T rx);
		void rotateY(T ry);
		void rotateZ(T rz);

		/* 单位化 */
		Vec3<T>& normalize(void);


		/* 计算两个向量的夹角，角度为[0,pi] */
		T getAngle(const Vec3<T>& v);

		/* 计算该点与直线p1-p2最近的点 */
		Vec3<T> nearestPointOfLine(const Vec3<T>& p1, const Vec3<T>& p2) const;

		/* 计算该点与线段p1-p2最近的点 */
		Vec3<T> nearestPointOfLineSegment(const Vec3<T>& p1, const Vec3<T>& p2) const;

		/* 计算该点与直线p1-p2的距离 */
		T distanceToLine(const Vec3<T>& p1, const Vec3<T>& p2) const;

		/* 计算该点与线段p1-p2的距离 */
		T distanceToLineSegment(const Vec3<T>& p1, const Vec3<T>& p2) const;


	};

	template<typename T>
	Vec3<T> operator + (const T value, const Vec3<T>& v);
	template<typename T>
	Vec3<T> operator - (const T value, const Vec3<T>& v);
	template<typename T>
	Vec3<T> operator * (const T value, const Vec3<T>& v);
	template<typename T>
	Vec3<T> operator / (const T value, const Vec3<T>& v);



	typedef Vec3<float> Vec3f;
	typedef Vec3<double> Vec3d;



}; // namespace CAX




#endif