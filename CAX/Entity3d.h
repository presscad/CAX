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
			Curve,		// ����
			Surface,	// ����
			Solid,		// ʵ��
		};

		/* ���ػ������� */
		BaseType baseType(void);

	protected:
		Entity3d(BaseType baseType);
		~Entity3d();


	private:

		const BaseType m_baseType;
	};

} // namespace CAX

#endif // #ifndef _ENTITY3D_H_