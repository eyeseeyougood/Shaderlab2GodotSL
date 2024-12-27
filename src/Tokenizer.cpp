#include"Tokenizer.hpp"

Token* Tokenize(string filename)
{
    Token* currentToken = new Token();
    Token* result = currentToken; // keep track of head

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open the file!" << endl;
        return nullptr;
    }

    string line;
    string buff = "";
    bool bufferIsComment = false;
    bool cCharIsToken;
    int lineID = 0;
    while (getline(file, line)) {
        for (int i = 0; i < line.length(); i++)
        {
            if (GetToken({line[i]}, true) == TokenType::none || buff.length() == 0)
            {
                buff.push_back(line[i]);
                cCharIsToken = false;
            }
            else
            {
                cCharIsToken = true;
            }

            cout << buff << endl;

            TokenType potentialToken = GetToken(buff, false);

            // check for comments
            bufferIsComment = buff[0] == '/' && buff[1] == '/';

            if (bufferIsComment) {continue;}

            // if ends on a token, then it is an unidentified token
            if (cCharIsToken) { potentialToken = TokenType::unidentified; }

            // handle variables / datatypes being at the end of the line
            if (potentialToken == TokenType::none && i == line.length()-1) { potentialToken = TokenType::unidentified; }

            if (potentialToken != TokenType::none)
            {
                currentToken->type = potentialToken;
                Token* nToken = new Token();
                currentToken->next = nToken;
                currentToken = nToken;
                buff.clear();
                cout << "found main token: " << potentialToken << endl;
            }

            if (cCharIsToken)
            {
                currentToken->type = GetToken({line[i]}, true);
                Token* nToken = new Token();
                currentToken->next = nToken;
                currentToken = nToken;
                cout << "found extra token: " << currentToken->type << endl;
            }
        }

        if (bufferIsComment)
        {
            currentToken->type = TokenType::comment;
            Token* nToken = new Token();
            currentToken->next = nToken;
            currentToken = nToken;
            buff.clear();
            bufferIsComment = false;
        }

        currentToken->type = TokenType::endline;
        Token* nToken = new Token();
        currentToken->next = nToken;
        currentToken = nToken;
        buff.clear();
        cout << "found endline token" << endl;

        lineID++;
    }

    file.close();

    return result;
}

bool IsRubbish(string value)
{
    return RubbishMapping.find(value) != RubbishMapping.end();
}

bool IsValidInteger(string str) {
    try {
        stoi(str);
        return true;
    } catch (const invalid_argument& e) {
        return false;
    } catch (const out_of_range& e) {
        return false;
    }
}

TokenType GetToken(string value, bool isExtra)
{
    TokenType result = TokenType::none;

    if (value[0] == '\"' && value[value.length()-1] == '\"' && value.length() > 1)
    {
        result = TokenType::sliteral;
    }
    else if (IsValidInteger(value) && !isExtra)
    {
        result = TokenType::iliteral;
    }
    else if (value == " ")
    {
        result = TokenType::space;
    }
    else if (value == "{")
    {
        result = TokenType::ocurly;
    }
    else if (value == "}")
    {
        result = TokenType::ccurly;
    }
    else if (value == "(")
    {
        result = TokenType::obracket;
    }
    else if (value == ")")
    {
        result = TokenType::cbracket;
    }
    else if (value == ",")
    {
        result = TokenType::comma;
    }
    else if (value == "+")
    {
        result = TokenType::addition;
    }
    else if (value == "=")
    {
        result = TokenType::assignment;
    }
    else if (value == ".")
    {
        result = TokenType::dot;
    }
    else if (value == ":")
    {
        result = TokenType::inheritance;
    }
    else if (value == ";")
    {
        result = TokenType::semicolon;
    }
    else if (value == "-")
    {
        result = TokenType::subtraction;
    }
    else if (value == "return")
    {
        result = TokenType::treturn;
    }
    else if (value == "struct")
    {
        result = TokenType::tstruct;
    }
    else if (value == "normalize") // is this a retarded token???
    {
        result = TokenType::normalise;
    }
    else if (IsRubbish(value))
    {
        result = TokenType::rubbish;
    }

    return result;
}