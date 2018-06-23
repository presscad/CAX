#pragma once

#ifndef _POLYLINE2D_H_
#define _POLYLINE2D_H_

#include <list>

#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{

	class Polyline2d : public Entity2d
	{
	public:
		// {{ 静态函数 }}
		static double SignedArea(const std::list<Vec2d>& vertices);
		static double Area(const std::list<Vec2d>& vertices);


		// {{ 构造函数和析构函数 }}
		Polyline2d();
		explicit Polyline2d(const std::list<Vec2d>& vertices);
		~Polyline2d();

		
		// {{ override }}
		// 返回二维图形的类型
		virtual Type type(void) const;
		// 判断是否封闭
		bool isClosed(void) const;
		// 获取多段线的起点和终点
		Vec2d head(void) const;
		Vec2d tail(void) const;
		// 获取包围盒
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// 反向
		virtual void reverse(void);
		// 获取长度
		virtual double length(void) const;


		// {{ 获取属性 }}
		std::list<Vec2d>& vertices(void);


		// 获取
		double signedArea(void) const;
		double area(void) const;

	private:
		// 多段线的顶点集
		std::list<Vec2d> m_vertices;
	};

} // namespace CAX


#endif // _POLYLINE2D_H_

