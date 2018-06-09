#pragma once

#ifndef _INSTANCEPOOL_H_
#define _INSTANCEPOOL_H_


#include <cstddef>
#include <cstdlib>
#include <cassert>
#include <cstdio>

namespace CAX
{


	/*
	*	对象池
	*	T			对象的类型
	*	blockSize	一个block中有多少个对象
	*/
	template<typename T, size_t blockSize>
	class InstancePool
	{
	public:
		typedef T			value_type;
		typedef T*			pointer;


		InstancePool();
		~InstancePool();

		/* 分配一个对象内存 */
		T* newInstance(void);
		/* 回收一个对象内存 */
		void deleteInstance(T* p);

	private:



		/* 用于连接每一个Block */
		typedef struct BlockLinker {
			BlockLinker* pNext;
		} *BlockSlot;

		typedef struct SlotType {
			SlotType*	pNext;
			char		type[sizeof(T)];
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

		const size_t m_blockSize;
		const size_t m_blockBytes;
		const size_t m_typeBytes;
		const size_t m_slotBytes;
	};


}// namespace CAX


#endif




#ifndef _INSTANCE_IMP_
#define _INSTANCE_IMP_


namespace CAX
{
	template<typename T, size_t blockSize>
	InstancePool<T, blockSize>::InstancePool() :
		m_pCurrentBlock(NULL),
		m_pFreeInstance(NULL),
		m_iCurrentInstance(blockSize + 1),
		m_blockSize(blockSize),
		m_blockBytes(sizeof(BlockLinker) + blockSize * (sizeof(SlotType))),
		m_typeBytes(sizeof(T)),
		m_slotBytes(sizeof(SlotType))
	{
		//std::printf("block_types = %d", m_blockBytes);
	}

	template<typename T, size_t blockSize>
	InstancePool<T, blockSize>::~InstancePool()
	{
		deletePool();
	}

	template<typename T, size_t blockSize>
	void InstancePool<T, blockSize>::deletePool(void)
	{
		if (m_pCurrentBlock) {
			size_t iCurrentSlot = 1;
			Slot pCurSlot = reinterpret_cast<Slot>(m_pCurrentBlock + 1);
			pointer pType = NULL;
			while (iCurrentSlot <= m_blockSize)
			{
				pType = reinterpret_cast<T*>(&(pCurSlot->type));
				// 析构
				pType->~T();

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
					pType = reinterpret_cast<T*>(&(pCurSlot->type));

					pType->~T();

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

	template<typename T, size_t blockSize>
	T* InstancePool<T, blockSize>::newInstance(void)
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


	template<typename T, size_t blockSize>
	void InstancePool<T, blockSize>::deleteInstance(T* p)
	{
		if (!p)
		{
			p->~T();
			Slot pFreeSlot = reinterpret_cast<Slot>(reinterpret_cast<SlotLinker>(p) - 1);
			pFreeSlot->pNext = m_pFreeInstance;
			m_pFreeInstance = pFreeSlot;
		}
	}


	template<typename T, size_t blockSize>
	void InstancePool<T, blockSize>::allocateBlock(void)
	{
		BlockSlot pNewBlock = reinterpret_cast<BlockSlot>(std::malloc(m_blockBytes));

		assert(pNewBlock);

		pNewBlock->pNext = m_pCurrentBlock;
		m_pCurrentBlock = pNewBlock;

		m_iCurrentInstance = 1;
	}

} // namespace CAX




#endif