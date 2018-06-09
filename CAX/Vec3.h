#pragma once




#ifndef _VEC3_H_
#define _VEC3_H_

namespace CAX {


	template<typename T>
	class Vec3
	{
	public:
		typedef T value_type;

		T x;
		T y;
		T z;

		/* ���캯�� */
		Vec3(void);
		explicit Vec3(T value);
		Vec3(T fx, T fy);
		Vec3(T fx, T fy, T fz);
		/* ���ƹ��캯�� */
		Vec3(const Vec3<T>& v);
		Vec3<T>& operator = (const Vec3<T>& v);
		~Vec3(void);



		/* {{ ��������� }} */
		/* ��������ֵ��reference */
		T& operator[] (unsigned short index);
		/* ��������ֵ��const reference */
		const T& operator[] (unsigned short index) const;
		/* �ӷ�(��ӦԪ�����) */
		Vec3<T> operator + (const Vec3<T>& v) const;
		Vec3<T> operator + (const T value) const;
		//friend Vec3<T> operator + (const T value, const Vec3<T>& v);
		/* ����(��ӦԪ�����) */
		Vec3<T> operator - (const Vec3<T>& v) const;
		Vec3<T> operator - (const T value) const;
		//friend Vec3<T> operator - (const T value, const Vec3<T>& v);
		/* �˷�(��ӦԪ�����) */
		Vec3<T> operator * (const Vec3<T>& v) const;
		Vec3<T> operator * (const T value) const;
		//friend Vec3<T> operator * (const T value, const Vec3<T>& v);
		/* ����(��ӦԪ�����) */
		Vec3<T> operator / (const Vec3<T>& v) const;
		Vec3<T> operator / (const T value) const;
		//friend Vec3<T> operator / (const T value, const Vec3<T>& v);
		/* ���� */
		Vec3<T> operator - (void) const;
		/* �Լ� */
		Vec3<T>& operator += (const Vec3<T>& v);
		Vec3<T>& operator += (const T value);
		/* �Լ� */
		Vec3<T>& operator -= (const Vec3<T>& v);
		Vec3<T>& operator -= (const T value);
		/* �Գ� */
		Vec3<T>& operator *= (const Vec3<T>& v);
		Vec3<T>& operator *= (const T value);
		/* �Գ� */
		Vec3<T>& operator /= (const Vec3<T>& v);
		Vec3<T>& operator /= (const T value);
		/* ����ж� */
		bool operator == (const Vec3<T>& v) const;
		bool operator != (const Vec3<T>& v) const;


		/* ���� */
		T length(void) const;
		T length(const Vec3<T>& v) const;

		/* ���ȵ�ƽ�� */
		T squareLength(void) const;
		T squareLength(const Vec3<T>& v) const;

		/* ��� */
		T dot(const Vec3<T>& v) const;

		/* ��� */
		Vec3<T> cross(const Vec3<T>& v) const;


		/* ���������޸� */
		void set(T fx, T fy, T fz);
		void scaleX(T sx);
		void scaleY(T sy);
		void scaleZ(T sz);
		void scale(T sx, T sy, T sz);
		void translateX(T tx);
		void translateY(T ty);
		void translateZ(T tz);
		void translate(T tx, T ty, T tz);
		void rotateX(T rx);
		void rotateY(T ry);
		void rotateZ(T rz);

		/* ��λ�� */
		Vec3<T>& normalize(void);


		/* �������������ļнǣ��Ƕ�Ϊ[0,pi] */
		T getAngle(const Vec3<T>& v);

		/* ����õ���ֱ��p1-p2����ĵ� */
		Vec3<T> nearestPointOfLine(const Vec3<T>& p1, const Vec3<T>& p2) const;

		/* ����õ����߶�p1-p2����ĵ� */
		Vec3<T> nearestPointOfLineSegment(const Vec3<T>& p1, const Vec3<T>& p2) const;

		/* ����õ���ֱ��p1-p2�ľ��� */
		T distanceToLine(const Vec3<T>& p1, const Vec3<T>& p2) const;

		/* ����õ����߶�p1-p2�ľ��� */
		T distanceToLineSegment(const Vec3<T>& p1, const Vec3<T>& p2) const;


	};

	template<typename T>
	Vec3<T> operator + (const T value, const Vec3<T>& v);
	template<typename T>
	Vec3<T> operator - (const T value, const Vec3<T>& v);
	template<typename T>
	Vec3<T> operator * (const T value, const Vec3<T>& v);
	template<typename T>
	Vec3<T> operator / (const T value, const Vec3<T>& v);



	typedef Vec3<float> Vec3f;
	typedef Vec3<double> Vec3d;



}; // namespace CAX




#endif