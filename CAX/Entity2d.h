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
			Point,			// ��
			Line,			// �߶�
			Polyline,		// �����
			LwPolyline,		// ���߶κ�Բ����ɵĶ����
			Arc,			// Բ��
			Circle,			// Բ
			Ellipse,		// ��Բ
		};

		/* ���캯������������ */
		Entity2d(Type type);
		virtual ~Entity2d();

		/* ���ض�άͼ�ε����� */
		Type type(void) const;


		/* �ж��Ƿ��� */
		virtual bool isClosed(void) = 0;

		/* ����ͼԪ�������յ� */
		virtual Vec2d head(void) = 0;
		virtual Vec2d tail(void) = 0;

	private:

		const Type m_type;

	}; // class Entity2d

} // namespace CAX


#endif