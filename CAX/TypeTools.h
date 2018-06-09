#pragma once


#ifndef _TYPETOOLS_H_
#define _TYPETOOLS_H_

namespace CAX
{
	/* 基类型 */
	template<typename... types>
	class SizeTraits;

	/* 递归特化 */
	template<typename T, typename... types>
	class SizeTraits<T, types...>
	{
	public:
		enum
		{
			max_value =
			sizeof(T) > SizeTraits<types...>::max_value ?
			sizeof(T) : SizeTraits<types...>::max_value,
			min_value =
			sizeof(T) < SizeTraits<types...>::min_value ?
			sizeof(T) : SizeTraits<types...>::min_value
		};
	};

	/* 终止特化 */
	template<typename T>
	class SizeTraits<T>
	{
	public:
		enum {
			max_value = sizeof(T),
			min_value = sizeof(T)
		};
	};


}// namespace CAX



#endif