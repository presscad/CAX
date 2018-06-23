#include "TriangleSurface.h"


namespace CAX
{

	TriangleSurface::TriangleSurface()
	{

	}


	TriangleSurface::~TriangleSurface()
	{

	}

	Surface3d::Type TriangleSurface::type(void) const
	{
		return Surface3d::TriangleSurface;
	}

	
	BoundingBox3d TriangleSurface::boundingBox3d(void) const
	{
		using namespace std;
		BoundingBox3d box;
		
		vector<CAX::Triangle>::const_iterator iter;
		for(iter=m_triangles.begin(); iter!=m_triangles.end(); ++iter)
		{
			box.add(iter->boundingBox3d());
		}

		return box;
	}



	std::vector<CAX::Triangle>& TriangleSurface::triangles(void)
	{
		return m_triangles;
	}

	std::vector<Vec3d>& TriangleSurface::normals(void)
	{
		return m_normals;
	}

	std::vector<Vec3f>& TriangleSurface::colors(void)
	{
		return m_colors;
	}



	void TriangleSurface::fromData(
		const std::vector<Vec3d>& inVertices,
		const std::vector<Vec3d>& inNormals)
	{
		m_triangles.clear();
		//m_normals.clear();
		m_colors.clear();

		size_t triangleCount = inVertices.size() / 3;
		CAX::Triangle triangle;
		for(size_t i=0; i<triangleCount; ++i)
		{
			triangle.vertices()[0] = inVertices[3 * i];
			triangle.vertices()[1] = inVertices[3 * i + 1];
			triangle.vertices()[2] = inVertices[3 * i + 2];
			m_triangles.push_back(triangle);
		}
		m_normals = inNormals;

		getDataType(m_triangles, m_normals, m_colors);
	}

	void TriangleSurface::fromData(
		const std::vector<Vec3d>& inVertices,
		const std::vector<Vec3d>& inNormals,
		const std::vector<Vec3f>& inColors)
	{
		m_triangles.clear();
		//m_normals.clear();
		m_colors.clear();

		size_t triangleCount = inVertices.size() / 3;
		CAX::Triangle triangle;
		for (size_t i = 0; i<triangleCount; ++i)
		{
			triangle.vertices()[0] = inVertices[3 * i];
			triangle.vertices()[1] = inVertices[3 * i + 1];
			triangle.vertices()[2] = inVertices[3 * i + 2];
			m_triangles.push_back(triangle);
		}
		m_normals = inNormals;
		m_colors = inColors;

		getDataType(m_triangles, m_normals, m_colors);
	}

	void TriangleSurface::fromData(
		const std::vector<CAX::Triangle>& inTriangles,
		const std::vector<Vec3d>& inNormals)
	{
		m_triangles = inTriangles;
		m_normals = inNormals;
		m_colors.clear();

		getDataType(m_triangles, m_normals, m_colors);
	}

	void TriangleSurface::fromData(
		const std::vector<CAX::Triangle>& inTriangles,
		const std::vector<Vec3d>& inNormals,
		const std::vector<Vec3f>& inColors)
	{
		m_triangles = inTriangles;
		m_normals = inNormals;
		m_colors = inColors;

		getDataType(m_triangles, m_normals, m_colors);
	}

	TriangleSurface::DataType TriangleSurface::getDataType(
		const std::vector<CAX::Triangle>& m_triangles,
		const std::vector<Vec3d> m_normals,
		const std::vector<Vec3f> m_colors)
	{
		if(m_triangles.size() == m_normals.size())
		{
			if(m_triangles.size() == m_colors.size())
			{
				m_dataType = ONE_NORMAL_PER_TRIANGLE_WITH_COLOR;
			}
			else
			{
				m_dataType = ONE_NORMAL_PER_TRIANGLE;
			}
		}
		else if(m_triangles.size() * 3 == m_normals.size())
		{
			if(m_triangles.size() == m_colors.size())
			{
				m_dataType = ONE_NORMAL_PER_VERTEX_WITH_COLOR;
			}
			else
			{
				m_dataType = ONE_NORMAL_PER_VERTEX;
			}
		}
		else
		{
			m_dataType = INVALID_DATA_TYPE;
		}

		return m_dataType;
	}


} // namespace CAX