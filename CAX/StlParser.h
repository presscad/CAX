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


		// 构造函数 和 析构函数
		StlParser();
		~StlParser();

		// 解析文件
		bool parse(const char* filepath);


		// 获取解析得到的数据
		std::vector<Triangle>& triangles(void);
		std::vector<Vec3d>& normals(void);

	private:
		// trimLeft
		char* trimLeft(char* str);


		// 解析得到的数据
		char m_modelName[128];					// 模型的名称
		std::vector<Triangle> m_triangles;		// 三角形
		std::vector<Vec3d> m_normals;	// 法向量


		size_t m_nLine;
		FileType m_fileType;					// 文件类型
		ErrorCode m_errorCode;					// 错误码

		bool m_bError;


	}; // class StlParser

} // namespace CAX

