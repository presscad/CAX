#pragma once


#ifndef _CONVEX2D_H_
#define _CONVEX2D_H_


#include <vector>


#include "Entity2d.h"
#include "Vec2.h"


namespace CAX
{

	class Convex2d : public Entity2d
	{
	public:
		// {{ 构造函数 和 析构函数 }}
		Convex2d();
		~Convex2d();


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
		const std::vector<Vec2d>& vertices(void) const;

	private:
		// {{ 属性 }}
		std::vector<Vec2d> m_vertices;		// 凸包的顶点
		bool m_clockwise;					// 是否顺时针

	};

} // namespace CAX


#endif