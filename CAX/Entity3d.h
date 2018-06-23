#pragma once


#ifndef _ENTITY3D_H_
#define _ENTITY3D_H_


#include "BoundingBox3d.h"


namespace CAX
{
	class Entity3d
	{
	public:
		enum BaseType
		{
			Curve,		// 曲线
			Surface,	// 曲面
			Solid,		// 实体
		};

		// 构造函数 和 析构函数
		Entity3d();
		virtual ~Entity3d();

		// 返回基础类型
		virtual BaseType baseType(void) const = 0;
		// 获取包围盒
		virtual BoundingBox3d boundingBox3d(void) const = 0;


	private:

	};

} // namespace CAX

#endif // #ifndef _ENTITY3D_H_