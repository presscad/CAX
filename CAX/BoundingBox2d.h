#pragma once


#ifndef _BOUNDINGBOX2D_H_
#define _BOUNDINGBOX2D_H_


namespace CAX
{

	template<typename T>
	class Vec2;

	typedef Vec2<double> Vec2d;


	class BoundingBox2d
	{
	public:
		/* {{ 最小值，最大值 }} */
		double minX;
		double minY;
		double maxX;
		double maxY;

		// 构造函数和析构函数
		BoundingBox2d(void);
		BoundingBox2d(
			const double fMinX, const double fMinY, 
			const double fMaxX, const double fMaxY);
		~BoundingBox2d();

		// 复制构造函数 和 赋值函数
		BoundingBox2d(const BoundingBox2d& boundingBox);
		BoundingBox2d& operator = (const BoundingBox2d& boundingBox);

		// 获取包围盒的中心
		Vec2d center(void) const;

		// 判断是否为有效包围盒 
		bool isValid(void) const;

		// 添加进包围盒
		void add(const double x, const double y);
		void add(const Vec2d& v);
		void add(const BoundingBox2d& boundingBox);

		// 相交检测
		bool intersects(const BoundingBox2d& boundingBox) const;


		/* 包含检测 */
		bool contains(const double x, const double y) const;
		bool contains(const Vec2d& v) const;
		bool contains(const Vec2d& v1, const Vec2d v2) const;
		bool contains(const BoundingBox2d& boundingBox) const;


		/* 相等判断 */
		bool operator == (const BoundingBox2d& boundingBox) const;

	}; // class BoundingBox2d

} // namespace CAX


#endif