#include "Vec2.h"


#include <cmath>


#include "Constants.h"
#include "MathTools.h"


namespace CAX
{
	template<typename T>
	Vec2<T>::Vec2(void) :
		x(0),
		y(0)
	{
	}

	template<typename T>
	Vec2<T>::Vec2(T value) :
		x(value),
		y(value)
	{
	}

	template<typename T>
	Vec2<T>::Vec2(T fx, T fy) :
		x(fx),
		y(fy)
	{

	}

	template<typename T>
	Vec2<T>::Vec2(const Vec2<T>& v) :
		x(v.x),
		y(v.y)
	{

	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator = (const Vec2<T>& v)
	{
		x = v.x;
		y = v.y;

		return *this;
	}

	template<typename T>
	Vec2<T>::~Vec2(void)
	{

	}

	template<typename T>
	T& Vec2<T>::operator [] (unsigned short index)
	{
		switch (index) {
		case 0:
			return x;
		case 1:
			return y;
		}
		return x;
	}

	template<typename T>
	const T& Vec2<T>::operator [] (unsigned short index) const
	{
		switch (index) {
		case 0:
			return x;
		case 1:
			return y;
		}
		return x;
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator + (const Vec2<T>& v) const
	{
		return Vec2<T>(x + v.x, y + v.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator + (const T value) const
	{
		return Vec2<T>(x + value, y + value);
	}

	template<typename T>
	Vec2<T> operator + (const T value, const Vec2<T>& v)
	{
		return Vec2<T>(value + v.x, value + v.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator - (const Vec2<T>& v) const
	{
		return Vec2<T>(x - v.x, y - v.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator - (const T value) const
	{
		return Vec2<T>(x - value, y - value);
	}

	template<typename T>
	Vec2<T> operator - (const T value, const Vec2<T>& v)
	{
		return Vec2<T>(value - v.x, value - v.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator * (const Vec2<T>& v) const
	{
		return Vec2<T>(x * v.x, y * v.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator * (const T value) const
	{
		return Vec2<T>(x * value, y * value);
	}

	template<typename T>
	Vec2<T> operator * (const T value, const Vec2<T>& v)
	{
		return Vec2<T>(value * v.x, value * v.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator / (const Vec2<T>& v) const
	{
		return Vec2<T>(x / v.x, y / v.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator / (const T value) const
	{
		return Vec2<T>(x / value, y / value);
	}

	template<typename T>
	Vec2<T> operator / (const T value, const Vec2<T>& v)
	{
		return Vec2<T>(value / v.x, value / v.y);
	}

	template<typename T>
	Vec2<T> Vec2<T>::operator - (void) const
	{
		return Vec2<T>(-x, -y);
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator += (const Vec2<T>& v)
	{
		x += v.x;
		y += v.y;

		return *this;
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator += (T value)
	{
		x += value;
		y += value;

		return *this;
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator -= (const Vec2<T>& v)
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator -= (T value)
	{
		x -= value;
		y -= value;

		return *this;
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator *= (const Vec2<T>& v)
	{
		x *= v.x;
		y *= v.y;

		return *this;
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator *= (T value)
	{
		x *= value;
		y *= value;

		return *this;
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator /= (const Vec2<T>& v)
	{
		x *= v.x;
		y *= v.y;

		return *this;
	}

	template<typename T>
	Vec2<T>& Vec2<T>::operator /= (T value)
	{
		x /= value;
		y /= value;

		return *this;
	}


	template<typename T>
	bool Vec2<T>::operator == (const Vec2<T>& v)  const
	{
		return (std::abs(x - v.x) <= Constants<T>::EPSILON)
			&& (std::abs(y - v.y) <= Constants<T>::EPSILON);
	}

	template<typename T>
	bool Vec2<T>::operator != (const Vec2<T>& v) const
	{
		return !((*this) == v);
	}




	template<typename T>
	T Vec2<T>::length(void) const
	{
		return std::sqrt(x * x + y * y);
	}

	template<typename T>
	T Vec2<T>::length(const Vec2<T>& v) const
	{
		T dx = x - v.x;
		T dy = y - v.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	template<typename T>
	T Vec2<T>::squareLength(void) const
	{
		return (x * x + y * y);
	}

	template<typename T>
	T Vec2<T>::squareLength(const Vec2<T>& v) const
	{
		T dx = x - v.x;
		T dy = y - v.y;
		return (dx * dx + dy * dy);
	}


	template<typename T>
	T Vec2<T>::dot(const Vec2<T>& v) const
	{
		return (x * v.x + y * v.y);
	}

	template<typename T>
	T Vec2<T>::crossValue(const Vec2<T>& v) const
	{
		return (x * v.y - y * v.x);
	}




	template<typename T>
	Vec2<T>& Vec2<T>::normalize(void)
	{
		T len = length();
		if (len != 0.0f && len != 1.0f) {
			x /= len;
			y /= len;
		}
		return *this;
	}

	template<typename T>
	void Vec2<T>::set(const T fx, const T fy)
	{
		x = fx;
		y = fy;
	}

	template<typename T>
	void Vec2<T>::scaleX(const T sx)
	{
		x *= sx;
	}

	template<typename T>
	void Vec2<T>::scaleY(const T sy)
	{
		y *= sy;
	}

	template<typename T>
	void Vec2<T>::scale(const T sx, const T sy)
	{
		x *= sx;
		y *= sy;
	}

	template<typename T>
	void Vec2<T>::translateX(const T tx)
	{
		x += tx;
	}

	template<typename T>
	void Vec2<T>::translateY(const T ty)
	{
		y += ty;
	}

	template<typename T>
	void Vec2<T>::translate(const T tx, const T ty)
	{
		x += tx;
		y += ty;
	}

	template<typename T>
	void Vec2<T>::rotateLeft90(void)
	{
		T oldX = x;
		x = -y;
		y = oldX;
	}

	template<typename T>
	void Vec2<T>::rotateRight90(void)
	{
		T oldX = x;
		x = y;
		y = -oldX;
	}

	template<typename T>
	void Vec2<T>::rotate(const T radian)
	{
		T fx = x;
		T fy = y;
		T fsin = std::sin(radian);
		T fcos = std::cos(radian);

		x = (fx * fcos) - (fy * fsin);
		y = (fx * fsin) + (fy * fcos);
	}


	template<typename T>
	T Vec2<T>::xRadian(void) const
	{
		return std::atan2(y, x);
	}

	template<typename T>
	T Vec2<T>::yRadian(void) const
	{
		return std::atan2(-x, y);
	}

	template<typename T>
	T Vec2<T>::xDegree(void) const
	{
		return toDegrees(xRadian());
	}

	template<typename T>
	T Vec2<T>::yDegree(void) const
	{
		return toDegrees(yRadian());
	}


	template<typename T>
	T Vec2<T>::getAngle(const Vec2<T>& v) const
	{
		T den = length() * v.length();

		if (std::abs(den) > 1.0e-10) {
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

		//·ÖÄ¸Îª0
		return Constants<T>::MAX;
	}

	template<typename T>
	Vec2<T> Vec2<T>::nearestPointOfLine(const Vec2<T>& p1, const Vec2<T>& p2) const
	{
		if (p1 == p2) {
			return p1;
		}

		Vec2<T> norm = p2 - p1;
		Vec2<T> p1p0 = *this - p1;
		T t = norm.dot(p1p0) / norm.squareLength();

		return (p1 + t * norm);
	}

	template<typename T>
	Vec2<T> Vec2<T>::nearestPointOfLineSegment(const Vec2<T>& p1, const Vec2<T>& p2) const
	{
		if (p1 == p2) {
			return p1;
		}

		Vec2<T> norm = p2 - p1;
		Vec2<T> p1p0 = *this - p1;
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
	T Vec2<T>::distanceToLine(const Vec2<T>& p1, const Vec2<T>& p2) const
	{
		if (p1 == p2) {
			return length(p1);
		}

		Vec2<T> p1p2 = p2 - p1;
		Vec2<T> p1p0 = *this - p1;

		return (std::abs(p1p2.crossValue(p1p0)) / p1p2.length());
	}

	template<typename T>
	T Vec2<T>::distanceToLineSegment(const Vec2<T>& p1, const Vec2<T>& p2) const
	{
		if (p1 == p2) {
			return length(p1);
		}

		Vec2<T> norm = p2 - p1;
		Vec2<T> p1p0 = *this - p1;
		T t = norm.dot(p1p0) / norm.squareLength();

		if (t >= 1.0f) {
			return length(p2);
		}
		else if (t <= 0.0f) {
			return length(p1);
		}

		return distanceToLine(p1, p2);
	}




	template class Vec2<float>;
	template class Vec2<double>;
} // namespace CAX