#include "handler.h"
#include <cstdlib>
#include <functional>

namespace myTool {
    auto in_range = [](int b, int e) {
        return [=](int x) {
            return x >= b && x <= e;
        };
    };
    template <typename T, typename U>
    std::function<bool(int)>combin_range(T a, U b) {
        return [=](int x) {
            return a(x) || b(x);
        };
    }
    auto is_lowwer = in_range('a', 'z');
    auto is_upper = in_range('A', 'Z');
    auto is_digit = in_range('0', '9');
    auto is_alpha = combin_range(is_lowwer, is_upper);
    auto is_letter = combin_range(is_alpha, is_digit);
}
bool IdHandler::Test(string token, bool forInvoke)
{
	if (forInvoke == true) return false;
    if (token.size() == 0) return false;
    if (myTool::is_digit(token[0])) return false;
    for (auto x : token) {
        if (myTool::is_letter(x)) continue;
        return false;
    }
    return true;
}
shared_ptr<Expr> IdHandler::IdFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<IdExpr> expr = make_shared<IdExpr>();
    expr->name = token;
    return expr;
}

shared_ptr<Expr> NumberHandler::NumberFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<NumberExpr> expr = make_shared<NumberExpr>();
    expr->number = 0;
    for (auto x : token) {
        expr->number += expr->number * 9 + (x - '0');
    }
    return expr;
}
bool NumberHandler::Test(string token, bool forInvoke)
{
	if (forInvoke == true) return false;
    if (token.size() == 0) return false;
    for (auto x : token) {
        if (myTool::is_digit(x)) continue;
        return false;
    }
    return true;
}

bool BinaryHandler::Test(string token, bool forInvoke)
{
	if (forInvoke == true) return false;
    if (token.size() != 1) return false;
    switch(token[0]) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
    return false;
}
shared_ptr<Expr>BinaryHandler::BinaryFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<BinaryExpr> expr = make_shared<BinaryExpr>();
    switch(token[0]) {
        case '+': expr->op = BinaryOperator::Plus; break;
        case '-': expr->op = BinaryOperator::Minus; break;
        case '*': expr->op = BinaryOperator::Multiply; break;
        case '/': expr->op = BinaryOperator::Divide; break;   
    }
    expr->first = arguments[0];
    expr->second = arguments[1];
    arguments.erase(arguments.begin());
    arguments[0] = expr;
    if (arguments.size() == 1) {
        return expr;
    } else {
        return CreateExpr(token, arguments);
    }
    
}

shared_ptr<Expr> InvokeHandler::InvokeFactory::CreateExpr(string token, vector<shared_ptr<Expr>>arguments)
{
	shared_ptr<InvokeExpr> expr = make_shared<InvokeExpr>();
    expr->name = token;
    for (auto x : arguments) {
        expr->arguments.push_back(x);
    }
    return expr;
}
bool InvokeHandler::Test(string token, bool forInvoke)
{
	if (forInvoke == false) return false;
    if (token.size() <= 0) return false;
    if (myTool::is_digit(token[0])) return false;
    for (auto x : token) {
        if (myTool::is_letter(x)) continue;
        return false;
    }
    return true;
    
}


