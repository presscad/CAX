#pragma once


#ifndef _SPLINE2D_H_
#define _SPLINE2D_H_


#include <vector>


#include "Entity2d.h"


namespace CAX
{

	class Spline2d : public Entity2d
	{
	public:
		// {{ 构造函数和析构函数 }}
		Spline2d();
		~Spline2d();


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


		// {{ 获取属性 }}
		std::vector<Vec2d>& controls(void);
		std::vector<double>& knots(void);
		unsigned int& degree(void);

	private:
		// {{ 属性 }}
		std::vector<Vec2d> m_controls;
		std::vector<double> m_knots;
		unsigned int m_degree;


	}; // class Spline2d

} // namespace CAX


#endif