#pragma once


#ifndef _DXFPARSER_H_
#define _DXFPARSER_H_


#ifndef LINE_BUFFER_SIZE
#define LINE_BUFFER_SIZE 256
#endif


#include <list>
#include <cstdio>

#include "Entity2d.h"

namespace CAX
{

	class DxfParser
	{
	public:
		/* 错误码 */
		enum ErrorCode
		{
			SUCCESS,

			ERROR_OPEN_FILE,
			ERROR_GROUP_CODE,
			ERROR_GROUP_VALUE,

			ERROR_UNKNOWN_SECTION,
			ERROR_UNKNOWN_ENTITY,

			ERROR_END_OF_FILE,

			ERROR_POLYLINE_NO_VERTICES,
			ERROR_POLYLINE_NOT_ENOUGHT_VERTICES,

			ERROR_LWPOLYLINE_NO_VERTICES,
			ERROR_LWPOLYLINE_NOT_ENOUGH_VERTICES
		};


		DxfParser();
		~DxfParser();

		// 获取参数
		bool& polylneToLines(void);
		bool& lwPolylineToLineArcs(void);

		// 设置参数
		bool polylineToLines(const bool bPolylineToLines);
		bool lwPolylineToLineArcs(const bool bLwPolylineToLineArcs);

		// 获取实体
		std::list<Entity2d*>& entities(void);

		// 解析文件
		bool parse(const char *filepath);

	private:
		/* Section */
		enum SectionType
		{
			SECTION_NONE,
			SECTION_HEADER,
			SECTION_CLASSES,
			SECTION_TABLES,
			SECTION_BLOCKS,
			SECTION_ENTITIES,
			SECTION_OBJECTS,
			NUM_OF_SECTION
		};

		/* dxf实体类型 */
		enum EntityType
		{
			ENTITY_NONE,
			ENTITY_POINT,
			ENTITY_LINE,
			ENTITY_POLYLINE,
			ENTITY_LWPOLYLINE,
			ENTITY_ARC,
			ENTITY_CIRCLE,
			ENTITY_ELLIPSE,
			ENTITY_SPLINE,
			NUM_OF_ENTITY
		};

		bool getCodeAndValue(FILE* pFile);
		// section段的处理程序
		void handleSectionNone(FILE* pFile);
		void handleSectionHeader(FILE* pFile);
		void handleSectionClasses(FILE* pFile);
		void handleSectionTables(FILE* pFile);
		void handleSectionBlocks(FILE* pFile);
		void handleSectionEntities(FILE* pFile);
		void handleSectionObjects(FILE* pFile);
		// Entity段的处理程序
		void handleEntityNone(FILE* pFile);
		void handleEntityPoint(FILE* pFile);
		void handleEntityLine(FILE* pFile);
		void handleEntityPolyline(FILE* pFile);
		void handleEntityLwPolyline(FILE* pFile);
		void handleEntityArc(FILE* pFile);
		void handleEntityCircle(FILE* pFile);
		void handleEntityEllipse(FILE* pFile);
		void handleEntitySpline(FILE* pFile);


		// 将凸度图元转化成直线或圆弧
		Entity2d* bulgeToLineOrArc(const Vec2d& start, const Vec2d& end, const double bulge);

		// 根据m_groupValue修改m_entity
		bool nextEntity(void);

		// trim a line
		char* trimGroupCode(char* groupCodeLine);
		char* trimGroupValue(char* groupValueLine);

		// 将字符数组转换成int类型
		int strToInt(char* s);
		// 将字符数组转换成double类型
		double strToDouble(char* s);

		void onParseError(void);




		// 解析参数
		bool m_bPolylineToLines;			// 是否将Polyline转成Line
		bool m_bLwPolylineToLineArcs;		// 是否将lwpolyline转成Line和Arc

		// 解析到的二维图形集合 
		std::list<Entity2d*> m_entities;
		

		// {{ 解析过程需要的变量 }}
		// 错误码
		ErrorCode m_errorCode;
		// 读取到的信息状态
		SectionType m_section;
		EntityType m_entity;
		// 组码行 和 组值行
		char m_codeLine[LINE_BUFFER_SIZE];
		char m_valueLine[LINE_BUFFER_SIZE];
		// 组码 和 组值
		int m_groupCode;
		char* m_groupValue;
		// 行号 和 scanf结果
		int m_nLine;
		int m_scanfRet;
		// 结束标志 和 错误标志
		bool m_bEnd;
		bool m_bError;

		//bool DxfParser::(*sectionHandler[NUM_OF_SECTION])(void);
	};

}


#endif