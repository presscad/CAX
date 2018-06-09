#include "MathTools.h"


#include <algorithm>


#include "Constants.h"


namespace CAX
{
	template<typename T>
	T toRadians(const T degrees)
	{
		return static_cast<T>(degrees * Constants<T>::PI / 180.0);
	}

	template<typename T>
	T toDegrees(const T radians)
	{
		return static_cast<T>(radians * 180.0 / Constants<T>::PI);
	}

	template<typename T>
	T clamp(const T value, const T lower, const T upper)
	{
		return std::max<T>(std::min<T>(upper, value), lower);
	}

	template<typename T>
	bool equals(const T value1, const T value2)
	{
		return std::abs(value1 - value2) < Constants<T>::EPSILON;
	}





	void CRC16_Modbus(unsigned char *data, unsigned int nBytes, unsigned char* res)
	{
		unsigned short value = 0xFFFF;

		for (int i = 0; i<nBytes; i++)
		{
			value ^= data[i];
			unsigned short exor = value & 0x0001;
			for (int j = 0; j<8; j++)
			{
				value = value >> 1;
				if (exor)
				{
					value ^= 0xA001;
				}
				exor = value & 0x0001;
			}
		}
		res[0] = (value >> 8) & 0x00FF;
		res[1] = value & 0x00FF;
	}



	template float toRadians<float>(const float degrees);
	template double toRadians<double>(const double degrees);

	template float toDegrees<float>(const float radians);
	template double toDegrees<double>(const double radians);

	template float clamp<float>(const float value, const float lower, const float upper);
	template double clamp<double>(const double value, const double lower, const double upper);

	template bool equals<float>(const float value1, const float value2);
	template bool equals<double>(const double value1, const double value2);
}