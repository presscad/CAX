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
		~Arc2d();


		/* @override 判断是否封闭 */
		bool isClosed(void);

		/* @override 获取起点和终点 */
		Vec2d head(void);
		Vec2d tail(void);
		
		/* 获取圆心、半径、起点弧度和终点弧度 */
		Vec2d& center(void);
		double& radius(void);
		double& startRadian(void);
		double& endRadian(void);

	private:
		/* 圆心、半径、起点弧度和终点弧度	
		 * 弧度范围是[0~2pi]		
		 * 顺时针圆弧起点 > 终点， 逆时针圆弧反之 */
		Vec2d m_center;			// 圆心
		double m_radius;		// 半径
		double m_startRadian;	// 起点弧度
		double m_endRadian;		// 终点弧度

	}; // Arc2d

} // namespace CAX


#endif
