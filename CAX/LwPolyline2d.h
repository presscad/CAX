#pragma once

#ifndef _LWPOLYLINE_H_
#define _LWPOLYLINE_H_


#include <list>


#include "Entity2d.h"


namespace CAX
{
	
	class LwPolyline2d : public Entity2d
	{
	public:
		LwPolyline2d();
		~LwPolyline2d();

		// {{ @override }}
		/* 返回二维图形的类型 */
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

		// {{ 获取属性 }}
		std::list<Entity2d*>& segments(void);

	private:
		// 直线和圆弧的集合
		std::list<Entity2d*> m_segments;
		

	}; // class LwPolyline2d

} // namespace CAX



#endif