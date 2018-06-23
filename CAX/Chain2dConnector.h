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

		// {{ 获取属性 }}
		std::list<Chain2d>& chains(void);
		

		// 从list<Entity2d*>进行串接
		void fromList(const std::list<Entity2d*>& entityList);

	private:
		// 单链集合
		std::list<Chain2d> m_chains;
	};

} // namespace CAX


#endif