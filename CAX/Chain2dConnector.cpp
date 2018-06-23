#include "Chain2dConnector.h"


namespace CAX
{

	Chain2dConnector::Chain2dConnector()
	{

	}

	Chain2dConnector::Chain2dConnector(const std::list<Entity2d*>& entityList)
	{
		fromList(entityList);
	}

	Chain2dConnector::~Chain2dConnector()
	{

	}





	std::list<Chain2d>& Chain2dConnector::chains(void)
	{
		return m_chains;
	}



	void Chain2dConnector::fromList(const std::list<Entity2d*>& entityList)
	{
		using namespace std;

		if(entityList.empty()){
			return;
		}

		list<Entity2d*> entities = entityList;
		
		// 先处理封闭的图形
		list<Entity2d*>::iterator iter = entities.begin();
		while(iter != entities.end())
		{
			if((*iter)->isClosed())
			{
				list<Entity2d*>::iterator currentIter = iter++;
				Chain2d chain(*currentIter);
				m_chains.push_back(chain);

				entities.erase(currentIter);
			}
			else
			{
				++iter;
			}
		}


		list<Entity2d*> headEntities;
		list<Entity2d*> tailEntities;
		bool bHeadContinue = true;
		bool bTailContinue = true;

		while(!entities.empty())
		{
			Chain2d chain(entities.front());
			entities.pop_front();

			m_chains.push_back(chain);
			Chain2d& currentChain = m_chains.back();

			if(currentChain.isClosed())
			{
				continue;
			}

			while(true)
			{
				bHeadContinue = true;
				bTailContinue = true;

				list<Entity2d*>::iterator iter = entities.begin();
				while (iter != entities.end())
				{
					if (bTailContinue && (*iter)->head() == currentChain.tail())
					{
						list<Entity2d*>::iterator tailIter = iter++;
						tailEntities.push_back((*tailIter));

						entities.erase(tailIter);
					}
					else if (bTailContinue && (*iter)->tail() == currentChain.tail())
					{
						list<Entity2d*>::iterator tailIter = iter++;
						// 反向
						(*tailIter)->reverse();
						tailEntities.push_back((*tailIter));

						entities.erase(tailIter);
					}
					else if (bHeadContinue && (*iter)->head() == currentChain.head())
					{
						list<Entity2d*>::iterator headIter = iter++;
						// 反向
						(*headIter)->reverse();
						headEntities.push_back((*headIter));

						entities.erase(headIter);
					}
					else if (bHeadContinue && (*iter)->tail() == currentChain.head())
					{
						list<Entity2d*>::iterator headIter = iter++;
						headEntities.push_back((*headIter));

						entities.erase(headIter);
					}
					else
					{
						++iter;
					}
				} // while (iter != entities.end())

				size_t headCount = headEntities.size();
				size_t tailCount = tailEntities.size();
				// 终止条件
				if (headCount == 0 && tailCount == 0)
				{
					break;
				}
				if (headCount > 1 && tailCount > 1)
				{
					entities.insert(entities.end(), headEntities.begin(), headEntities.end());
					entities.insert(entities.end(), tailEntities.begin(), tailEntities.end());
					headEntities.clear();
					tailEntities.clear();
					break;
				}
				if (headCount == 0 && tailCount > 1)
				{
					entities.insert(entities.end(), tailEntities.begin(), tailEntities.end());
					tailEntities.clear();
					break;
				}
				if (headCount > 1 && tailCount == 0)
				{
					entities.insert(entities.end(), headEntities.begin(), headEntities.end());
					headEntities.clear();
					break;
				}


				// 与头部相连的实体
				if (headCount > 1)
				{
					bHeadContinue = false;
				}
				else if (headCount == 0)
				{
					bHeadContinue = false;
				}
				else // headCount == 1
				{
					currentChain.entities().push_front(headEntities.front());
					headEntities.clear();
				}

				// 与尾部相连的实体
				if (tailCount > 1)
				{
					bTailContinue = false;
				}
				else if (tailCount == 0)
				{
					bTailContinue = false;
				}
				else // tailCount == 1
				{
					currentChain.entities().push_back(tailEntities.front());
					tailEntities.clear();
				}
			}
			
		}
		
	}


} // namespace CAX
