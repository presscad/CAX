#pragma once


#ifndef _CIRCLE2D_H_
#define _CIRCLE2D_H_


#include "Entity2d.h"
#include "Vec2.h"


namespace CAX
{

	class Circle2d : public Entity2d
	{
	public:
		// {{ 构造函数和析构函数 }}
		Circle2d();
		virtual ~Circle2d();


		// {{ override }}
		// 返回二维图形的类型
		virtual Type type(void) const;
		// 判断是否封闭
		bool isClosed(void) const;
		// 返回圆心
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
		Vec2d& center(void);
		double& radius(void);
		bool& clockwise(void);

	private:
		// {{ 属性 }}
		//  圆心、半径和转向 
		Vec2d m_center;			// 圆心
		double m_radius;		// 半径
		bool m_clockwise;		// 是否顺时针

	}; // class Circle2d

} // namespace CAX


#endif