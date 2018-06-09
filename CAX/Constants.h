#pragma once
#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <cfloat>

/* 圆周率pi */
#ifndef	F_PI
#define	F_PI	3.1415926f
#endif

#ifndef	D_PI
#define	D_PI	3.141592653589793
#endif

/* 圆周率pi对应的角度值 */
#ifndef F_PI_ANGLE
#define F_PI_ANGLE	180.0f
#endif

#ifndef D_PI_ANGLE
#define D_PI_ANGLE	180.0
#endif

/* 2*pi */
#ifndef F_DOUBLE_PI
#define F_DOUBLE_PI	6.2831853f
#endif

#ifndef D_DOUBLE_PI
#define D_DOUBLE_PI	6.283185307179586
#endif

/* pi/2 */
#ifndef F_HALF_PI
#define F_HALF_PI	1.5707963f
#endif 

#ifndef D_HALF_PI
#define D_HALF_PI	1.570796326794896
#endif 

/* 自然常数e */
#ifndef F_E
#define F_E		2.7182818f
#endif

#ifndef D_E		
#define D_E		2.718281828459045
#endif

/* 浮点数精度Epsilon */
#ifndef F_EPSILON
#define F_EPSILON	1.0e-6f
#endif

#ifndef D_EPSILON
#define D_EPSILON	1.0e-6	
#endif

/* 浮点数最大值 */
#ifndef F_MAX
#define F_MAX	FLT_MAX
#endif

#ifndef D_MAX
#define D_MAX	DBL_MAX
#endif

/* 浮点数最小值 */
#ifndef F_MIN
#define F_MIN	(-FLT_MAX)
#endif

#ifndef D_MIN
#define D_MIN	(-DBL_MAX)
#endif

namespace CAX {

	template <typename T>
	class Constants {
	public:
		typedef T value_type;
	}; // class Constants


	   /* float类型的常量 */
	template<>
	class Constants<float> {
	public:
		typedef float value_type;

		static const value_type PI;
		static const value_type DOUBLE_PI;
		static const value_type HALF_PI;
		static const value_type PI_ANGLE;
		static const value_type E;
		static const value_type MAX;
		static const value_type MIN;
		static const value_type EPSILON;
	}; // class Constants<float>


	   /* double类型的常量 */
	template<>
	class Constants<double> {
	public:
		typedef double value_type;

		static const value_type PI;
		static const value_type DOUBLE_PI;
		static const value_type HALF_PI;
		static const value_type PI_ANGLE;
		static const value_type E;
		static const value_type MAX;
		static const value_type MIN;
		static const value_type EPSILON;
	}; // class Constants<double>

} // namespace Base

#endif



