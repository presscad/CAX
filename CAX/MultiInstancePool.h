#pragma once


#ifndef _MULTIINSTANCEPOOL_H_
#define _MULTIINSTANCEPOOL_H_


#include <cstddef>
#include <cassert>

namespace CAX
{
	template<size_t maxBytes, size_t blockSize, typename destructor>
	class MultiInstancePool
	{
	public:
		typedef destructor destructor_type;

		MultiInstancePool(void);
		~MultiInstancePool(void);

		/* 分配一个对象内存 */
		template<typename T>
		T* newInstance();
		/* 回收一个对象内存 */
		template<typename T>
		void deleteInstance(T* p);


	private:
		/* 用于连接每一个Block */
		typedef struct BlockLinker {
			BlockLinker* pNext;
		} *BlockSlot;

		typedef struct SlotType {
			SlotType*	pNext;
			char		type[maxBytes];
		} *Slot;

		/* 用于连接每一个Slot */
		typedef struct SlotLinkerType {
			SlotType* pNext;
		} *SlotLinker;


		void allocateBlock(void);
		void deletePool(void);


		BlockSlot m_pCurrentBlock;
		Slot m_pFreeInstance;
		size_t m_iCurrentInstance;

		destructor m_destructor;

		const size_t m_blockSize;
		const size_t m_blockBytes;
		const size_t m_typeBytes;
		const size_t m_slotBytes;

	}; // class MultiInstancePool

} // namespace CAX


#endif




#ifndef _MULTIINSTANCEPOOL_IMP_
#define _MULTIINSTANCEPOOL_IMP_


namespace CAX
{
	template<size_t maxBytes, size_t blockSize, typename destructor>
	MultiInstancePool<maxBytes, blockSize, destructor>::MultiInstancePool(void) :
		m_pCurrentBlock(NULL),
		m_pFreeInstance(NULL),
		m_iCurrentInstance(blockSize + 1),
		m_blockSize(blockSize),
		m_blockBytes(sizeof(BlockLinker) + blockSize * (sizeof(SlotType))),
		m_typeBytes(sizeof(maxBytes)),
		m_slotBytes(sizeof(SlotType))
	{

	}

	template<size_t maxBytes, size_t blockSize, typename destructor>
	MultiInstancePool<maxBytes, blockSize, destructor>::~MultiInstancePool(void)
	{
		deletePool();
	}

	template<size_t maxBytes, size_t blockSize, typename destructor>
	void MultiInstancePool<maxBytes, blockSize, destructor>::deletePool(void)
	{
		if (m_pCurrentBlock) {
			size_t iCurrentSlot = 1;
			Slot pCurSlot = reinterpret_cast<Slot>(m_pCurrentBlock + 1);
			void* pType = NULL;
			while (iCurrentSlot < m_iCurrentInstance)
			{
				pType = reinterpret_cast<void*>(&(pCurSlot->type));
				// 析构
				m_destructor(pType);

				pCurSlot++;
				iCurrentSlot++;
			}

			BlockSlot pCurrentBlock = m_pCurrentBlock->pNext;
			pCurSlot = reinterpret_cast<Slot>(m_pCurrentBlock + 1);
			while (pCurrentBlock)
			{
				iCurrentSlot = 1;
				while (iCurrentSlot <= m_blockSize)
				{
					pType = reinterpret_cast<void*>(&(pCurSlot->type));
					// 析构
					m_destructor(pType);

					pCurSlot++;
					iCurrentSlot++;
				}

				pCurrentBlock = pCurrentBlock->pNext;
			}


			pCurrentBlock = m_pCurrentBlock;
			BlockSlot pNextBlock = NULL;
			while (pCurrentBlock)
			{
				pNextBlock = pCurrentBlock->pNext;

				std::free(pCurrentBlock);

				pCurrentBlock = pNextBlock;
			}

		}
	}

	template<size_t maxBytes, size_t blockSize, typename destructor>
	void MultiInstancePool<maxBytes, blockSize, destructor>::allocateBlock(void)
	{
		BlockSlot pNewBlock = reinterpret_cast<BlockSlot>(std::malloc(m_blockBytes));

		assert(pNewBlock);

		pNewBlock->pNext = m_pCurrentBlock;
		m_pCurrentBlock = pNewBlock;

		m_iCurrentInstance = 1;
	}

	template<size_t maxBytes, size_t blockSize, typename destructor>
	template<typename T>
	T* MultiInstancePool<maxBytes, blockSize, destructor>::newInstance(void)
	{
		T* pType = NULL;

		if (m_pFreeInstance)
		{
			pType = reinterpret_cast<T*>(&(m_pFreeInstance->type));

			new (pType) T();
			m_pFreeInstance = m_pFreeInstance->pNext;
		}
		else
		{
			if (m_iCurrentInstance > m_blockSize)
			{
				allocateBlock();
			}
			Slot pCurSlot = reinterpret_cast<Slot>(m_pCurrentBlock + 1);
			pType = reinterpret_cast<T*>(&((pCurSlot + (m_iCurrentInstance - 1))->type));

			new (pType) T();

			m_iCurrentInstance++;
		}

		return pType;
	}

	template<size_t maxBytes, size_t blockSize, typename destructor>
	template<typename T>
	void MultiInstancePool<maxBytes, blockSize, destructor>::deleteInstance(T* p)
	{
		if (!p)
		{
			m_destructor(p);

			Slot pFreeSlot = reinterpret_cast<Slot>(reinterpret_cast<SlotLinker>(p) - 1);
			pFreeSlot->pNext = m_pFreeInstance;
			m_pFreeInstance = pFreeSlot;
		}
	}


} // namespace CAX





#endif