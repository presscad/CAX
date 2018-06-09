#include "Entity3d.h"


namespace CAX
{
	Entity3d::Entity3d(BaseType baseType) :
		m_baseType(baseType)
	{

	}


	Entity3d::~Entity3d()
	{

	}


	Entity3d::BaseType Entity3d::baseType(void)
	{
		return m_baseType;
	}
} // namespace CAX