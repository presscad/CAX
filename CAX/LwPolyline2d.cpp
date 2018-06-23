#include "LwPolyline2d.h"


namespace CAX
{

	LwPolyline2d::LwPolyline2d()
	{

	}


	LwPolyline2d::~LwPolyline2d()
	{
		using namespace std;

		list<Entity2d*>::iterator iter;
		for(iter=m_segments.begin(); iter!=m_segments.end(); ++iter)
		{
			Entity2d::deleteInstance(*iter);
		}
	}

	Entity2d::Type LwPolyline2d::type(void) const
	{
		return Entity2d::LwPolyline;
	}

	bool LwPolyline2d::isClosed(void) const
	{

		if (m_segments.size() < 2) 
		{
			return m_segments.front()->isClosed();
		} 
		
		return (m_segments.front()->head() == m_segments.back()->tail());
	}

	Vec2d LwPolyline2d::head(void) const
	{
		return m_segments.front()->head();
	}

	Vec2d LwPolyline2d::tail(void) const
	{
		return m_segments.back()->tail();
	}

	BoundingBox2d LwPolyline2d::boundingBox2d(void) const
	{
		using namespace std;
		BoundingBox2d box;

		list<Entity2d*>::const_iterator iter;
		for (iter = m_segments.cbegin(); iter != m_segments.cend(); iter++)
		{
			box.add((*iter)->boundingBox2d());
		}

		return box;
	}

	BoundingBox3d LwPolyline2d::boundingBox3d(void) const
	{
		using namespace std;
		BoundingBox3d box;

		list<Entity2d*>::const_iterator iter;
		for (iter = m_segments.cbegin(); iter != m_segments.cend(); iter++)
		{
			box.add((*iter)->boundingBox3d());
		}

		return box;
	}

	void LwPolyline2d::reverse(void)
	{
		using namespace std;
		list<Entity2d*>::iterator iter;
		for(iter=m_segments.begin(); iter!=m_segments.end(); iter++)
		{
			(*iter)->reverse();
		}

		m_segments.reverse();
	}

	double LwPolyline2d::length(void) const
	{
		using namespace std;

		double totalLength = 0.0;
		list<Entity2d*>::const_iterator iter;
		for(iter=m_segments.cbegin(); iter!=m_segments.cend(); ++iter)
		{
			totalLength += (*iter)->length();
		}
		return totalLength;
	}


	std::list<Entity2d*>& LwPolyline2d::segments(void)
	{
		return m_segments;
	}


} // namespace CAX
