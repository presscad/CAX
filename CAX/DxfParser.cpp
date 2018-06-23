#include "DxfParser.h"


#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>


#include "MathTools.h"
#include "Point2d.h"
#include "Line2d.h"
#include "Polyline2d.h"
#include "LwPolyline2d.h"
#include "Arc2d.h"
#include "Circle2d.h"
#include "Ellipse2d.h"


namespace CAX
{

	DxfParser::DxfParser():
		m_bPolylineToLines(false),
		m_bLwPolylineToLineArcs(false)
	{

	}


	DxfParser::~DxfParser()
	{

	}


	bool& DxfParser::polylneToLines(void)
	{
		return m_bPolylineToLines;
	}

	bool& DxfParser::lwPolylineToLineArcs(void)
	{
		return m_bLwPolylineToLineArcs;
	}

	// 设置参数
	bool DxfParser::polylineToLines(const bool bPolylineToLines)
	{
		m_bPolylineToLines = bPolylineToLines;
		return m_bPolylineToLines;
	}

	bool DxfParser::lwPolylineToLineArcs(const bool bLwPolylineToLineArcs)
	{
		m_bLwPolylineToLineArcs = bLwPolylineToLineArcs;
		return m_bLwPolylineToLineArcs;
	}



	std::list<Entity2d*>& DxfParser::entities(void)
	{
		return m_entities;
	}


	char* DxfParser::trimGroupCode(char* groupCodeLine)
	{
		using namespace std;

		int lastChar = std::strlen(groupCodeLine) - 1;

		while ((lastChar >= 0) &&
			((groupCodeLine[lastChar] == 10)
				|| (groupCodeLine[lastChar] == 13)
				|| (groupCodeLine[lastChar] == ' ')
				|| (groupCodeLine[lastChar] == '\t')))
		{
			groupCodeLine[lastChar] = '\0';
			lastChar--;
		}

		char* s = groupCodeLine;
		while ((s[0] == ' ') || (s[0] == '\t')) {
			++s;
		}

		return ((s[0]) ? s : NULL);
	}

	char* DxfParser::trimGroupValue(char* groupValueLine)
	{
		using namespace std;

		int lastChar = strlen(groupValueLine) - 1;
		while ((lastChar >= 0) &&
			((groupValueLine[lastChar] == 10)
				|| (groupValueLine[lastChar] == 13)))
		{
			groupValueLine[lastChar] = '\0';
			lastChar--;
		}

		return groupValueLine;
	}


	int DxfParser::strToInt(char* s)
	{
		using namespace std;

		//char* end;
		//int value = std::strtol(s, &end, 10);
		//if (end == s || *end != '\0' || errno == ERANGE) {
		//	return -1;
		//}
		//return value;

		return atoi(s);
	}

	double DxfParser::strToDouble(char* s)
	{
		using namespace std;

		return atof(s);
	}

	void DxfParser::onParseError(void)
	{
	
	}

	bool DxfParser::nextEntity(void)
	{
		using namespace std;
		if(strcmp(m_groupValue, "ENDSEC") == 0)
		{
			m_entity = ENTITY_NONE;
			m_section = SECTION_NONE;
			return true;
		}
		else if(strcmp(m_groupValue, "POINT") == 0)
		{
			m_entity = ENTITY_POINT;
			return true;
		}
		else if(strcmp(m_groupValue, "LINE") == 0)
		{
			m_entity = ENTITY_LINE;
			return true;
		}
		else if (strcmp(m_groupValue, "POLYLINE") == 0)
		{
			m_entity = ENTITY_POLYLINE;
			return true;
		}
		else if (strcmp(m_groupValue, "LWPOLYLINE") == 0)
		{
			m_entity = ENTITY_LWPOLYLINE;
			return true;
		}
		else if (strcmp(m_groupValue, "ARC") == 0)
		{
			m_entity = ENTITY_ARC;
			return true;
		}
		else if (strcmp(m_groupValue, "CIRCLE") == 0)
		{
			m_entity = ENTITY_CIRCLE;
			return true;
		}
		else if (strcmp(m_groupValue, "ELLIPSE") == 0)
		{
			m_entity = ENTITY_ELLIPSE;
			return true;
		}
		else if (strcmp(m_groupValue, "SPLINE") == 0)
		{
			m_entity = ENTITY_SPLINE;
			return true;
		}

		return false;
	}


	bool DxfParser::parse(const char *filepath)
	{
		using namespace std;

		FILE* pFile = fopen(filepath, "rt");
		if(!pFile)
		{
			// 文件无法打开
			m_errorCode = ERROR_OPEN_FILE;
			return false;
		}

		m_entities.resize(0);
		m_section = SECTION_NONE;
		m_entity = ENTITY_NONE;
		m_nLine = 0;


		m_bEnd = false;
		m_bError = false;


		while (!m_bEnd && !m_bError)
		{
			switch(m_section)
			{
			case SECTION_NONE:
				handleSectionNone(pFile);
				break;
			case SECTION_HEADER:
				handleSectionHeader(pFile);
				break;
			case SECTION_CLASSES:
				handleSectionClasses(pFile);
				break;
			case SECTION_TABLES:
				handleSectionTables(pFile);
				break;
			case SECTION_BLOCKS:
				handleSectionBlocks(pFile);
				break;
			case SECTION_ENTITIES:
				handleSectionEntities(pFile);
				break;
			case SECTION_OBJECTS:
				handleSectionObjects(pFile);
				break;
			}
		}

		fclose(pFile);

		if(m_bError)
		{
			std::list<Entity2d*>::iterator iter;
			for(iter=m_entities.begin(); iter!=m_entities.end(); ++iter)
			{
				Entity2d::deleteInstance(*iter);
			}
			return false;
		}

		return true;
	}

	bool DxfParser::getCodeAndValue(FILE* pFile)
	{
		fgets(m_codeLine, LINE_BUFFER_SIZE, pFile);
		m_nLine++;
		char* groupCodeTrim = trimGroupCode(m_codeLine);
		if (!groupCodeTrim)
		{
			m_bError = true;
			m_errorCode = ERROR_GROUP_CODE;
			return false;
		}
		m_groupCode = strToInt(groupCodeTrim);
		if (m_groupCode < 0) {
			m_bError = true;
			m_errorCode = ERROR_GROUP_CODE;
			return false;
		}
		fgets(m_valueLine, LINE_BUFFER_SIZE, pFile);
		m_nLine++;
		m_groupValue = trimGroupValue(m_valueLine);

		return true;
	}


	void DxfParser::handleSectionNone(FILE* pFile)
	{
		using namespace std;

		while(!feof(pFile))
		{
			if(!getCodeAndValue(pFile))
			{
				return;
			}

			switch(m_groupCode)
			{
			case 0:
				if (strcmp(m_groupValue, "EOF") == 0) {
					m_bEnd = true;
					return;
				}
				break;
			case 2:
				if (strcmp(m_groupValue, "HEADER") == 0)
				{
					m_section = SECTION_HEADER;
				}
				else if (strcmp(m_groupValue, "CLASSES") == 0)
				{
					m_section = SECTION_CLASSES;
				}
				else if (strcmp(m_groupValue, "TABLES") == 0)
				{
					m_section = SECTION_TABLES;
				}
				else if (strcmp(m_groupValue, "BLOCKS") == 0)
				{
					m_section = SECTION_BLOCKS;
				}
				else if (strcmp(m_groupValue, "ENTITIES") == 0)
				{
					m_section = SECTION_ENTITIES;
				}
				else if (strcmp(m_groupValue, "OBJECTS") == 0)
				{
					m_section = SECTION_OBJECTS;
				}
				else
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_SECTION;
					return;
				}
				return;
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleSectionHeader(FILE* pFile)
	{
		using namespace std;

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}
			if (m_groupCode == 0 && strcmp(m_groupValue, "ENDSEC") == 0)
			{
				m_section = SECTION_NONE;
				return;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleSectionClasses(FILE* pFile)
	{
		using namespace std;

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}
			if (m_groupCode == 0 && strcmp(m_groupValue, "ENDSEC") == 0)
			{
				m_section = SECTION_NONE;
				return;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleSectionTables(FILE* pFile)
	{
		using namespace std;

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}
			if (m_groupCode == 0 && strcmp(m_groupValue, "ENDSEC") == 0)
			{
				m_section = SECTION_NONE;
				return;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleSectionBlocks(FILE* pFile)
	{
		using namespace std;

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}
			if (m_groupCode == 0 && strcmp(m_groupValue, "ENDSEC") == 0)
			{
				m_section = SECTION_NONE;
				return;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleSectionEntities(FILE* pFile)
	{
		switch(m_entity)
		{
		case ENTITY_NONE:
			handleEntityNone(pFile);
			break;
		case ENTITY_POINT:
			handleEntityPoint(pFile);
			break;
		case ENTITY_LINE:
			handleEntityLine(pFile);
			break;
		case ENTITY_POLYLINE:
			handleEntityPolyline(pFile);
			break;
		case ENTITY_LWPOLYLINE:
			handleEntityLwPolyline(pFile);
			break;
		case ENTITY_ARC:
			handleEntityArc(pFile);
			break;
		case ENTITY_CIRCLE:
			handleEntityCircle(pFile);
			break;
		case ENTITY_ELLIPSE:
			handleEntityEllipse(pFile);
			break;
		case ENTITY_SPLINE:
			handleEntitySpline(pFile);
			break;
		}
	}

	void DxfParser::handleSectionObjects(FILE* pFile)
	{
		using namespace std;

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}
			if (m_groupCode == 0 && strcmp(m_groupValue, "ENDSEC") == 0)
			{
				m_section = SECTION_NONE;
				return;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}


	void DxfParser::handleEntityNone(FILE* pFile)
	{
		using namespace std;

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}
			if (m_groupCode == 0)
			{
				if(!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleEntityPoint(FILE* pFile)
	{
		using namespace std;

		Point2d *pPoint = Entity2d::newPoint();
		m_entities.push_back(pPoint);

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}

			switch(m_groupCode)
			{
			case 0: // 下一个实体
				if(!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
				break;
			case 10: // 点X坐标
				pPoint->location().x = strToDouble(m_groupValue);
				break;
			case 20: // 点Y坐标
				pPoint->location().y = strToDouble(m_groupValue);
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleEntityLine(FILE* pFile)
	{
		using namespace std;

		Line2d *pLine = Entity2d::newLine();
		m_entities.push_back(pLine);

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}
			switch (m_groupCode)
			{
			case 0: // 下一个实体
				if (!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
				break;
			case 10: // 起点X坐标
				pLine->start().x = strToDouble(m_groupValue);
				break;
			case 20: // 起点Y坐标
				pLine->start().y = strToDouble(m_groupValue);
				break;
			case 11: // 终点X坐标
				pLine->end().x = strToDouble(m_groupValue);
				break;
			case 21: // 终点Y坐标
				pLine->end().y = strToDouble(m_groupValue);
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleEntityPolyline(FILE* pFile)
	{
		using namespace std;

		Polyline2d *pPolyline = Entity2d::newPolyline();
		m_entities.push_back(pPolyline);

		Vec2d vertex;
		int flag = 0;

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}
			switch (m_groupCode)
			{
			case 0: // 下一个实体

				//错误判断
				if(pPolyline->vertices().empty())
				{
					m_bError = true;
					m_errorCode = ERROR_POLYLINE_NO_VERTICES;
					return;
				}
				if(pPolyline->vertices().size() < 2)
				{
					m_bError = true;
					m_errorCode = ERROR_POLYLINE_NOT_ENOUGHT_VERTICES;
					return;
				}

				if(flag == 1 && !pPolyline->vertices().empty())
				{
					pPolyline->vertices().push_back(pPolyline->vertices().front());
				}

				// 将PoLyline转成直线段
				if(m_bPolylineToLines)
				{
					m_entities.pop_back();

					list<Vec2d>::iterator iter = pPolyline->vertices().begin();
					list<Vec2d>::iterator iterEnd = pPolyline->vertices().end();
					list<Vec2d>::iterator iterPre;
					while((iterPre = iter++) != iterEnd)
					{
						Line2d* pLine = Entity2d::newLine();
						pLine->start() = *iterPre;
						pLine->end() = *iter;
						m_entities.push_back(pLine);
					}
					Entity2d::deleteInstance(pPolyline);
				}

				if (!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
				break;
			case 10: // 顶点X坐标
				vertex.x = strToDouble(m_groupValue);
				break;
			case 20: // 顶点Y坐标
				vertex.y = strToDouble(m_groupValue);
				pPolyline->vertices().push_back(vertex);
				break;
			case 70: // 多段线标识（是否封闭）
				flag = strToInt(m_groupValue);
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleEntityLwPolyline(FILE* pFile)
	{
		using namespace std;

		LwPolyline2d *pLwPolyline = Entity2d::newLwPolyline();
		m_entities.push_back(pLwPolyline);

		Vec2d vertex;
		double bulge;
		size_t bulgeCount;
		vector<Vec2d> vertices;
		vector<double> bulges;
		size_t nVertices;
		int flag;

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}

			switch (m_groupCode)
			{
			case 0: // 下一个实体
				// 错误判断
				if(vertices.size() < 2)
				{
					m_bError = true;
					m_errorCode = ERROR_LWPOLYLINE_NO_VERTICES;
					return;
				}

				if(vertices.size() != nVertices)
				{
					m_bError = true;
					m_errorCode = ERROR_LWPOLYLINE_NOT_ENOUGH_VERTICES;
					return;
				}


				for(size_t i=bulges.size(); i<nVertices; ++i)
				{
					bulges.push_back(0.0);
				}	


				// 转换成直线或圆弧
				for(size_t i=1; i<vertices.size(); ++i)
				{
					Entity2d* pEntity = bulgeToLineOrArc(vertices[i-1], vertices[i], bulges[i-1]);
					pLwPolyline->segments().push_back(pEntity);
				}

				if(flag == 1)
				{
					//封闭
					Entity2d* pEntity = bulgeToLineOrArc(vertices.back(), vertices.front(), bulges.back());
					pLwPolyline->segments().push_back(pEntity);
				}

				// 将LwPolyline转换成直线和圆弧
				if (m_bLwPolylineToLineArcs)
				{
					m_entities.pop_back();

					m_entities.insert(m_entities.end(),
						pLwPolyline->segments().begin(), pLwPolyline->segments().end());

					pLwPolyline->segments().clear();
					Entity2d::deleteInstance(pLwPolyline);
				}

				if (!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
				break;
			case 10: // 顶点X坐标
				vertex.x = strToDouble(m_groupValue);
				break;
			case 20: // 顶点Y坐标
				vertex.y = strToDouble(m_groupValue);
				vertices.push_back(vertex);
				break;
			case 42: // 凸度
				bulgeCount = vertices.size() - 1;
				bulge = strToDouble(m_groupValue);
				for(size_t i=bulges.size(); i<bulgeCount; i++)
				{
					bulges.push_back(0.0);
				}
				bulge = strToDouble(m_groupValue);
				bulges.push_back(bulge);
				break;
			case 70: // 标识（是否封闭）
				flag = strToInt(m_groupValue);
				break;
			case 90: // 顶点数
				nVertices = strToInt(m_groupValue);
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleEntityArc(FILE* pFile)
	{
		using namespace std;

		Arc2d *pArc = Entity2d::newArc();
		m_entities.push_back(pArc);

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}

			switch (m_groupCode)
			{
			case 0: // 下一个实体
				if (!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
				break;
			case 10: // 圆心X坐标
				pArc->center().x = strToDouble(m_groupValue);
				break;
			case 20: // 圆心Y坐标
				pArc->center().y = strToDouble(m_groupValue);
				break;
			case 40: // 半径
				pArc->radius() = strToDouble(m_groupValue);
				break;
			case 50: // 起点弧度
				pArc->startRadian() = strToDouble(m_groupValue);
				break;
			case 51: // 终点弧度
				pArc->endRadian() = strToDouble(m_groupValue);
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleEntityCircle(FILE* pFile)
	{
		using namespace std;

		Circle2d *pCircle = Entity2d::newCircle();
		m_entities.push_back(pCircle);

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}

			switch (m_groupCode)
			{
			case 0: // 下一个实体
				if (!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
				break;
			case 10: // 圆心X坐标
				pCircle->center().x = strToDouble(m_groupValue);
				break;
			case 20: // 圆心Y坐标
				pCircle->center().y = strToDouble(m_groupValue);
				break;
			case 40: // 半径
				pCircle->radius() = strToDouble(m_groupValue);
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleEntityEllipse(FILE* pFile)
	{
		using namespace std;

		Ellipse2d *pEllipse = Entity2d::newEllipse();
		m_entities.push_back(pEllipse);

		Vec2d majorAxis;
		double ratio = 0.0;
		double startRadian;
		double endRadian;

		while(!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}

			switch (m_groupCode)
			{
			case 0: // 下一个实体

				pEllipse->major() = majorAxis.length();
				pEllipse->minor() = ratio * pEllipse->major();
				pEllipse->rotateRadian() = majorAxis.xRadian();
				pEllipse->startRadian() = startRadian - pEllipse->rotateRadian();
				pEllipse->endRadian() = endRadian - pEllipse->rotateRadian();

				pEllipse->startRadian() = cycleClamp(pEllipse->startRadian(), 0.0, Constants<double>::PIx2);
				pEllipse->endRadian() = cycleClamp(pEllipse->endRadian(), 0.0, Constants<double>::PIx2);

				if (!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
				break;
			case 10: // 椭圆心X坐标
				pEllipse->center().x = strToDouble(m_groupValue);
				break;
			case 20: // 椭圆心Y坐标
				pEllipse->center().y = strToDouble(m_groupValue);
				break;
			case 11: // 主轴向量X坐标
				majorAxis.x = strToDouble(m_groupValue);
				break;
			case 21: // 主轴向量Y坐标
				majorAxis.y = strToDouble(m_groupValue);
				break;
			case 40: // 短轴和主轴的长度比
				ratio = strToDouble(m_groupValue);
				break;
			case 41: // 开始弧度
				startRadian = strToDouble(m_groupValue);
				break;
			case 42: // 终点弧度
				endRadian = strToDouble(m_groupValue);
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}

	void DxfParser::handleEntitySpline(FILE* pFile)
	{
		using namespace std;

		//Circle2d *pCircle = Entity2d::newCircle();
		//m_entities.push_back(pCircle);

		while (!feof(pFile))
		{
			if (!getCodeAndValue(pFile))
			{
				return;
			}

			switch (m_groupCode)
			{
			case 0: // 下一个实体
				if (!nextEntity())
				{
					m_bError = true;
					m_errorCode = ERROR_UNKNOWN_ENTITY;
					return;
				}
				return;
				break;
			case 10: // 控制点X坐标
				break;
			case 20: // 控制点Y坐标
				break;
			case 11: // 拟合点X坐标
				break;
			case 21: // 拟合点Y坐标
				break;
			case 12: // 起点切线X分量
				break;
			case 22: // 起点切线Y分量
				break;
			case 13: // 终点切线X分量
				break;
			case 23: // 终点切线Y分量
				break;
			case 40: // 节点值
				break;
			case 41: // 权重
				break;
			case 70: // 标识
				break;
			case 71: // degree曲线次数
				break;
			case 72: // 节点向量个数
				break;
			case 73: // 控制点个数
				break;
			case 74: // 拟合点合数
				break;
			default:
				break;
			}
		}

		m_bError = true;
		m_errorCode = ERROR_END_OF_FILE;
		return;
	}



	Entity2d* DxfParser::bulgeToLineOrArc(const Vec2d& start, const Vec2d& end, const double bulge)
	{
		if(equals(bulge, 0.0))
		{
			Line2d* pLine = Entity2d::newLine();
			pLine->start() = start;
			pLine->end() = end;
			return pLine;
		}
		else
		{
			Arc2d* pArc = Entity2d::newArc();
			pArc->fromBulge(start, end, bulge);
			return pArc;
		}
	}

}