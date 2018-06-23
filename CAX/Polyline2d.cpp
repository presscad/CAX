#include "Polyline2d.h"


#include <cmath>


#include "Triangle2d.h"


namespace CAX
{
	double Polyline2d::SignedArea(const std::list<Vec2d>& vertices)
	{
		using namespace std;

		size_t count = vertices.size();
		if(count < 3)
		{
			return 0.0;
		}

		double totalArea = 0.0;
		list<Vec2d>::const_iterator nextIter = vertices.cbegin();
		list<Vec2d>::const_iterator preIter = nextIter++;
		list<Vec2d>::const_iterator curIter = nextIter++;
		while(nextIter != vertices.cend())
		{
			totalArea = Triangle2d::SignedArea(*preIter, *curIter, *nextIter);
			preIter = curIter++;
			curIter = nextIter++;
		}

		return totalArea;
	}


	double Polyline2d::Area(const std::list<Vec2d>& vertices)
	{
		return std::abs(SignedArea(vertices));
	}


	Polyline2d::Polyline2d()
	{

	}

	Polyline2d::Polyline2d(const std::list<Vec2d>& vertices):
		m_vertices(vertices)
	{

	}

	Polyline2d::~Polyline2d()
	{

	}

	Entity2d::Type Polyline2d::type(void) const
	{
		return Entity2d::Polyline;
	}

	Vec2d Polyline2d::head(void) const
	{
		return m_vertices.front();
	}

	Vec2d Polyline2d::tail(void) const
	{
		return m_vertices.back();
	}

	bool Polyline2d::isClosed(void) const
	{
		return (m_vertices.front() == m_vertices.back());
	}


	BoundingBox2d Polyline2d::boundingBox2d(void) const
	{
		using namespace std;
		BoundingBox2d box;
		
		list<Vec2d>::const_iterator iter;
		for(iter=m_vertices.cbegin(); iter!=m_vertices.cend(); iter++)
		{
			box.add(*iter);
		}

		return box;
	}

	BoundingBox3d Polyline2d::boundingBox3d(void) const
	{
		using namespace std;
		BoundingBox3d box;

		list<Vec2d>::const_iterator iter;
		for (iter = m_vertices.cbegin(); iter != m_vertices.cend(); iter++)
		{
			box.add(iter->x, iter->y, 0.0);
		}

		return box;
	}

	void Polyline2d::reverse(void)
	{
		m_vertices.reverse();
	}

	double Polyline2d::length(void) const
	{
		using namespace std;

		if(m_vertices.size() < 2)
		{
			return 0.0;
		}

		list<Vec2d>::const_iterator iter = m_vertices.cbegin();
		list<Vec2d>::const_iterator curIter;
		double totalLength = 0.0;
		while(true)
		{
			curIter = (iter++);
			if(iter != m_vertices.cend())
			{
				totalLength += curIter->length(*iter);
			}
			else
			{
				break;
			}
		}
		return totalLength;
	}




	std::list<Vec2d>& Polyline2d::vertices(void)
	{
		return m_vertices;
	}



	double Polyline2d::signedArea(void) const
	{
		return SignedArea(m_vertices);
	}

	double Polyline2d::area(void) const
	{
		return Area(m_vertices);
	}



} // namespace CAX

