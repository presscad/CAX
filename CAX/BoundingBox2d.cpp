#include "BoundingBox2d.h"


#include <algorithm>


#include "Constants.h"
#include "Vec2.h"


namespace CAX
{


	BoundingBox2d::BoundingBox2d():
		minX(Constants<double>::MAX),
		minY(Constants<double>::MAX),
		maxX(Constants<double>::MIN),
		maxY(Constants<double>::MIN)
	{

	}

	BoundingBox2d::BoundingBox2d(const double fMinX, const double fMinY, const double fMaxX, const double fMaxY)
	{
		minX = std::min<double>(fMinX, fMaxX);
		maxX = std::max<double>(fMinX, fMaxX);
		minY = std::min<double>(fMinY, fMaxY);
		maxY = std::max<double>(fMinY, fMaxY);
	}

	BoundingBox2d::~BoundingBox2d()
	{

	}

	BoundingBox2d::BoundingBox2d(const BoundingBox2d& boundingBox):
		minX(boundingBox.minX),
		minY(boundingBox.minY),
		maxX(boundingBox.maxX),
		maxY(boundingBox.maxY)
	{

	}

	BoundingBox2d& BoundingBox2d::operator = (const BoundingBox2d& boundingBox)
	{
		minX = boundingBox.minX;
		minY = boundingBox.minY;
		maxX = boundingBox.maxX;
		maxY = boundingBox.maxY;
		return *this;
	}

	Vec2d BoundingBox2d::center(void) const
	{
		return Vec2d(
			0.5 * (minX + maxX),
			0.5 * (minY + maxY)
		);
	}

	bool BoundingBox2d::isValid(void) const
	{
		return (minX <= maxX) && (minY <= maxY);
	}


	void BoundingBox2d::add(const double x, const double y)
	{
		minX = std::min<double>(minX, x);
		minY = std::min<double>(minY, y);
		maxX = std::max<double>(maxX, x);
		maxY = std::max<double>(maxY, y);
	}

	void BoundingBox2d::add(const Vec2d& v)
	{
		minX = std::min<double>(minX, v.x);
		minY = std::min<double>(minY, v.y);
		maxX = std::max<double>(maxX, v.x);
		maxY = std::max<double>(maxY, v.y);
	}

	void BoundingBox2d::add(const BoundingBox2d& boundingBox)
	{
		minX = std::min<double>(minX, boundingBox.minX);
		minY = std::min<double>(minY, boundingBox.minY);
		maxX = std::max<double>(maxX, boundingBox.minX);
		maxY = std::max<double>(maxY, boundingBox.minY);

		minX = std::min<double>(minX, boundingBox.maxX);
		minY = std::min<double>(minY, boundingBox.maxY);
		maxX = std::max<double>(maxX, boundingBox.maxX);
		maxY = std::max<double>(maxY, boundingBox.maxY);
	}


	bool BoundingBox2d::intersects(const BoundingBox2d& boundingBox) const
	{
		if ((minX < boundingBox.maxX) 
			&& (maxX > boundingBox.minX) 
			&& (minY < boundingBox.maxY) 
			&& (maxY > boundingBox.minY))
		{
			return true;
		}

		return false;
	}


	bool BoundingBox2d::contains(const double x, const double y) const
	{
		return (x >= minX)
			&& (x <= maxX)
			&& (y >= minY)
			&& (y <= maxY);
	}

	bool BoundingBox2d::contains(const Vec2d& v) const
	{
		return (v.x >= minX)
			&& (v.x <= maxX)
			&& (v.y >= minY)
			&& (v.y <= maxY);
	}

	bool BoundingBox2d::contains(const Vec2d& v1, const Vec2d v2) const
	{
		return (contains(v1) && contains(v2));
	}

	bool BoundingBox2d::contains(const BoundingBox2d& boundingBox) const
	{
		return (boundingBox.minX > minX)
			&& (boundingBox.maxX < maxX)
			&& (boundingBox.minY > minY)
			&& (boundingBox.maxY < maxY);
	}


	bool BoundingBox2d::operator == (const BoundingBox2d& boundingBox) const
	{
		return (minX == boundingBox.minX)
			&& (minY == boundingBox.minY)
			&& (maxX == boundingBox.maxX)
			&& (maxY == boundingBox.maxY);
	}

} // namespace CAX

