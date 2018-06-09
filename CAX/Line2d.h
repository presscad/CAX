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
		~Line2d();

		/* @override �ж��Ƿ��� */
		bool isClosed(void);

		/* @override ��ȡ�����յ� */
		Vec2d head(void);
		Vec2d tail(void);

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


