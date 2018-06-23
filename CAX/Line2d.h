#pragma once

#ifndef _LINE2D_H_
#define _LINE2D_H_

#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{
	
	class Line2d : public Entity2d
	{
	public:
		/* 构造函数和析构函数 */
		Line2d();
		Line2d(const double startx, const double starty, const double endx, const double endy);
		Line2d(const Vec2d& start, const Vec2d& end);
		virtual ~Line2d();
	
		// {{ override }} 
		// 返回二维图形的类型 
		virtual Type type(void) const;
		// 判断是否封闭
		bool isClosed(void) const;
		// 获取起点和终点
		Vec2d head(void) const;
		Vec2d tail(void) const;
		// 获取包围盒
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// 反向
		virtual void reverse(void);
		// 获取长度
		virtual double length(void) const;

		/* 获取起点和终点 */
		Vec2d& start(void);
		Vec2d& end(void);

	private:
		/* 起点和终点 */
		Vec2d m_start;			// 起点
		Vec2d m_end;			// 终点
	};

} // namespace CAX


#endif // #ifndef _LINE2D_H_


