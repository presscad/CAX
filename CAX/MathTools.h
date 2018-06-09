#pragma once


#include "Constants.h"


namespace CAX
{

	/* 角度 => 弧度 */
	template<typename T>
	inline T toRadians(const T degrees);

	/* 弧度 => 角度 */
	template<typename T>
	inline T toDegrees(const T radians);

	/* clamp */
	template<typename T>
	T clamp(const T value, const T lower, const T upper);

	/* 判断相等 
	 * 主要用于浮点数的相等判断 */
	template<typename T>
	bool equals(const T value1, const T value2);




	void CRC16_Modbus(unsigned char *data, unsigned int nBytes, unsigned char* res);
	
}


