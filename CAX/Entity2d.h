#pragma once

#ifndef _ENTITY2D_H_
#define _ENTITY2D_H_


#include "Vec2.h"
#include "BoundingBox2d.h"
#include "BoundingBox3d.h"

namespace CAX
{
	class Point2d;
	class Line2d;
	class Polyline2d;
	class LwPolyline2d;
	class Arc2d;
	class Circle2d;
	class Ellipse2d;

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
			Spline,			// ����(NURBS)

			Triangle,		// ������

			Chain,			// ����

			Convex,			// ͹��
		};

		static Point2d* newPoint();
		static Line2d* newLine();
		static Polyline2d* newPolyline();
		static LwPolyline2d* newLwPolyline();
		static Arc2d* newArc();
		static Circle2d* newCircle();
		static Ellipse2d* newEllipse();
		static void deleteInstance(Entity2d* p);
		//template<typename T>
		//static T* newInstance();

		// {{ ���캯������������ }}
		Entity2d();
		virtual ~Entity2d();

		// ���ض�άͼ�ε�����
		virtual Type type(void) const = 0;
		// �ж��Ƿ���
		virtual bool isClosed(void) const = 0;
		// ����ͼԪ�������յ�
		virtual Vec2d head(void) const = 0;
		virtual Vec2d tail(void) const = 0;
		// ��ȡ��Χ��
		virtual BoundingBox2d boundingBox2d(void) const = 0;
		virtual BoundingBox3d boundingBox3d(void) const = 0;
		// ����
		virtual void reverse(void) = 0;
		// ��ȡ����
		virtual double length(void) const = 0;

	private:

	}; // class Entity2d



} // namespace CAX


#endif