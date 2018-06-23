#pragma once


#include "Constants.h"


namespace CAX
{

	// �Ƕ� => ����
	template<typename T>
	inline T toRadians(const T degrees);

	// ���� => �Ƕ� 
	template<typename T>
	inline T toDegrees(const T radians);

	// clamp 
	// ��valueֵ������lower��upper֮��
	// ��С��lower�������lower
	// ������upper�������upper
	template<typename T>
	T clamp(const T value, const T lower, const T upper);

	// ���ڵ�clamp
	// ��valueֵ������lower��upper֮��
	// ����Ϊ(upper-lower)
	template<typename T>
	T cycleClamp(const T value, const T lower, const T upper);

	// �ж���� 
	// ��Ҫ���ڸ�����������ж�
	template<typename T>
	bool equals(const T value1, const T value2);

	// ��Χ�ж�
	template<typename T>
	bool inRange(const T value, const T fmin, const T fmax);



	// ����Modbus���͵�CRC16У����
	void CRC16_Modbus(unsigned char *data, unsigned int nBytes, unsigned char* res);
	
}


