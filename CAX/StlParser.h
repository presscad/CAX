#pragma once


#include <cstddef>
#include <vector>

#include "Triangle.h"


namespace CAX
{
	
	class StlParser
	{
	public:
		enum ErrorCode
		{
			SUCCESS,

			ERROR_IMPROPER_EXTNAME,
			ERROR_OPEN_FILE,

			ERROR_PARSE_NORMAL,

			ERROR_VERTEX_COUNT,
			ERROR_PARSE_VERTEX,

			ERROR_NO_DATA,


			ERROR_PARSE_SOLID_NAME,
			ERROR_PARSE_TRIANGLE_COUNT,
			ERROR_TRIANGLE_COUNT,
			ERROR_PARSE_VERTEX_AND_NORMAL,
		};

		enum FileType
		{
			BINARY = 1,
			ASCII  = 2,
		};


		// ���캯�� �� ��������
		StlParser();
		~StlParser();

		// �����ļ�
		bool parse(const char* filepath);


		// ��ȡ�����õ�������
		std::vector<Triangle>& triangles(void);
		std::vector<Vec3d>& normals(void);

	private:
		// trimLeft
		char* trimLeft(char* str);


		// �����õ�������
		char m_modelName[128];					// ģ�͵�����
		std::vector<Triangle> m_triangles;		// ������
		std::vector<Vec3d> m_normals;	// ������


		size_t m_nLine;
		FileType m_fileType;					// �ļ�����
		ErrorCode m_errorCode;					// ������

		bool m_bError;


	}; // class StlParser

} // namespace CAX

