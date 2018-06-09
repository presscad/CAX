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
		~Arc2d();


		/* @override �ж��Ƿ��� */
		bool isClosed(void);

		/* @override ��ȡ�����յ� */
		Vec2d head(void);
		Vec2d tail(void);
		
		/* ��ȡԲ�ġ��뾶����㻡�Ⱥ��յ㻡�� */
		Vec2d& center(void);
		double& radius(void);
		double& startRadian(void);
		double& endRadian(void);

	private:
		/* Բ�ġ��뾶����㻡�Ⱥ��յ㻡��	
		 * ���ȷ�Χ��[0~2pi]		
		 * ˳ʱ��Բ����� > �յ㣬 ��ʱ��Բ����֮ */
		Vec2d m_center;			// Բ��
		double m_radius;		// �뾶
		double m_startRadian;	// ��㻡��
		double m_endRadian;		// �յ㻡��

	}; // Arc2d

} // namespace CAX


#endif
