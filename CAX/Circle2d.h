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
		/* 构造函数和析构函数 */
		Circle2d();
		~Circle2d();

		/* @override 判断是否封闭 */
		bool isClosed(void);

		/* @override 返回圆心 */
		Vec2d start(void);
		Vec2d end(void);

		/* 返回圆心和半径 */
		inline Vec2d& center(void);
		inline double& radius(void);

	private:
		/* 圆心、半径和转向 */
		Vec2d m_center;			// 圆心
		double m_radius;		// 半径
		bool m_clockwise;		// 是否顺时针

	}; // class Circle2d

} // namespace CAX


#endif