// BillyBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <boost/algorithm/string/trim.hpp>
#include "common/string.h"
#include "common/array.h"

using std::string;
using std::vector;
using boost::trim;
using common::array::containsp;

char memory[3583];

void print(vector<string> args)
{
    printf("foo");
}

vector<string> arguments(string input)
{
    vector<string> args;

    trim(input);
    
    if (input.find("PRINT") == 0) {
        if (input.length() == 5)
            return args;

        input.replace(0, 5, "");

        string chunk = "";
        char cur = input[0];
        bool quotedp = false;

        while (!input.empty())
        {
            if (cur == '"')
            {
                chunk.push_back(cur);

                if (quotedp)
                {
                    args.push_back(chunk);
                    chunk = "";
                    quotedp = false;
                }
                else
                {
                    quotedp = true;
                }
            }
            else if(cur == ' ') // whitespace
            {
                if (quotedp)
                {
                    chunk.push_back(cur);
                }
                else if (chunk != "")
                {
                    args.push_back(chunk);
                    chunk = "";
                }
            }
            else
            {
                printf("made it\n");
                chunk.push_back(cur);
            }

            input.replace(0, 1, "");
            if (input.length() > 0)
                cur = input[0];
        }
        if (!chunk.empty())
            args.push_back(chunk);
    }

    return args;
}

void interpret(char* input)
{
    vector<string> args;
    string uc_input;
    string cmd;

    uc_input = common::string::upcase(input);
    trim(uc_input);

    if (uc_input.find("PRINT") == 0)
    {
        args = arguments(uc_input);
        print(args);
    }
    else
    {
        printf("?SYNTAX\n ERROR\n");
    }
}

void read()
{
    char input[80]; // max input length

    printf("READY.\n");
    gets_s(input);
    interpret(input);
}

int main()
{
    printf("**** BILLY BASIC V1 ****\n%i BYTES FREE\n", (int)(sizeof(memory) / sizeof(memory[0])));

    for (;;)
    {
        read();
    }
}

void BillyBasic()
{
    main();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
