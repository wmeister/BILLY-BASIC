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
using namespace common::array;
using common::string::numberp();

namespace BillyBasicUnitTest
{
	TEST_CLASS(BillyBasicUnitTest)
	{
	public:
		
		TEST_METHOD(TestArgumentsReturnsEmptyVector)
		{
			vector<string> args = arguments("PRINT");
			Assert::AreEqual(0, (int)args.size());
		}

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
		
		TEST_METHOD(TestCommonStringUpcase)
		{
			Assert::AreEqual("PRINT", common::string::upcase("print").c_str());
		}

		TEST_METHOD(TestCommonArrayContainspWorksWithArrayOfChar)
		{
			char array[] = { 'A','B','C' };

			Assert::IsTrue(containsp(array, 3, 'A'));
			Assert::IsTrue(containsp(array, 3, 'B'));
			Assert::IsTrue(containsp(array, 3, 'C'));
		}

		TEST_METHOD(TestTokenizeReturnsVectorOfTokens)
		{
			
		}

		TEST_METHOD(TestIsANumberReturnsTrueWithAStringOfNumbers)
		{
			Assert::IsTrue(numberp("123"));
		}

		TEST_METHOD(TestIsANumberReturnsFalseWithAStringThatHasLetters)
		{
			Assert::IsFalse(numberp("1x2"));
		}
	};
}
