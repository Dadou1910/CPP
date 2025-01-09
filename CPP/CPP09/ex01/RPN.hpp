#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>

class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expression) const;
private:
    bool isOperator(const std::string &token) const;
    int applyOperator(const std::string &op, int lhs, int rhs) const;
};

#endif