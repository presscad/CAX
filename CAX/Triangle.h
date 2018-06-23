#pragma once

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_


#include "Surface3d.h"
#include "Vec3.h"
#include "BoundingBox3d.h"

namespace CAX
{

	class Triangle : public Surface3d
	{
	public:
		Triangle();
		~Triangle();

		// {{ @override }}
		// 返回类型
		virtual Type type(void) const;
		// 返回包围盒
		virtual BoundingBox3d boundingBox3d(void) const;

		// {{ 获取属性 }}
		Vec3d* vertices(void);

	private:
		// {{ 属性 }}
		// 三个顶点
		Vec3d m_vertices[3];
	};

} // namespace CAX


#endif