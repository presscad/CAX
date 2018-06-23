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

		// {{ ��ȡ���� }}
		std::list<Entity2d*>& segments(void);

	private:
		// ֱ�ߺ�Բ���ļ���
		std::list<Entity2d*> m_segments;
		

	}; // class LwPolyline2d

} // namespace CAX



#endif