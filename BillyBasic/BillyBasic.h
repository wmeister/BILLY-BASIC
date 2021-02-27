#pragma once

#include <string>
#include <vector>

typedef struct { std::string type; std::string raw; } token;
void print(std::vector<std::string>);
std::vector<std::string> arguments(std::string);
void eval(char*);
void read();
int main();
void syntax_error();
void BillyBasic();
std::vector<token> tokenize(std::vector<std::string>);
bool var_namep(char*);