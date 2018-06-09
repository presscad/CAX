#include "Entity2d.h"


namespace CAX
{

	Entity2d::Entity2d(Type type):
		m_type(type)
	{
	}


	Entity2d::~Entity2d()
	{
	}

	Entity2d::Type Entity2d::type(void) const
	{
		return m_type;
	}

} // namespace CAX

