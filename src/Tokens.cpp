#include"Tokens.hpp"

string SymbolFromToken(TokenType type)
{
    string result = "";

    switch (type)
    {
        case TokenType::unidentified:
            result = "(undefined)";
            break;
        case TokenType::none:
            result = "(none)";
            break;
        case TokenType::sliteral:
            result = "(string literal)";
            break;
        case TokenType::fliteral:
            result = "(float literal)";
            break;
        case TokenType::iliteral:
            result = "(integer literal)";
            break;
        case TokenType::cliteral:
            result = "(character literal)";
            break;
        case TokenType::variable:
            result = "(variable)";
            break;
        case TokenType::assignment:
            result = "=";
            break;
        case TokenType::addition:
            result = "+";
            break;
        case TokenType::subtraction:
            result = "-";
            break;
        case TokenType::endline:
            result = "\n";
            break;
        case TokenType::space:
            result = " ";
            break;
        case TokenType::rubbish:
            result = "(rubbish)";
            break;
        case TokenType::obracket:
            result = "(";
            break;
        case TokenType::cbracket:
            result = ")";
            break;
        case TokenType::ocurly:
            result = "{";
            break;
        case TokenType::ccurly:
            result = "}";
            break;
        case TokenType::comma:
            result = ",";
            break;
        case TokenType::tstruct:
            result = "struct";
            break;
        case TokenType::normalise:
            result = "normalise";
            break;
        case TokenType::comment:
            result = "// some comment (lost while tokenising)";
            break;
        case TokenType::dot:
            result = ".";
            break;
        case TokenType::inheritance:
            result = ":";
            break;
        case TokenType::datatype:
            result = "(datatype)";
            break;
        case TokenType::treturn:
            result = "return";
            break;
        case TokenType::semicolon:
            result = ";";
            break;
    }

    return result;
}

string NameFromToken(TokenType type)
{
    string result = "";

    switch (type)
    {
        case TokenType::unidentified:
            result = "undefined";
            break;
        case TokenType::none:
            result = "none";
            break;
        case TokenType::sliteral:
            result = "string literal";
            break;
        case TokenType::fliteral:
            result = "float literal";
            break;
        case TokenType::iliteral:
            result = "integer literal";
            break;
        case TokenType::cliteral:
            result = "character literal";
            break;
        case TokenType::variable:
            result = "variable";
            break;
        case TokenType::assignment:
            result = "assignment";
            break;
        case TokenType::addition:
            result = "addition";
            break;
        case TokenType::subtraction:
            result = "subtraction";
            break;
        case TokenType::endline:
            result = "endline";
            break;
        case TokenType::space:
            result = "space";
            break;
        case TokenType::rubbish:
            result = "rubbish";
            break;
        case TokenType::obracket:
            result = "open bracket";
            break;
        case TokenType::cbracket:
            result = "close bracket";
            break;
        case TokenType::ocurly:
            result = "open curly bracket";
            break;
        case TokenType::ccurly:
            result = "close curly bracket";
            break;
        case TokenType::comma:
            result = "comma";
            break;
        case TokenType::tstruct:
            result = "struct";
            break;
        case TokenType::normalise:
            result = "normalise";
            break;
        case TokenType::comment:
            result = "comment";
            break;
        case TokenType::dot:
            result = "dot";
            break;
        case TokenType::inheritance:
            result = "inheritance";
            break;
        case TokenType::datatype:
            result = "datatype";
            break;
        case TokenType::treturn:
            result = "return";
            break;
        case TokenType::semicolon:
            result = "semicolon";
            break;
    }

    return result;
}