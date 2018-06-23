#pragma once


#ifndef _TRIANGLESURFACE_H_
#define _TRIANGLESURFACE_H_


#include <vector>


#include "Surface3d.h"
#include "Triangle.h"


namespace CAX
{

	class TriangleSurface : public Surface3d
	{
	public:
		enum DataType
		{
			INVALID_DATA_TYPE,
			
			ONE_NORMAL_PER_VERTEX,
			ONE_NORMAL_PER_VERTEX_WITH_COLOR,

			ONE_NORMAL_PER_TRIANGLE,
			ONE_NORMAL_PER_TRIANGLE_WITH_COLOR
		};


		// {{ 构造函数 和 析构函数 }}
		TriangleSurface();
		~TriangleSurface();


		// {{ @override }}
		// 返回类型
		virtual Type type(void) const;
		// 返回包围盒
		virtual BoundingBox3d boundingBox3d(void) const;


		// {{ 获取属性 }}
		std::vector<CAX::Triangle>& triangles(void);
		std::vector<Vec3d>& normals(void);
		std::vector<Vec3f>& colors(void);

		// {{ 设置属性 }}
		void fromData(
			const std::vector<Vec3d>& inVertices,
			const std::vector<Vec3d>& inNormals);
		void fromData(
			const std::vector<Vec3d>& inVertices,
			const std::vector<Vec3d>& inNormals,
			const std::vector<Vec3f>& inColors);
		void fromData(
			const std::vector<CAX::Triangle>& inTriangles,
			const std::vector<Vec3d>& inNormals);
		void fromData(
			const std::vector<CAX::Triangle>& inTriangles,
			const std::vector<Vec3d>& inNormals,
			const std::vector<Vec3f>& inColors);


		// 获取数据类型
		DataType getDataType(
			const std::vector<CAX::Triangle>& m_triangles,
			const std::vector<Vec3d> m_normals,
			const std::vector<Vec3f> m_colors);

	private:
		// {{ 属性 }}
		std::vector<CAX::Triangle> m_triangles;
		std::vector<Vec3d> m_normals;
		std::vector<Vec3f> m_colors;


		DataType m_dataType;

	}; // class TriangleSurface

} // namespace CAX

#endif