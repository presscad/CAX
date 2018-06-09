#pragma once


#ifndef _ENTITY3D_H_
#define _ENTITY3D_H_


namespace CAX
{
	class Entity3d
	{
	public:
		enum BaseType
		{
			Curve,		// 曲线
			Surface,	// 曲面
			Solid,		// 实体
		};

		/* 返回基础类型 */
		BaseType baseType(void);

	protected:
		Entity3d(BaseType baseType);
		~Entity3d();


	private:

		const BaseType m_baseType;
	};

} // namespace CAX

#endif // #ifndef _ENTITY3D_H_