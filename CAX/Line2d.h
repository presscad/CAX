#pragma once

#ifndef _LINE2D_H_
#define _LINE2D_H_

#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{
	
	class Line2d : public Entity2d
	{
	public:
		/* ���캯������������ */
		Line2d();
		Line2d(const double startx, const double starty, const double endx, const double endy);
		Line2d(const Vec2d& start, const Vec2d& end);
		virtual ~Line2d();
	
		// {{ override }} 
		// ���ض�άͼ�ε����� 
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

		/* ��ȡ�����յ� */
		Vec2d& start(void);
		Vec2d& end(void);

	private:
		/* �����յ� */
		Vec2d m_start;			// ���
		Vec2d m_end;			// �յ�
	};

} // namespace CAX


#endif // #ifndef _LINE2D_H_


