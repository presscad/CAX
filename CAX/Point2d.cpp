#include "Point2d.h"


namespace CAX
{

	Point2d::Point2d():
		Entity2d(Entity2d::Point),
		m_location()
	{
	}

	Point2d::Point2d(double x, double y) :
		Entity2d(Entity2d::Point),
		m_location(x, y)
	{

	}

	Point2d::~Point2d()
	{
	}

	Vec2d& Point2d::location(void)
	{
		return m_location;
	}

	Vec2d Point2d::head(void)
	{
		return m_location;
	}

	Vec2d Point2d::tail(void)
	{
		return m_location;
	}

	bool Point2d::isClosed(void)
	{
		return true;
	}

} // namespace CAX

