#include "Ellipse2d.h"


#include <cmath>
#include <algorithm>


#include "Constants.h"
#include "MathTools.h"


namespace CAX
{

	Ellipse2d::Ellipse2d():
		m_center(0.0, 0.0),
		m_major(1.0),
		m_minor(1.0),
		m_startRadian(0.0),
		m_endRadian(Constants<double>::PI),
		m_clockwise(false)
	{

	}


	Ellipse2d::~Ellipse2d()
	{

	}

	Entity2d::Type Ellipse2d::type(void) const
	{
		return Entity2d::Ellipse;
	}

	bool Ellipse2d::isClosed(void) const
	{
		return equals(std::abs(m_startRadian - m_endRadian), Constants<double>::PIx2);
	}

	Vec2d Ellipse2d::head(void) const
	{
		return Vec2d();
	}

	Vec2d Ellipse2d::tail(void) const
	{
		return Vec2d();
	}

	BoundingBox2d Ellipse2d::boundingBox2d(void) const
	{
		using namespace std;

		BoundingBox2d box;

		if(isClosed())
		{
			if(equals(m_rotateRadian, 0.0)
				|| equals(m_rotateRadian, Constants<double>::PI)
				|| equals(m_rotateRadian, -Constants<double>::PI))
			{
				box.minX = m_center.x - m_major;
				box.minY = m_center.y - m_minor;
				box.maxX = m_center.x + m_major;
				box.maxY = m_center.y + m_minor;
			}
			else if(equals(m_rotateRadian, Constants<double>::PI_2)
				|| equals(m_rotateRadian, -Constants<double>::PI_2))
			{
				box.minX = m_center.x - m_minor;
				box.minY = m_center.y - m_major;
				box.maxX = m_center.x + m_minor;
				box.maxY = m_center.y + m_major;
			}
			else
			{
				double cos_rotate = cos(m_rotateRadian);
				double sin_rotate = sin(m_rotateRadian);
				double tan_rotate = sin_rotate / cos_rotate;
				double radian1 = atan(-m_minor * tan_rotate / m_major);
				double radian2 = radian1 + Constants<double>::PI;
				double value1 = m_center.x + m_major * cos(radian1) * cos_rotate 
					- m_minor * sin(radian1) * sin_rotate;
				double value2 = m_center.x + m_major * cos(radian2) * cos_rotate
					- m_minor * sin(radian2) * sin_rotate;

				box.minX = min(value1, value2);
				box.maxX = max(value1, value2);

				radian1 = atan(m_minor / tan_rotate / m_major);
				radian2 = radian1 + Constants<double>::PI;
				value1 = m_center.y + m_minor * sin(radian1) * cos_rotate
					+ m_major * cos(radian1) * sin_rotate;
				value2 = m_center.y + m_minor * sin(radian2) * cos_rotate
					+ m_major * cos(radian2) * sin_rotate;

				box.minY = min(value1, value2);
				box.maxY = max(value1, value2);
			}
		}
		else
		{
			double cos_rotate = cos(m_rotateRadian);
			double sin_rotate = sin(m_rotateRadian);
			Vec2d start(
				m_center.x + m_major * cos(m_startRadian) * cos_rotate - m_minor * sin(m_startRadian) * sin_rotate,
				m_center.y + m_minor * sin(m_startRadian) * cos_rotate - m_major * cos(m_startRadian) * sin_rotate
			);
			Vec2d end(
				m_center.x + m_major * cos(m_endRadian) * cos_rotate - m_minor * sin(m_endRadian) * sin_rotate,
				m_center.y + m_minor * sin(m_endRadian) * cos_rotate - m_major * cos(m_endRadian) * sin_rotate
			);

			box.add(start);
			box.add(end);

			Vec2d vertex;
			if (equals(m_rotateRadian, 0.0)
				|| equals(m_rotateRadian, Constants<double>::PI_2)
				|| equals(m_rotateRadian, -Constants<double>::PI_2)
				|| equals(m_rotateRadian, Constants<double>::PI)
				|| equals(m_rotateRadian, -Constants<double>::PI))
			{
				if (m_clockwise)
				{
					if (m_endRadian > m_startRadian)
					{
						if (inRange(0.0, m_startRadian, m_endRadian))
						{
							vertex.x = m_center.x + m_major * cos(0.0) * cos_rotate - m_minor * sin(0.0) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(0.0) * cos_rotate - m_major * cos(0.0) * sin_rotate;
							box.add(vertex);
						}
						if (inRange(Constants<double>::PI_2, m_startRadian, m_endRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PI_2) * cos_rotate - m_minor * sin(Constants<double>::PI_2) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PI_2) * cos_rotate - m_major * cos(Constants<double>::PI_2) * sin_rotate;
							box.add(vertex);
						}
						if (inRange(Constants<double>::PI, m_startRadian, m_endRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PI) * cos_rotate - m_minor * sin(Constants<double>::PI) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PI) * cos_rotate - m_major * cos(Constants<double>::PI) * sin_rotate;
							box.add(vertex);
						}
						if (inRange(Constants<double>::PIx3_2, m_startRadian, m_endRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PIx3_2) * cos_rotate - m_minor * sin(Constants<double>::PIx3_2) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PIx3_2) * cos_rotate - m_major * cos(Constants<double>::PIx3_2) * sin_rotate;
							box.add(vertex);
						}
					}
					else
					{
						if (!inRange(0.0, m_endRadian, m_startRadian))
						{
							vertex.x = m_center.x + m_major * cos(0.0) * cos_rotate - m_minor * sin(0.0) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(0.0) * cos_rotate - m_major * cos(0.0) * sin_rotate;
							box.add(vertex);
						}
						if (!inRange(Constants<double>::PI_2, m_endRadian, m_startRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PI_2) * cos_rotate - m_minor * sin(Constants<double>::PI_2) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PI_2) * cos_rotate - m_major * cos(Constants<double>::PI_2) * sin_rotate;
							box.add(vertex);
						}
						if (!inRange(Constants<double>::PI, m_endRadian, m_startRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PI) * cos_rotate - m_minor * sin(Constants<double>::PI) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PI) * cos_rotate - m_major * cos(Constants<double>::PI) * sin_rotate;
							box.add(vertex);
						}
						if (!inRange(Constants<double>::PIx3_2, m_endRadian, m_startRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PIx3_2) * cos_rotate - m_minor * sin(Constants<double>::PIx3_2) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PIx3_2) * cos_rotate - m_major * cos(Constants<double>::PIx3_2) * sin_rotate;
							box.add(vertex);
						}
					} // end if(m_endRadian > m_startRadian)
				}
				else // if else(m_clockwise)
				{
					if (m_endRadian < m_startRadian)
					{
						if (inRange(0.0, m_endRadian, m_startRadian))
						{
							vertex.x = m_center.x + m_major * cos(0.0) * cos_rotate - m_minor * sin(0.0) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(0.0) * cos_rotate - m_major * cos(0.0) * sin_rotate;
							box.add(vertex);
						}
						if (inRange(Constants<double>::PI_2, m_endRadian, m_startRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PI_2) * cos_rotate - m_minor * sin(Constants<double>::PI_2) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PI_2) * cos_rotate - m_major * cos(Constants<double>::PI_2) * sin_rotate;
							box.add(vertex);
						}
						if (inRange(Constants<double>::PI, m_endRadian, m_startRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PI) * cos_rotate - m_minor * sin(Constants<double>::PI) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PI) * cos_rotate - m_major * cos(Constants<double>::PI) * sin_rotate;
							box.add(vertex);
						}
						if (inRange(Constants<double>::PIx3_2, m_endRadian, m_startRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PIx3_2) * cos_rotate - m_minor * sin(Constants<double>::PIx3_2) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PIx3_2) * cos_rotate - m_major * cos(Constants<double>::PIx3_2) * sin_rotate;
							box.add(vertex);
						}
					}
					else
					{
						if (!inRange(0.0, m_startRadian, m_endRadian))
						{
							vertex.x = m_center.x + m_major * cos(0.0) * cos_rotate - m_minor * sin(0.0) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(0.0) * cos_rotate - m_major * cos(0.0) * sin_rotate;
							box.add(vertex);
						}
						if (!inRange(Constants<double>::PI_2, m_startRadian, m_endRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PI_2) * cos_rotate - m_minor * sin(Constants<double>::PI_2) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PI_2) * cos_rotate - m_major * cos(Constants<double>::PI_2) * sin_rotate;
							box.add(vertex);
						}
						if (!inRange(Constants<double>::PI, m_startRadian, m_endRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PI) * cos_rotate - m_minor * sin(Constants<double>::PI) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PI) * cos_rotate - m_major * cos(Constants<double>::PI) * sin_rotate;
							box.add(vertex);
						}
						if (!inRange(Constants<double>::PIx3_2, m_startRadian, m_endRadian))
						{
							vertex.x = m_center.x + m_major * cos(Constants<double>::PIx3_2) * cos_rotate - m_minor * sin(Constants<double>::PIx3_2) * sin_rotate;
							vertex.y = m_center.y + m_minor * sin(Constants<double>::PIx3_2) * cos_rotate - m_major * cos(Constants<double>::PIx3_2) * sin_rotate;
							box.add(vertex);
						}
					}

				}// end if(m_clockwise)
			}// end if equals(0.0, pi/2, -pi/2)
			else
			{
				double tan_rotate = sin_rotate / cos_rotate;
				double radian[4];
				radian[0] = cycleClamp(atan(-m_minor * tan_rotate / m_major), 0.0, Constants<double>::PIx2);
				radian[1] = cycleClamp(radian[0] + Constants<double>::PI, 0.0, Constants<double>::PIx2);
				radian[2] = cycleClamp(atan(m_minor / tan_rotate / m_major), 0.0, Constants<double>::PIx2);
				radian[3] = cycleClamp(radian[2] + Constants<double>::PI, 0.0, Constants<double>::PIx2);

				if(m_clockwise)
				{
					if(m_endRadian > m_startRadian)
					{
						for(size_t i=1; i<4; ++i)
						{
							if(inRange(radian[i], m_startRadian, m_endRadian))
							{
								vertex.x = m_center.x + m_major * cos(radian[i]) * cos_rotate - m_minor * sin(radian[i]) * sin_rotate;
								vertex.y = m_center.y + m_minor * sin(radian[i]) * cos_rotate - m_major * cos(radian[i]) * sin_rotate;
								box.add(vertex);
							}
						}
					}
					else
					{
						for (size_t i = 1; i<4; ++i)
						{
							if (!inRange(radian[i], m_endRadian, m_startRadian))
							{
								vertex.x = m_center.x + m_major * cos(radian[i]) * cos_rotate - m_minor * sin(radian[i]) * sin_rotate;
								vertex.y = m_center.y + m_minor * sin(radian[i]) * cos_rotate - m_major * cos(radian[i]) * sin_rotate;
								box.add(vertex);
							}
						}
					}
				}
				else
				{
					if (m_endRadian < m_startRadian)
					{
						for (size_t i = 1; i<4; ++i)
						{
							if (inRange(radian[i], m_endRadian, m_startRadian))
							{
								vertex.x = m_center.x + m_major * cos(radian[i]) * cos_rotate - m_minor * sin(radian[i]) * sin_rotate;
								vertex.y = m_center.y + m_minor * sin(radian[i]) * cos_rotate - m_major * cos(radian[i]) * sin_rotate;
								box.add(vertex);
							}
						}
					}
					else
					{
						for (size_t i = 1; i<4; ++i)
						{
							if (!inRange(radian[i], m_startRadian, m_endRadian))
							{
								vertex.x = m_center.x + m_major * cos(radian[i]) * cos_rotate - m_minor * sin(radian[i]) * sin_rotate;
								vertex.y = m_center.y + m_minor * sin(radian[i]) * cos_rotate - m_major * cos(radian[i]) * sin_rotate;
								box.add(vertex);
							}
						}
					}
				}
			}
		}

		return box;
	}

	BoundingBox3d Ellipse2d::boundingBox3d(void) const
	{
		return BoundingBox3d();
	}

	void Ellipse2d::reverse(void)
	{
		std::swap(m_startRadian, m_endRadian);
		m_clockwise = !m_clockwise;
	}

	double Ellipse2d::length(void) const
	{
		return 0.0;
	}




	Vec2d& Ellipse2d::center(void)
	{
		return m_center;
	}

	double& Ellipse2d::major(void)
	{
		return m_major;
	}

	double& Ellipse2d::minor(void)
	{
		return m_minor;
	}

	double& Ellipse2d::startRadian(void)
	{
		return m_startRadian;
	}

	double& Ellipse2d::endRadian(void)
	{
		return m_endRadian;
	}

	double& Ellipse2d::rotateRadian(void)
	{
		return m_rotateRadian;
	}



} // namespace CAX

