#include "array.h"
#include <algorithm>

using std::find;
using std::begin;
using std::end;

namespace common
{
	namespace array
	{

		bool containsp(char* array, size_t size, char elm)
		{
			for (size_t i = 0; i < size; i++)
			{
				if (array[i] == elm)
					return true;
			}

			return false;
		}
	}
}