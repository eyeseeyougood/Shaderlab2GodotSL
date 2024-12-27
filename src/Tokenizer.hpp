#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>
#include"Tokens.hpp"

using namespace std;

TokenType GetToken(string value, bool isExtra);

bool IsRubbish(string value);

bool IsValidInteger(string value);

unordered_set<string> RubbishMapping =
{
    "CGPROGRAM",
    "ENDCG",
};