#pragma once

#include<iostream>
#include"string"
using namespace std;

enum TokenType
{
    unidentified   =     -2,
    none           =     -1,
    sliteral       =      0,
    fliteral       =      1,
    iliteral       =      2,
    cliteral       =      3,
    variable       =      4,
    assignment     =      5,
    addition       =      6,
    subtraction    =      7,
    endline        =      8,
    space          =      9,
    rubbish        =     10,
    obracket       =     11,
    cbracket       =     12,
    ocurly         =     13,
    ccurly         =     14,
    comma          =     15,
    tstruct        =     16,
    normalise      =     17,
    comment        =     18,
    dot            =     19,
    inheritance    =     20,
    datatype       =     21,
    treturn        =     22,
    semicolon      =     23,
    function       =     24,
};

struct Token
{
    TokenType type = (TokenType)-1;

    string originalData;

    Token* next;
};

string NameFromToken(TokenType type);

string SymbolFromToken(TokenType type);