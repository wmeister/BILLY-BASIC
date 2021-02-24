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
using common::string::numberp;

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
			Assert::IsFalse(containsp(array, 3, 'D'));
		}

		TEST_METHOD(TestTokenizeReturnsVectorOfTokens)
		{
			vector<token> tokens = tokenize(vector<string>({"1", "\"two\"", "3"}));
			Assert::IsTrue(std::is_same<decltype(tokens), vector<token>>::value);
			Assert::AreEqual(3, (int)tokens.size());
		}

		TEST_METHOD(TestTokenizeReturnsCorrectTokenType)
		{
			vector<token> tokens = tokenize(vector<string>({ "1", "\"two\"", "3" }));
			Assert::AreEqual("integer", tokens[0].type.c_str());
			Assert::AreEqual("string", tokens[1].type.c_str());
			Assert::AreEqual("integer", tokens[2].type.c_str());
		}

		TEST_METHOD(TestTokenizeReturnsCorrectTokenRaw)
		{
			vector<token> tokens = tokenize(vector<string>({ "1", "\"two\"", "3" }));
			Assert::AreEqual("1", tokens[0].raw.c_str());
			Assert::AreEqual("\"two\"", tokens[1].raw.c_str());
			Assert::AreEqual("3", tokens[2].raw.c_str());
		}

		TEST_METHOD(TestTokenizeReturnsInvalidTokenType)
		{
			vector<token> tokens = tokenize(vector<string>({ "\"invalid" }));
			Assert::AreEqual("invalid", tokens[0].type.c_str());
		}

		TEST_METHOD(TestNumberpReturnsTrueWithAStringOfNumbers)
		{
			Assert::IsTrue(numberp("123"));
		}

		TEST_METHOD(TestNumberpReturnsFalseWithAStringThatHasLetters)
		{
			Assert::IsFalse(numberp("1x2"));
		}
	};
}
