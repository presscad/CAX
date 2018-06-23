#include "BoundingBox3d.h"


#include <algorithm>


#include "Constants.h"


namespace CAX
{

	BoundingBox3d::BoundingBox3d():
		minX(Constants<double>::MAX),
		minY(Constants<double>::MAX),
		minZ(Constants<double>::MAX),
		maxX(Constants<double>::MIN),
		maxY(Constants<double>::MIN),
		maxZ(Constants<double>::MIN)
	{
	}

	BoundingBox3d::BoundingBox3d(
		const double fMinX, const double fMinY, const double fMinZ,
		const double fMaxX, const double fMaxY, const double fMaxZ)
	{
		minX = std::min<double>(fMinX, fMaxX);
		maxX = std::max<double>(fMinX, fMaxX);
		minY = std::min<double>(fMinY, fMaxY);
		maxY = std::max<double>(fMinY, fMaxY);
		minZ = std::min<double>(fMinZ, fMaxZ);
		maxZ = std::max<double>(fMinZ, fMaxZ);
	}

	BoundingBox3d::~BoundingBox3d()
	{

	}

	BoundingBox3d::BoundingBox3d(const BoundingBox3d& boundingBox):
		minX(boundingBox.minX),
		minY(boundingBox.minY),
		minZ(boundingBox.minZ),
		maxX(boundingBox.maxX),
		maxY(boundingBox.maxY),
		maxZ(boundingBox.maxZ)
	{
		
	}

	BoundingBox3d& BoundingBox3d::operator = (const BoundingBox3d& boundingBox)
	{
		minX = boundingBox.minX;
		minY = boundingBox.minY;
		minZ = boundingBox.minZ;
		maxX = boundingBox.maxX;
		maxY = boundingBox.maxY;
		maxZ = boundingBox.maxZ;

		return *this;
	}

	Vec3d BoundingBox3d::center(void) const
	{
		return Vec3d(
			0.5 * (minX + maxX),
			0.5 * (minY + maxY),
			0.5 * (minZ + maxZ)
		);
	}

	bool BoundingBox3d::isValid(void) const
	{
		return (minX <= maxX) && (minY <= maxY) && (minZ <= maxZ);
	}

	void BoundingBox3d::add(const double x, const double y, const double z)
	{
		minX = std::min<double>(minX, x);
		minY = std::min<double>(minY, y);
		minZ = std::min<double>(minZ, z);
		maxX = std::max<double>(maxX, x);
		maxY = std::max<double>(maxY, y);
		maxZ = std::max<double>(maxZ, z);
	}

	void BoundingBox3d::add(const Vec3d& v)
	{
		minX = std::min<double>(minX, v.x);
		minY = std::min<double>(minY, v.y);
		minZ = std::min<double>(minZ, v.z);
		maxX = std::max<double>(maxX, v.x);
		maxY = std::max<double>(maxY, v.y);
		maxZ = std::max<double>(maxZ, v.z);
	}

	void BoundingBox3d::add(const BoundingBox3d& boundingBox)
	{
		minX = std::min<double>(minX, boundingBox.minX);
		minY = std::min<double>(minY, boundingBox.minY);
		minZ = std::min<double>(minZ, boundingBox.minZ);
		maxX = std::max<double>(maxX, boundingBox.minX);
		maxY = std::max<double>(maxY, boundingBox.minY);
		maxZ = std::max<double>(maxZ, boundingBox.minZ);

		minX = std::min<double>(minX, boundingBox.maxX);
		minY = std::min<double>(minY, boundingBox.maxY);
		minZ = std::min<double>(minZ, boundingBox.maxZ);
		maxX = std::max<double>(maxX, boundingBox.maxX);
		maxY = std::max<double>(maxY, boundingBox.maxY);
		maxZ = std::max<double>(maxZ, boundingBox.maxZ);
	}

	bool BoundingBox3d::intersects(const BoundingBox3d& boundingBox) const
	{
		if ((minX < boundingBox.maxX)
			&& (maxX > boundingBox.minX)
			&& (minY < boundingBox.maxY)
			&& (maxY > boundingBox.minY)
			&& (minZ < boundingBox.maxZ)
			&& (maxZ > boundingBox.minZ))
		{
			return true;
		}

		return false;
	}

	bool BoundingBox3d::contains(const double x, const double y, const double z) const
	{
		return (x >= minX)
			&& (x <= maxX)
			&& (y >= minY)
			&& (y <= maxY)
			&& (z >= minZ)
			&& (z <= maxZ);
	}

	bool BoundingBox3d::contains(const Vec3d& v) const
	{
		return (v.x >= minX)
			&& (v.x <= maxX)
			&& (v.y >= minY)
			&& (v.y <= maxY)
			&& (v.z >= minZ)
			&& (v.z <= maxZ);
	}

	bool BoundingBox3d::contains(const Vec3d& v1, const Vec3d v2) const
	{
		return contains(v1) && contains(v2);
	}

	bool BoundingBox3d::contains(const BoundingBox3d& boundingBox) const
	{
		return (boundingBox.minX > minX)
			&& (boundingBox.maxX < maxX)
			&& (boundingBox.minY > minY)
			&& (boundingBox.maxY < maxY)
			&& (boundingBox.minZ > minZ)
			&& (boundingBox.maxZ < maxZ);
	}

	bool BoundingBox3d::operator == (const BoundingBox3d& boundingBox) const
	{
		return (minX == boundingBox.minX)
			&& (minY == boundingBox.minY)
			&& (minZ == boundingBox.minZ)
			&& (maxX == boundingBox.maxX)
			&& (maxY == boundingBox.maxY)
			&& (maxZ == boundingBox.maxZ);
	}
}
