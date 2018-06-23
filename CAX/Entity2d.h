#pragma once

#ifndef _ENTITY2D_H_
#define _ENTITY2D_H_


#include "Vec2.h"
#include "BoundingBox2d.h"
#include "BoundingBox3d.h"

namespace CAX
{
	class Point2d;
	class Line2d;
	class Polyline2d;
	class LwPolyline2d;
	class Arc2d;
	class Circle2d;
	class Ellipse2d;

	class Entity2d
	{
	public:
		
		enum Type
		{
			Point,			// 点
			Line,			// 线段
			Polyline,		// 多段线
			LwPolyline,		// 由线段和圆弧组成的多段线
			Arc,			// 圆弧
			Circle,			// 圆
			Ellipse,		// 椭圆
			Spline,			// 样条(NURBS)

			Triangle,		// 三角形

			Chain,			// 单链

			Convex,			// 凸包
		};

		static Point2d* newPoint();
		static Line2d* newLine();
		static Polyline2d* newPolyline();
		static LwPolyline2d* newLwPolyline();
		static Arc2d* newArc();
		static Circle2d* newCircle();
		static Ellipse2d* newEllipse();
		static void deleteInstance(Entity2d* p);
		//template<typename T>
		//static T* newInstance();

		// {{ 构造函数和析构函数 }}
		Entity2d();
		virtual ~Entity2d();

		// 返回二维图形的类型
		virtual Type type(void) const = 0;
		// 判断是否封闭
		virtual bool isClosed(void) const = 0;
		// 返回图元的起点和终点
		virtual Vec2d head(void) const = 0;
		virtual Vec2d tail(void) const = 0;
		// 获取包围盒
		virtual BoundingBox2d boundingBox2d(void) const = 0;
		virtual BoundingBox3d boundingBox3d(void) const = 0;
		// 反向
		virtual void reverse(void) = 0;
		// 获取长度
		virtual double length(void) const = 0;

	private:

	}; // class Entity2d



} // namespace CAX


#endif