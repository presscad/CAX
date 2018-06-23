#pragma once


#ifndef _TRIANGLE2D_H_
#define _TRIANGLE2D_H_


#include "Entity2d.h"
#include "Vec2.h"


namespace CAX
{

	class Triangle2d : public Entity2d
	{
	public:

		// {{ ��̬���� }}
		// �������
		static double SignedArea(const Vec2d& v1, const Vec2d& v2, const Vec2d& v3);
		// ���
		static double Area(const Vec2d& v1, const Vec2d& v2, const Vec2d& v3);


		// {{ ���캯�� �� �������� }}
		Triangle2d();
		virtual ~Triangle2d();


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
		Vec2d* vertices(void);

		// ͨ��������ȡ����
		Vec2d& operator [](unsigned short index);
		const Vec2d& operator [](unsigned short index) const;

		// {{ ��ȡ }}
		// �������
		double signedArea(void) const;
		// ���
		double area(void) const;
		


	private:
		// {{ ���� }}
		Vec2d m_vertices[3];		// ��������
		bool m_clockwise;			// �Ƿ���ʱ��


	}; // class Triangle2d

} // namespace CAX


#endif