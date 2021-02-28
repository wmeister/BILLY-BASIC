#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "../BillyBasic/BillyBasic.h"
#include "../BillyBasic/common/string.h"
#include "../BillyBasic/common/array.h"
#include "../BillyBasic/common/character.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::string;
using std::vector;
using namespace common::array;
using namespace common::string;

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

		TEST_METHOD(TestVar_namepReturnsFalseWithInvalidVariableNames)
		{
			Assert::IsFalse(var_namep("1"));
			Assert::IsFalse(var_namep("$"));
			Assert::IsFalse(var_namep("%"));
			Assert::IsFalse(var_namep("PRINT"));
			Assert::IsFalse(var_namep("XPRINTX"));
		}
		
		TEST_METHOD(TestVar_namepReturnsTrueWithValidVariableNames)
		{
			Assert::IsTrue(var_namep("A$"));
			Assert::IsTrue(var_namep("MTH$"));
			Assert::IsTrue(var_namep("K%"));
			Assert::IsTrue(var_namep("CNT%"));
			Assert::IsTrue(var_namep("FP"));
			Assert::IsTrue(var_namep("SUM"));
		}

		TEST_METHOD(TestLetterspReturnsTrueWithLetters)
		{
			Assert::IsTrue(lettersp("abc", 3));
			Assert::IsTrue(lettersp("XYZ", 3));
		}

		TEST_METHOD(TestLetterspReturnsFalseWithNumbers)
		{
			Assert::IsFalse(lettersp("123", 3));
			Assert::IsFalse(lettersp("12three", 7));
		}

		TEST_METHOD(TestCommonCharacterNumberpReturnsTrueWith0)
		{
			Assert::IsTrue(common::character::numberp('0'));
		}

		TEST_METHOD(TestCommonCharacterNumberpReturnsFalseWithA)
		{
			Assert::IsFalse(common::character::numberp(('A')));
		}

		TEST_METHOD(TestAlphanumpReturnsTrueWithValidInput)
		{
			Assert::IsTrue(alphanump("aaa", 3));
			Assert::IsTrue(alphanump("111", 3));
			Assert::IsTrue(alphanump("a1a", 3));
			Assert::IsTrue(alphanump("1a1", 3));
		}

		TEST_METHOD(TestAlphanumpReturnsFalseWithInvalidInput)
		{
			Assert::IsFalse(alphanump("%", 1));
			Assert::IsFalse(alphanump("$", 1));
			Assert::IsFalse(alphanump("@", 1));
		}
	};
}
