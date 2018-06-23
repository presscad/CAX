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
		// ��������
		virtual Type type(void) const;
		// ���ذ�Χ��
		virtual BoundingBox3d boundingBox3d(void) const;

		// {{ ��ȡ���� }}
		Vec3d* vertices(void);

	private:
		// {{ ���� }}
		// ��������
		Vec3d m_vertices[3];
	};

} // namespace CAX


#endif