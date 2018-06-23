#pragma once


#ifndef _TRIANGLE2D_H_
#define _TRIANGLE2D_H_


#include "Entity2d.h"
#include "Vec2.h"


namespace CAX
{

	class Triangle2d : public Entity2d
	{
	public:

		// {{ 静态函数 }}
		// 符号面积
		static double SignedArea(const Vec2d& v1, const Vec2d& v2, const Vec2d& v3);
		// 面积
		static double Area(const Vec2d& v1, const Vec2d& v2, const Vec2d& v3);


		// {{ 构造函数 和 析构函数 }}
		Triangle2d();
		virtual ~Triangle2d();


		// {{ override }}
		/* 返回二维图形的类型 */
		virtual Type type(void) const;
		// 判断是否封闭
		virtual bool isClosed(void) const;
		// 获取图元的起点和终点
		virtual Vec2d head(void) const;
		virtual Vec2d tail(void) const;
		// 获取包围盒
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// 反向
		virtual void reverse(void);
		// 获取长度
		virtual double length(void) const;


		// {{ 获取属性 }}
		Vec2d* vertices(void);

		// 通过索引获取顶点
		Vec2d& operator [](unsigned short index);
		const Vec2d& operator [](unsigned short index) const;

		// {{ 获取 }}
		// 符号面积
		double signedArea(void) const;
		// 面积
		double area(void) const;
		


	private:
		// {{ 属性 }}
		Vec2d m_vertices[3];		// 三个顶点
		bool m_clockwise;			// 是否逆时针


	}; // class Triangle2d

} // namespace CAX


#endif