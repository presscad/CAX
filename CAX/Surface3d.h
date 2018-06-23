#pragma once


#ifndef _SURFACE3D_H_
#define _SURFACE3D_H_


#include "Entity3d.h"


namespace CAX
{

	class Surface3d : public Entity3d
	{
	public:
		enum Type
		{
			Triangle,
			TriangleSurface,
		};

		// 构造函数 和 析构函数
		Surface3d();
		virtual ~Surface3d();

		// {{ override }}
		// 返回基础类型
		virtual BaseType baseType(void) const;
		// 返回包围盒
		virtual BoundingBox3d boundingBox3d(void) const = 0;

		virtual Type type(void) const = 0;
	};

} // namespace CAX


#endif