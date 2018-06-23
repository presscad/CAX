#include "ObjParser.h"


#include <string>
#include <unordered_map>

namespace CAX
{

	ObjParser::ObjParser() :
		m_bParseTexture(false),
		m_hasMtlFile(false)
	{
	}


	ObjParser::~ObjParser()
	{
	}

	std::vector<Vec3d>& ObjParser::vertices(void)
	{
		return m_vertices;
	}

	std::vector<Vec3d>& ObjParser::normals(void)
	{
		return m_normals;
	}

	std::vector<Vec3u>& ObjParser::vertexIndices(void)
	{
		return m_vertexIndices;
	}

	std::vector<Vec3u>& ObjParser::normalIndices(void)
	{
		return m_normalIndices;
	}

	std::vector<Vec3f>& ObjParser::colors(void)
	{
		return m_colors;
	}


	void ObjParser::replaceAll(char* str, char oldChar, char newChar)
	{
		char* s = str;
		while(*s != '\0')
		{
			if(*s == oldChar)
			{
				*s = newChar;
			}
			++s;
		}
	}

	char* ObjParser::trimLeft(char* str)
	{
		char* s = str;
		while ((*s == ' ') || (*s == '\t'))
		{
			++s;
		}
		return s;
	}

	bool ObjParser::parse(const char* filepath)
	{
		using namespace std;

		m_vertices.clear();
		m_normals.clear();
		m_texCoords.clear();
		m_vertexIndices.clear();
		m_normalIndices.clear();
		m_texCoordIndices.clear();
		m_colors.clear();
		m_hasMtlFile = false;
		m_bError = false;

		char pFilePath[256];
		strcpy(pFilePath, filepath);
		replaceAll(pFilePath, '\\', '/');

		char* pExtName = strrchr(pFilePath, '.');
		if(strcmp(pExtName,".obj") != 0 && strcmp(pExtName,".OBJ") != 0)
		{
			m_bError = true;
			m_errorCode = ERROR_IMPROPER_EXTNAME;
			return false;
		}


		// 处理MTL文件 (纹理文件)
		strcpy(pExtName + 1, "mtl");
		FILE* pFile = fopen(pFilePath, "rt");
		const size_t LINE_BUFFER_SIZE = 256;
		char lineBuff[LINE_BUFFER_SIZE];
		char* pLineTrim;
		size_t scanfRet;

		unordered_map<string, Vec3f> colorMap;

		if(pFile)
		{
			m_hasMtlFile = true;
			char name[32];
			Vec3f color;

			while(!feof(pFile))
			{
				fgets(lineBuff, LINE_BUFFER_SIZE, pFile);
				pLineTrim = trimLeft(lineBuff);
				
				if(strncmp(pLineTrim, "newmtl", 6) == 0)
				{
					scanfRet = sscanf(pLineTrim, "newmtl %s", name);
					if(scanfRet < 1)
					{
						m_bError = true;
						m_errorCode = ERROR_NEWMTL_NO_NAME;
						break;
					}
				}
				else if(strncmp(pLineTrim, "Ns", 2) == 0)
				{
					
				}
				else if(strncmp(pLineTrim, "Ka", 2) == 0)
				{
				
				}
				else if(strncmp(pLineTrim, "Kd", 2) == 0)
				{
					scanfRet = sscanf(pLineTrim, "Kd %f %f %f", &color.x, &color.y, &color.z);
					if(scanfRet < 3)
					{
						m_bError = true;
						m_errorCode = ERROR_KD_NOT_ENOUGH_COLOR;
						break;
					}
					colorMap[name] = color;
				}
				else if(strncmp(pLineTrim, "Ks", 2) == 0)
				{
				
				}
				else if(strncmp(pLineTrim, "d", 1) == 0)
				{
				
				}
				else if(strncmp(pLineTrim, "illum", 5) == 0)
				{
				
				}
			}
		}

		if(pFile)
		{
			fclose(pFile);
		}
		

		if (m_bError)
		{
			return false;
		}


		// 处理obj文件
		pFile = fopen(filepath, "rt");
		if(!pFile)
		{
			m_bError = true;
			m_errorCode = ERROR_OPEN_FILE;
			return false;
		}


		Vec3d vertex;
		Vec3d normal;
		Vec3d texCoord;
		Vec3u vertexIndex;
		Vec3u normalIndex;
		Vec3u texCoordIndex;
		char mtlName[64];
		bool hasNormal = false;
		bool hasTexture = false;


		while(!feof(pFile))
		{
			fgets(lineBuff, LINE_BUFFER_SIZE, pFile);
			pLineTrim = trimLeft(lineBuff);

			if(strncmp(pLineTrim, "vn", 2) == 0)
			{
				// 法向量数据
				scanfRet = sscanf(pLineTrim, "vn %lf %lf %lf", &normal.x, &normal.y, &normal.z);
				if (scanfRet < 3)
				{
					m_bError = true;
					m_errorCode = ERROR_PARSE_VN_DATA;
					break;
				}
				m_normals.push_back(normal);
			}
			else if(strncmp(pLineTrim, "vt", 2) == 0)
			{
				hasTexture = true;
				// 纹理坐标数据
				if(m_bParseTexture)
				{
					scanfRet = sscanf(pLineTrim, "vt %lf %lf %lf", &texCoord.x, &texCoord.y, &texCoord.z);
					if (scanfRet < 3)
					{
						m_bError = true;
						m_errorCode = ERROR_PARSE_VT_DATA;
						break;
					}
					m_texCoords.push_back(texCoord);
				}
			}
			else if (strncmp(pLineTrim, "v", 1) == 0)
			{
				// 顶点数据
				scanfRet = sscanf(pLineTrim, "v %lf %lf %lf", &vertex.x, &vertex.y, &vertex.z);
				if (scanfRet < 3)
				{
					m_bError = true;
					m_errorCode = ERROR_PARSE_V_DATA;
					break;
				}
				m_vertices.push_back(vertex);
			}
			else if(strncmp(pLineTrim, "usemtl", 6) == 0)
			{
				// 纹理数据
				scanfRet = sscanf(pLineTrim, "usemtl %s", mtlName);
				if(scanfRet < 1)
				{
					m_bError = true;
					m_errorCode = ERROR_PARSE_USEMTL_DATA;
					break;
				}
			}
			else if(strncmp(pLineTrim, "f", 1) == 0)
			{
				// 面数据
				if(hasTexture)
				{	
					if(m_bParseTexture)
					{
						scanfRet = sscanf(pLineTrim, "f %u/%u/%u %u/%u/%u %u/%u/%u",
							&vertexIndex.x, &texCoordIndex.x, &normalIndex.x,
							&vertexIndex.y, &texCoordIndex.y, &normalIndex.y,
							&vertexIndex.z, &texCoordIndex.z, &normalIndex.z);
						if (scanfRet < 9)
						{
							m_bError = true;
							m_errorCode = ERROR_PARSE_F_DATA;
							break;
						}
						vertexIndex -= 1;
						normalIndex -= 1;
						texCoordIndex -= 1;
						m_vertexIndices.push_back(vertexIndex);
						m_normalIndices.push_back(normalIndex);
						m_texCoordIndices.push_back(texCoordIndex);
					}
					else
					{
						scanfRet = sscanf(pLineTrim, "f %u/%*u/%u %u/%*u/%u %u/%*u/%u",
							&vertexIndex.x, &normalIndex.x,
							&vertexIndex.y, &normalIndex.y,
							&vertexIndex.z, &normalIndex.z);
						if (scanfRet < 6)
						{
							m_bError = true;
							m_errorCode = ERROR_PARSE_F_DATA;
							break;
						}
						vertexIndex -= 1;
						normalIndex -= 1;
						m_vertexIndices.push_back(vertexIndex);
						m_normalIndices.push_back(normalIndex);
					}
				}
				else
				{
					scanfRet = sscanf(pLineTrim, "f %u//%u %u//%u %u//%u",
						&vertexIndex.x, &normalIndex.x,
						&vertexIndex.y, &normalIndex.y,
						&vertexIndex.z, &normalIndex.z);
					if (scanfRet < 6)
					{
						m_bError = true;
						m_errorCode = ERROR_PARSE_F_DATA;
						break;
					}
					vertexIndex -= 1;
					normalIndex -= 1;
					m_vertexIndices.push_back(vertexIndex);
					m_normalIndices.push_back(normalIndex);
				}

				if(!colorMap.empty())
				{
					unordered_map<string, Vec3f>::iterator iter
						= colorMap.find(mtlName);
					if(iter != colorMap.end())
					{
						m_colors.push_back(iter->second);
					}
					else
					{
						m_bError = true;
						m_errorCode = ERROR_COLOR_DATA;
						break;
					}
				}

			}

		}

		fclose(pFile);

		if(m_bError)
		{
			m_vertices.clear();
			m_normals.clear();
			m_texCoords.clear();
			m_vertexIndices.clear();
			m_normalIndices.clear();
			m_texCoordIndices.clear();
			m_colors.clear();
			return false;
		}

		if(m_vertices.empty())
		{
			m_bError = true;
			m_errorCode = ERROR_EMPTY_VERTICES;
		}
		else if(m_normals.empty())
		{
			m_bError = true;
			m_errorCode = ERROR_EMPTY_NORMALS;
		}
		else if(m_bParseTexture && hasTexture && m_texCoords.empty())
		{
			m_bError = true;
			m_errorCode = ERROR_EMPTY_TEXCOORDS;
		}
		else if(m_vertexIndices.empty())
		{
			m_bError = true;
			m_errorCode = ERROR_EMPTY_INDICES;
		}
		else
		{
			size_t vertexMax = m_vertices.size();
			size_t normalMax = m_normals.size();
			size_t texCoordMax = m_texCoords.size();
			for (size_t i = 0; i<m_vertexIndices.size(); ++i)
			{
				if (m_vertexIndices[i].x >= vertexMax
					|| m_vertexIndices[i].y >= vertexMax
					|| m_vertexIndices[i].z >= vertexMax
					|| m_normalIndices[i].x >= normalMax
					|| m_normalIndices[i].y >= normalMax
					|| m_normalIndices[i].z >= normalMax)
				{
					m_bError = true;
					m_errorCode = ERROR_INDEX_OUT_OF_RANGE;
					break;
				}
				if(m_bParseTexture && hasTexture)
				{
					if(m_texCoordIndices[i].x >= texCoordMax
						|| m_texCoordIndices[i].y >= texCoordMax
						|| m_texCoordIndices[i].z >= texCoordMax)
					{
						m_bError = true;
						m_errorCode = ERROR_INDEX_OUT_OF_RANGE;
						break;
					}
				}
			}
		}
		
		if (m_bError)
		{
			m_vertices.clear();
			m_normals.clear();
			m_texCoords.clear();
			m_vertexIndices.clear();
			m_normalIndices.clear();
			m_texCoordIndices.clear();
			m_colors.clear();
			return false;
		}

		return true;
	}


} // namespace CAX

