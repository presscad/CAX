#include "Triangle2d.h"


#include <cmath>


namespace CAX
{

	double Triangle2d::SignedArea(const Vec2d& v1, const Vec2d& v2, const Vec2d& v3)
	{
		Vec2d vec1 = v2 - v1;
		Vec2d vec2 = v3 - v1;
		return (0.5 * vec1.crossValue(vec2));
	}

	double Triangle2d::Area(const Vec2d& v1, const Vec2d& v2, const Vec2d& v3)
	{
		return std::abs(SignedArea(v1, v2, v3));
	}



	Triangle2d::Triangle2d()
	{
	}


	Triangle2d::~Triangle2d()
	{
	}

	Entity2d::Type Triangle2d::type(void) const
	{
		return Entity2d::Triangle;
	}

	bool Triangle2d::isClosed(void) const
	{
		return true;
	}

	Vec2d Triangle2d::head(void) const
	{
		return m_vertices[0];
	}

	Vec2d Triangle2d::tail(void) const
	{
		return m_vertices[0];
	}

	BoundingBox2d Triangle2d::boundingBox2d(void) const
	{
		BoundingBox2d box;
		box.add(m_vertices[0]);
		box.add(m_vertices[1]);
		box.add(m_vertices[2]);

		return box;
	}

	BoundingBox3d Triangle2d::boundingBox3d(void) const
	{
		BoundingBox2d box2d = boundingBox2d();

		return BoundingBox3d(box2d.minX, box2d.minY, 0.0, box2d.maxX, box2d.maxY, 0.0);
	}

	void Triangle2d::reverse(void)
	{
		m_clockwise = !m_clockwise;
	}

	double Triangle2d::length(void) const
	{
		double totalLength = 0.0;
		totalLength += m_vertices[0].length(m_vertices[1]);
		totalLength += m_vertices[1].length(m_vertices[2]);
		totalLength += m_vertices[2].length(m_vertices[0]);

		return totalLength;
	}


	double Triangle2d::signedArea(void) const
	{
		return SignedArea(m_vertices[0], m_vertices[1], m_vertices[2]);
	}

	double Triangle2d::area(void) const
	{
		return Area(m_vertices[0], m_vertices[1], m_vertices[2]);
	}




	Vec2d* Triangle2d::vertices(void)
	{
		return m_vertices;
	}

	Vec2d& Triangle2d::operator [](unsigned short index)
	{
		return m_vertices[index];
	}

	const Vec2d& Triangle2d::operator [](unsigned short index) const
	{
		return m_vertices[index];
	}

} // namespace CAX

