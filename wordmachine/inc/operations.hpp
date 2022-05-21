#ifndef _OPERATIONS_HPP
#define _OPERATIONS_HPP
#include<stdint.h>
#include<iostream>
#include<vector>
#include<string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stack>
// this header file contains boost::split function
#include<bits/stdc++.h>
#include<boost/algorithm/string.hpp>

class calculate
{
    public:
    int32_t operation(std::string &S);
    bool pop();
    bool dup();
    bool min();
    bool plus();

    private:
    std::stack<uint32_t> m_stack;

};
#endif