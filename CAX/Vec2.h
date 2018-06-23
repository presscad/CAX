#pragma once

#ifndef _VEC2_H_
#define _VEC2_H_



namespace CAX {

	template<typename T>
	class Vec2
	{
	public:
		typedef T value_type;


		// 共有成员 
		T x;	//坐标x
		T y;	//坐标y


		// 构造函数 
		Vec2(void);
		explicit Vec2(T value);
		Vec2(T fx, T fy);

		// 复制构造函数 和 赋值函数
		Vec2(const Vec2<T>& v);
		Vec2<T>& operator = (const Vec2<T>& v);

		// 析构函数
		~Vec2(void);



		// {{ 运算符重载 }}
		// 返回坐标值的引用，索引值只能取0和1
		T& operator [] (unsigned short index);
		const T& operator [] (unsigned short index) const;
		// 加法
		Vec2<T> operator + (const Vec2<T>& v) const;
		Vec2<T> operator + (const T value) const;
		//friend Vec2<T> operator + (T value, const Vec2<T>& v);
		// 减法
		Vec2<T> operator - (const Vec2<T>& v) const;
		Vec2<T> operator - (const T value) const;
		//friend Vec2<T> operator - (T value, const Vec2<T>& v);
		// 乘法
		Vec2<T> operator * (const Vec2<T>& v) const;
		Vec2<T> operator * (const T value) const;
		//friend Vec2<T> operator * (T value, const Vec2<T>& v);
		// 除法
		Vec2<T> operator / (const Vec2<T>& v) const;
		Vec2<T> operator / (const T value) const;
		///friend Vec2<T> operator / (T value, const Vec2<T>& v);
		// 负号
		Vec2<T> operator - (void) const;
		// 自加
		Vec2<T>& operator += (const Vec2<T>& v);
		Vec2<T>& operator += (T value);
		// 自减
		Vec2<T>& operator -= (const Vec2<T>& v);
		Vec2<T>& operator -= (T value);
		// 自乘
		Vec2<T>& operator *= (const Vec2<T>& v);
		Vec2<T>& operator *= (T value);
		// 自除
		Vec2<T>& operator /= (const Vec2<T>& v);
		Vec2<T>& operator /= (T value);
		// 相等判断
		bool operator == (const Vec2<T>& v) const;
		bool operator != (const Vec2<T>& v) const;




		// {{ 计算信息 }}
		// 计算长度
		T length(void) const;
		T length(const Vec2<T>& v) const;
		// 计算平方长度
		T squareLength(void) const;
		T squareLength(const Vec2<T>& v) const;
		// 计算点积
		T dot(const Vec2<T>& v) const;
		// 计算叉积的Z值 */
		T crossValue(const Vec2<T>& v) const;

		// 计算与坐标轴的夹角
		// 弧度范围[-pi, pi]
		// 角度范围[-180, 180]
		T xRadian(void) const;
		T yRadian(void) const;
		T xDegree(void) const;
		T yDegree(void) const;

		// 计算两个向量的夹角弧度值，角度为[0,pi]
		T getAngle(const Vec2<T>& v) const;

		Vec2<T> nearestPointOfLine(const Vec2<T>& p1, const Vec2<T>& p2) const;
		Vec2<T> nearestPointOfLineSegment(const Vec2<T>& p1, const Vec2<T>& p2) const;

		T distanceToLine(const Vec2<T>& p1, const Vec2<T>& p2) const;
		T distanceToLineSegment(const Vec2<T>& p1, const Vec2<T>& p2) const;



		// 对向量的修改
		// 单位化
		Vec2<T>& normalize(void);

		void set(const T fx, const T fy);
		void scaleX(const T sx);
		void scaleY(const T sy);
		void scale(const T sx, const T sy);
		void translateX(const T tx);
		void translateY(const T ty);
		void translate(const T tx, const T ty);
		void rotateLeft90(void);
		void rotateRight90(void);
		void rotate(const T radian);



	};


	template<typename T>
	Vec2<T> operator + (const T value, const Vec2<T>& v);
	template<typename T>
	Vec2<T> operator - (const T value, const Vec2<T>& v);
	template<typename T>
	Vec2<T> operator * (const T value, const Vec2<T>& v);
	template<typename T>
	Vec2<T> operator / (const T value, const Vec2<T>& v);


	typedef Vec2<float> Vec2f;
	typedef Vec2<double> Vec2d;


} // namespace CAX




#endif

