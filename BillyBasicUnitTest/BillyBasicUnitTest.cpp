#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "../BillyBasic/BillyBasic.h"
#include "../BillyBasic/common/string.h"
#include "../BillyBasic/common/array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::string;
using std::vector;

namespace BillyBasicUnitTest
{
	TEST_CLASS(BillyBasicUnitTest)
	{
	public:
		
		TEST_METHOD(TestArgumentsTrims)
		{
			vector<string> args = arguments(" PRINT1   ");
			Assert::AreEqual(1, (int)args.size());
			Assert::AreEqual("1", args[0].c_str());
		}

		TEST_METHOD(TestArgumentsWithOneInteger)
		{
			vector<string>args = arguments("PRINT 1");
			Assert::AreEqual(1, (int)args.size());
			Assert::AreEqual("1", args[0].c_str());
		}
		
		TEST_METHOD(TestStringUpcase)
		{
			Assert::AreEqual("PRINT", common::string::upcase("print").c_str());
		}

		TEST_METHOD(TestArrayContainsp)
		{
			char array[] = { 'A','B','C' };

			Assert::IsTrue(common::array::containsp(array, 'A'));
		}
	};
}
