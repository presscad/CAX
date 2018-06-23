#include "Surface3d.h"


namespace CAX
{

	Surface3d::Surface3d()
	{
	}


	Surface3d::~Surface3d()
	{
	}

	Entity3d::BaseType Surface3d::baseType(void) const
	{
		return Entity3d::Surface;
	}

} // namespace CAX

