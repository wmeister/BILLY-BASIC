#include <algorithm>
#include <string>
#include "string.h"
#include "array.h"

using std::toupper;
using std::tolower;

#define UPPER_OR_LOWER(x,c) x == tolower(c) || x == toupper(c)

namespace common 
{
	namespace string 
	{
		using std::string;

		bool alphanump(char* str, size_t size)
		{
			for (size_t i = 0; i < size; i++)
			{
				if (str[i] == '0'
					|| str[i] == '1'
					|| str[i] == '2'
					|| str[i] == '3'
					|| str[i] == '4'
					|| str[i] == '5'
					|| str[i] == '6'
					|| str[i] == '7'
					|| str[i] == '8'
					|| str[i] == '9'
					|| UPPER_OR_LOWER(str[i], 'A')
					|| UPPER_OR_LOWER(str[i], 'B')
					|| UPPER_OR_LOWER(str[i], 'C')
					|| UPPER_OR_LOWER(str[i], 'D')
					|| UPPER_OR_LOWER(str[i], 'E')
					|| UPPER_OR_LOWER(str[i], 'F')
					|| UPPER_OR_LOWER(str[i], 'G')
					|| UPPER_OR_LOWER(str[i], 'H')
					|| UPPER_OR_LOWER(str[i], 'I')
					|| UPPER_OR_LOWER(str[i], 'J')
					|| UPPER_OR_LOWER(str[i], 'K')
					|| UPPER_OR_LOWER(str[i], 'L')
					|| UPPER_OR_LOWER(str[i], 'M')
					|| UPPER_OR_LOWER(str[i], 'N')
					|| UPPER_OR_LOWER(str[i], 'O')
					|| UPPER_OR_LOWER(str[i], 'P')
					|| UPPER_OR_LOWER(str[i], 'Q')
					|| UPPER_OR_LOWER(str[i], 'R')
					|| UPPER_OR_LOWER(str[i], 'S')
					|| UPPER_OR_LOWER(str[i], 'T')
					|| UPPER_OR_LOWER(str[i], 'U')
					|| UPPER_OR_LOWER(str[i], 'V')
					|| UPPER_OR_LOWER(str[i], 'W')
					|| UPPER_OR_LOWER(str[i], 'X')
					|| UPPER_OR_LOWER(str[i], 'Y')
					|| UPPER_OR_LOWER(str[i], 'Z'))
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			
			return true;
		}
		
		bool lettersp(char* str, size_t size)
		{
			for (size_t i = 0; i < size; i++)
			{
				if(UPPER_OR_LOWER(str[i], 'A')
					|| UPPER_OR_LOWER(str[i], 'B')
					|| UPPER_OR_LOWER(str[i], 'C')
					|| UPPER_OR_LOWER(str[i], 'D')
					|| UPPER_OR_LOWER(str[i], 'E')
					|| UPPER_OR_LOWER(str[i], 'F')
					|| UPPER_OR_LOWER(str[i], 'G')
					|| UPPER_OR_LOWER(str[i], 'H')
					|| UPPER_OR_LOWER(str[i], 'I')
					|| UPPER_OR_LOWER(str[i], 'J')
					|| UPPER_OR_LOWER(str[i], 'K')
					|| UPPER_OR_LOWER(str[i], 'L')
					|| UPPER_OR_LOWER(str[i], 'M')
					|| UPPER_OR_LOWER(str[i], 'N')
					|| UPPER_OR_LOWER(str[i], 'O')
					|| UPPER_OR_LOWER(str[i], 'P')
					|| UPPER_OR_LOWER(str[i], 'Q')
					|| UPPER_OR_LOWER(str[i], 'R')
					|| UPPER_OR_LOWER(str[i], 'S')
					|| UPPER_OR_LOWER(str[i], 'T')
					|| UPPER_OR_LOWER(str[i], 'U')
					|| UPPER_OR_LOWER(str[i], 'V')
					|| UPPER_OR_LOWER(str[i], 'W')
					|| UPPER_OR_LOWER(str[i], 'X')
					|| UPPER_OR_LOWER(str[i], 'Y')
					|| UPPER_OR_LOWER(str[i], 'Z'))
				{
					continue;
				}
				else
				{
					return false;
				}
			}

			return true;
		}
		
		string upcase(char* str)
		{
			string uc_str = string(str);
			std::transform(uc_str.begin(), uc_str.end(), uc_str.begin(), ::toupper);
			return uc_str;
		}

		bool numberp(string str)
		{
			for (char c : str)
			{
				if (!common::array::containsp(const_cast<char*>("0123456789"), 10, c))
					return false;
			}
			return true;
		}
	}
}
