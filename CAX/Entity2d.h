#pragma once

#ifndef _ENTITY2D_H_
#define _ENTITY2D_H_


#include "Vec2.h"


namespace CAX
{

	class Entity2d
	{
	public:
		
		enum Type
		{
			Point,			// 点
			Line,			// 线段
			Polyline,		// 多段线
			LwPolyline,		// 由线段和圆弧组成的多段线
			Arc,			// 圆弧
			Circle,			// 圆
			Ellipse,		// 椭圆
		};

		/* 构造函数和析构函数 */
		Entity2d(Type type);
		virtual ~Entity2d();

		/* 返回二维图形的类型 */
		Type type(void) const;


		/* 判断是否封闭 */
		virtual bool isClosed(void) = 0;

		/* 返回图元的起点和终点 */
		virtual Vec2d head(void) = 0;
		virtual Vec2d tail(void) = 0;

	private:

		const Type m_type;

	}; // class Entity2d

} // namespace CAX


#endif