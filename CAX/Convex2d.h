#pragma once


#ifndef _CONVEX2D_H_
#define _CONVEX2D_H_


#include <vector>


#include "Entity2d.h"
#include "Vec2.h"


namespace CAX
{

	class Convex2d : public Entity2d
	{
	public:
		// {{ ���캯�� �� �������� }}
		Convex2d();
		~Convex2d();


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
		const std::vector<Vec2d>& vertices(void) const;

	private:
		// {{ ���� }}
		std::vector<Vec2d> m_vertices;		// ͹���Ķ���
		bool m_clockwise;					// �Ƿ�˳ʱ��

	};

} // namespace CAX


#endif