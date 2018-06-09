#include "LwPolyline2d.h"


namespace CAX
{

	LwPolyline2d::LwPolyline2d():
		Entity2d(Entity2d::LwPolyline)
	{
	}


	LwPolyline2d::~LwPolyline2d()
	{
	}

	bool LwPolyline2d::isClosed(void)
	{

		if (m_segments.size() < 2) 
		{
			return m_segments.front()->isClosed();
		} 
		
		return (m_segments.front()->head() == m_segments.back()->tail());
	}

	Vec2d LwPolyline2d::head(void)
	{
		return m_segments.front()->head();
	}

	Vec2d LwPolyline2d::tail(void)
	{
		return m_segments.back()->tail();
	}
} // namespace CAX
