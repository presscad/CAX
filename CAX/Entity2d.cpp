#include "Entity2d.h"


#include "MultiInstancePool.h"
#include "TypeTools.h"
#include "Point2d.h"
#include "Line2d.h"
#include "Polyline2d.h"
#include "LwPolyline2d.h"
#include "Arc2d.h"
#include "Circle2d.h"
#include "Ellipse2d.h"

namespace CAX
{
	struct Destructor2d
	{
		void operator () (void* p)
		{
			Entity2d *pEntity = reinterpret_cast<Entity2d*>(p);
			pEntity->~Entity2d();
			//switch(pEntity->type())
			//{
			//case Entity2d::Point:
			//	reinterpret_cast<Point2d*>(pEntity)->~Point2d();
			//	break;
			//case Entity2d::Line:
			//	reinterpret_cast<Line2d*>(pEntity)->~Line2d();
			//	break;
			//case Entity2d::Polyline:
			//	reinterpret_cast<Polyline2d*>(pEntity)->~Polyline2d();
			//	break;
			//case Entity2d::LwPolyline:
			//	reinterpret_cast<LwPolyline2d*>(pEntity)->~LwPolyline2d();
			//	break;
			//case Entity2d::Arc:
			//	reinterpret_cast<Arc2d*>(pEntity)->~Arc2d();
			//	break;
			//case Entity2d::Circle:
			//	reinterpret_cast<Circle2d*>(pEntity)->~Circle2d();
			//	break;
			//case Entity2d::Ellipse:
			//	break;
			//}
		}
	};

	static MultiInstancePool<
		SizeTraits<Point2d, Line2d, Polyline2d, LwPolyline2d, Arc2d, Circle2d>::max_value
		, 1024, Destructor2d> gPool2d;


	Point2d* Entity2d::newPoint()
	{
		return gPool2d.newInstance<Point2d>();
	}

	Line2d* Entity2d::newLine()
	{
		return gPool2d.newInstance<Line2d>();
	}

	Polyline2d* Entity2d::newPolyline()
	{
		return gPool2d.newInstance<Polyline2d>();
	}

	LwPolyline2d* Entity2d::newLwPolyline()
	{
		return gPool2d.newInstance<LwPolyline2d>();
	}
	Arc2d* Entity2d::newArc()
	{
		return gPool2d.newInstance<Arc2d>();
	}

	Circle2d* Entity2d::newCircle()
	{
		return gPool2d.newInstance<Circle2d>();
	}

	Ellipse2d* Entity2d::newEllipse()
	{
		return gPool2d.newInstance<Ellipse2d>();
	}

	void Entity2d::deleteInstance(Entity2d* p)
	{
		gPool2d.deleteInstance(p);
	}

	//template<typename T>
	//T* Entity2d::newInstance()
	//{
	//	return gPool2d.newInstance<T>();
	//}




	Entity2d::Entity2d()
	{
	}


	Entity2d::~Entity2d()
	{
	}





} // namespace CAX

