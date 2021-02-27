#include <algorithm>
#include <string>
#include "string.h"
#include "array.h"

namespace common 
{
	namespace string 
	{
		using std::string;

		bool lettersp(char* str)
		{
			for (size_t i = 0; i < _countof(str); i++)
			{
				if(str[i] == 'A'
					|| str[i] == 'a')
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
