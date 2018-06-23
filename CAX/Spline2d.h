#pragma once


#ifndef _SPLINE2D_H_
#define _SPLINE2D_H_


#include <vector>


#include "Entity2d.h"


namespace CAX
{

	class Spline2d : public Entity2d
	{
	public:
		// {{ ���캯������������ }}
		Spline2d();
		~Spline2d();


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
		std::vector<Vec2d>& controls(void);
		std::vector<double>& knots(void);
		unsigned int& degree(void);

	private:
		// {{ ���� }}
		std::vector<Vec2d> m_controls;
		std::vector<double> m_knots;
		unsigned int m_degree;


	}; // class Spline2d

} // namespace CAX


#endif