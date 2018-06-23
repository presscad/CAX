#include "Point2d.h"


namespace CAX
{

	Point2d::Point2d():
		m_location()
	{

	}

	Point2d::Point2d(double x, double y):
		m_location(x, y)
	{

	}

	Point2d::~Point2d()
	{

	}

	Entity2d::Type Point2d::type(void) const
	{
		return Entity2d::Point;
	}

	Vec2d Point2d::head(void) const
	{
		return m_location;
	}

	Vec2d Point2d::tail(void) const
	{
		return m_location;
	}

	bool Point2d::isClosed(void) const
	{
		return true;
	}

	BoundingBox2d Point2d::boundingBox2d(void) const
	{
		BoundingBox2d box;
		box.add(m_location);

		return box;
	}

	BoundingBox3d Point2d::boundingBox3d(void) const
	{
		BoundingBox3d box;
		box.add(m_location.x, m_location.y, 0.0);

		return box;
	}

	void Point2d::reverse(void)
	{
		// 什么都不需要做
	}

	double Point2d::length(void) const
	{
		return 0;
	}



	Vec2d& Point2d::location(void)
	{
		return m_location;
	}


} // namespace CAX

