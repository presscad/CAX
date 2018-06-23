#include "Convex2d.h"


#include <algorithm>


namespace CAX
{

	Convex2d::Convex2d()
	{
	}


	Convex2d::~Convex2d()
	{
	}


	Entity2d::Type Convex2d::type(void) const
	{
		return Entity2d::Convex;
	}

	bool Convex2d::isClosed(void) const
	{
		return true;
	}

	Vec2d Convex2d::head(void) const
	{
		return m_vertices.front();
	}

	Vec2d Convex2d::tail(void) const
	{
		return m_vertices.back();
	}

	BoundingBox2d Convex2d::boundingBox2d(void) const
	{
		using namespace std;

		BoundingBox2d box;
		vector<Vec2d>::const_iterator iter;
		for (iter = m_vertices.cbegin(); iter != m_vertices.cend(); ++iter)
		{
			box.add(*iter);
		}

		return box;
	}

	BoundingBox3d Convex2d::boundingBox3d(void) const
	{
		BoundingBox2d box2d = boundingBox2d();

		return BoundingBox3d(box2d.minX, box2d.minY, 0.0, box2d.maxX, box2d.maxY, 0.0);
	}

	void Convex2d::reverse(void)
	{
		std::reverse(m_vertices.begin(), m_vertices.end());
		m_clockwise = !m_clockwise;
	}

	double Convex2d::length(void) const
	{
		using namespace std;

		if(m_vertices.size() < 2)
		{
			return 0.0;
		}

		double totalLength = 0.0;
		vector<Vec2d>::const_iterator nextIter = m_vertices.cbegin();
		vector<Vec2d>::const_iterator curIter = nextIter++;
		while(nextIter != m_vertices.cend())
		{
			totalLength += curIter->length(*nextIter);
			curIter = nextIter++;
		}

		return totalLength;
	}




	const std::vector<Vec2d>& Convex2d::vertices(void) const
	{
		return m_vertices;
	}

} // namespace CAX

