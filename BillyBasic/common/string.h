#pragma once
#include <string>

namespace common {
	namespace string {
		std::string upcase(char*);
		bool numberp(std::string);
		bool lettersp(char*, size_t);
		bool alphanump(char*, size_t);
	}
}