#pragma once


#include "Constants.h"


namespace CAX
{

	// 角度 => 弧度
	template<typename T>
	inline T toRadians(const T degrees);

	// 弧度 => 角度 
	template<typename T>
	inline T toDegrees(const T radians);

	// clamp 
	// 将value值限制在lower和upper之间
	// 若小于lower，则等于lower
	// 若大于upper，则等于upper
	template<typename T>
	T clamp(const T value, const T lower, const T upper);

	// 周期的clamp
	// 将value值限制在lower和upper之间
	// 周期为(upper-lower)
	template<typename T>
	T cycleClamp(const T value, const T lower, const T upper);

	// 判断相等 
	// 主要用于浮点数的相等判断
	template<typename T>
	bool equals(const T value1, const T value2);

	// 范围判断
	template<typename T>
	bool inRange(const T value, const T fmin, const T fmax);



	// 计算Modbus类型的CRC16校验码
	void CRC16_Modbus(unsigned char *data, unsigned int nBytes, unsigned char* res);
	
}


