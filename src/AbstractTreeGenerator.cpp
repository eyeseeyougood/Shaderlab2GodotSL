#include"AbstractTreeGenerator.hpp"

Token* StripTokenWhiteSpace(Token* tokens)
{
    Token* i = tokens;
    Token* newTokens = new Token();
    newTokens->type = i->type;
    Token* newTokensHead = newTokens;

    bool first = true;
    while (i->next != nullptr)
    {
        TokenType t = i->next->type;
        if (t != TokenType::space &&
            t != TokenType::endline
        )
        {
            newTokens->next = new Token();
            newTokens->next->type = i->next->type;
            newTokens = newTokens->next;
        }

        i = i->next;
    }

    return newTokensHead;
}

void GenerateAST(Token* tokens)
{
    Token* i = tokens;

    while (i->next != nullptr)
    {
        if (i->type == TokenType::treturn)
        {
            if (i->next->type == TokenType::variable)
            {
                
            }
        }

        i = i->next;
    }
}