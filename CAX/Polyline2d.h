#pragma once

#ifndef _POLYLINE2D_H_
#define _POLYLINE2D_H_

#include <list>

#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{

	class Polyline2d : public Entity2d
	{
	public:
		/* ���캯������������ */
		Polyline2d();
		explicit Polyline2d(const std::list<Vec2d>& vertices);
		~Polyline2d();

		/* ��ȡ����ߵĶ��㼯 */
		std::list<Vec2d>& vertices(void);

		/* @override �ж��Ƿ��� */
		bool isClosed(void);

		/* @override ��ȡ����ߵ������յ� */
		Vec2d head(void);
		Vec2d tail(void);

	private:
		/* ����ߵĶ��㼯 */
		std::list<Vec2d> m_vertices;
	};

} // namespace CAX


#endif // _POLYLINE2D_H_

