#include "Chain2d.h"


namespace CAX
{

	Chain2d::Chain2d()
	{

	}

	Chain2d::Chain2d(Entity2d* pEntity)
	{
		m_entities.push_back(pEntity);
	}

	Chain2d::Chain2d(const std::list<Entity2d*>& entityList)
	{
		if(isSorted(entityList))
		{
			m_entities = entityList;
			return;
		}
	}

	Entity2d::Type Chain2d::type(void) const
	{
		return Entity2d::Chain;
	}

	Chain2d::~Chain2d()
	{

	}




	bool Chain2d::isClosed(void) const
	{
		if(m_entities.size() == 1)
		{
			return m_entities.front()->isClosed();
		}

		return (head() == tail());
	}

	Vec2d Chain2d::head(void) const
	{
		return m_entities.front()->head();
	}

	Vec2d Chain2d::tail(void) const
	{
		return m_entities.back()->tail();
	}

	BoundingBox2d Chain2d::boundingBox2d(void) const
	{
		using namespace std;
		BoundingBox2d box;

		list<Entity2d*>::const_iterator iter;
		for(iter=m_entities.cbegin(); iter!=m_entities.cend(); ++iter)
		{
			box.add((*iter)->boundingBox2d());
		}

		return box;
	}

	BoundingBox3d Chain2d::boundingBox3d(void) const
	{
		BoundingBox2d box2d = boundingBox2d();

		return BoundingBox3d(box2d.minX, box2d.minY, 0.0, box2d.maxX, box2d.maxY, 0.0);
	}

	void Chain2d::reverse(void)
	{
		using namespace std;
		list<Entity2d*>::iterator iter;
		for(iter=m_entities.begin(); iter!=m_entities.end(); ++iter)
		{
			(*iter)->reverse();
		}

		m_entities.reverse();
	}

	double Chain2d::length(void) const
	{
		using namespace std;

		double totalLength = 0.0;
		list<Entity2d*>::const_iterator iter;
		for(iter=m_entities.cbegin(); iter!=m_entities.cend(); ++iter)
		{
			totalLength += (*iter)->length();
		}
		return totalLength;
	}


	bool Chain2d::isSorted(const std::list<Entity2d*>& entityList)
	{
		using namespace std;

		if(entityList.size() < 2)
		{
			return true;
		}
		
		list<Entity2d*>::const_iterator iter = entityList.cbegin();
		Vec2d tail = (*iter)->tail();
		Vec2d head;

		for(++iter ; iter!=entityList.cend(); ++iter)
		{
			head = (*iter)->head();
			if(tail != head){
				return false;
			}
			tail = (*iter)->tail();
		}

		return true;
	}

	bool Chain2d::isSorted(void) const
	{
		return isSorted(m_entities);
	}


	std::list<Entity2d*>& Chain2d::entities(void)
	{
		return m_entities;
	}

}

