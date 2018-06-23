#pragma once


#ifndef _CIRCLE2D_H_
#define _CIRCLE2D_H_


#include "Entity2d.h"
#include "Vec2.h"


namespace CAX
{

	class Circle2d : public Entity2d
	{
	public:
		// {{ ���캯������������ }}
		Circle2d();
		virtual ~Circle2d();


		// {{ override }}
		// ���ض�άͼ�ε�����
		virtual Type type(void) const;
		// �ж��Ƿ���
		bool isClosed(void) const;
		// ����Բ��
		Vec2d head(void) const;
		Vec2d tail(void) const;
		// ��ȡ��Χ��
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// ����
		virtual void reverse(void);
		// ��ȡ����
		virtual double length(void) const;

		// {{ ��ȡ���� }}
		Vec2d& center(void);
		double& radius(void);
		bool& clockwise(void);

	private:
		// {{ ���� }}
		//  Բ�ġ��뾶��ת�� 
		Vec2d m_center;			// Բ��
		double m_radius;		// �뾶
		bool m_clockwise;		// �Ƿ�˳ʱ��

	}; // class Circle2d

} // namespace CAX


#endif