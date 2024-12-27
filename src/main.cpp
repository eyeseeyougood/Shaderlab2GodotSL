#include"main.hpp"

int main()
{
    Token* tokens = Tokenize("C:\\Users\\Mati\\source\\repos\\Shaderlab2GodotSL\\Example Shader.txt");

    // output all of the tokens by traversal
    Token* cToken = tokens;
    while(cToken->next != nullptr)
    {
        //cout << cToken->type << ", ";
        cToken = cToken->next;
    }

    // reconstruct generic code from tokens
    ofstream outputFile("C:\\Users\\Mati\\source\\repos\\Shaderlab2GodotSL\\Tokenized Shader.txt");

    if (!outputFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << " " << endl;
    cout << " " << endl;
    cToken = StripTokenWhiteSpace(tokens);
    while(cToken->next != nullptr)
    {
        string symbol = SymbolFromToken(cToken->type);
        outputFile << symbol;
        cToken = cToken->next;
    }

    outputFile.close();

    return 0;
}