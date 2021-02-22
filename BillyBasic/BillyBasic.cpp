/* BILLY BASIC - A BASIC interpreter like on Commodore 64
 * Copyright(C) 2021 William Meister ALL RIGHTS RESERVED
 * URL: https://github.com/wmeister/BILLY-BASIC
 *
 **************************************************************************
 *
 * This program is proprietary software, you CAN NOT redistribute it and/or
 * modify it under ANY circumstances UNLESS you are the original author or
 * have received expressed written permission from the original author!
 *
 * THIS PROGRAM HAS NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED! THE
 * SOFTWARE IS PROVIDED "AS IS". NEVER IN ANY EVENT SHALL THE AUTHOR OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY DAMAGES, CLAIM OR OTHER LIABILITY
 * RELATED TO THE SOFTWARE.
 *
 * If you are seeing this license in source code it's because the author
 * was nice enough to hope people could learn by example from it.
 *
 * You should have received a copy of the Friendly Capitalist License
 * along with this program. If you did not, please email to0n@sdf.org
 *
 **************************************************************************
 *
 * For more information on why you shouldn't give your code away for free
 * visit http://to0n.sdf.org/fcl
 *
 */
// BillyBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <boost/algorithm/string/trim.hpp>
#include "common/string.h"
#include "common/array.h"
#include "BillyBasic.h"

using std::string;
using std::vector;
using boost::trim;
using common::array::containsp;

char memory[38911];

void syntax_error()
{
    printf("?SYNTAX\n ERROR\n");
}

// TODO unit test this
vector<token> tokenize(vector<string> strings)
{
    vector<token> tokens;

    for(string str : strings)
    {
        token tok;
        tok.raw = str;
        if(str[0] == '"' && str[str.length()-1] == '"')
        {
            tok.type = "string";
        }
        else 
        {
            // TODO iterate through str and check if all chars are numbers
            tok.type = "invalid";
        }
        tokens.push_back(tok);
    }
    return tokens;
}

void print(vector<string> args)
{
    // check for incomplete strings
    for(string arg : args)
    {
        if(arg[0] == '"')
        {
            if(arg[arg.length()-1] != '"')
            {
                syntax_error();
                return;
            }
        }
    }

    // actually print the arguments
    for(token arg : tokenize(args))
    {
        
    }
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

void eval(char* input)
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
        syntax_error();
    }
}

void read()
{
    char input[80]; // max input length

    printf("READY.\n");
    gets_s(input);
    eval(input);
}

int main()
{
    printf("       **** BILLY BASIC V1 ****\n64K RAM SYSTEM  %i BASIC BYTES FREE\n", (int)(sizeof(memory) / sizeof(memory[0])));

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
