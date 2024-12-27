#pragma once

#include<iostream>
#include"CustomDataTypes.hpp"
#include"Tokens.hpp"

using namespace std;

void GenerateAST(Token* tokens);

// TODO: add constructors and destructors to manage memory, for now, this is completely cooked

struct ASNode
{
    ASNode* left;
    ASNode* middle;
    ASNode* right;
};

struct Vec4Node : ASNode
{
    Vec4* data = new Vec4();
};

struct FragOutNode : ASNode
{
    Vec4Node* right;
};

struct VertShaderNode : ASNode
{
};

struct FragShaderNode : ASNode
{
};

struct PropertyNode : ASNode
{
    PropertyNode* next;

    string name;
    GenericType* type;
};

struct PropertiesNode : ASNode
{
    PropertyNode* properties;
};

struct ShaderNode : ASNode
{
    string name;
    
    PropertiesNode* properties;
    VertShaderNode* vertShader;
    FragShaderNode* fragShader;
};

struct AssignmentNode : ASNode
{
};

struct AdditionNode : ASNode
{
};

struct SubtractionNode : ASNode
{
};

struct MultiplicationNode : ASNode
{
};

struct DivisionNode : ASNode
{
};