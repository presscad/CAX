#pragma once


#ifndef _OBJPARSER_H_
#define _OBJPARSER_H_


#include <vector>

#include "Triangle.h"


namespace CAX
{

	class ObjParser
	{
	public:
		enum ErrorCode
		{
			SUCCESS,

			ERROR_IMPROPER_EXTNAME,

			ERROR_NEWMTL_NO_NAME,
			ERROR_KD_NOT_ENOUGH_COLOR,

			ERROR_OPEN_FILE,

			ERROR_PARSE_V_DATA,
			ERROR_PARSE_VN_DATA,
			ERROR_PARSE_VT_DATA,
			ERROR_PARSE_USEMTL_DATA,
			ERROR_PARSE_F_DATA,
			ERROR_COLOR_DATA,

			ERROR_EMPTY_VERTICES,
			ERROR_EMPTY_NORMALS,
			ERROR_EMPTY_TEXCOORDS,
			ERROR_EMPTY_INDICES,

			ERROR_INDEX_OUT_OF_RANGE
		};

		// {{ ���캯�� �� �������� }}
		ObjParser();
		~ObjParser();

		// �����ļ�
		bool parse(const char* filepath);

		// {{ ��ȡ���� }}
		std::vector<Vec3d>& vertices(void);
		std::vector<Vec3d>& normals(void);
		std::vector<Vec3u>& vertexIndices(void);
		std::vector<Vec3u>& normalIndices(void);
		std::vector<Vec3f>& colors(void);

	private:
		// {{ �������� }}
		void replaceAll(char* str, char oldChar, char newChar);
		char* trimLeft(char* str);




		// {{ �����õ������� }}
		// �����ζ�������
		std::vector<Vec3d> m_vertices;
		// ����������
		std::vector<Vec3d> m_normals;
		// ������������
		std::vector<Vec3d> m_texCoords;
		// ��������
		std::vector<Vec3u> m_vertexIndices;
		// ����������
		std::vector<Vec3u> m_normalIndices;
		// ������������
		std::vector<Vec3u> m_texCoordIndices;
		// ��ɫ����
		std::vector<Vec3f> m_colors;
		

		// ����
		bool m_bParseTexture;

		// �������̱���
		bool m_hasMtlFile;
		bool m_bError;
		ErrorCode m_errorCode;
		

	}; // class ObjParser

} // namespace CAX


#endif