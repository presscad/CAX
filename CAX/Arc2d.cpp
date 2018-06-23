#include "Arc2d.h"


#include <cmath>
#include <algorithm>


#include "Constants.h"
#include "MathTools.h"


namespace CAX
{

	Arc2d::Arc2d():
		m_center(),
		m_radius(1.0),
		m_startRadian(0.0),
		m_endRadian(Constants<double>::PI),
		m_clockwise(false)
	{
		
	}



	Arc2d::~Arc2d()
	{

	}

	Entity2d::Type Arc2d::type(void) const
	{
		return Entity2d::Arc;
	}

	bool Arc2d::isClosed(void) const
	{
		return equals(std::abs(m_startRadian - m_endRadian), Constants<double>::PIx2);
	}

	Vec2d Arc2d::head(void) const
	{
		return Vec2d(
			m_center.x + m_radius * std::cos(m_startRadian),
			m_center.y + m_radius * std::sin(m_startRadian));
	}

	Vec2d Arc2d::tail(void) const
	{
		return Vec2d(
			m_center.x + m_radius * std::cos(m_endRadian),
			m_center.y + m_radius * std::sin(m_endRadian));
	}

	BoundingBox2d Arc2d::boundingBox2d(void) const
	{
		// 起点和终点弧度都在 [0,2pi]
		Vec2d start(
			m_center.x + m_radius * std::cos(m_startRadian),
			m_center.y + m_radius * std::sin(m_startRadian)
		);
		Vec2d end(
			m_center.x + m_radius * std::cos(m_endRadian),	
			m_center.y + m_radius * std::sin(m_endRadian)
		);

		BoundingBox2d box;
		box.add(start);
		box.add(end);

		Vec2d vertex;

		if(m_clockwise)
		{
			if(m_endRadian > m_startRadian)
			{
				if(inRange(Constants<double>::PI_2, m_startRadian, m_endRadian))
				{	
					vertex.x = m_center.x;
					vertex.y = m_center.y + m_radius;
					box.add(vertex);
				}
				if(inRange(Constants<double>::PI, m_startRadian, m_endRadian))
				{
					vertex.x = m_center.x - m_radius;
					vertex.y = m_center.y;
					box.add(vertex);
				}
				if(inRange(Constants<double>::PIx3_2, m_startRadian, m_endRadian))
				{
					vertex.x = m_center.x;
					vertex.y = m_center.y - m_radius;
					box.add(vertex);
				}
				if(inRange(Constants<double>::PIx2, m_startRadian, m_endRadian))
				{
					vertex.x = m_center.x + m_radius;
					vertex.y = m_center.y;
					box.add(vertex);
				}
			}
			else
			{
				if (!inRange(Constants<double>::PI_2, m_endRadian, m_startRadian))
				{
					vertex.x = m_center.x;
					vertex.y = m_center.y + m_radius;
					box.add(vertex);
				}
				if (!inRange(Constants<double>::PI, m_endRadian, m_startRadian))
				{
					vertex.x = m_center.x - m_radius;
					vertex.y = m_center.y;
					box.add(vertex);
				}
				if (!inRange(Constants<double>::PIx3_2, m_endRadian, m_startRadian))
				{
					vertex.x = m_center.x;
					vertex.y = m_center.y - m_radius;
					box.add(vertex);
				}
				if (!inRange(Constants<double>::PIx2, m_endRadian, m_startRadian))
				{
					vertex.x = m_center.x + m_radius;
					vertex.y = m_center.y;
					box.add(vertex);
				}
			}
		}
		else
		{
			if(m_endRadian < m_startRadian)
			{
				if (inRange(Constants<double>::PI_2, m_endRadian, m_startRadian))
				{
					vertex.x = m_center.x;
					vertex.y = m_center.y + m_radius;
					box.add(vertex);
				}
				if (inRange(Constants<double>::PI, m_endRadian, m_startRadian))
				{
					vertex.x = m_center.x - m_radius;
					vertex.y = m_center.y;
					box.add(vertex);
				}
				if (inRange(Constants<double>::PIx3_2, m_endRadian, m_startRadian))
				{
					vertex.x = m_center.x;
					vertex.y = m_center.y - m_radius;
					box.add(vertex);
				}
				if (inRange(Constants<double>::PIx2, m_endRadian, m_startRadian))
				{
					vertex.x = m_center.x + m_radius;
					vertex.y = m_center.y;
					box.add(vertex);
				}
			}
			else
			{
				if (!inRange(Constants<double>::PI_2, m_startRadian, m_endRadian))
				{
					vertex.x = m_center.x;
					vertex.y = m_center.y + m_radius;
					box.add(vertex);
				}
				if (!inRange(Constants<double>::PI, m_startRadian, m_endRadian))
				{
					vertex.x = m_center.x - m_radius;
					vertex.y = m_center.y;
					box.add(vertex);
				}
				if (!inRange(Constants<double>::PIx3_2, m_startRadian, m_endRadian))
				{
					vertex.x = m_center.x;
					vertex.y = m_center.y - m_radius;
					box.add(vertex);
				}
				if (!inRange(Constants<double>::PIx2, m_startRadian, m_endRadian))
				{
					vertex.x = m_center.x + m_radius;
					vertex.y = m_center.y;
					box.add(vertex);
				}
			}
		}

		return box;
	}

	BoundingBox3d Arc2d::boundingBox3d(void) const
	{
		BoundingBox2d box2d = boundingBox2d();

		return BoundingBox3d(box2d.minX, box2d.minY, 0.0, box2d.maxX, box2d.maxY, 0.0);
	}

	void Arc2d::reverse(void)
	{
		std::swap(m_startRadian, m_endRadian);
		m_clockwise = !m_clockwise;
	}

	double Arc2d::length(void) const
	{
		return (m_radius * absRadianRange());
	}




	Vec2d& Arc2d::center(void)
	{
		return m_center;
	}

	double& Arc2d::radius(void)
	{
		return m_radius;
	}

	double& Arc2d::startRadian(void)
	{
		return m_startRadian;
	}

	double& Arc2d::endRadian(void)
	{
		return m_endRadian;
	}

	double Arc2d::radianRange(void) const
	{
		if(m_clockwise)
		{
			if(m_endRadian >= m_startRadian)
			{
				return (m_endRadian - m_startRadian);
			}
			else
			{
				return (m_endRadian + Constants<double>::PI - m_startRadian);
			}
		}
		else
		{
			if(m_endRadian <= m_startRadian)
			{
				return (m_endRadian - m_startRadian);
			}
			else
			{
				return (m_endRadian - Constants<double>::PI - m_startRadian);
			}
		}
	}

	double Arc2d::degreeRange(void) const
	{
		return toDegrees<double>(radianRange());
	}

	double Arc2d::absRadianRange(void) const
	{
		return std::abs(radianRange());
	}

	double Arc2d::absDegreeRange(void) const
	{
		return std::abs(degreeRange());
	}

	void Arc2d::fromBulge(const Vec2d& start, const Vec2d& end, const double bulge)
	{
		double chordLength = start.length(end);
		double halfChordLength = 0.5 * chordLength;
		double h = std::abs(halfChordLength * bulge);
		Vec2d chordCenter = 0.5 * (start + end);

		if(equals(bulge, 1.0) || equals(bulge, -1.0))
		{
			m_radius = halfChordLength;
			m_center = chordCenter;
		}
		else
		{
			m_radius = ((h * h) + (halfChordLength * halfChordLength)) / (2 * h);

			Vec2d startToChordCenter = chordCenter - start;
			double d = std::abs(m_radius - h);
			if((bulge > 0.0 && bulge < 1.0) || bulge < -1.0)
			{
				//向左拐
				m_center.x = chordCenter.x - startToChordCenter.y * d / halfChordLength;
				m_center.y = chordCenter.y + startToChordCenter.x * d / halfChordLength;
			}
			else
			{
				//向右拐
				m_center.x = chordCenter.x + startToChordCenter.y * d / halfChordLength;
				m_center.y = chordCenter.y - startToChordCenter.x * d / halfChordLength;
			}
		}

		m_startRadian = atan2(start.y - m_center.y, start.x - m_center.x);
		double arcRadian = 4.0 * atan(bulge);
		m_endRadian = m_startRadian + arcRadian;

		m_clockwise = bulge < 0.0 ? true : false;
		cycleClamp(m_startRadian, 0.0, Constants<double>::PIx2);
		cycleClamp(m_endRadian, 0.0, Constants<double>::PIx2);
	}


} // namespace CAX
