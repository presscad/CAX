#include "Polyline2d.h"


namespace CAX
{
	
	Polyline2d::Polyline2d() :
		Entity2d(Entity2d::Polyline)
	{

	}

	Polyline2d::Polyline2d(const std::list<Vec2d>& vertices):
		Entity2d(Entity2d::Polyline),
		m_vertices(vertices)
	{

	}

	Polyline2d::~Polyline2d()
	{

	}

	std::list<Vec2d>& Polyline2d::vertices(void)
	{
		return m_vertices;
	}

	Vec2d Polyline2d::head(void)
	{
		return m_vertices.front();
	}

	Vec2d Polyline2d::tail(void)
	{
		return m_vertices.back();
	}

	bool Polyline2d::isClosed(void)
	{
		return (m_vertices.front() == m_vertices.back());
	}
} // namespace CAX

