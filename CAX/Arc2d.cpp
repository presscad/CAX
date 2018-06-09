#include "Arc2d.h"


#include <cmath>


#include "Constants.h"
#include "MathTools.h"


namespace CAX
{

	Arc2d::Arc2d():
		Entity2d(Entity2d::Arc),
		m_center(),
		m_radius(1.0),
		m_startRadian(0.0),
		m_endRadian(Constants<double>::PI)
	{
		
	}



	Arc2d::~Arc2d()
	{

	}


	bool Arc2d::isClosed(void)
	{
		return equals(abs(m_startRadian - m_endRadian), Constants<double>::DOUBLE_PI);
	}

	Vec2d Arc2d::head(void)
	{
		return Vec2d(
			m_center.x + m_radius * std::cos(m_startRadian),
			m_center.y + m_radius * std::sin(m_startRadian));
	}

	Vec2d Arc2d::tail(void)
	{
		return Vec2d(
			m_center.x + m_radius * std::cos(m_endRadian),
			m_center.y + m_radius * std::sin(m_endRadian));
	}

	Vec2d& Arc2d::center(void)
	{
		return m_center;
	}

	double& Arc2d::radius(void)
	{
		return m_radius;
	}

	double& Arc2d::startRadian(void)
	{
		return m_startRadian;
	}

	double& Arc2d::endRadian(void)
	{
		return m_endRadian;
	}

} // namespace CAX
