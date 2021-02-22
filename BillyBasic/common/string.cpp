#include <algorithm>
#include <string>
#include "string.h"
#include "array.h"

namespace common 
{
	namespace string 
	{
		using std::string;

		string upcase(char* str) {
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
