#include "Vec3.h"

#include <cmath>

#include "Constants.h"


namespace CAX
{
	template<typename T>
	Vec3<T>::Vec3(void) :
		x(0),
		y(0),
		z(0)
	{

	}

	template<typename T>
	Vec3<T>::Vec3(T value) :
		x(value),
		y(value),
		z(value)
	{

	}

	template<typename T>
	Vec3<T>::Vec3(T fx, T fy) :
		x(fx),
		y(fy),
		z(0)
	{

	}

	template<typename T>
	Vec3<T>::Vec3(T fx, T fy, T fz) :
		x(fx),
		y(fy),
		z(fz)
	{

	}

	template<typename T>
	Vec3<T>::Vec3(const Vec3<T>& v) :
		x(v.x),
		y(v.y),
		z(v.z)
	{

	}


	template<typename T>
	Vec3<T>& Vec3<T>::operator = (const Vec3<T>& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}



	template<typename T>
	Vec3<T>::~Vec3(void)
	{

	}


	template<typename T>
	typename T& Vec3<T>::operator[] (unsigned short index)
	{
		switch (index) {
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		}
		return x;
	}

	template<typename T>
	const T& Vec3<T>::operator[] (unsigned short index) const
	{
		switch (index) {
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		}
		return x;
	}


	template<typename T>
	Vec3<T> Vec3<T>::operator + (const Vec3<T>& v) const
	{
		return Vec3<T>(x + v.x, y + v.y, z + v.z);
	}

	template<typename T>
	Vec3<T> Vec3<T>::operator + (const T value) const
	{
		return Vec3<T>(x + value, y + value, z + value);
	}

	template<typename T>
	Vec3<T> operator + (const T value, const Vec3<T>& v)
	{
		return Vec3<T>(value + v.x, value + v.y, value + v.z);
	}


	template<typename T>
	Vec3<T> Vec3<T>::operator - (const Vec3<T>& v) const
	{
		return Vec3<T>(x - v.x, y - v.y, z - v.z);
	}

	template<typename T>
	Vec3<T> Vec3<T>::operator - (const T value) const
	{
		return Vec3<T>(x - value, y - value, z - value);
	}

	template<typename T>
	Vec3<T> operator - (const T value, const Vec3<T>& v)
	{
		return Vec3<T>(value - v.x, value - v.y, value - v.z);
	}


	template<typename T>
	Vec3<T> Vec3<T>::operator * (const Vec3<T>& v) const
	{
		return Vec3<T>(x * v.x, y * v.y, z * v.z);
	}

	template<typename T>
	Vec3<T> Vec3<T>::operator * (const T value) const
	{
		return Vec3<T>(x * value, y * value, z * value);
	}

	template<typename T>
	Vec3<T> operator * (const T value, const Vec3<T>& v)
	{
		return Vec3<T>(value * v.x, value * v.y, value * v.z);
	}


	template<typename T>
	Vec3<T> Vec3<T>::operator / (const Vec3<T>& v) const
	{
		return Vec3<T>(x / v.x, y / v.y, z / v.z);
	}

	template<typename T>
	Vec3<T> Vec3<T>::operator / (const T value) const
	{
		return Vec3<T>(x / value, y / value, z / value);
	}

	template<typename T>
	Vec3<T> operator / (const T value, const Vec3<T>& v)
	{
		return Vec3<T>(value / v.x, value / v.y, value / v.z);
	}


	template<typename T>
	Vec3<T> Vec3<T>::operator - (void) const
	{
		return Vec3<T>(-x, -y, -z);
	}


	template<typename T>
	Vec3<T>& Vec3<T>::operator += (const Vec3<T>& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	template<typename T>
	Vec3<T>& Vec3<T>::operator += (const T value)
	{
		x += value;
		y += value;
		z += value;
		return *this;
	}


	template<typename T>
	Vec3<T>& Vec3<T>::operator -= (const Vec3<T>& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	template<typename T>
	Vec3<T>& Vec3<T>::operator -= (const T value)
	{
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}


	template<typename T>
	Vec3<T>& Vec3<T>::operator *= (const Vec3<T>& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	template<typename T>
	Vec3<T>& Vec3<T>::operator *= (const T value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}


	template<typename T>
	Vec3<T>& Vec3<T>::operator /= (const Vec3<T>& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}

	template<typename T>
	Vec3<T>& Vec3<T>::operator /= (const T value)
	{
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}


	template<typename T>
	bool Vec3<T>::operator == (const Vec3<T>& v) const
	{
		return (std::abs(x - v.x) <= Constants<T>::EPSILON)
			&& (std::abs(y - v.y) <= Constants<T>::EPSILON)
			&& (std::abs(z - v.z) <= Constants<T>::EPSILON);
	}

	template<typename T>
	bool Vec3<T>::operator != (const Vec3<T>& v) const
	{
		return !((*this) == v);
	}



	template<typename T>
	T Vec3<T>::length(void) const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	template<typename T>
	T Vec3<T>::length(const Vec3<T>& v) const
	{
		T dx = x - v.x;
		T dy = y - v.y;
		T dz = z - v.z;
		return std::sqrt(dx * dx + dy * dy + dz * dz);
	}

	template<typename T>
	T Vec3<T>::squareLength(void) const
	{
		return (x * x + y * y + z * z);
	}

	template<typename T>
	T Vec3<T>::squareLength(const Vec3<T>& v) const
	{
		T dx = x - v.x;
		T dy = y - v.y;
		T dz = z - v.z;
		return (dx * dx + dy * dy + dz * dz);
	}


	template<typename T>
	T Vec3<T>::dot(const Vec3<T>& v) const
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	template<typename T>
	Vec3<T> Vec3<T>::cross(const Vec3<T>& v) const
	{
		return Vec3<T>(
			(y * v.z) - (z * v.y),
			(z * v.x) - (x * v.z),
			(x * v.y) - (y * v.x));
	}


	template<typename T>
	void Vec3<T>::set(T fx, T fy, T fz)
	{
		x = fx;
		y = fy;
		z = fz;
	}

	template<typename T>
	void Vec3<T>::scaleX(T sx)
	{
		x *= sx;
	}

	template<typename T>
	void Vec3<T>::scaleY(T sy)
	{
		y *= sy;
	}

	template<typename T>
	void Vec3<T>::scaleZ(T sz)
	{
		z *= sz;
	}

	template<typename T>
	void Vec3<T>::scale(T sx, T sy, T sz)
	{
		x *= sx;
		y *= sy;
		z *= sz;
	}

	template<typename T>
	void Vec3<T>::translateX(T tx)
	{
		x += tx;
	}

	template<typename T>
	void Vec3<T>::translateY(T ty)
	{
		y += ty;
	}

	template<typename T>
	void Vec3<T>::translateZ(T tz)
	{
		z += tz;
	}

	template<typename T>
	void Vec3<T>::translate(T tx, T ty, T tz)
	{
		x += tx;
		y += ty;
		z += tz;
	}

	template<typename T>
	void Vec3<T>::rotateX(T rx)
	{
		T fy = y;
		T fz = z;
		T fsin = std::sin(rx);
		T fcos = std::cos(rx);

		y = (fy * fcos) - (fz * fsin);
		z = (fy * fsin) + (fz * fcos);
	}

	template<typename T>
	void Vec3<T>::rotateY(T ry)
	{
		T fx = x;
		T fz = z;
		T fsin = std::sin(ry);
		T fcos = std::cos(ry);

		x = (fz * fsin) + (fx * fcos);
		z = (fz * fcos) - (fx * fsin);
	}

	template<typename T>
	void Vec3<T>::rotateZ(T rz)
	{
		T fx = x;
		T fy = y;
		T fsin = std::sin(rz);
		T fcos = std::cos(rz);

		x = (fx * fcos) - (fy * fsin);
		y = (fx * fsin) + (fy * fcos);
	}

	template<typename T>
	Vec3<T>& Vec3<T>::normalize(void)
	{
		T len = length();
		if (len != 0.0f && len != 1.0f) {
			x /= len;
			y /= len;
			z /= len;
		}
		return *this;
	}


	template<typename T>
	T Vec3<T>::getAngle(const Vec3<T>& v)
	{
		T den = length() * v.length();

		if (std::abs(den) > 1.0e-10f) {
			T fcos = dot(v) / den;
			if (fcos <= -1.0f) {
				return Constants<T>::PI;
			}
			else if (fcos >= 1.0f) {
				return 0.0f;
			}
			else {
				return std::acos(fcos);
			}
		}

		//分母为0
		return Constants<T>::MAX;
	}

	template<typename T>
	Vec3<T> Vec3<T>::nearestPointOfLine(const Vec3<T>& p1, const Vec3<T>& p2) const
	{
		if (p1 == p2) {
			return p1;
		}
		Vec3<T> norm = p2 - p1;
		Vec3<T> p1p0 = *this - p1;
		T t = norm.dot(p1p0) / norm.squareLength();

		return (p1 + t * norm);
	}

	template<typename T>
	Vec3<T> Vec3<T>::nearestPointOfLineSegment(const Vec3<T>& p1, const Vec3<T>& p2) const
	{
		if (p1 == p2) {
			return p1;
		}

		Vec3<T> norm = p2 - p1;
		Vec3<T> p1p0 = *this - p1;
		T t = norm.dot(p1p0) / norm.squareLength();

		if (t >= 1.0f) {
			return p2;
		}
		else if (t <= 0.0f) {
			return p1;
		}

		return (p1 + t * norm);
	}

	template<typename T>
	T Vec3<T>::distanceToLine(const Vec3<T>& p1, const Vec3<T>& p2) const
	{
		if (p1 == p2) {
			return length(p1);
		}

		Vec3<T> p1p2 = p2 - p1;
		Vec3<T> p1p0 = *this - p1;

		return (p1p2.cross(p1p0).length() / p1p2.length());
	}

	template<typename T>
	T Vec3<T>::distanceToLineSegment(const Vec3<T>& p1, const Vec3<T>& p2) const
	{
		if (p1 == p2) {
			return length(p1);
		}

		Vec3<T> norm = p2 - p1;
		Vec3<T> p1p0 = *this - p1;
		T t = norm.dot(p1p0) / norm.squareLength();

		if (t >= 1.0f) {
			return length(p2);
		}
		else if (t <= 0.0f) {
			return length(p1);
		}

		return distanceToLine(p1, p2);
	}




	//显示实例化
	template class Vec3<float>;
	template class Vec3<double>;
}

