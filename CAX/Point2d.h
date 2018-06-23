#pragma once

#ifndef _POINT2D_H_
#define _POINT2D_H_

#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{
	class Point2d : public Entity2d
	{
	public:
		// 构造函数和析构函数
		Point2d();
		Point2d(double x, double y);
		virtual ~Point2d();

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
		Vec2d& location(void);


	private:
		/* 点的位置 */
		Vec2d m_location;

	};
}


#endif


