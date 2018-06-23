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
		// 构造函数 和 析构函数
		Chain2d();
		explicit Chain2d(Entity2d* pEntity);
		explicit Chain2d(const std::list<Entity2d*>& entityList);
		virtual ~Chain2d();

		// {{ override }}
		/* 返回二维图形的类型 */
		virtual Type type(void) const;
		// 判断是否封闭
		virtual bool isClosed(void) const;
		// 获取图元的起点和终点
		virtual Vec2d head(void) const;
		virtual Vec2d tail(void) const;
		// 获取包围盒
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// 反向
		virtual void reverse(void);
		// 获取长度
		virtual double length(void) const;


		// 判断list<Entity2d*>是否已经排序
		static bool isSorted(const std::list<Entity2d*>& entityList);
		// 判断是否已经排序
		bool isSorted(void) const;


		// {{ 获取属性 }}
		std::list<Entity2d*>& entities(void);

	private:
		// 单链中的实体集合
		std::list<Entity2d*> m_entities;

	};

} // namespace CAX


#endif