#include <algorithm>
#include <string>
#include "string.h"

namespace common {
	namespace string {
		using std::string;

		const char* upcase(char* str) {
			string uc_str = string(str, sizeof(str));
			std::transform(uc_str.begin(), uc_str.end(), uc_str.begin(), ::toupper);
			return uc_str.c_str();
		}
	}
}
