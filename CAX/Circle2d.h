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
		/* ���캯������������ */
		Circle2d();
		~Circle2d();

		/* @override �ж��Ƿ��� */
		bool isClosed(void);

		/* @override ����Բ�� */
		Vec2d start(void);
		Vec2d end(void);

		/* ����Բ�ĺͰ뾶 */
		inline Vec2d& center(void);
		inline double& radius(void);

	private:
		/* Բ�ġ��뾶��ת�� */
		Vec2d m_center;			// Բ��
		double m_radius;		// �뾶
		bool m_clockwise;		// �Ƿ�˳ʱ��

	}; // class Circle2d

} // namespace CAX


#endif