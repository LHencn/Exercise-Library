#include "Visitor.h"
void ExprPointer::Visit(NumberExpr* node)
{
  this->result = "";
    int number = node->number;
    do {
        this->result = static_cast<char>(number % 10 + '0') + this->result;
        number /= 10;
    } while (number);
    return ;
}
void ExprPointer::Visit(IdExpr* node)
{
	this->result = node->name;
}
void ExprPointer::Visit(BinaryExpr* node)
{
    this->result = "";
    switch (node->op) {
        case BinaryOperator::Plus:     this->result += "+"; break;
        case BinaryOperator::Minus:    this->result += "-"; break;
        case BinaryOperator::Multiply: this->result += "*"; break;
        case BinaryOperator::Divide:   this->result += "/"; break;
    }
    ExprPointer first, second;
    node->first->Accept(&first);
    node->second->Accept(&second);
    this->result += " " + first.result + " " + second.result;
    this->result = "(" + this->result + ")";
    return ;
}
void ExprPointer::Visit(InvokeExpr* node)
{
	ExprPointer first;
    this->result = node->name;
    for (auto x : node->arguments) {
        x->Accept(&first);
        this->result += " " + first.result;
    }
    this->result = "(" + this->result + ")";
    return ;
}
