#pragma once

#ifndef _POLYLINE2D_H_
#define _POLYLINE2D_H_

#include <list>

#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{

	class Polyline2d : public Entity2d
	{
	public:
		/* 构造函数和析构函数 */
		Polyline2d();
		explicit Polyline2d(const std::list<Vec2d>& vertices);
		~Polyline2d();

		/* 获取多段线的顶点集 */
		std::list<Vec2d>& vertices(void);

		/* @override 判断是否封闭 */
		bool isClosed(void);

		/* @override 获取多段线的起点和终点 */
		Vec2d head(void);
		Vec2d tail(void);

	private:
		/* 多段线的顶点集 */
		std::list<Vec2d> m_vertices;
	};

} // namespace CAX


#endif // _POLYLINE2D_H_

