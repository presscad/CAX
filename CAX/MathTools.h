#pragma once


#include "Constants.h"


namespace CAX
{

	/* �Ƕ� => ���� */
	template<typename T>
	inline T toRadians(const T degrees);

	/* ���� => �Ƕ� */
	template<typename T>
	inline T toDegrees(const T radians);

	/* clamp */
	template<typename T>
	T clamp(const T value, const T lower, const T upper);

	/* �ж���� 
	 * ��Ҫ���ڸ�����������ж� */
	template<typename T>
	bool equals(const T value1, const T value2);




	void CRC16_Modbus(unsigned char *data, unsigned int nBytes, unsigned char* res);
	
}


