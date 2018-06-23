#include "Triangle.h"


namespace CAX
{

	Triangle::Triangle()
	{
	}


	Triangle::~Triangle()
	{
	}

	Surface3d::Type Triangle::type(void) const
	{
		return Surface3d::Triangle;
	}

	BoundingBox3d Triangle::boundingBox3d(void) const
	{
		BoundingBox3d box;
		box.add(m_vertices[0]);
		box.add(m_vertices[1]);
		box.add(m_vertices[2]);

		return box;
	}


	Vec3d* Triangle::vertices(void)
	{
		return m_vertices;
	}

} // namespace CAX
