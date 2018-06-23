#pragma once


#ifndef _ELLIPSE2d_H_
#define _ELLIPSE2d_H_


#include "Vec2.h"
#include "Entity2d.h"


namespace CAX
{

	class Ellipse2d : public Entity2d
	{
	public:
		Ellipse2d();
		~Ellipse2d();

		/* @override */
		/* 返回二维图形的类型 */
		virtual Type type(void) const;
		/* 判断是否封闭 */
		virtual bool isClosed(void) const;
		/* 获取图元的起点和终点 */
		virtual Vec2d head(void) const;
		virtual Vec2d tail(void) const;
		/* 获取包围盒 */
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		/* 反向 */
		virtual void reverse(void);
		// 获取长度
		virtual double length(void) const;


		/* 获取属性 */
		Vec2d& center(void);
		double& major(void);
		double& minor(void);
		double& startRadian(void);
		double& endRadian(void);
		double& rotateRadian(void);


	private:
		/* 椭圆心、主轴长、短轴长、起点弧度，终点弧度和旋转角度*/
		Vec2d m_center;
		double m_major;
		double m_minor;
		double m_startRadian;
		double m_endRadian;
		double m_rotateRadian;		// [-90, 90]
		bool m_clockwise;			// 是否逆时针

	}; // class Ellipse2d

} // namespace CAX


#endif