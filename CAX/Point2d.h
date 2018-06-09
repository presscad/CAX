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
		/* ���캯������������ */
		Point2d();
		Point2d(double x, double y);
		virtual ~Point2d();

		/* ��ȡ���λ�� */
		Vec2d& location(void);

		/* @override �ж��Ƿ��� */
		bool isClosed(void);

		/* @override ��ȡͼԪ�������յ� */
		Vec2d head(void);
		Vec2d tail(void);

	private:
		/* ���λ�� */
		Vec2d m_location;

	};
}


#endif


