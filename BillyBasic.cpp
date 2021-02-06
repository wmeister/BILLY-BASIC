// BillyBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <boost/algorithm/string/trim.hpp>
#include "common/string.h"

using std::string;
using std::vector;

char memory[3583];

vector<string> arguments(string str)
{

}

string interpret(char* input)
{
    vector<string> args;
    string uc_input;
    string cmd;

    boost::trim(input);
    uc_input = common::string::upcase(input);
    

    if (cmd == "PRINT")
    {
        args = arguments(uc_input);
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
    printf("**** BILLY BASIC V1 ****\n%i BYTES FREE\n", sizeof(memory)/sizeof(memory[0]));

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
