#include "Circle2d.h"


namespace CAX
{

	Circle2d::Circle2d():
		Entity2d(Entity2d::Circle),
		m_center(0.0, 0.0),
		m_radius(1.0),
		m_clockwise(false)
	{

	}


	Circle2d::~Circle2d()
	{

	}

	bool Circle2d::isClosed(void)
	{
		return true;
	}

	Vec2d Circle2d::start(void)
	{
		return m_center;
	}

	Vec2d Circle2d::end(void)
	{
		return m_center;
	}

	Vec2d& Circle2d::center(void)
	{
		return m_center;
	}

	double& Circle2d::radius(void)
	{
		return m_radius;
	}

} //namespace CAX
