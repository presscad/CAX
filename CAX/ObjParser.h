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

		// {{ 构造函数 和 析构函数 }}
		ObjParser();
		~ObjParser();

		// 解析文件
		bool parse(const char* filepath);

		// {{ 获取数据 }}
		std::vector<Vec3d>& vertices(void);
		std::vector<Vec3d>& normals(void);
		std::vector<Vec3u>& vertexIndices(void);
		std::vector<Vec3u>& normalIndices(void);
		std::vector<Vec3f>& colors(void);

	private:
		// {{ 辅助函数 }}
		void replaceAll(char* str, char oldChar, char newChar);
		char* trimLeft(char* str);




		// {{ 解析得到的数据 }}
		// 三角形顶点数据
		std::vector<Vec3d> m_vertices;
		// 法向量数据
		std::vector<Vec3d> m_normals;
		// 纹理坐标数据
		std::vector<Vec3d> m_texCoords;
		// 顶点索引
		std::vector<Vec3u> m_vertexIndices;
		// 法向量索引
		std::vector<Vec3u> m_normalIndices;
		// 纹理坐标索引
		std::vector<Vec3u> m_texCoordIndices;
		// 颜色数据
		std::vector<Vec3f> m_colors;
		

		// 参数
		bool m_bParseTexture;

		// 解析过程变量
		bool m_hasMtlFile;
		bool m_bError;
		ErrorCode m_errorCode;
		

	}; // class ObjParser

} // namespace CAX


#endif