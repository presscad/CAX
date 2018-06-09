#include "Line2d.h"


namespace CAX
{
	
	Line2d::Line2d():
		Entity2d(Entity2d::Line),
		m_start(),
		m_end()
	{
	}

	Line2d::Line2d(const double startx, const double starty, const double endx, const double endy):
		Entity2d(Entity2d::Line),
		m_start(startx, starty),
		m_end(endx, endy)
	{

	}

	Line2d::Line2d(const Vec2d& start, const Vec2d& end):
		Entity2d(Entity2d::Line),
		m_start(start),
		m_end(end)
	{

	}

	Line2d::~Line2d()
	{
	}

	Vec2d Line2d::head(void) 
	{
		return m_start;
	}

	Vec2d Line2d::tail(void)
	{
		return m_end;
	}

	Vec2d& Line2d::start(void)
	{
		return m_start;
	}

	Vec2d& Line2d::end(void)
	{
		return m_end;
	}

	bool Line2d::isClosed(void)
	{
		return false;
	}

} // namespace CAX

