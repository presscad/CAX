#pragma once


#ifndef _BOUNDINGBOX2D_H_
#define _BOUNDINGBOX2D_H_


namespace CAX
{

	template<typename T>
	class Vec2;

	typedef Vec2<double> Vec2d;


	class BoundingBox2d
	{
	public:
		/* {{ ��Сֵ�����ֵ }} */
		double minX;
		double minY;
		double maxX;
		double maxY;

		// ���캯������������
		BoundingBox2d(void);
		BoundingBox2d(
			const double fMinX, const double fMinY, 
			const double fMaxX, const double fMaxY);
		~BoundingBox2d();

		// ���ƹ��캯�� �� ��ֵ����
		BoundingBox2d(const BoundingBox2d& boundingBox);
		BoundingBox2d& operator = (const BoundingBox2d& boundingBox);

		// ��ȡ��Χ�е�����
		Vec2d center(void) const;

		// �ж��Ƿ�Ϊ��Ч��Χ�� 
		bool isValid(void) const;

		// ��ӽ���Χ��
		void add(const double x, const double y);
		void add(const Vec2d& v);
		void add(const BoundingBox2d& boundingBox);

		// �ཻ���
		bool intersects(const BoundingBox2d& boundingBox) const;


		/* ������� */
		bool contains(const double x, const double y) const;
		bool contains(const Vec2d& v) const;
		bool contains(const Vec2d& v1, const Vec2d v2) const;
		bool contains(const BoundingBox2d& boundingBox) const;


		/* ����ж� */
		bool operator == (const BoundingBox2d& boundingBox) const;

	}; // class BoundingBox2d

} // namespace CAX


#endif