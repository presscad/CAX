#include "StlParser.h"


#include <cstring>


namespace CAX
{

	StlParser::StlParser():
		m_nLine(0),
		m_fileType(ASCII),
		m_errorCode(SUCCESS),
		m_bError(false)
	{
	}


	StlParser::~StlParser()
	{
	}

	char* StlParser::trimLeft(char* str)
	{
		char* s = str;
		while((*s == ' ') || (*s == '\t'))
		{
			s++;
		}
		return s;
	}

	std::vector<Triangle>& StlParser::triangles(void)
	{
		return m_triangles;
	}

	std::vector<Vec3d>& StlParser::normals(void)
	{
		return m_normals;
	}




	bool StlParser::parse(const char* filepath)
	{
		using namespace std;

		m_modelName[0] = '\0';
		m_triangles.clear();
		m_bError = false;

		const char* pExtName = strrchr(filepath, '.');
		if(!pExtName || strcmp(pExtName, ".stl") != 0)
		{
			m_bError = true;
			m_errorCode = ERROR_IMPROPER_EXTNAME;
			return false;
		}

		FILE* pFile = fopen(filepath, "rb");
		if(!pFile)
		{
			m_bError = true;
			m_errorCode = ERROR_OPEN_FILE;
			return false;
		}

		char modelName[80];
		modelName[78] = 'a';
		modelName[79] = 'a';
		int nRead = fread(modelName, sizeof(char), 80, pFile);

		bool is0 = modelName[78] == '\0' && modelName[79] == '\0';
		bool is32 = modelName[78] == ' ' && modelName[79] == ' ';
		if(nRead == 80 && (is0 || is32))
		{
			m_fileType = BINARY;
		}
		else
		{
			m_fileType = ASCII;
		}

		rewind(pFile);

		if(m_fileType == ASCII)
		{
			pFile = freopen(filepath, "r", pFile);
		}

		Triangle triangle;

		switch(m_fileType)
		{
		case ASCII:
			{
				m_nLine = 0;
				const int LINE_BUFFER_SIZE = 256;
				char lineBuff[LINE_BUFFER_SIZE];
				char* pLineTrim;

				bool bFacet = false;
				bool bOuterLoop = false;
				size_t scanfRet;
				Vec3d normal;
				Triangle triangle;
				size_t nVertex = 0;

				while (!feof(pFile))
				{
					fgets(lineBuff, LINE_BUFFER_SIZE, pFile);
					++m_nLine;
					pLineTrim = trimLeft(lineBuff);

					if (strncmp(pLineTrim, "solid", 5) == 0)
					{
						sscanf(pLineTrim + 6, "%s", m_modelName);
						//strcpy(m_modelName, pLineTrim + 6);
					}
					else if(strncmp(pLineTrim, "facet", 5) == 0)
					{
						bFacet = true;
						
						scanfRet = sscanf(pLineTrim, "facet normal %lf %lf %lf", 
							&(normal.x), &(normal.y), &(normal.z));
						if(scanfRet < 3)
						{
							m_bError = true;
							m_errorCode = ERROR_PARSE_NORMAL;
							break;
						}
					}
					else if(strncmp(pLineTrim, "outer", 5) == 0)
					{
						bOuterLoop = true;
					}
					else if (strncmp(pLineTrim, "vertex", 6) == 0)
					{
						if(nVertex >= 3)
						{
							m_bError = true;
							m_errorCode = ERROR_VERTEX_COUNT;
							break;
						}
						scanfRet = sscanf(pLineTrim, "vertex %lf %lf %lf",
							&(triangle.vertices()[nVertex].x), &(triangle.vertices()[nVertex].y), &(triangle.vertices()[nVertex].z));
						if (scanfRet < 3)
						{
							m_bError = true;
							m_errorCode = ERROR_PARSE_VERTEX;
							break;
						}
						++nVertex;
					}
					else if (strncmp(pLineTrim, "endloop", 7) == 0)
					{
						bOuterLoop = false;
					}
					else if (strncmp(pLineTrim, "endfacet", 8) == 0)
					{
						bFacet = false;
						nVertex = 0;

						m_triangles.push_back(triangle);
						m_normals.push_back(normal);
						
					}
					else if (strncmp(pLineTrim, "endsolid", 8) == 0)
					{
						break;
					}
				}

				if(m_triangles.empty())
				{
					m_bError = true;
					m_errorCode = ERROR_NO_DATA;
					break;
				}

			}
			break;
		case BINARY:
			{
				char buff[128];
				int nRead;

				// 实体名称
				nRead = fread(buff, sizeof(char), 80, pFile);
				if(nRead < 80)
				{
					m_bError = true;
					m_errorCode = ERROR_PARSE_SOLID_NAME;
					break;
				}
				buff[80] = '\0';
				strcpy(m_modelName, buff);

				// 三角片个数
				nRead = fread(buff, sizeof(char), 4, pFile);
				if(nRead < 4)
				{
					m_bError = true;
					m_errorCode = ERROR_PARSE_TRIANGLE_COUNT;
					break;
				}
				buff[4] = '\t';
				unsigned int count;
				memcpy(&count, buff, 4);
				if(count <= 0)
				{
					m_bError = true;
					m_errorCode = ERROR_TRIANGLE_COUNT;
					break;
				}

				Vec3d normal;
				Triangle triangle;
				Vec3f fNormal;
				Vec3f fVertex;

				for(size_t i=0; i<count; ++i)
				{
					nRead = fread(buff, sizeof(char), 50, pFile);
					if(nRead < 50)
					{
						m_bError = true;
						m_errorCode = ERROR_PARSE_VERTEX_AND_NORMAL;
						break;
					}

					memcpy(&fNormal.x, buff, 12);
					normal.x = fNormal.x;
					normal.y = fNormal.y;
					normal.z = fNormal.z;

					memcpy(&fVertex.x, buff + 12, 12);
					triangle.vertices()[0].x = fVertex.x;
					triangle.vertices()[0].y = fVertex.y;
					triangle.vertices()[0].z = fVertex.z;

					memcpy(&fVertex.x, buff + 24, 12);
					triangle.vertices()[1].x = fVertex.x;
					triangle.vertices()[1].y = fVertex.y;
					triangle.vertices()[1].z = fVertex.z;

					memcpy(&fVertex.x, buff + 36, 12);
					triangle.vertices()[2].x = fVertex.x;
					triangle.vertices()[2].y = fVertex.y;
					triangle.vertices()[2].z = fVertex.z;

					m_triangles.push_back(triangle);
					m_normals.push_back(normal);

				}
			}
			break;
		}
		
		if(pFile)
		{
			fclose(pFile);
		}

		if(m_bError)
		{
			m_triangles.clear();
			m_normals.clear();
			return false;
		}


		return true;
	}

} // namespace CAX