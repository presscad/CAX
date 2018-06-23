#include "Circle2d.h"


#include "Constants.h"


namespace CAX
{

	Circle2d::Circle2d():
		m_center(0.0, 0.0),
		m_radius(1.0),
		m_clockwise(false)
	{

	}


	Circle2d::~Circle2d()
	{

	}

	Entity2d::Type Circle2d::type(void) const
	{
		return Entity2d::Circle;
	}

	bool Circle2d::isClosed(void) const
	{
		return true;
	}

	Vec2d Circle2d::head(void) const
	{
		return Vec2d(m_center.x + m_radius, m_center.y);
	}

	Vec2d Circle2d::tail(void) const
	{
		return Vec2d(m_center.x + m_radius, m_center.y);
	}

	BoundingBox2d Circle2d::boundingBox2d(void) const
	{
		double minX = m_center.x - m_radius;
		double minY = m_center.y - m_radius;
		double maxX = m_center.x + m_radius;
		double maxY = m_center.y + m_radius;

		return BoundingBox2d(minX, minY, maxX, maxY);
	}

	BoundingBox3d Circle2d::boundingBox3d(void) const
	{
		double minX = m_center.x - m_radius;
		double minY = m_center.y - m_radius;
		double maxX = m_center.x + m_radius;
		double maxY = m_center.y + m_radius;

		return BoundingBox3d(minX, minY, 0.0, maxX, maxY, 0.0);
	}
	
	void Circle2d::reverse(void)
	{
		m_clockwise = !m_clockwise;
	}

	double Circle2d::length(void) const
	{
		return (m_radius * Constants<double>::PIx2);
	}



	Vec2d& Circle2d::center(void)
	{
		return m_center;
	}

	double& Circle2d::radius(void)
	{
		return m_radius;
	}

	bool& Circle2d::clockwise(void)
	{
		return m_clockwise;
	}

} //namespace CAX
