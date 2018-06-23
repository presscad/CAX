#pragma once


#ifndef _BOUNDINGBOX3D_H_
#define _BOUNDINGBOX3D_H_


#include "Vec2.h"
#include "Vec3.h"


namespace CAX
{

	class BoundingBox3d
	{
	public:
		// {{ 最小值，最大值 }} 
		double minX;
		double minY;
		double minZ;
		double maxX;
		double maxY;
		double maxZ;

		BoundingBox3d();
		BoundingBox3d(
			const double fMinX, const double fMinY, const double fMinZ,
			const double fMaxX, const double fMaxY, const double fMaxZ);
		~BoundingBox3d();

		// 复制构造函数 和 赋值函数
		BoundingBox3d(const BoundingBox3d& boundingBox);
		BoundingBox3d& operator = (const BoundingBox3d& boundingBox);

		// 获取中心
		Vec3d center(void) const;

		// 判断是否为有效包围盒
		bool isValid(void) const;

		// 添加进包围盒
		void add(const double x, const double y, const double z);
		void add(const Vec3d& v);
		void add(const BoundingBox3d& boundingBox);

		// 相交检测
		bool intersects(const BoundingBox3d& boundingBox) const;

		// 包含检测
		bool contains(const double x, const double y, const double z) const;
		bool contains(const Vec3d& v) const;
		bool contains(const Vec3d& v1, const Vec3d v2) const;
		bool contains(const BoundingBox3d& boundingBox) const;


		// 相等判断
		bool operator == (const BoundingBox3d& boundingBox) const;

	}; // class BoundingBox3d

} // namespace CAX


#endif