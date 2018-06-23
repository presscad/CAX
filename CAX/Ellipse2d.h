#pragma once


#ifndef _ELLIPSE2d_H_
#define _ELLIPSE2d_H_


#include "Vec2.h"
#include "Entity2d.h"


namespace CAX
{

	class Ellipse2d : public Entity2d
	{
	public:
		Ellipse2d();
		~Ellipse2d();

		/* @override */
		/* ���ض�άͼ�ε����� */
		virtual Type type(void) const;
		/* �ж��Ƿ��� */
		virtual bool isClosed(void) const;
		/* ��ȡͼԪ�������յ� */
		virtual Vec2d head(void) const;
		virtual Vec2d tail(void) const;
		/* ��ȡ��Χ�� */
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		/* ���� */
		virtual void reverse(void);
		// ��ȡ����
		virtual double length(void) const;


		/* ��ȡ���� */
		Vec2d& center(void);
		double& major(void);
		double& minor(void);
		double& startRadian(void);
		double& endRadian(void);
		double& rotateRadian(void);


	private:
		/* ��Բ�ġ����᳤�����᳤����㻡�ȣ��յ㻡�Ⱥ���ת�Ƕ�*/
		Vec2d m_center;
		double m_major;
		double m_minor;
		double m_startRadian;
		double m_endRadian;
		double m_rotateRadian;		// [-90, 90]
		bool m_clockwise;			// �Ƿ���ʱ��

	}; // class Ellipse2d

} // namespace CAX


#endif