#pragma once

#ifndef _POINT2D_H_
#define _POINT2D_H_

#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{
	class Point2d : public Entity2d
	{
	public:
		// ���캯������������
		Point2d();
		Point2d(double x, double y);
		virtual ~Point2d();

		// {{ override }}
		/* ���ض�άͼ�ε����� */
		virtual Type type(void) const;
		// �ж��Ƿ���
		virtual bool isClosed(void) const;
		// ��ȡͼԪ�������յ�
		virtual Vec2d head(void) const;
		virtual Vec2d tail(void) const;
		// ��ȡ��Χ��
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// ����
		virtual void reverse(void);
		// ��ȡ����
		virtual double length(void) const;

		// {{ ��ȡ���� }}
		Vec2d& location(void);


	private:
		/* ���λ�� */
		Vec2d m_location;

	};
}


#endif


