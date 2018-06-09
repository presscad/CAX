#pragma once

#ifndef _LWPOLYLINE_H_
#define _LWPOLYLINE_H_


#include <list>


#include "Entity2d.h"


namespace CAX
{
	
	class LwPolyline2d : public Entity2d
	{
	public:
		LwPolyline2d();
		~LwPolyline2d();

		/* @override �ж��Ƿ��� */
		bool isClosed(void);

		/* @override ��ȡ�����յ� */
		Vec2d head(void);
		Vec2d tail(void);

	private:
		/* ֱ�ߺ�Բ���ļ��� */
		std::list<Entity2d*> m_segments;
		

	}; // class LwPolyline2d

} // namespace CAX



#endif