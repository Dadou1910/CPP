#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN &RPN::operator=(const RPN &other) { (void)other; return *this; }
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperator(const std::string &op, int lhs, int rhs) const
{
    if (op == "+")
        return (lhs + rhs);
    if (op == "-")
        return (lhs - rhs);
    if (op == "*")
        return (lhs * rhs);
    if (op == "/")
    {
        if (rhs == 0)
            throw std::runtime_error("Error: Division by zero");
        return (lhs / rhs);
    }
    throw std::runtime_error("Error: Unknown operator");
}

int RPN::evaluate(const std::string &expression) const
{
    std::istringstream iss(expression);
    std::string token;
    std::stack<int> operands;

    while (iss >> token)
    {
        if (isOperator(token))
        {
            if (operands.size() < 2)
                throw std::runtime_error("Error: Malformed expression");

            int rhs = operands.top(); operands.pop();
            int lhs = operands.top(); operands.pop();

            operands.push(applyOperator(token, lhs, rhs));
        }
        else
        {
            try
            {
                operands.push(std::stoi(token));
            }
            catch (const std::exception &)
            {
                throw std::runtime_error("Error: Invalid token \"" + token + "\"");
            }
        }
    }

    if (operands.size() != 1)
        throw std::runtime_error("Error: Malformed expression");

    return (operands.top());
}
