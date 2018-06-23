#include "Line2d.h"


#include <algorithm>


namespace CAX
{
	
	Line2d::Line2d():
		m_start(),
		m_end()
	{
	}

	Line2d::Line2d(const double startx, const double starty, const double endx, const double endy):
		m_start(startx, starty),
		m_end(endx, endy)
	{

	}

	Line2d::Line2d(const Vec2d& start, const Vec2d& end):
		m_start(start),
		m_end(end)
	{

	}

	Line2d::~Line2d()
	{
	}

	Entity2d::Type Line2d::type(void) const
	{
		return Entity2d::Line;
	}

	Vec2d Line2d::head(void) const
	{
		return m_start;
	}

	Vec2d Line2d::tail(void) const
	{
		return m_end;
	}

	bool Line2d::isClosed(void) const
	{
		return false;
	}

	BoundingBox2d Line2d::boundingBox2d(void) const
	{
		BoundingBox2d box;
		box.add(m_start);
		box.add(m_end);

		return box;
	}

	BoundingBox3d Line2d::boundingBox3d(void) const
	{
		BoundingBox3d box;
		box.add(m_start.x, m_start.y, 0.0);
		box.add(m_end.x, m_end.y, 0.0);

		return box;
	}

	void Line2d::reverse(void)
	{
		std::swap(m_start, m_end);
	}

	double Line2d::length(void) const
	{
		return m_start.length(m_end);
	}



	Vec2d& Line2d::start(void)
	{
		return m_start;
	}

	Vec2d& Line2d::end(void)
	{
		return m_end;
	}

	

} // namespace CAX

