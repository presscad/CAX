#pragma once

#ifndef _VEC2_H_
#define _VEC2_H_



namespace CAX {

	template<typename T>
	class Vec2
	{
	public:
		typedef T value_type;


		// ���г�Ա 
		T x;	//����x
		T y;	//����y


		// ���캯�� 
		Vec2(void);
		explicit Vec2(T value);
		Vec2(T fx, T fy);

		// ���ƹ��캯�� �� ��ֵ����
		Vec2(const Vec2<T>& v);
		Vec2<T>& operator = (const Vec2<T>& v);

		// ��������
		~Vec2(void);



		// {{ ��������� }}
		// ��������ֵ�����ã�����ֵֻ��ȡ0��1
		T& operator [] (unsigned short index);
		const T& operator [] (unsigned short index) const;
		// �ӷ�
		Vec2<T> operator + (const Vec2<T>& v) const;
		Vec2<T> operator + (const T value) const;
		//friend Vec2<T> operator + (T value, const Vec2<T>& v);
		// ����
		Vec2<T> operator - (const Vec2<T>& v) const;
		Vec2<T> operator - (const T value) const;
		//friend Vec2<T> operator - (T value, const Vec2<T>& v);
		// �˷�
		Vec2<T> operator * (const Vec2<T>& v) const;
		Vec2<T> operator * (const T value) const;
		//friend Vec2<T> operator * (T value, const Vec2<T>& v);
		// ����
		Vec2<T> operator / (const Vec2<T>& v) const;
		Vec2<T> operator / (const T value) const;
		///friend Vec2<T> operator / (T value, const Vec2<T>& v);
		// ����
		Vec2<T> operator - (void) const;
		// �Լ�
		Vec2<T>& operator += (const Vec2<T>& v);
		Vec2<T>& operator += (T value);
		// �Լ�
		Vec2<T>& operator -= (const Vec2<T>& v);
		Vec2<T>& operator -= (T value);
		// �Գ�
		Vec2<T>& operator *= (const Vec2<T>& v);
		Vec2<T>& operator *= (T value);
		// �Գ�
		Vec2<T>& operator /= (const Vec2<T>& v);
		Vec2<T>& operator /= (T value);
		// ����ж�
		bool operator == (const Vec2<T>& v) const;
		bool operator != (const Vec2<T>& v) const;




		// {{ ������Ϣ }}
		// ���㳤��
		T length(void) const;
		T length(const Vec2<T>& v) const;
		// ����ƽ������
		T squareLength(void) const;
		T squareLength(const Vec2<T>& v) const;
		// ������
		T dot(const Vec2<T>& v) const;
		// ��������Zֵ */
		T crossValue(const Vec2<T>& v) const;

		// ������������ļн�
		// ���ȷ�Χ[-pi, pi]
		// �Ƕȷ�Χ[-180, 180]
		T xRadian(void) const;
		T yRadian(void) const;
		T xDegree(void) const;
		T yDegree(void) const;

		// �������������ļнǻ���ֵ���Ƕ�Ϊ[0,pi]
		T getAngle(const Vec2<T>& v) const;

		Vec2<T> nearestPointOfLine(const Vec2<T>& p1, const Vec2<T>& p2) const;
		Vec2<T> nearestPointOfLineSegment(const Vec2<T>& p1, const Vec2<T>& p2) const;

		T distanceToLine(const Vec2<T>& p1, const Vec2<T>& p2) const;
		T distanceToLineSegment(const Vec2<T>& p1, const Vec2<T>& p2) const;



		// ���������޸�
		// ��λ��
		Vec2<T>& normalize(void);

		void set(const T fx, const T fy);
		void scaleX(const T sx);
		void scaleY(const T sy);
		void scale(const T sx, const T sy);
		void translateX(const T tx);
		void translateY(const T ty);
		void translate(const T tx, const T ty);
		void rotateLeft90(void);
		void rotateRight90(void);
		void rotate(const T radian);



	};


	template<typename T>
	Vec2<T> operator + (const T value, const Vec2<T>& v);
	template<typename T>
	Vec2<T> operator - (const T value, const Vec2<T>& v);
	template<typename T>
	Vec2<T> operator * (const T value, const Vec2<T>& v);
	template<typename T>
	Vec2<T> operator / (const T value, const Vec2<T>& v);


	typedef Vec2<float> Vec2f;
	typedef Vec2<double> Vec2d;


} // namespace CAX




#endif

