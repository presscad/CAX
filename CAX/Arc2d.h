#pragma once

#ifndef _ARC2D_H_
#define _ARC2D_H_


#include "Entity2d.h"
#include "Vec2.h"

namespace CAX
{
	
	class Arc2d : public Entity2d
	{
	public:
		/* 构造函数和析构函数 */
		Arc2d();
		virtual ~Arc2d();


		// {{ @override }}
		/* 返回二维图形的类型 */
		virtual Type type(void) const;
		// 判断是否封闭
		bool isClosed(void) const;
		// 获取起点和终点
		Vec2d head(void) const;
		Vec2d tail(void) const;
		// 获取包围盒
		virtual BoundingBox2d boundingBox2d(void) const;
		virtual BoundingBox3d boundingBox3d(void) const;
		// 反向
		virtual void reverse(void);
		// 获取长度
		virtual double length(void) const;

		
		// 获取圆心、半径、起点弧度和终点弧度
		Vec2d& center(void);
		double& radius(void);
		double& startRadian(void);
		double& endRadian(void);

		// 获取弧度跨度 或 角度跨度
		double radianRange(void) const;
		double degreeRange(void) const;

		// 获取绝对弧度跨度 或 绝对角度跨度
		double absRadianRange(void) const;
		double absDegreeRange(void) const;

		// 根据起点、终点和凸度三个参数 换算 圆弧参数
		void fromBulge(const Vec2d& start, const Vec2d& end, const double bulge);


	private:
		// 圆心、半径、起点弧度和终点弧度	
		// 弧度范围是[0~2pi]		
		// 顺时针圆弧起点 > 终点， 逆时针圆弧反之
		Vec2d m_center;			// 圆心
		double m_radius;		// 半径
		double m_startRadian;	// 起点弧度
		double m_endRadian;		// 终点弧度
		bool m_clockwise;		// 是否逆时针

	}; // Arc2d

} // namespace CAX


#endif
