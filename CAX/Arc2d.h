#pragma once

#ifndef _ARC2D_H_
#define _ARC2D_H_


#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{
	
	class Arc2d : public Entity2d
	{
	public:
		/* ���캯������������ */
		Arc2d();
		virtual ~Arc2d();


		// {{ @override }}
		/* ���ض�άͼ�ε����� */
		virtual Type type(void) const;
		// �ж��Ƿ���
		bool isClosed(void) const;
		// ��ȡ�����յ�
		Vec2d head(void) const;
		Vec2d tail(void) const;
		// ��ȡ��Χ��
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// ����
		virtual void reverse(void);
		// ��ȡ����
		virtual double length(void) const;

		
		// ��ȡԲ�ġ��뾶����㻡�Ⱥ��յ㻡��
		Vec2d& center(void);
		double& radius(void);
		double& startRadian(void);
		double& endRadian(void);

		// ��ȡ���ȿ�� �� �Ƕȿ��
		double radianRange(void) const;
		double degreeRange(void) const;

		// ��ȡ���Ի��ȿ�� �� ���ԽǶȿ��
		double absRadianRange(void) const;
		double absDegreeRange(void) const;

		// ������㡢�յ��͹���������� ���� Բ������
		void fromBulge(const Vec2d& start, const Vec2d& end, const double bulge);


	private:
		// Բ�ġ��뾶����㻡�Ⱥ��յ㻡��	
		// ���ȷ�Χ��[0~2pi]		
		// ˳ʱ��Բ����� > �յ㣬 ��ʱ��Բ����֮
		Vec2d m_center;			// Բ��
		double m_radius;		// �뾶
		double m_startRadian;	// ��㻡��
		double m_endRadian;		// �յ㻡��
		bool m_clockwise;		// �Ƿ���ʱ��

	}; // Arc2d

} // namespace CAX


#endif
