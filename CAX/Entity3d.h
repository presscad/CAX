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
			Curve,		// ����
			Surface,	// ����
			Solid,		// ʵ��
		};

		// ���캯�� �� ��������
		Entity3d();
		virtual ~Entity3d();

		// ���ػ�������
		virtual BaseType baseType(void) const = 0;
		// ��ȡ��Χ��
		virtual BoundingBox3d boundingBox3d(void) const = 0;


	private:

	};

} // namespace CAX

#endif // #ifndef _ENTITY3D_H_