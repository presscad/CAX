#pragma once

#ifndef _POLYLINE2D_H_
#define _POLYLINE2D_H_

#include <list>

#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{

	class Polyline2d : public Entity2d
	{
	public:
		// {{ ��̬���� }}
		static double SignedArea(const std::list<Vec2d>& vertices);
		static double Area(const std::list<Vec2d>& vertices);


		// {{ ���캯������������ }}
		Polyline2d();
		explicit Polyline2d(const std::list<Vec2d>& vertices);
		~Polyline2d();

		
		// {{ override }}
		// ���ض�άͼ�ε�����
		virtual Type type(void) const;
		// �ж��Ƿ���
		bool isClosed(void) const;
		// ��ȡ����ߵ������յ�
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
		std::list<Vec2d>& vertices(void);


		// ��ȡ
		double signedArea(void) const;
		double area(void) const;

	private:
		// ����ߵĶ��㼯
		std::list<Vec2d> m_vertices;
	};

} // namespace CAX


#endif // _POLYLINE2D_H_

