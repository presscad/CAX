#include "Spline2d.h"


namespace CAX
{

	Spline2d::Spline2d()
	{

	}


	Spline2d::~Spline2d()
	{

	}


	Entity2d::Type Spline2d::type(void) const
	{
		return Entity2d::Spline;
	}

	bool Spline2d::isClosed(void) const
	{
		return (head() == tail());
	}

	Vec2d Spline2d::head(void) const
	{
		return m_controls.front();
	}

	Vec2d Spline2d::tail(void) const
	{
		return m_controls.back();
	}

	BoundingBox2d Spline2d::boundingBox2d(void) const
	{
		return BoundingBox2d();
	}

	BoundingBox3d Spline2d::boundingBox3d(void) const
	{
		return BoundingBox3d();
	}

	void Spline2d::reverse(void)
	{
	
	}

	double Spline2d::length(void) const
	{
		return 0.0;
	}



	std::vector<Vec2d>& Spline2d::controls(void)
	{
		return m_controls;
	}

	std::vector<double>& Spline2d::knots(void)
	{
		return m_knots;
	}
	
	unsigned int& Spline2d::degree(void)
	{
		return m_degree;
	}



} // namespace CAX

