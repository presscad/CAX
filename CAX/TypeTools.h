#pragma once


#ifndef _TYPETOOLS_H_
#define _TYPETOOLS_H_

#include <cstddef>

namespace CAX
{
	/* ������ */
	template<typename... types>
	class SizeTraits;

	/* �ݹ��ػ� */
	template<typename T, typename... types>
	class SizeTraits<T, types...>
	{
	public:
		static const size_t max_value =
			sizeof(T) > SizeTraits<types...>::max_value ?
			sizeof(T) : SizeTraits<types...>::max_value;
		static const size_t min_value =
			sizeof(T) < SizeTraits<types...>::min_value ?
			sizeof(T) : SizeTraits<types...>::min_value;
	};

	/* ��ֹ�ػ� */
	template<typename T>
	class SizeTraits<T>
	{
	public:
		static const size_t max_value = sizeof(T);
		static const size_t min_value = sizeof(T);
	};


}// namespace CAX



#endif