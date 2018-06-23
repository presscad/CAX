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
		/* ������ */
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

		// ��ȡ����
		bool& polylneToLines(void);
		bool& lwPolylineToLineArcs(void);

		// ���ò���
		bool polylineToLines(const bool bPolylineToLines);
		bool lwPolylineToLineArcs(const bool bLwPolylineToLineArcs);

		// ��ȡʵ��
		std::list<Entity2d*>& entities(void);

		// �����ļ�
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

		/* dxfʵ������ */
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
		// section�εĴ������
		void handleSectionNone(FILE* pFile);
		void handleSectionHeader(FILE* pFile);
		void handleSectionClasses(FILE* pFile);
		void handleSectionTables(FILE* pFile);
		void handleSectionBlocks(FILE* pFile);
		void handleSectionEntities(FILE* pFile);
		void handleSectionObjects(FILE* pFile);
		// Entity�εĴ������
		void handleEntityNone(FILE* pFile);
		void handleEntityPoint(FILE* pFile);
		void handleEntityLine(FILE* pFile);
		void handleEntityPolyline(FILE* pFile);
		void handleEntityLwPolyline(FILE* pFile);
		void handleEntityArc(FILE* pFile);
		void handleEntityCircle(FILE* pFile);
		void handleEntityEllipse(FILE* pFile);
		void handleEntitySpline(FILE* pFile);


		// ��͹��ͼԪת����ֱ�߻�Բ��
		Entity2d* bulgeToLineOrArc(const Vec2d& start, const Vec2d& end, const double bulge);

		// ����m_groupValue�޸�m_entity
		bool nextEntity(void);

		// trim a line
		char* trimGroupCode(char* groupCodeLine);
		char* trimGroupValue(char* groupValueLine);

		// ���ַ�����ת����int����
		int strToInt(char* s);
		// ���ַ�����ת����double����
		double strToDouble(char* s);

		void onParseError(void);




		// ��������
		bool m_bPolylineToLines;			// �Ƿ�Polylineת��Line
		bool m_bLwPolylineToLineArcs;		// �Ƿ�lwpolylineת��Line��Arc

		// �������Ķ�άͼ�μ��� 
		std::list<Entity2d*> m_entities;
		

		// {{ ����������Ҫ�ı��� }}
		// ������
		ErrorCode m_errorCode;
		// ��ȡ������Ϣ״̬
		SectionType m_section;
		EntityType m_entity;
		// ������ �� ��ֵ��
		char m_codeLine[LINE_BUFFER_SIZE];
		char m_valueLine[LINE_BUFFER_SIZE];
		// ���� �� ��ֵ
		int m_groupCode;
		char* m_groupValue;
		// �к� �� scanf���
		int m_nLine;
		int m_scanfRet;
		// ������־ �� �����־
		bool m_bEnd;
		bool m_bError;

		//bool DxfParser::(*sectionHandler[NUM_OF_SECTION])(void);
	};

}


#endif