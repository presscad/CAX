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
		/* 构造函数和析构函数 */
		Point2d();
		Point2d(double x, double y);
		virtual ~Point2d();

		/* 获取点的位置 */
		Vec2d& location(void);

		/* @override 判断是否封闭 */
		bool isClosed(void);

		/* @override 获取图元的起点和终点 */
		Vec2d head(void);
		Vec2d tail(void);

	private:
		/* 点的位置 */
		Vec2d m_location;

	};
}


#endif


