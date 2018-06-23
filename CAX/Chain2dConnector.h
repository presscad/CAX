#pragma once


#ifndef _CHAIN2DCONNECTOR_H_
#define _CHAIN2DCONNECTOR_H_


#include <list>


#include "Chain2d.h"


namespace CAX
{

	class Chain2dConnector
	{
	public:
		Chain2dConnector();
		Chain2dConnector(const std::list<Entity2d*>& entityList);
		~Chain2dConnector();

		// {{ ��ȡ���� }}
		std::list<Chain2d>& chains(void);
		

		// ��list<Entity2d*>���д���
		void fromList(const std::list<Entity2d*>& entityList);

	private:
		// ��������
		std::list<Chain2d> m_chains;
	};

} // namespace CAX


#endif