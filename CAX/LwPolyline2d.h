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

		/* @override 判断是否封闭 */
		bool isClosed(void);

		/* @override 获取起点和终点 */
		Vec2d head(void);
		Vec2d tail(void);

	private:
		/* 直线和圆弧的集合 */
		std::list<Entity2d*> m_segments;
		

	}; // class LwPolyline2d

} // namespace CAX



#endif