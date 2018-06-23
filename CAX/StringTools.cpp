#include "StringTools.h"

#include <cstring>

namespace CAX
{

	char* trimLeft(char* pStr)
	{
		char* s = pStr;
		while ((s[0] == ' ') || (s[0] == '\t')) {
			++s;
		}
		return s;
	}

	char* trimRight(char* pStr)
	{
		using namespace std;

		int lastChar = std::strlen(pStr) - 1;

		while ((lastChar >= 0) &&
			((pStr[lastChar] == 10)
				|| (pStr[lastChar] == 13)
				|| (pStr[lastChar] == ' ')
				|| (pStr[lastChar] == '\t')))
		{
			pStr[lastChar] = '\0';
			lastChar--;
		}
		
		return pStr;
	}

	char* trim(char* pStr)
	{
		using namespace std;

		int lastChar = std::strlen(pStr) - 1;

		// trimRight
		while ((lastChar >= 0) &&
			((pStr[lastChar] == 10)
				|| (pStr[lastChar] == 13)
				|| (pStr[lastChar] == ' ')
				|| (pStr[lastChar] == '\t')))
		{
			pStr[lastChar] = '\0';
			lastChar--;
		}

		// trimLeft
		char* s = pStr;
		while ((s[0] == ' ') || (s[0] == '\t')) {
			++s;
		}

		return ((s[0]) ? s : NULL);
	}

} // namespace CAX
