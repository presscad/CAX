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
		// {{ ��Сֵ�����ֵ }} 
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

		// ���ƹ��캯�� �� ��ֵ����
		BoundingBox3d(const BoundingBox3d& boundingBox);
		BoundingBox3d& operator = (const BoundingBox3d& boundingBox);

		// ��ȡ����
		Vec3d center(void) const;

		// �ж��Ƿ�Ϊ��Ч��Χ��
		bool isValid(void) const;

		// ��ӽ���Χ��
		void add(const double x, const double y, const double z);
		void add(const Vec3d& v);
		void add(const BoundingBox3d& boundingBox);

		// �ཻ���
		bool intersects(const BoundingBox3d& boundingBox) const;

		// �������
		bool contains(const double x, const double y, const double z) const;
		bool contains(const Vec3d& v) const;
		bool contains(const Vec3d& v1, const Vec3d v2) const;
		bool contains(const BoundingBox3d& boundingBox) const;


		// ����ж�
		bool operator == (const BoundingBox3d& boundingBox) const;

	}; // class BoundingBox3d

} // namespace CAX


#endif