#pragma once


#ifndef _CHAIN2D_H_
#define _CHAIN2D_H_


#include <list>


#include "Entity2d.h"


namespace CAX
{

	class Chain2d : public Entity2d
	{
	public:
		// ���캯�� �� ��������
		Chain2d();
		explicit Chain2d(Entity2d* pEntity);
		explicit Chain2d(const std::list<Entity2d*>& entityList);
		virtual ~Chain2d();

		// {{ override }}
		/* ���ض�άͼ�ε����� */
		virtual Type type(void) const;
		// �ж��Ƿ���
		virtual bool isClosed(void) const;
		// ��ȡͼԪ�������յ�
		virtual Vec2d head(void) const;
		virtual Vec2d tail(void) const;
		// ��ȡ��Χ��
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// ����
		virtual void reverse(void);
		// ��ȡ����
		virtual double length(void) const;


		// �ж�list<Entity2d*>�Ƿ��Ѿ�����
		static bool isSorted(const std::list<Entity2d*>& entityList);
		// �ж��Ƿ��Ѿ�����
		bool isSorted(void) const;


		// {{ ��ȡ���� }}
		std::list<Entity2d*>& entities(void);

	private:
		// �����е�ʵ�弯��
		std::list<Entity2d*> m_entities;

	};

} // namespace CAX


#endif